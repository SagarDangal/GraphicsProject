#include "vec3.h"

namespace sparky {namespace maths {
	
	vec3::vec3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float& x, const float& y, const float& z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::add(const vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	vec3& vec3::subtract(const vec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	vec3& vec3::multiply(const vec3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	vec3& vec3::divide(const vec3& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	vec3& vec3::operator+=(const vec3& other) {
		return add(other);
	}

	vec3& vec3::operator-=(const vec3& other) {
		return subtract(other);
	}

	vec3& vec3::operator*=(const vec3& other) {
		return multiply(other);
	}

	vec3 vec3::translate(const vec3& other) {
		return add(other);
	}
	vec3 vec3::rotate(const vec3& other, float angle) {
		float a = sin(angle);
		float b = cos(angle);
		float c = 1.0f - b;

		
		return vec3((x*b - y * a + other.x*c + other.y*a),
			(x*a+y*b+other.y*c-other.x*a),
			0);

	}

	vec3& vec3::operator/=(const vec3& other) {
		return divide(other);
	}

	bool vec3::operator==(const vec3& other) {
		return x == other.x && y == other.y && z==other.z;
	}

	bool vec3::operator!=(const vec3& other) {
		return x != other.x || y != other.y || z!=other.z;
	}

	vec3 operator+(vec3 left,vec3& right) {
		return left.add(right);
	}

	vec3 operator-(vec3 left, vec3& right) {
		return left.subtract(right);
	}

	vec3 operator*(vec3 left, vec3& right) {
		return left.multiply(right);
	}

	vec3 operator/(vec3 left, vec3& right) {
		return left.divide(right);
	}

	std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
		stream << "vec3:(" << vector.x << " , " << vector.y <<" , "<< vector.z <<")";
		return stream;
	}

} }