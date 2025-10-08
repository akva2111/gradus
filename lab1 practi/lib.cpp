#include "angle.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <cassert>

void Angle::normalize() {
    int totalMinutes = degrees * 60 + minutes;
    int minutesInFullCircle = 360 * 60;
    totalMinutes = totalMinutes % minutesInFullCircle;
    if (totalMinutes < 0) {
        totalMinutes += minutesInFullCircle;
    }
    degrees = totalMinutes / 60;
    minutes = totalMinutes % 60;
    if (degrees >= 360) {
        degrees = 0;
        minutes = 0;
    }
}

Angle::Angle() : degrees(0), minutes(0) {}

Angle::Angle(int deg, int min) : degrees(deg), minutes(min) {
    normalize();
    assert(degrees >= 0 && degrees < 360);
    assert(minutes >= 0 && minutes < 60);
}

void Angle::inputAngle() {
    std::cout << "Enter the degrees (integer): ";
    std::cin >> degrees;
    std::cout << "Enter the minut (integer): ";
    std::cin >> minutes;
    normalize();
    assert(degrees >= 0 && degrees < 360);
    assert(minutes >= 0 && minutes < 60);
}

std::string Angle::toString() const {
    std::stringstream ss;
    ss << degrees << "° " << minutes << "'";
    return ss.str();
}

int Angle::getDegrees() const { return degrees; }
void Angle::setDegrees(int deg) {
    degrees = deg;
    normalize();
}

void Angle::setMinutes(int min) {
    minutes = min;
    normalize();
}

int Angle::getMinutes() const { return minutes; }


double Angle::toRadians() const {
    double totalDegrees = static_cast<double>(degrees) + static_cast<double>(minutes) / 60.0;
    return (totalDegrees / 180.0) * M_PI;
}

double Angle::sin() const { return std::sin(toRadians()); }

double Angle::cos() const { return std::cos(toRadians()); }

bool Angle::operator==(const Angle& other) const {
    return degrees == other.degrees && minutes == other.minutes;
}

bool Angle::operator<(const Angle& other) const {
    if (degrees != other.degrees) return degrees < other.degrees;
    return minutes < other.minutes;
}

bool Angle::operator>(const Angle& other) const { return other < *this; }

bool Angle::operator<=(const Angle& other) const { return !(*this > other); }

bool Angle::operator>=(const Angle& other) const { return !(*this < other); }

Angle& Angle::operator+=(const Angle& other) {
    this->degrees += other.degrees;
    this->minutes += other.minutes;
    normalize();
    assert(degrees >= 0 && degrees < 360);
    assert(minutes >= 0 && minutes < 60);
    return *this;
}

Angle& Angle::operator-=(const Angle& other) {
    this->degrees -= other.degrees;
    this->minutes -= other.minutes;
    normalize();
    assert(degrees >= 0 && degrees < 360);
    assert(minutes >= 0 && minutes < 60);
    return *this;
}

Angle Angle::operator*(int n) const {
    if (n == 0) return Angle(0, 0);
    Angle result;
    result.degrees = this->degrees * n;
    result.minutes = this->minutes * n;
    result.normalize();
    assert(result.degrees >= 0 && result.degrees < 360);
    assert(result.minutes >= 0 && result.minutes < 60);
    return result;
}

Angle Angle::operator+(const Angle& other) const {
    Angle result;
    result.degrees = this->degrees + other.degrees;
    result.minutes = this->minutes + other.minutes;
    result.normalize();
    assert(result.degrees >= 0 && result.degrees < 360);
    assert(result.minutes >= 0 && result.minutes < 60);
    return result;
}

Angle Angle::operator-() const {
    if (degrees == 0 && minutes == 0) return Angle(0, 0);
    int totalMinutes = degrees * 60 + minutes;
    int minutesInFullCircle = 360 * 60;
    int negatedTotalMinutes = minutesInFullCircle - totalMinutes;
    Angle result;
    result.degrees = negatedTotalMinutes / 60;
    result.minutes = negatedTotalMinutes % 60;
    result.normalize();
    return result;
}

Angle Angle::operator*=(int n) const {
    if (n == 0) return Angle(0, 0);
    Angle result;
    result.degrees = n * this->degrees;
    result.minutes = n * this->minutes;
    result.normalize();
    assert(result.degrees >= 0 && result.degrees < 360);
    assert(result.minutes >= 0 && result.minutes < 60);
    return result;
}