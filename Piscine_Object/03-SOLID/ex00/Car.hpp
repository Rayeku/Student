#include <iostream>
#include <string>
#include <vector>

#ifndef CAR_HPP
# define CAR_HPP

using namespace std;

// Basic car class
class Car
{
    private:
        bool _stop;
        unsigned int _speed;
        unsigned int _speedLimit;
        int _gearLevel;
        int _angle;
    
    public:
        Car();
        ~Car();

        // Starts the engine
        void start();
        // Stops the engine and applies the brakes
        void stop();
        // Increases the speed of the car by a specified value
        void accelerate(unsigned int speed);
        // Shifts up to the next gear
        void shift_gears_up();
        // Shifts down to the previous gear
        void shift_gears_down();
        // Puts the transmission in reverse gear
        void reverse();
        // Turns the wheels by a specified angle
        void turn_wheel(int angle);
        // Returns the wheels to a straight-ahead position
        void straighten_wheels();
        // Applies a specified force to the brakes
        void apply_force_on_brakes(int force);
        // Applies the brakes with maximum force for an emergency stop
        void apply_emergency_brakes();
};

Car::Car() { 
    _stop = true;
    _speed = 0;
    _speedLimit = 180;
    _gearLevel = 0;
}

Car::~Car() {}

void Car::start() {
    if (_stop == false) {
        cout << "Car engine is already running" << endl;
        return;
    }
    _stop = false;
    cout << "Car engine is running" << endl;
}

void Car::stop() {
    if (_stop == true) {
        cout << "Car engine is not running" << endl;
        return;
    }
    _stop = true;
    cout << "Car engine has been stopped" << endl;
}

void Car::accelerate(unsigned int speed) {
    if (speed > _speedLimit || _speed + speed > _speedLimit)
    {
        cout << "Car speed limit cannot pass " << _speedLimit << "kmh/h" << endl;
        _speed = _speedLimit;
        return;
    }
    _speed+= speed;
    cout << "Current car speed : " << _speed << "kmh/h" << endl;
}

void Car::shift_gears_up() {
    if (_gearLevel == 5) {
        cout << "Cannot shift up past level 5" << endl;
        return;
    }
    int previousLevel = _gearLevel++;
    cout << "Car's gear shiftup from :" << previousLevel << " to : " << _gearLevel << endl;
    return;
}

void Car::shift_gears_down() {
    if (_gearLevel == 0) {
        cout << "Cannot Shift down past level 0" << endl;
        return;
    }
    int previousLevel = _gearLevel--;
    cout << "Car's gear down from :" << previousLevel << " to : " << _gearLevel << endl;
    return;
}

void Car::reverse() {
    if (_speed != 0)
    {
        cout << "Put the speed car at 0 before reverse gear" << endl;
        return;
    }
    int previousLevel = _gearLevel;
    _gearLevel = -1;
    cout << "Car's gear down from :" << previousLevel << " to : " << "R" << endl;
}

void Car::turn_wheel(int angle) {
    (void)angle;
}
void Car::straighten_wheels() {
    _angle = 0;
    cout << "Current car's wheels angle : " << _angle << "°" << endl;
}

void Car::apply_force_on_brakes(int force) {
    switch (force)
    {
    case 1:
        cout << "very light force applied" << endl;
        _speed =- 5;
        break;
    case 2:
        cout << "light force applied" << endl;
        _speed =- 15;
        break;
    case 3:
        cout << "medium force applied" << endl;
        _speed =- 25;
        break;
    case 4:
        cout << "hard force applied" << endl;
        _speed =- 50;
        break;
    case 5:
        cout << "maximum force applied" << endl;
        _speed = 0;
        break;
    default:
        cout << "Unknown force applied" << endl;
        break;
    }
    cout << "Current car's speed : " << _speed << "km/h" << endl;
}

void Car::apply_emergency_brakes() {
    _speed = 0;
    _gearLevel = 0;

    cout << "Emergency brakes" << endl;
    cout << "Current car's speed : " << _speed << "km/h" << endl;
    cout << "Current car's gear level : " << _gearLevel << endl;
    straighten_wheels();
}

#endif
