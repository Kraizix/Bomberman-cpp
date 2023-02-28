#pragma once
#include "Vector2.h"
class DirVector {
public:
	const Vec2f VectorZ = { 0.0f, -1.0f };
	const Vec2f VectorS = { 0.0f, 1.0f };
	const Vec2f VectorQ = { -1.0f, 0.0f };
	const Vec2f VectorD = { 1.0f, 0.0f };

	Vec2f GetVectorZ() {
		return VectorZ;
	};
	Vec2f GetVectorS() {
		return VectorS;
	}
	Vec2f GetVectorQ() {
		return VectorQ;
	}
	Vec2f GetVectorD() {
		return VectorD;
	}
};