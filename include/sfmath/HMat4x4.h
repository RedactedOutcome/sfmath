#pragma once
#include "Core.h"

namespace sfmath{
    class SMat4x4;
    /// @brief A column major 4x4 matrix
    class HMat4x4{
    public:
        HMat4x4()SFMATH_NOEXCEPT;
        HMat4x4(float* data, bool canFree)SFMATH_NOEXCEPT;
        ~HMat4x4()SFMATH_NOEXCEPT;

        HMat4x4(const HMat4x4& matrix)SFMATH_NOEXCEPT;
        HMat4x4(HMat4x4&& matrix)SFMATH_NOEXCEPT;

        /// @brief Attempts to free and reset m_Data if m_CanFree
        void Free()SFMATH_NOEXCEPT;
        /// @brief Releases m_Data and m_CanFree without deallocating
        void Release()SFMATH_NOEXCEPT;

        /// @brief frees data if possible and allocates a new float[16] for matrix data
        void AllocateNew()SFMATH_NOEXCEPT;

        HMat4x4 operator*(const HMat4x4& right)SFMATH_NOEXCEPT;
        HMat4x4& operator*=(const HMat4x4& right)SFMATH_NOEXCEPT;
    public:
        void SetData(float* data, bool canFree)SFMATH_NOEXCEPT;
        /// @brief returns a value inside the matrix if has data if not then 0
        float GetValue(int row, int col) const SFMATH_NOEXCEPT;
        void SetValue(int row, int col, float value) SFMATH_NOEXCEPT;
        void AddValue(int row, int col, float value) SFMATH_NOEXCEPT;
    public:
        /// @brief returns the data the buffer is current using
        float* GetData() const SFMATH_NOEXCEPT{return m_Data;}
        /// @brief returns if the heap matrix has ownership
        bool CanFree() const SFMATH_NOEXCEPT{return m_CanFree;}
    private:
        float* m_Data = nullptr;
        bool m_CanFree = false;
    };
}