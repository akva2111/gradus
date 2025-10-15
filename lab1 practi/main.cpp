#include <iostream>
#include "angle.h"
#include <limits>

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
            std::cout << "error. input integer number " << std::endl;
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
        std::cout << "1. input new angle" << std::endl;
        std::cout << "2. output now degrees" << std::endl;
        std::cout << "3. take sin degrees" << std::endl;
        std::cout << "4. take cos degrees" << std::endl;
        std::cout << "5. permutet to radian" << std::endl;
        std::cout << "6. Compare the current angle with another one (>, <, ==)" << std::endl;
        std::cout << "7. Zoom in on another angle (+=)" << std::endl;
        std::cout << "8. Zoom out to a different angle (-=)" << std::endl;
        std::cout << "9. Multiply by a number (*)" << std::endl;
        std::cout << "10. Fold with a different angle (+)" << std::endl;
        std::cout << "11. input new minut" << std::endl;
        std::cout << "12. input new degrees" << std::endl;
        std::cout << "0. end calculator" << std::endl;
        std::cout << "---------------------" << std::endl;

        int choice = getIntegerInput("choos operaciy (input number from 0 to 10): ");
        Angle otherAngle;
        int multiplier;
        int number;
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
                std::cout << currentAngle.toString() << " equal " << otherAngle.toString() << std::endl;
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
        case 11:
            std::cout << "input new minute" << std::endl;
            std::cin >> number;
            currentAngle.setMinutes(number);
            break;
        case 12:
            std::cout << "input new degree" << std::endl;
            std::cin >> number;
            currentAngle.setDegrees(number);
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