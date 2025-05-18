#pragma once

#include "Vec2.hpp"
#include "Vec3.hpp"

namespace sfmath{
    class MatrixUtils{
    public:
        static float ToRadians(float degrees){return degrees * 0.0174533f;}

        static inline float GetMat4Data(float* dst, unsigned char r, unsigned char c) {return dst[c * 4 + r];}
        static inline void SetMat4Data(float* dst, unsigned char r, unsigned char c, float f){ dst[c * 4 + r] = f;}
        static inline void MultiplyMat4DataBy(float* dst, unsigned char r, unsigned char c, float f){dst[c * 4 + r] *= f;}
        static inline void AddMat4DataBy(float* dst, unsigned char r, unsigned char c, float f){ dst[c * 4 + r] += f;}

        //Any functions here marked noexcept will never crash unless you pass invalid data

        static void MultiplyMat4x4(float* dst, float* first, float* second);

        //Projection
        static void CreateOrthoProjection(float* dst, float pNear, float pFar, float left, float right, float top, float bottom);
        static void CreatePerspectiveProjection(float* dst, float fovInRadians, float aspectRatio, float pNear, float pFar);

        static void CreateScalingMatrix(float* dst, float x, float y, float z) noexcept;
        //Translation
        static void CreateTranslationMatrix(float* dst, float x, float y, float z) noexcept;
        template<typename TYPE>
        static void CreateTranslationMatrixXZ(float* dst, const Vec2<TYPE> vec2) noexcept{
            SetMat4Data(dst, 0, 3, static_cast<float>(vec2.m_X));
            SetMat4Data(dst, 2, 3, static_cast<float>(vec2.m_Y));
        }
        //Rotation
        static void RotateMat4x4(float* dst, float angle, Vec3<float> axis) noexcept;
        static void CreateRotationMatrixAxisX(float* dst, float angleInRadians)noexcept;
        static void CreateRotationMatrixAxisY(float* dst, float angleInRadians)noexcept;
        static void CreateRotationMatrixAxisZ(float* dst, float angleInRadians)noexcept;

        //Scaling
        static void ScaleMat4x4(float* dst, float x, float y, float z) noexcept;

    #pragma region Templates

        /// @brief 
        /// @tparam TYPE Specifies that the TYPE of vector3 is. So Vec3<TYPE> 
        /// @param dst the src and dst of the matrix we are translating
        /// @param vector the vector we are translating by
        template <typename TYPE>
        static void TranslateMat4x4(float* dst, const Vec3<TYPE>& vector) noexcept{
            Mat4x4 translationMatrix;
            CreateTranslationMatrix(translationMatrix.GetData(), vector.m_X, vector.m_Y, vector.m_Z);
            MultiplyMat4x4(dst, dst, translationMatrix.GetData());
        }
    #pragma endregion
    private:
    };
}