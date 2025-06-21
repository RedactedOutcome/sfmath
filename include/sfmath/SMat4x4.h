#pragma once

#include "Vec4.hpp"

namespace sfmath{
    class HMat4x4;
    /// @brief A mat4x4 where its data is stored inside the class
    class SMat4x4{
    public:
        /// Just a default constructor doesnt set identity
        SMat4x4()SFMATH_NOEXCEPT;
        /// Sets matrix data to a copy of a 16 byte 4x4 matrix
        SMat4x4(const float* data)SFMATH_NOEXCEPT;
        /// Sets matrix data to a copy of an SMat4x4
        SMat4x4(const SMat4x4& mat)SFMATH_NOEXCEPT;
        ~SMat4x4()SFMATH_NOEXCEPT;
        
        void Clear()SFMATH_NOEXCEPT;
        /// @brief Zeros out the entire matrix and sets to an identity matrix
        void SetIdentity() SFMATH_NOEXCEPT;
        
        void Copy(const SMat4x4& matrix)SFMATH_NOEXCEPT;
        void Copy(const HMat4x4& matrix)SFMATH_NOEXCEPT;
    public:
        SMat4x4 operator*(const SMat4x4& rhs) const SFMATH_NOEXCEPT;
        SMat4x4 operator*(const HMat4x4& rhs) const SFMATH_NOEXCEPT;
        SMat4x4 operator*(const float* rhs) const SFMATH_NOEXCEPT;
        SMat4x4& operator*=(const SMat4x4& rhs) SFMATH_NOEXCEPT;
        SMat4x4& operator*=(const HMat4x4& rhs) SFMATH_NOEXCEPT;
        SMat4x4& operator*=(const float* rhs) SFMATH_NOEXCEPT;
    public:
        /// @brief directly retrieves a matrix value depending on row and column. Doesnt do safety checks
        inline float GetValue(unsigned char row, unsigned char col) const SFMATH_NOEXCEPT{
            return m_Data[row * 4 + col];
        }
        /// @brief directly sets a matrix value depending on row and column. Doesnt do safety checks
        inline void SetValue(unsigned char row, unsigned char col, float value) SFMATH_NOEXCEPT{
            m_Data[row * 4 + col] = value;
        }
        /// @brief directly adds a matrix value depending on row and column. Doesnt do safety checks
        inline void AddValue(unsigned char row, unsigned char col, float value) SFMATH_NOEXCEPT{
            m_Data[row * 4 + col] += value;
        }
    public:
        Vec4<float> GetRow(int row)SFMATH_NOEXCEPT{
            return Vec4<float>(m_Data[row * 4] + 0, m_Data[row * 4] + 1,m_Data[row * 4] + 2, m_Data[row * 4] + 3);
        }
        Vec4<float> GetColumn(int column)SFMATH_NOEXCEPT{
            return Vec4<float>(m_Data[column * 4 + 0], m_Data[column * 4 + 1], m_Data[column * 4 + 2], m_Data[column * 4 + 3]);
        }
        constexpr float* GetData() const SFMATH_NOEXCEPT{return (float*)m_Data;}
    public:
        Vec4<float> operator [](int row) const SFMATH_NOEXCEPT{
            return Vec4<float>(GetValue(row, 0), GetValue(row, 1), GetValue(row, 2), GetValue(row, 3));
        }
    private:
        float m_Data[16];
    };
}