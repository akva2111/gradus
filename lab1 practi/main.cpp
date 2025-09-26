#include <iostream> 
#include <iomanip>
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
};