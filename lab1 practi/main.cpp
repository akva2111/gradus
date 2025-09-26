#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
class Angle {
private:
    int degrees; 
    int minutes; // 0-59

    
    void normalize() {
        // all to minut
        int totalMinutes = degrees * 60 + minutes;

        // podrobno [-360*60, 360*60)
        int minutesInFullCircle = 360 * 60;
        totalMinutes = totalMinutes % minutesInFullCircle;

        // - come to+
        if (totalMinutes < 0) {
            totalMinutes += minutesInFullCircle;
        }

        // all gradus
        degrees = totalMinutes / 60;
        minutes = totalMinutes % 60;

        // 360
        if (degrees >= 360) {
            degrees = 0;
            minutes = 0;
        }
    }
};