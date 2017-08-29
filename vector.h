#ifndef VECTOR_H
#define VECTOR_H

constexpr float defaultZ = 0.0f;
constexpr float defaultW = 1.0f;

class Vector2 {
protected:
    float x, y;
public:
    Vector2();
    Vector2(const Vector2&);
    Vector2(float, float);
    virtual ~Vector2();
    Vector2& operator=(const Vector2&);
    Vector2 operator+(const Vector2&) const;
    Vector2& operator+=(const Vector2&);
    Vector2 operator-(const Vector2&) const;
    Vector2& operator-=(const Vector2&);
    float operator*(const Vector2&) const;
    Vector2 operator*(float) const;
    Vector2& operator*=(float);
    Vector2 operator/(float) const;
    Vector2& operator/=(float);
    virtual float Size() const;
    float& X();
    float& Y();
    float X() const;
    float Y() const;
};

class Vector3 : public Vector2 {
protected:
    float z;
public:
    Vector3();
    Vector3(const Vector2&, float z = defaultZ);
    Vector3(const Vector3&);
    Vector3(float, float, float);
    virtual ~Vector3();
    Vector3& operator=(const Vector3&);
    Vector3 operator+(const Vector3&) const;
    Vector3& operator+=(const Vector3&);
    Vector3 operator-(const Vector3&) const;
    Vector3& operator-=(const Vector3&);
    float operator*(const Vector3&) const;
    Vector3 operator*(float) const;
    Vector3& operator*=(float);
    Vector3 operator/(float) const;
    Vector3& operator/=(float);
    Vector3 operator%(const Vector3&) const;
    Vector3& operator%=(const Vector3&);
    virtual float Size() const;
    float& Z();
    float Z() const;
};

class Vector4 : public Vector3 {
protected:
    float w;
public:
    Vector4();
    Vector4(const Vector3&, float w = defaultW);
    Vector4(const Vector4&);
    Vector4(float, float, float, float);
    virtual ~Vector4();
    Vector4& operator=(const Vector4&);
    Vector4 operator+(const Vector4&) const;
    Vector4& operator+=(const Vector4&);
    Vector4 operator-(const Vector4&) const;
    Vector4& operator-=(const Vector4&);
    float operator*(const Vector4&) const;
    Vector4 operator*(float) const;
    Vector4& operator*=(float);
    Vector4 operator%(const Vector4&) const;
    Vector4& operator%=(const Vector4&);
    Vector4 operator/(float) const;
    Vector4& operator/=(float);
    virtual float Size() const;
    float& W();
    float W() const;
};

#endif //VECTOR_H
