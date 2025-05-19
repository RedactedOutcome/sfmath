#include "sfmath/pch.h"
#include "SMat4x4.h"
#include "HMat4x4.h"

namespace sfmath{
    SMat4x4::SMat4x4()SFMATH_NOEXCEPT{}
    SMat4x4::SMat4x4(const float* data)SFMATH_NOEXCEPT{
        for(unsigned char i = 0; i < 16; i++)
            m_Data[i] = data[i];
    }
    SMat4x4::SMat4x4(const SMat4x4& mat)SFMATH_NOEXCEPT{
        memcpy(m_Data, mat.m_Data, sizeof(float) * 16);
    }
    SMat4x4::~SMat4x4()SFMATH_NOEXCEPT{}

    void SMat4x4::Clear()SFMATH_NOEXCEPT{
        memset(&m_Data, 0, sizeof(m_Data));
    }
    void SMat4x4::SetIdentity()SFMATH_NOEXCEPT{
        memset(&m_Data, 0, sizeof(m_Data));
        SetValue(0,0, 1.0f);
        SetValue(1,1, 1.0f);
        SetValue(2,2, 1.0f);
        SetValue(3,3, 1.0f);
    }

    void SMat4x4::Copy(const SMat4x4& matrix)SFMATH_NOEXCEPT{
        float* src = matrix.GetData();
        for(uint8_t i = 0; i < 16; i++)
            m_Data[i] = src[i];
    }
    void SMat4x4::Copy(const HMat4x4& matrix)SFMATH_NOEXCEPT{
        float* src = matrix.GetData();
        if(src == nullptr){
            memset(m_Data, 0, sizeof(m_Data));
            return;
        }

        for(uint8_t i = 0; i < 16; i++)
            m_Data[i] = src[i];
    }

    SMat4x4 SMat4x4::operator*(const SMat4x4& rhs) const SFMATH_NOEXCEPT{
        SMat4x4 result;
        for(uint8_t row = 0; row < 4; row++){
            for(uint8_t col = 0; col < 4; col++){
                int offset = row * 4 + col;
                for(uint8_t k = 0; k < 4; k++){
                    result.m_Data[offset] += GetValue(row, k) * rhs.GetValue(k, col);
                }
            }
        }
        return result;
    }
    SMat4x4 SMat4x4::operator*(const HMat4x4& rhs) const SFMATH_NOEXCEPT{
        if(!rhs.GetData())return *this;
        SMat4x4 result;
        for(uint8_t row = 0; row < 4; row++){
            for(uint8_t col = 0; col < 4; col++){
                int offset = row * 4 + col;
                for(uint8_t k = 0; k < 4; k++){
                    result.m_Data[offset] += GetValue(row, k) * rhs.GetValue(k, col);
                }
            }
        }
        return result;
    }
    SMat4x4 SMat4x4::operator*(const float* rhs) const SFMATH_NOEXCEPT{
        if(!rhs){
            SMat4x4 result;
            result.Clear();
            return result;
        }
        SMat4x4 result;
        for(uint8_t row = 0; row < 4; row++){
            for(uint8_t col = 0; col < 4; col++){
                int offset = row * 4 + col;
                for(uint8_t k = 0; k < 4; k++){
                    result.m_Data[offset] += GetValue(row, k) * rhs[k * 4 + col];
                }
            }
        }
        return result;
    }
    SMat4x4& SMat4x4::operator*=(const SMat4x4& rhs) SFMATH_NOEXCEPT{
        SMat4x4 copy(*this);

        for(uint8_t row = 0; row < 4; row++){
            for(uint8_t col = 0; col < 4; col++){
                int offset = row * 4 + col;
                for(uint8_t k = 0; k < 4; k++){
                    m_Data[offset] += copy.GetValue(row, k) * rhs.GetValue(k, col);
                }
            }
        }
        return *this;
    }
    SMat4x4& SMat4x4::operator*=(const HMat4x4& rhs) SFMATH_NOEXCEPT{
        if(rhs.GetData() == nullptr){
            memset(m_Data, 0, sizeof(m_Data));
            return *this;
        }

        SMat4x4 copy(*this);

        for(uint8_t row = 0; row < 4; row++){
            for(uint8_t col = 0; col < 4; col++){
                int offset = row * 4 + col;
                for(uint8_t k = 0; k < 4; k++){
                    m_Data[offset] += copy.GetValue(row, k) * rhs.GetValue(k, col);
                }
            }
        }
        return *this;
    }
    SMat4x4& SMat4x4::operator*=(const float* rhs) SFMATH_NOEXCEPT{
        if(rhs == nullptr){
            memset(m_Data, 0, sizeof(m_Data));
            return *this;
        }

        SMat4x4 copy(*this);

        for(uint8_t row = 0; row < 4; row++){
            for(uint8_t col = 0; col < 4; col++){
                int offset = row * 4 + col;
                for(uint8_t k = 0; k < 4; k++){
                    m_Data[offset] += copy.GetValue(row, k) * rhs[k * 4 + col];
                }
            }
        }
        return *this;
    }
}