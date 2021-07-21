/******************************************************************
** vec3.h
** @Author       : BanMing
** @Date         : 7/21/2021, 9:29:19 PM
** @Description  :
*******************************************************************/

#ifndef Vec3_H
#define Vec3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3
{
private:
	/* data */
public:
	float x, y, z;

public:
	vec3() : x(0), y(0), z(0) {}
	vec3(float x) : x(x), y(0), z(0) {}
	vec3(float x, float y) : x(x), y(y), z(0) {}
	vec3(float x, float y, float z) : x(x), y(y), z(z) {}

	vec3 operator-() const { return vec3(-x, -y, -z); }

	vec3 &operator+=(const vec3 &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	vec3 &operator*=(const float t)
	{
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}

	vec3 &operator/=(const float t)
	{
		return *this *= 1 / t;
	}

	float length() const
	{
		return sqrt(length_squared());
	}

	float length_squared() const
	{
		return x * x + y * y + z * z;
	}
};

// Type aliases for vec3
using point3 = vec3; // 3D position
using color = vec3;	 // RGB color

// vec3 Utility Functions
inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
	return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
	return vec3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
	return vec3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
	return vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline vec3 operator*(const vec3 &u, float t)
{
	return vec3(u.x * t, u.y * t, u.z * t);
}

inline vec3 operator*(float t, const vec3 &u)
{
	return vec3(u.x * t, u.y * t, u.z * t);
}

inline vec3 operator/(const vec3 &u, float t)
{
	return (1 / t) * u;
}

inline float dot(const vec3 &u, const vec3 &v)
{
	return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
	return vec3(u.y * v.z - u.z * v.y,
				u.z * v.x - u.x * v.z,
				u.x * v.y - u.y * u.x);
}

inline vec3 unit_vector(vec3 v)
{
	return v / v.length();
}

inline vec3 lerp(const vec3 &u, const vec3 &v, const float &t)
{
	return u * (1 - t) + v * t;
}

#endif