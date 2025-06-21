#pragma once

#include "Core.h"

//TODO: More static asserts for easier error messages

namespace sfmath{
    template<typename TYPE=float>
    class Vec3{
    public:
        TYPE m_X = static_cast<TYPE>(0);
        TYPE m_Y = static_cast<TYPE>(0);
        TYPE m_Z = static_cast<TYPE>(0);

        Vec3()SFMATH_NOEXCEPT{}
        Vec3(TYPE value)SFMATH_NOEXCEPT:
            m_X(value),
            m_Y(value),
            m_Z(value){
            static_assert(std::is_arithmetic<TYPE>::value, "TYPE must be a numeric type");
        }

        Vec3(TYPE x, TYPE y)SFMATH_NOEXCEPT:
            m_X(x),
            m_Y(y),
            m_Z(0){
            static_assert(std::is_arithmetic<TYPE>::value, "TYPE must be a numeric type");
        }

        Vec3(TYPE x, TYPE y, TYPE z)SFMATH_NOEXCEPT:
            m_X(x),
            m_Y(y),
            m_Z(z){
            static_assert(std::is_arithmetic<TYPE>::value, "TYPE must be a numeric type");
        }

        void SetData(TYPE x, TYPE y, TYPE z) SFMATH_NOEXCEPT{
            m_X = x;
            m_Y = y;
            m_Z = z;
        }
    public:
        //TODO: make only available for type float/double
        typename std::enable_if<std::is_floating_point<TYPE>::value, void>::type
        Normalize() SFMATH_NOEXCEPT{
            TYPE mag = GetMagnitude();
            if(mag <= 1)return;
            m_X /= mag;
            m_Y /= mag;
            m_Z /= mag;
        }
        Vec3<TYPE> GetNormalized() const SFMATH_NOEXCEPT{
            TYPE mag = GetMagnitude();
            if(mag == 1)return *this;
            if(mag <= 0.001)mag = 0.001;

            return Vec3<TYPE>(m_X / mag, m_Y / mag, m_Z / mag);
        }
        template<typename T>
        T GetMagnitude() const SFMATH_NOEXCEPT{return static_cast<T>(sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z));}
        TYPE GetMagnitude() const SFMATH_NOEXCEPT{return static_cast<TYPE>(sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z));}

        template<typename T>
        T GetDotProduct(const Vec3<TYPE> rhs) const SFMATH_NOEXCEPT{return static_cast<T>(m_X * rhs.m_X + m_Y * rhs.m_Y + m_Z * rhs.m_Z);}
        TYPE GetDotProduct(const Vec3<TYPE> rhs) const SFMATH_NOEXCEPT{return static_cast<TYPE>(m_X * rhs.m_X + m_Y * rhs.m_Y + m_Z * rhs.m_Z);}
    public:
        //Operators
        Vec3<TYPE> operator-() const SFMATH_NOEXCEPT{
            return Vec3<TYPE>(-m_X, -m_Y, -m_Z);
        }
        Vec3<TYPE> operator+=(const Vec3<TYPE> rhs) SFMATH_NOEXCEPT{
            m_X += rhs.m_X;
            m_Y += rhs.m_Y;
            m_Z += rhs.m_Z;
            return *this;
        }
        Vec3<TYPE> operator-=(const Vec3<TYPE> rhs) SFMATH_NOEXCEPT{
            m_X -= rhs.m_X;
            m_Y -= rhs.m_Y;
            m_Z -= rhs.m_Z;
            return *this;
        }
        Vec3<TYPE> operator*=(const Vec3<TYPE> rhs) SFMATH_NOEXCEPT{
            m_X *= rhs.m_X;
            m_Y *= rhs.m_Y;
            m_Z *= rhs.m_Z;
            return *this;
        }
        Vec3<TYPE> operator/=(const Vec3<TYPE> rhs) SFMATH_NOEXCEPT{
            m_X /= rhs.m_X;
            m_Y /= rhs.m_Y;
            m_Z /= rhs.m_Z;
            return *this;
        }
        Vec3<TYPE> operator*=(TYPE value) SFMATH_NOEXCEPT{
            m_X *= value;
            m_Y *= value;
            m_Z *= value;
            return *this;
        }
        Vec3<TYPE> operator/=(TYPE value) SFMATH_NOEXCEPT{
            m_X /= value;
            m_Y /= value;
            m_Z /= value;
            return *this;
        }

        Vec3<TYPE> operator+(const Vec3<TYPE> rhs) const SFMATH_NOEXCEPT{
            return Vec3<TYPE>(m_X + rhs.m_X, m_Y + rhs.m_Y, m_Z + rhs.m_Z);
        }
        Vec3<TYPE> operator-(const Vec3<TYPE> rhs) const SFMATH_NOEXCEPT{
            return Vec3<TYPE>(m_X - rhs.m_X, m_Y - rhs.m_Y, m_Z - rhs.m_Z);
        }
        Vec3<TYPE> operator*(const Vec3<TYPE> rhs) const SFMATH_NOEXCEPT{
            return Vec3<TYPE>(m_X * rhs.m_X, m_Y * rhs.m_Y, m_Z * rhs.m_Z);
        }
        Vec3<TYPE> operator/(const Vec3<TYPE> rhs) const SFMATH_NOEXCEPT{
            return Vec3<TYPE>(m_X / rhs.m_X, m_Y / rhs.m_Y, m_Z / rhs.m_Z);
        }

        inline bool operator==(const Vec3<TYPE>& rhs) const SFMATH_NOEXCEPT {
            static_assert(std::is_arithmetic<TYPE>::value, "TYPE must be a numeric type");
            return rhs.m_X == m_X && rhs.m_Y == m_Y && rhs.m_Z == m_Z;
        }
        inline bool operator!=(const Vec3<TYPE>& rhs) const SFMATH_NOEXCEPT{
            return rhs.m_X != m_X || rhs.m_Y != m_Y || rhs.m_Z != m_Z;
        }
    };
}