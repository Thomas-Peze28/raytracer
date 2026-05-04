/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Vector3D
*/

#pragma once

    #include <cmath>

namespace Raytracer
{
    namespace Math
    {
        class Vector3D
        {
            public:
                Vector3D();
                Vector3D(double x, double y, double z);
                Vector3D(const Vector3D &other);
                ~Vector3D() = default;

                float length() const;
                float dot(const Vector3D &other) const;

                double _x;
                double _y;
                double _z;

                Vector3D& operator=(const Vector3D &other);


                Vector3D operator+(const Vector3D &other) const;
                Vector3D &operator+=(const Vector3D &other);

                Vector3D operator-(const Vector3D &other) const;
                Vector3D &operator-=(const Vector3D &other);

                Vector3D operator*(const Vector3D &other) const;
                Vector3D &operator*=(const Vector3D &other);

                Vector3D operator/(const Vector3D &other) const;
                Vector3D &operator/=(const Vector3D &other);

                Vector3D operator*(float scalar) const;
                Vector3D &operator*=(float scalar);

                Vector3D operator/(double scalar) const;
                Vector3D &operator/=(double scalar);
        };
    };
};