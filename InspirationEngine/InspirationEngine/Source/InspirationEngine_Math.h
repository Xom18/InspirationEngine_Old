#pragma once

class IVec2
{
public:
	int x, y;

	IVec2(int _x = 0, int _y = 0){ x = _x; y = _y;}
	IVec2 operator +(IVec2 inV){ IVec2 t(0, 0); t.x = x + inV.x; t.y = y + inV.y;return t; }
	IVec2 operator -(IVec2 inV){ IVec2 t(0, 0); t.x = x - inV.x; t.y = y - inV.y;return t; }
	IVec2 operator *(IVec2 inV){ IVec2 t(0, 0); t.x = x * inV.x; t.y = y * inV.y;return t; }
	IVec2 operator /(IVec2 inV){ IVec2 t(0, 0); t.x = x / inV.x; t.y = y / inV.y;return t; }

	void operator +=(IVec2 inV){ x += inV.x; y += inV.y; }
	void operator -=(IVec2 inV){ x -= inV.x; y -= inV.y; }
	void operator *=(IVec2 inV){ x *= inV.x; y *= inV.y; }
	void operator /=(IVec2 inV){ x /= inV.x; y /= inV.y; }

	IVec2 operator +(int inV){ IVec2 t(0, 0); t.x = x + inV; t.y = y + inV; }
	IVec2 operator -(int inV){ IVec2 t(0, 0); t.x = x - inV; t.y = y - inV; }
	IVec2 operator *(int inV){ IVec2 t(0, 0); t.x = x * inV; t.y = y * inV; }
	IVec2 operator /(int inV){ IVec2 t(0, 0); t.x = x / inV; t.y = y / inV; }

	void operator +=(int inV){ x += inV; y += inV; }
	void operator -=(int inV){ x -= inV; y -= inV; }
	void operator *=(int inV){ x *= inV; y *= inV; }
	void operator /=(int inV){ x /= inV; y /= inV; }
};

class Vec2
{
	float x, y;

	Vec2(float _x = 0, float _y = 0){ x = _x; y = _y; }
	Vec2 operator +(Vec2 inV){ Vec2 t(0, 0); t.x = x + inV.x; t.y = y + inV.y; return t; }
	Vec2 operator -(Vec2 inV){ Vec2 t(0, 0); t.x = x - inV.x; t.y = y - inV.y; return t; }
	Vec2 operator *(Vec2 inV){ Vec2 t(0, 0); t.x = x * inV.x; t.y = y * inV.y; return t; }
	Vec2 operator /(Vec2 inV){ Vec2 t(0, 0); t.x = x / inV.x; t.y = y / inV.y; return t; }

	void operator +=(Vec2 inV){ x += inV.x; y += inV.y; }
	void operator -=(Vec2 inV){ x -= inV.x; y -= inV.y; }
	void operator *=(Vec2 inV){ x *= inV.x; y *= inV.y; }
	void operator /=(Vec2 inV){ x /= inV.x; y /= inV.y; }

	Vec2 operator +(float inV){ Vec2 t(0, 0); t.x = x + inV; t.y = y + inV; }
	Vec2 operator -(float inV){ Vec2 t(0, 0); t.x = x - inV; t.y = y - inV; }
	Vec2 operator *(float inV){ Vec2 t(0, 0); t.x = x * inV; t.y = y * inV; }
	Vec2 operator /(float inV){ Vec2 t(0, 0); t.x = x / inV; t.y = y / inV; }

	void operator +=(float inV){ x += inV; y += inV; }
	void operator -=(float inV){ x -= inV; y -= inV; }
	void operator *=(float inV){ x *= inV; y *= inV; }
	void operator /=(float inV){ x /= inV; y /= inV; }
};