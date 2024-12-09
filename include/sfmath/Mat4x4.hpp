#pragma once

#include "Vec4.hpp"

namespace sfmath{
    class Mat4x4{
    public:
        Mat4x4()SFMATH_NOEXCEPT{
            SetIdentity();
        }
        Mat4x4(float* data)SFMATH_NOEXCEPT{
            for(unsigned char i = 0; i < 16; i++){
                m_Data[i] = data[i];
            }
        }
        Mat4x4(Mat4x4& mat)SFMATH_NOEXCEPT{
            memcpy(m_Data, mat.m_Data, sizeof(float) * 16);
        }
        ~Mat4x4(){}

        void SetIdentity() SFMATH_NOEXCEPT{
            memset(&m_Data, 0, sizeof(m_Data));
            SetValue(0,0, 1.0f);
            SetValue(1,1, 1.0f);
            SetValue(2,2, 1.0f);
            SetValue(3,3, 1.0f);
        }

        inline float GetValue(unsigned char row, unsigned char col) const SFMATH_NOEXCEPT{
            return m_Data[col * 4 + row];
        }
        inline void SetValue(unsigned char row, unsigned char col, float value) SFMATH_NOEXCEPT{
            if(row < 0 || row > 3 || col < 0 || col > 3)return;

            m_Data[col * 4 + row] = value;
        }

        Mat4x4 operator*(const Mat4x4& rhs) const SFMATH_NOEXCEPT{             
            Mat4x4 mat;
            float* first = (float*)&m_Data;
            float* second = rhs.GetData();
            float* data = mat.GetData();
            for (unsigned char row = 0; row < 4; ++row) {
                for (unsigned char col = 0; col < 4; ++col) {
                    for (unsigned char k = 0; k < 4; ++k) {
                        data[col * 4 + row] += first[k * 4 + row] * second[col * 4 + k];
                    }
                }
            }
            return mat; // return the result by reference
        }
        Vec4<float> GetRow(int row)SFMATH_NOEXCEPT{
            Vec4<float> r(m_Data[row * 4] + 0, m_Data[row * 4] + 1,m_Data[row * 4] + 2,m_Data[row * 4] + 3);
            return r;
        }
        constexpr float* GetData() const SFMATH_NOEXCEPT{return (float*)m_Data;}
    public:
        Vec4<float> operator [](int row) const SFMATH_NOEXCEPT{
            return Vec4(GetValue(0, row),GetValue(1, row),GetValue(2, row),GetValue(3, row));
        }
    private:
        float m_Data[16];
    };
}