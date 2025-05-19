#include "sfmath/pch.h"
#include "HMat4x4.h"

namespace sfmath{
    HMat4x4::HMat4x4() SFMATH_NOEXCEPT{}
    HMat4x4::HMat4x4(float* data, bool canFree)SFMATH_NOEXCEPT : m_Data(data), m_CanFree(canFree){}
    HMat4x4::~HMat4x4()SFMATH_NOEXCEPT{
        Free();
    }
    HMat4x4::HMat4x4(const HMat4x4& matrix)SFMATH_NOEXCEPT : m_Data(matrix.m_Data), m_CanFree(false){}
    HMat4x4::HMat4x4(HMat4x4&& matrix)SFMATH_NOEXCEPT : m_Data(matrix.m_Data), m_CanFree(matrix.m_CanFree){
        matrix.m_Data = nullptr;
        matrix.m_CanFree = false;
    }

    void HMat4x4::Free()SFMATH_NOEXCEPT{
        if(!m_CanFree)return;
        m_CanFree = false;
        delete m_Data;
        m_Data = nullptr;
    }

    void HMat4x4::Release()SFMATH_NOEXCEPT{
        m_Data = nullptr;
        m_CanFree = false;
    }
    void HMat4x4::AllocateNew()SFMATH_NOEXCEPT{
        Free();
        m_Data = new float[16];
        m_CanFree = true;
    }
    
    float HMat4x4::GetValue(int row, int col) const SFMATH_NOEXCEPT{
        if(!m_Data)return 0.0f;
        return m_Data[row * 4 + col];
    }

    void HMat4x4::SetValue(int row, int col, float value) SFMATH_NOEXCEPT{
        if(!m_Data){
            m_Data = new float[16];
            m_CanFree = true;
        }

        m_Data[row * 4 + col] = value;
    }

    void HMat4x4::AddValue(int row, int col, float value) SFMATH_NOEXCEPT{
        if(!m_Data){
            m_Data = new float[16];
            m_CanFree = true;
        }

        m_Data[row * 4 + col] += value;
    }


    HMat4x4 HMat4x4::operator*(const HMat4x4& right)SFMATH_NOEXCEPT{
        if(!right.m_Data)return right;
        HMat4x4 result;
        result.m_Data = new float[16];

        for(uint8_t row = 0; row < 4; row++){
            for(uint8_t col = 0; col < 4; col++){
                int id = row * 4 + col;
                for(uint8_t k = 0; k < 4; k++){
                    result.m_Data[id] += GetValue(row, k) * right.GetValue(k, row);
                }
            }
        }

        return result;
    }

    HMat4x4& HMat4x4::operator*=(const HMat4x4& right)SFMATH_NOEXCEPT{
        if(!right.m_Data){
            memset(m_Data, 0, sizeof(float) * 16);
            return *this;
        }
        float original[16];
        memcpy(original, m_Data, sizeof(float) * 16);

        for(uint8_t row = 0; row < 4; row++){
            for(uint8_t col = 0; col < 4; col++){
                int rowIndex = row * 4;
                int id = rowIndex + col;
                for(uint8_t k = 0; k < 4; k++){
                    m_Data[id] += original[rowIndex + k] * right.GetValue(k, row);
                }
            }
        }

        return *this;
    }
    void HMat4x4::SetData(float* data, bool canFree)SFMATH_NOEXCEPT{
        m_Data = data;
        m_CanFree = canFree;
    }
}