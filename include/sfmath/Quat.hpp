#pragma once

namespace sfmath{
    class SMat4x4;
    class Quat{
    public:
        Quat() noexcept{}
        Quat(float x, float y, float z, float w) noexcept : m_X(x), m_Y(y), m_Z(z), m_W(w){}
        Quat(const Quat& quat) noexcept
            : m_X(quat.m_X), m_Y(quat.m_Y), m_Z(quat.m_Z), m_W(quat.m_W){}

        Quat GetConjugate() const noexcept{
            return Quat(-m_X, -m_Y, -m_Z, m_W);
        }


        /// @brief Returns a rotation matrix that represents the quaternion
        SMat4x4 ToSMat4x4Matrix()const noexcept{
            SMat4x4 result;
            return result;
        }
    public:
        Quat operator*(const Quat& right)const noexcept{
            float w = m_W*right.m_W - m_X*right.m_X - m_Y*right.m_Y - m_Z*right.m_Z;
            float x = m_W*right.m_X + m_X*right.m_W + m_Y*right.m_Z - m_Z*right.m_Y;
            float y = m_W*right.m_Y - m_X*right.m_Z + m_Y*right.m_W + m_Z*right.m_X;
            float z = m_W*right.m_Z + m_X*right.m_Y - m_Y*right.m_X + m_Z*right.m_W;
            return Quat(x, y, z, w);
        }

        Quat& operator*=(const Quat& right)noexcept{
            m_W = right.m_W;
            m_X = right.m_X;
            m_Y = right.m_Y;
            m_Z = right.m_Z;
        }
    public:
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