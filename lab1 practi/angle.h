#pragma once

#include <string>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Angle {
private:
    int degrees;
    int minutes;

    void normalize();

public:
    Angle();
    Angle(int deg, int min);

    void inputAngle();
    std::string toString() const;

    int getDegrees() const;
    void setDegrees(int deg);
    int getMinutes() const;
    void setMinutes(int min);

    double toRadians() const;
    double sin() const;
    double cos() const;

    bool operator==(const Angle& other) const;
    bool operator<(const Angle& other) const;
    bool operator>(const Angle& other) const;
    bool operator<=(const Angle& other) const;
    bool operator>=(const Angle& other) const;

    Angle& operator+=(const Angle& other);
    Angle& operator-=(const Angle& other);
    Angle operator*(int n) const;
    Angle operator+(const Angle& other) const;
    Angle operator-() const;
};
