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
            std::cout << "eror. input integer number " << std::endl;
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
    std::cout << "\nnow degrees: " << angle.toString() << std::endl;
}
int main() {
    std::cout << "calculator degrees" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    Angle currentAngle;
    inputAngleSafely(currentAngle, "input start degrees:");
    displayCurrentAngle(currentAngle);

    bool keepGoing = true;
    while (keepGoing) {
        std::cout << "\n--- menu ---" << std::endl;
        std::cout << "operac:" << std::endl;
        std::cout << "1. input new degrees" << std::endl;
        std::cout << "2. out put now degrees" << std::endl;
        std::cout << "3. take sin degrees" << std::endl;
        std::cout << "4. take cos degrees" << std::endl;
        std::cout << "5. permutet to radian" << std::endl;
        std::cout << "6. Compare the current angle with another one (>, <, ==)" << std::endl;
        std::cout << "7. Zoom in on another angle (+=)" << std::endl;
        std::cout << "8. Zoom out to a different angle (-=)" << std::endl;
        std::cout << "9. Multiply by a number (*)" << std::endl;
        std::cout << "10. Fold with a different angle (+)" << std::endl;
        std::cout << "0. end calculator" << std::endl;
        std::cout << "---------------------" << std::endl;

        int choice = getIntegerInput("choos operaciy (input number from 0 to 10): ");

        Angle otherAngle;
        int multiplier;

        switch (choice) {
        case 1:
            inputAngleSafely(currentAngle, "\n--- input new degrees ---");
            displayCurrentAngle(currentAngle);
            break;

        case 2:
            displayCurrentAngle(currentAngle);
            break;

        case 3:
            std::cout << "\n--- sin() ---" << std::endl;
            std::cout << "sin(" << currentAngle.toString() << ") = " << currentAngle.sin() << std::endl;
            break;

        case 4:
            std::cout << "\n--- cos() ---" << std::endl;
            std::cout << "cos(" << currentAngle.toString() << ") = " << currentAngle.cos() << std::endl;
            break;

        case 5:
            std::cout << "\n--- toRadians() ---" << std::endl;
            std::cout << currentAngle.toString() << " in radian = " << currentAngle.toRadians() << std::endl;
            break;

        case 6:
            std::cout << "\n--- Comparing the current angle with another one ---" << std::endl;
            inputAngleSafely(otherAngle, "input angle for comparison:");

            if (currentAngle == otherAngle) {
                std::cout << currentAngle.toString() << " equal" << otherAngle.toString() << std::endl;
            }
            else if (currentAngle < otherAngle) {
                std::cout << currentAngle.toString() << " less than " << otherAngle.toString() << std::endl;
            }
            else {
                std::cout << currentAngle.toString() << " more than " << otherAngle.toString() << std::endl;
            }
            break;

        case 7:
            std::cout << "\n--- operator += ---" << std::endl;
            inputAngleSafely(otherAngle, "input degrees, which needs to be added:");
            currentAngle += otherAngle;
            displayCurrentAngle(currentAngle);
            break;

        case 8:
            std::cout << "\n--- operator -= ---" << std::endl;
            inputAngleSafely(otherAngle, "input degrees, which one needs to be subtracted:");
            currentAngle -= otherAngle;
            displayCurrentAngle(currentAngle);
            break;

        case 9:
            std::cout << "\n--- Multiply by a number ---" << std::endl;
            multiplier = getIntegerInput("Enter the number to multiply: ");
            currentAngle = currentAngle * multiplier;
            displayCurrentAngle(currentAngle);
            break;

        case 10:
            std::cout << "\n--- The + operator (addition of two angles) ---" << std::endl;
            inputAngleSafely(otherAngle, "Enter the second corner for addition:");
            currentAngle = currentAngle + otherAngle;
            displayCurrentAngle(currentAngle);
            break;

        case 0:
            keepGoing = false;
            std::cout << "\n--- Program termination. Goodbye! ---" << std::endl;
            break;

        default:
            std::cout << "\nIncorrect operation selection. Please select a number between 0 and 10." << std::endl;
            break;
        }
    }

    return 0;
}