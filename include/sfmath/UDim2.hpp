#pragma once
#include "Core.h"
namespace sfmath{
    template<typename ScaleType, typename OffsetType>
    class UDim2{
    public:
        UDim2()SFMATH_NOEXCEPT:
            m_ScaleX(static_cast<ScaleType>(1)),
            m_ScaleY(static_cast<ScaleType>(1)),
            m_OffsetX(static_cast<OffsetType>(0)),
            m_OffsetY(static_cast<OffsetType>(0)){
        }
        UDim2(ScaleType scaleX, ScaleType scaleY, OffsetType offsetX, OffsetType offsetY)SFMATH_NOEXCEPT:
            m_ScaleX(static_cast<ScaleType>(scaleX)),
            m_ScaleY(static_cast<ScaleType>(scaleY)),
            m_OffsetX(static_cast<OffsetType>(offsetX)),
            m_OffsetY(static_cast<OffsetType>(offsetY)){
        }

        ScaleType m_ScaleX;
        ScaleType m_ScaleY;
        OffsetType m_OffsetX;
        OffsetType m_OffsetY;
    };
    }