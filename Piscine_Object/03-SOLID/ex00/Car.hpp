#ifndef CAR_HPP
# define CAR_HPP

// Include(s)
# include <iostream>
# include <string>

// Typeface(s)
# define BOLD "\033[1m"
# define ITALIC "\033[3m"

// Color(s)
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define GREEN "\033[32m"
# define BROWN "\033[38;5;94m"
# define ORANGE "\033[38;5;202m"
# define PURPLE "\033[38;5;175m"

# define LIGHTYELLOW "\033[38;5;229m"
# define YELLOW      "\033[38;5;220m"
# define DARKORANGE  "\033[38;5;166m"
# define DARKRED     "\033[38;5;88m"

# define BRAKE_FORCE "force applied on brakes"

using namespace std;

// Basic car class
class Car
{
    private:
        bool _running;
        unsigned int _speed;
        unsigned int _speedLimit;
        int _gearLevel;
        unsigned int _wheelAngle;
        unsigned int _maxWheelAngle;
    
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
        void turn_wheel(unsigned int angle);
        // Returns the wheels to a straight-ahead position
        void straighten_wheels();
        // Applies a specified force to the brakes
        void apply_force_on_brakes(unsigned int force);
        // Applies the brakes with maximum force for an emergency stop
        void apply_emergency_brakes();
        // Checks is the car engine is running, returns false if not, true otherwise 
        bool check_engine();
};

Car::Car() { 
    _running = false;
    _speed = 0;
    _speedLimit = 180;
    _gearLevel = 0;
    _wheelAngle = 0;
    _maxWheelAngle = 45;
}

Car::~Car() {}

void Car::start() {
    if (_running == true) {
        cout << RED ITALIC << "Car engine is already running" << RESET << endl;
        return;
    }
    _running = true;
    cout << BOLD GREEN << "Car engine is running" << RESET << endl;
}

void Car::stop() {
    if (!check_engine())
        return;
    else if (_speed != 0) {
        cout << RED ITALIC << "lower the car's speed at 0 km/h before shuting down" << RESET << endl;
        return;
    }
    _running = false;
    _wheelAngle = 0;
    _gearLevel = 0;
    cout << BOLD RED << "Car engine has stopped" << RESET << endl;
}

void Car::accelerate(unsigned int speed) {
    if (!check_engine())
        return;
    if (_gearLevel == 0) {
        cout << RED ITALIC << "Shift gear up at least once before accelerate" << RESET << endl;
    }
    if (speed > _speedLimit || _speed + speed > _speedLimit) {
        cout << RED ITALIC << "Car speed limit cannot pass " << _speedLimit << " kmh/h" << RESET << endl;
        _speed = _speedLimit;
    }
    else
        _speed+= speed;
    cout << "Car's speed increased to : " << GREEN << _speed << RESET << " kmh/h" << endl;
        if (speed >= _speedLimit ) {
            if (_gearLevel != -1)
                _gearLevel = 5;
            cout << "Car's current gear level : " << _gearLevel << endl;
        }
    }

void Car::shift_gears_up() {
    if (!check_engine())
        return; 
    if (_gearLevel < 0) {
        cout << "Lower the car's speed at 0 before gear shift up" << endl;
        return;
    }
    else if (_gearLevel >= 5) {
        cout << RED ITALIC << "Cannot shift up past level 5" << RESET << endl;
        return;
    }
    int previousLevel = _gearLevel++;
    cout << "Car's gear shiftup from : " << previousLevel << " to " << _gearLevel << endl;
    return;
}

void Car::shift_gears_down() {
    if (!check_engine())
        return; 
    if (_gearLevel <= 0) {
        cout << RED ITALIC << "Cannot shift down past level 0" << RESET << endl;
        return;
    }
    int previousLevel = _gearLevel--;
    cout << "Car's gear down from : " << previousLevel << " to " << _gearLevel << endl;
    return;
}

void Car::reverse() {
    if (!check_engine())
        return; 
    if (_speed != 0) {
        cout << RED ITALIC << "Lower the car's speed at 0 km/h before reverse gear" << RESET << endl;
        return;
    }
    int previousLevel = _gearLevel;
    _gearLevel = -1;
    cout << "Car's gear down from : " << previousLevel << " to " << "R" << endl;
}

void Car::turn_wheel(unsigned int angle) {
    if (!check_engine())
        return; 
    if (angle > _maxWheelAngle || _wheelAngle + angle > _maxWheelAngle) {
        cout << "Wheels angle cannot pass " << _maxWheelAngle << "°" << endl;
        _wheelAngle = _maxWheelAngle;
    }
    else
        _wheelAngle+= angle;
    cout << "Wheels current angle position : " << PURPLE <<  _wheelAngle << RESET << "°" << endl; 
}
void Car::straighten_wheels() {
    if (!check_engine())
        return; 
    _wheelAngle = 0;
    cout << "Car's current wheels angle : " << PURPLE << _wheelAngle << RESET << "°" << endl;
}

void Car::apply_force_on_brakes(unsigned int force) {
    if (!check_engine())
        return; 
    switch (force)
    {
    case 1:
        cout << LIGHTYELLOW << "Very light " << BRAKE_FORCE << RESET << endl;
        _speed -= 5;
        break;
    case 2:
        cout << YELLOW << "Light " << BRAKE_FORCE << RESET << endl;
        _speed -= 15;
        break;
    case 3:
        cout << ORANGE << "Medium " << BRAKE_FORCE << RESET << endl;
        _speed -= 25;
        break;
    case 4:
        cout << DARKORANGE << "Hard " << BRAKE_FORCE << RESET << endl;
        _speed -= 50;
        break;
    case 5:
        cout << BOLD RED << "Maximum " << BRAKE_FORCE << RESET << endl;
        _speed = 0;
        break;
    default:
        cout << "Unknown " << BRAKE_FORCE << " , nothing happened" << endl;
        break;
    }
    cout << "Car's speed decreased to : " << RED << _speed << RESET << " km/h" << endl;
    if (_speed == 0) {
        if (_gearLevel == -1)
            return;
        _gearLevel = 0;
    }
}

void Car::apply_emergency_brakes() {
    if (!check_engine())
        return; 
    _speed = 0;
    _gearLevel = 0;
    _wheelAngle = 0;

    cout << ITALIC BOLD RED << "Emergency brakes !!!" << RESET << endl;
    cout << "Car's current speed : " << RED << _speed << RESET << " km/h" << endl;
    cout << "Car's current gear level : " << _gearLevel << endl;
    cout << "Wheels current angle position : " << PURPLE << _wheelAngle << RESET << "°" << endl;
}

bool Car::check_engine() {
    if (_running == false) {
        cout << RED << "Car engine is not running" << RESET << endl;
        return false;
    }
    return true;
}

#endif
