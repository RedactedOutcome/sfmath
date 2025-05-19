#pragma once

namespace sfmath{
    class SMat4x4;
    class Quaternion{
    public:
        Quaternion() noexcept{}
        Quaternion(float x, float y, float z, float w) noexcept : m_X(x), m_Y(y), m_Z(z), m_W(w){}
        Quaternion(const Quaternion& quat) noexcept
            : m_X(quat.m_X), m_Y(quat.m_Y), m_Z(quat.m_Z), m_W(quat.m_W){}

        Quaternion GetConjugate() const noexcept{
            return Quaternion(-m_X, -m_Y, -m_Z, m_W);
        }

        Quaternion operator*(const Quaternion& right)const noexcept{
            float w = m_W*right.m_W - m_X*right.m_X - m_Y*right.m_Y - m_Z*right.m_Z;
            float x = m_W*right.m_X + m_X*right.m_W + m_Y*right.m_Z - m_Z*right.m_Y;
            float y = m_W*right.m_Y - m_X*right.m_Z + m_Y*right.m_W + m_Z*right.m_X;
            float z = m_W*right.m_Z + m_X*right.m_Y - m_Y*right.m_X + m_Z*right.m_W;
            return Quaternion(x, y, z, w);
        }
        
        SMat4x4 ToMatrix()const noexcept{
            SMat4x4 result;
            return result;
        }
    private:
        float m_X = 0;
        float m_Y = 0;
        float m_Z = 0;
        float m_W = 0;
    };
}