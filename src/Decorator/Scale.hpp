/**
 * @file Scale.hpp
 * @brief Decorator that applies non-uniform (or uniform) scaling to any primitive.
 *
 * This header declares the `Scale` decorator which wraps an existing
 * `IPrimitive` and provides a view of that primitive scaled around its
 * `pivot()` point. The decorator implements the same `IPrimitive` interface
 * so it can be stacked with other decorators such as `Translation` and
 * `Rotation` without altering client code.
 *
 * The scaling semantics used here are:
 * - Rays are transformed from world space into the scaled object space by
 *   dividing the ray origin and direction components by the scale factors
 *   (relative to the decorator pivot). This maps an incoming ray to the
 *   parametric space of the underlying primitive so intersection tests are
 *   delegated unchanged.
 * - When an intersection is reported by the underlying primitive, the hit
 *   point is transformed back into world space by applying the scale
 *   factors around the pivot.
 * - Normals are transformed by the inverse transpose of the (diagonal)
 *   scaling matrix. For axis-aligned scale (diagonal) this reduces to
 *   component-wise division followed by normalization. This implementation
 *   approximates the correct normal transform for diagonal scale matrices.
 *
 * The `Scale` class intentionally validates factors (non-zero) to avoid
 * singular transforms which would make ray tracing undefined.
 *
 * Doxygen blocks below are intentionally verbose to provide a comprehensive
 * description of behaviour, mathematics and usage examples for maintainers
 * and automated documentation generation systems.
 */

#pragma once

#include "IPrimitive.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"

#include <memory>

namespace Raytracer {

    namespace Object {

        /**
         * @brief Scale decorator applying per-axis factors to a primitive.
         *
         * The `Scale` decorator implements `IPrimitive` and wraps another
         * `IPrimitive` instance. It forwards intersection tests by
         * transforming rays into the scaled local space of the wrapped
         * primitive and converts hits back into world space.
         *
         * Usage example:
         * @code
         * std::unique_ptr<IPrimitive> s = std::make_unique<Sphere>(center, r, color);
         * s = std::make_unique<Scale>(std::move(s), Math::Vector3D(1.5, 1.0, 0.75));
         * scene.objects.push_back(std::move(s));
         * @endcode
         *
         * Notes on numerical stability:
         * - Zero factors are rejected with `ErrorMajor` because they
         *   represent singular transforms and would map points to a plane
         *   or line, breaking ray-to-object correspondence.
         * - Very small factors are allowed but may produce floating point
         *   sensitivity; consider clamping or validating upstream if needed.
         */
        class Scale : public IPrimitive {
            public:
                /**
                 * @brief Construct a Scale decorator.
                 *
                 * @param object The primitive to wrap (ownership transferred).
                 * @param factors Per-axis scale factors (x,y,z). All components
                 *        must be non-zero.
                 *
                 * The constructor caches the pivot point of the wrapped
                 * primitive because many primitives return stable pivot
                 * locations (e.g., center for spheres). If a primitive's
                 * pivot is dynamic, this decorator will use the pivot as it
                 * was at construction time.
                 */
                Scale(std::unique_ptr<IPrimitive> object, const Math::Vector3D &factors);

                /**
                 * @brief Default virtual destructor (override of interface).
                 */
                ~Scale() = default;

                /**
                 * @brief Ray-primitive intersection in world space.
                 *
                 * The method transforms the incoming ray into the scaled
                 * local space of the wrapped primitive, calls the wrapped
                 * `hit()` and remaps the resulting hit information into
                 * world space.
                 *
                 * This function returns a `HitResult` where:
                 * - `is_hit` is true when an intersection occurred,
                 * - `t` is an approximation of the hit distance in world
                 *   space (computed by projecting the world-space hit
                 *   position onto the ray's direction),
                 * - `point` is the hit location in world coordinates,
                 * - `normal` is the transformed and normalized surface
                 *   normal in world coordinates.
                 *
                 * @param ray Ray in world coordinates.
                 * @return HitResult describing the intersection.
                 */
                HitResult hit(const Ray &ray) const override;

                /**
                 * @brief Return the pivot point used by this decorator.
                 *
                 * The pivot is returned as a `Math::Vector3D` and is the
                 * cached pivot of the wrapped primitive measured in world
                 * coordinates at construction time.
                 *
                 * @return Pivot point of the decorated primitive.
                 */
                Math::Vector3D pivot() const override;

            private:
                std::unique_ptr<IPrimitive> _object; /**< Wrapped primitive */
                Math::Vector3D _factors;            /**< Scale factors */
                Math::Point3D _pivot;               /**< Cached pivot point */

                /**
                 * @brief Transform a normal/vector from object space to
                 * world space taking scaling into account.
                 *
                 * Because scaling is diagonal here (per-axis factors), the
                 * inverse-transpose of the scale matrix is also diagonal
                 * with reciprocal factors. For unit-preserving results we
                 * divide component-wise and normalize the result.
                 *
                 * @param vector Vector in object-local coordinates.
                 * @return Transformed vector in world coordinates (unnormalized).
                 */
                Math::Vector3D transformVector(const Math::Vector3D &vector) const;

                /**
                 * @brief Transform a point from object space back to world space.
                 *
                 * Applies per-axis multiplication around the pivot.
                 *
                 * @param point Point in object-local coordinates.
                 * @return Point in world coordinates.
                 */
                Math::Point3D transformPoint(const Math::Point3D &point) const;

                /**
                 * @brief Compute an approximate parametric `t` value for a world-space hit.
                 *
                 * This helper projects the vector from the ray origin to the
                 * hit point onto the ray direction to compute a scalar
                 * distance. The value is used by the scene hit traversal to
                 * sort intersections.
                 *
                 * @param ray Ray in world space.
                 * @param point Hit point in world space.
                 * @return Approximate `t` value (distance along ray direction).
                 */
                double computeT(const Ray &ray, const Math::Point3D &point) const;
        };
    }
}