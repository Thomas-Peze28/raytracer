/*
** EPITECH PROJECT, 2026
** include
** File description:
** Point3D
*/

#ifndef POINT3D_H
    #define POINT3D_H

    #include <iostream>
    #include <string>
    #include <vector>
    #include <cmath>
namespace Raytracer
{
    namespace Math
    {
        class Vector3D;

        class Point3D {
            public:
                Point3D();
                Point3D(float x, float y, float z);
                Point3D(const Point3D &other);
                ~Point3D() = default;

                float _x;
                float _y;
                float _z;

                Vector3D operator-(const Point3D& other) const;
                Point3D operator+(const Vector3D& vec) const;
                Point3D operator-(const Vector3D& vec) const;

            private:
                float distance(const Point3D& other) const;
        };
    }
}

#endif /* POINT3D_H */
