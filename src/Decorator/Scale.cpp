/**
 * @file Scale.cpp
 * @brief Implementation of the Scale decorator.
 *
 * This translation unit implements the algorithms described in the
 * documentation of `Scale.hpp`. The focus of the implementation is on
 * correctness of mapping between world space and the decorated object's
 * local (scaled) space and on providing a robust `HitResult` re-projection
 * back to world coordinates.
 *
 * The comments below are intentionally extensive to help future
 * maintainers understand the mathematics and rationale for each step.
 */

#include "Scale.hpp"
#include "RTCError.hpp"

#include <cmath>

/**
 * @brief Construct a Scale decorator and validate inputs.
 *
 * The constructor stores the wrapped primitive, the per-axis factors
 * and caches the pivot. The pivot is used to apply scale around the
 * primitive's natural center, ensuring consistent geometric behaviour.
 *
 * Rationale: caching the pivot at construction avoids repeated virtual
 * calls and stabilizes behaviour when primitives are immutable in
 * pivot. If a primitive were to change pivot dynamically (rare), the
 * decorator would need to be re-created or updated to reflect that.
 */
Raytracer::Object::Scale::Scale(std::unique_ptr<IPrimitive> object, const Math::Vector3D &factors)
    : _object(std::move(object)), _factors(factors), _pivot(_object->pivot()._x, _object->pivot()._y, _object->pivot()._z)
{
    if (_factors._x == 0.0 || _factors._y == 0.0 || _factors._z == 0.0) {
        throw ErrorMajor("Scale factors must be non-zero");
    }
}


/**
 * @brief Ray-primitive intersection handling for scaled primitives.
 *
 * Steps performed in this method:
 * 1. Translate the ray origin to pivot-relative coordinates (world->pivot).
 * 2. Divide origin components and direction components by scale factors
 *    to produce a ray in the wrapped primitive's local coordinate system.
 * 3. Call the wrapped primitive's `hit()` with the scaled ray.
 * 4. If a hit is found, convert the hit point back to world coordinates by
 *    applying per-axis multiplication around the pivot.
 * 5. Transform the reported normal by dividing by scale factors then
 *    normalizing the result (inverse-transpose for diagonal matrix).
 * 6. Recompute an approximate world-space `t` value for correct sorting.
 *
 * Notes on step (2): dividing both origin and direction by factors is
 * equivalent to applying the inverse scaling matrix to the ray. For
 * non-uniform scale this changes ray parameterization but preserves
 * geometric intersection relationships when remapped appropriately.
 */
Raytracer::HitResult Raytracer::Object::Scale::hit(const Ray &ray) const
{
    Math::Point3D local_origin(
        ray._origin._x - _pivot._x,
        ray._origin._y - _pivot._y,
        ray._origin._z - _pivot._z
    );

    // Map the ray into the object's unscaled local space by applying the
    // inverse of the scale (component-wise division). The pivot is re-applied
    // after scaling the origin so that the object-space origin is correctly
    // located relative to the primitive's expected coordinates.
    Ray scaled_ray(
        Math::Point3D(
            _pivot._x + (local_origin._x / _factors._x),
            _pivot._y + (local_origin._y / _factors._y),
            _pivot._z + (local_origin._z / _factors._z)
        ),
        Math::Vector3D(
            ray._direction._x / _factors._x,
            ray._direction._y / _factors._y,
            ray._direction._z / _factors._z
        )
    );

    // Delegate intersection test to wrapped primitive in its local space.
    HitResult result = _object->hit(scaled_ray);

    if (!result.is_hit) {
        // No intersection in local space -> no intersection in world.
        return result;
    }

    // Transform local hit point back to world coordinates using the scale
    // factors and pivot translation. We multiply the offset from pivot
    // by the scale factors and re-add the pivot.
    result.point = transformPoint(result.point);

    // Transform normal using inverse-transpose for diagonal scaling. Here
    // dividing component-wise by scaling factors approximates that and we
    // normalize to ensure lighting computations remain correct.
    result.normal = transformVector(result.normal).normalized();

    // Recompute an approximate world-space t for sorting intersections.
    result.t = computeT(ray, result.point);
    return result;
}


/**
 * @brief Return the cached pivot point used for scaling.
 *
 * The pivot is returned as a `Math::Vector3D` to match other pivot-using
 * APIs in the codebase.
 */
Raytracer::Math::Vector3D Raytracer::Object::Scale::pivot() const
{
    return Math::Vector3D(_pivot._x, _pivot._y, _pivot._z);
}


/**
 * @brief Transform a surface normal/vector from object-local to world.
 *
 * Because the scale matrix is diagonal, the inverse-transpose simply uses
 * reciprocal factors. For a general 3x3 matrix M the correct transform
 * for normals is (M^{-1})^{T} * n. For diagonal M = diag(sx, sy, sz)
 * this reduces to diag(1/sx, 1/sy, 1/sz) * n.
 */
Raytracer::Math::Vector3D Raytracer::Object::Scale::transformVector(const Math::Vector3D &vector) const
{
    return Math::Vector3D(vector._x / _factors._x, vector._y / _factors._y, vector._z / _factors._z);
}


/**
 * @brief Transform a point from object-local coordinates to world coordinates.
 *
 * This operation applies per-axis multiplication around the cached pivot.
 */
Raytracer::Math::Point3D Raytracer::Object::Scale::transformPoint(const Math::Point3D &point) const
{
    return Math::Point3D(
        _pivot._x + ((point._x - _pivot._x) * _factors._x),
        _pivot._y + ((point._y - _pivot._y) * _factors._y),
        _pivot._z + ((point._z - _pivot._z) * _factors._z)
    );
}


/**
 * @brief Compute a world-space parametric distance `t` for a hit point.
 *
 * The value is computed by projecting the vector from the ray origin to
 * the hit point onto the ray direction. This is robust for sorting hits
 * and for use by the scene's shadow checks.
 */
double Raytracer::Object::Scale::computeT(const Ray &ray, const Math::Point3D &point) const
{
    Math::Vector3D hit_vector = point - ray._origin;
    Math::Vector3D direction = ray._direction;
    double direction_length_sq = direction.dot(direction);

    if (direction_length_sq == 0.0) {
        return 0.0;
    }

    return hit_vector.dot(direction) / direction_length_sq;
}