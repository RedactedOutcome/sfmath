#pragma once
#include "pch.h"

class HMat4x4{
public:
    HMat4x4()noexcept;
public:
    /// @brief returns the data the buffer is current using
    
    float* GetData() const noexcept{return m_Data;}
private:
    float* m_Data = nullptr
};