#include "vector.h"
#include <cmath>

Vector2::Vector2() : x(0.0f), y(0.0f) {}

Vector2::Vector2(const Vector2& other) : x(other.x), y(other.y) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::~Vector2() {}

Vector2& Vector2::operator=(const Vector2& other) {
    x = other.x;
    y = other.y;
    return *this;
}

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(*this).operator+=(other);
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(*this).operator-=(other);
}

Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

float Vector2::operator*(const Vector2& other) const {
    return x * other.x + y * other.y;
}

Vector2 Vector2::operator*(float value) const {
    return Vector2(*this).operator*=(value);
}

Vector2& Vector2::operator*=(float value) {
    x *= value;
    y *= value;
    return *this;
}

Vector2 Vector2::operator/(float value) const {
    return Vector2(*this).operator/=(value);
}

Vector2& Vector2::operator/=(float value) {
    x /= value;
    y /= value;
    return *this;
}

float Vector2::Size() const {
    return sqrt(this->operator*(*this));
}

float& Vector2::X() {
    return x;
}

float& Vector2::Y() {
    return y;
}

float Vector2::X() const {
    return x;
}

float Vector2::Y() const {
    return y;
}

Vector3::Vector3() : Vector2(), z(defaultZ) {}

Vector3::Vector3(const Vector2& other, float z) : Vector2(other), z(z) {}

Vector3::Vector3(const Vector3& other) : Vector2(other.x, other.y),
                                         z(other.z)
                                         {}

Vector3::Vector3(float x, float y, float z) : Vector2(x, y), z(z) {}

Vector3::~Vector3() {}

Vector3& Vector3::operator=(const Vector3& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(*this).operator+=(other);
}

Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(*this).operator-=(other);
}

Vector3& Vector3::operator-=(const Vector3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

float Vector3::operator*(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::operator*(float value) const {
    return Vector3(*this).operator*=(value);
}

Vector3& Vector3::operator*=(float value) {
    x *= value;
    y *= value;
    z *= value;
    return *this;
}

Vector3 Vector3::operator/(float value) const {
    return Vector3(*this).operator/=(value);
}

Vector3& Vector3::operator/=(float value) {
    x /= value;
    y /= value;
    z /= value;
    return *this;
}

Vector3 Vector3::operator%(const Vector3& other) const {
    return Vector3(*this).operator%=(other);
}

Vector3& Vector3::operator%=(const Vector3& other) {
    x = y * other.z - z * other.y;
    y = z * other.x - x * other.z;
    z = x * other.y - y * other.x;
    return *this;
}

float Vector3::Size() const {
    return sqrt(this->operator*(*this));
}

float& Vector3::Z() {
    return z;
}

float Vector3::Z() const {
    return z;
}

Vector4::Vector4() : Vector3(), w(defaultW) {}

Vector4::Vector4(const Vector3& other, float w) : Vector3(other), w(w) {}

Vector4::Vector4(const Vector4& other) : Vector3(other.x, other.y, other.z),
                                         w(other.w)
                                         {}

Vector4::Vector4(float x, float y, float z, float w) : Vector3(x, y, z), w(w) {}

Vector4::~Vector4() {}

Vector4& Vector4::operator=(const Vector4& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
    return *this;
}

Vector4 Vector4::operator+(const Vector4& other) const {
    return Vector4(*this).operator+=(other);
}

Vector4& Vector4::operator+=(const Vector4& other) {
    float factor = w / other.w;
    x += other.x * factor;
    y += other.y * factor;
    z += other.z * factor;
    return *this;
}

Vector4 Vector4::operator-(const Vector4& other) const {
    return Vector4(*this).operator-=(other);
}

Vector4& Vector4::operator-=(const Vector4& other) {
    float factor = w / other.w;
    x -= other.x * factor;
    y -= other.y * factor;
    z -= other.z * factor;
    return *this;
}

float Vector4::operator*(const Vector4& other) const {
    return (Vector3(x,y,z) / w) * (Vector3(other.x, other.y, other.z) / other.w);
}

Vector4 Vector4::operator*(float value) const {
    return Vector4(*this).operator*=(value);
}

Vector4& Vector4::operator*=(float value) {
    x *= value;
    y *= value;
    z *= value;
    return *this;
}

Vector4 Vector4::operator/(float value) const {
    return Vector4(*this).operator/=(value);
}

Vector4& Vector4::operator/=(float value) {
    x /= value;
    y /= value;
    z /= value;
    return *this;
}

Vector4 Vector4::operator%(const Vector4& other) const {
    return Vector4(*this).operator%=(other);
}

Vector4& Vector4::operator%=(const Vector4& other) {
    this->operator=(Vector4((Vector3(x,y,z) / w) %
                            (Vector3(other.x, other.y, other.z) / other.w),
                            defaultW));
    return *this;
}

float Vector4::Size() const {
    return sqrt(this->operator*(*this));
}

float& Vector4::W() {
    return w;
}

float Vector4::W() const {
    return w;
}
