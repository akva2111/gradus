#include <iostream> 
#include <iomanip>
#include <cmath> 
#include <cassert>
#include <sstream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
class Angle {
private:
    int degrees;
    int minutes;


    void normalize() {
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
public:
    // --- 1)
    Angle() : degrees(0), minutes(0) {}

    Angle(int deg, int min) : degrees(deg), minutes(min) {
        normalize();
        assert(degrees >= 0 && degrees < 360);
        assert(minutes >= 0 && minutes < 60);
    }
    //2)
    void inputAngle() {
        std::cout << "Enter the degrees (integer): ";
        std::cin >> degrees;
        std::cout << "Enter the minut (integer): ";
        std::cin >> minutes;
        normalize();
        assert(degrees >= 0 && degrees < 360);
        assert(minutes >= 0 && minutes < 60);
    }
    std::string toString() const {
        std::stringstream ss;
        ss << degrees << "° " << minutes << "'";
        return ss.str();
    }
    //3)
    int getDegrees() const { return degrees; }
    int getMinutes() const { return minutes; }

    //4) 
    double toRadians() const {
        double totalDegrees = static_cast<double>(degrees) + static_cast<double>(minutes) / 60.0;
        return (totalDegrees / 180.0) * M_PI;
    }
    //  5)  sin 
    double sin() const { return std::sin(toRadians()); }

    //  6)  cos 
    double cos() const { return std::cos(toRadians()); }

    //  7) Checking the equality of two corners 
    bool operator==(const Angle& other) const {
        return degrees == other.degrees && minutes == other.minutes;
    }

    //  8) Angle Comparison 
    bool operator<(const Angle& other) const {
        if (degrees != other.degrees) return degrees < other.degrees;
        return minutes < other.minutes;
    }
    bool operator>(const Angle& other) const { return other < *this; }
    bool operator<=(const Angle& other) const { return !(*this > other); }
    bool operator>=(const Angle& other) const { return !(*this < other); }
    // 9) Increasing the angle by a preset amount
    Angle& operator+=(const Angle& other) {
        this->degrees += other.degrees;
        this->minutes += other.minutes;
        normalize();
        assert(degrees >= 0 && degrees < 360);
        assert(minutes >= 0 && minutes < 60);
        return *this;
    }

    // 10) Reducing the angle by a preset amount
    Angle& operator-=(const Angle& other) {
        this->degrees -= other.degrees;
        this->minutes -= other.minutes;
        normalize();
        assert(degrees >= 0 && degrees < 360);
        assert(minutes >= 0 && minutes < 60);
        return *this;
    }

    // 11) Multiplying the angle by the number n
    Angle operator*(int n) const {
        if (n == 0) return Angle(0, 0);
        Angle result;
        result.degrees = this->degrees * n;
        result.minutes = this->minutes * n;
        result.normalize();
        assert(result.degrees >= 0 && result.degrees < 360);
        assert(result.minutes >= 0 && result.minutes < 60);
        return result;
    }

    //12) summ 
    Angle operator+(const Angle& other) const {
        Angle result;
        result.degrees = this->degrees + other.degrees;
        result.minutes = this->minutes + other.minutes;
        result.normalize();
        assert(result.degrees >= 0 && result.degrees < 360);
        assert(result.minutes >= 0 && result.minutes < 60);
        return result;
    }

    // --- Дополнительные операторы ---
    Angle operator-() const {
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
};

Angle operator*(int n, const Angle& angle) {
    return angle * n;
}

int getIntegerInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.good()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void inputAngleSafely(Angle& angleToSet, const std::string& prompt) {
    std::cout << prompt << std::endl;
    angleToSet.inputAngle();
}

void displayCurrentAngle(const Angle& angle) {
    std::cout << "\nТекущий угол: " << angle.toString() << std::endl;
}