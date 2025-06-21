#pragma once

#include "Core.h"
#include "SMat4x4.h"

namespace sfmath{
    class SMat4x4;
    class Quat{
    public:
        Quat() noexcept{}
        /// @brief Takes in assumed normalized quaternion data
        Quat(float w, float x, float y, float z) noexcept : m_W(w), m_X(x), m_Y(y), m_Z(z){}
        /// @brief Makes a copy of an existing quaternion
        Quat(const Quat& quat) noexcept
            : m_W(quat.m_W), m_X(quat.m_X), m_Y(quat.m_Y), m_Z(quat.m_Z){}

        Quat GetConjugate() const noexcept{
            return Quat(m_W, -m_X, -m_Y, -m_Z);
        }

        /// @brief Returns a rotation matrix that represents the quaternion
        SMat4x4 ToSMat4x4Matrix()const noexcept{
            float xx = m_X*m_X, yy =m_Y*m_Y, zz=m_Z*m_Z, ww=m_W*m_W;

            float xy = m_X*m_Y, xz = m_X * m_Z;
            float wx = m_W * m_X, wy = m_W * m_Y, wz = m_W * m_X;
            float yz = m_Y * m_Z;

            SMat4x4 matrix;
            matrix.SetValue(0,0, 1-(2*yy)-(2*zz));
            matrix.SetValue(0,1, (2*xy)+(2*wz));
            matrix.SetValue(0,2, 2*xz-2*wy);
            matrix.SetValue(0,3, 0);
            
            matrix.SetValue(1,0, 2*xy-(2*wz));
            matrix.SetValue(1,1, 1-(2*xx)-(2*zz));
            matrix.SetValue(1,2, 2*yz+(2*wx));
            matrix.SetValue(1,3, 0);
            
            matrix.SetValue(2,0, (2*xz)+(2*wy));
            matrix.SetValue(2,1, (2*yz)-(2*wx));
            matrix.SetValue(2,2, 1-(2*xx)-(2*yy));
            matrix.SetValue(2,3, 0);
            
            matrix.SetValue(3,0, 0);
            matrix.SetValue(3,1, 0);
            matrix.SetValue(3,2, 0);
            matrix.SetValue(3,3, 1);
            return matrix;
        }
        Quat operator*(const Quat& right)const noexcept{
            float w = m_W*right.m_W - m_X*right.m_X - m_Y*right.m_Y - m_Z*right.m_Z;
            float x = m_W*right.m_X + m_X*right.m_W + m_Y*right.m_Z - m_Z*right.m_Y;
            float y = m_W*right.m_Y - m_X*right.m_Z + m_Y*right.m_W + m_Z*right.m_X;
            float z = m_W*right.m_Z + m_X*right.m_Y - m_Y*right.m_X + m_Z*right.m_W;
            return Quat(w, x, y, z);
        }

        Quat& operator*=(const Quat& right)noexcept{
            *this = *this * right;
        }
    public:
        /// @brief Sets corresponding components to an assumed normalized list of data
        void SetValues(float w, float x, float y, float z)noexcept{
            m_W = w;
            m_X = x;
            m_Y = y;
            m_Z = z;
        }
        /// @brief Normlizes the quaternion
        void Normalize()noexcept{
            float length = static_cast<float>(sqrt(m_W * m_W + m_X * m_X + m_Y * m_Y + m_Z * m_Z));
            m_W /= length;
            m_X /= length;
            m_Y /= length;
            m_Z /= length;
        }
    public:
        float GetW() const noexcept{return m_W;}
        float GetX() const noexcept{return m_X;}
        float GetY() const noexcept{return m_Y;}
        float GetZ() const noexcept{return m_Z;}
    private:
        float m_W = 0;
        float m_X = 0;
        float m_Y = 0;
        float m_Z = 0;
    };
}