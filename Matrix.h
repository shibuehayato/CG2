#pragma once
#define _USE_MATH_DEFIENS
#include <cmath>
#include <assert.h>

struct Matrix4x4
{
	float m[4][4];
};

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Transform
{
	Vector3 scale;
	Vector3 rotate;
	Vector3 translate;
};

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 MakeScaleMatrix(const Vector3& scale);

Matrix4x4 MakeIdentity4x4();

Matrix4x4 MakeRotateXMatrix(float radian);

Matrix4x4 MakeRotateYMatrix(float radian);

Matrix4x4 MakeRotateZMatrix(float radian);

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotation, const Vector3 translate);

Matrix4x4 Inverse(const Matrix4x4& m);

Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);