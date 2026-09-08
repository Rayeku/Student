#include "Car.hpp"

int main() {
    Car MyCar;

    MyCar.start();
    MyCar.shift_gears_up();
    MyCar.accelerate(20);

    MyCar.shift_gears_up();
    MyCar.accelerate(40);
    
    MyCar.apply_force_on_brakes(2);
    MyCar.shift_gears_down();
    MyCar.apply_emergency_brakes();

    MyCar.reverse();
	MyCar.accelerate(25);
	MyCar.accelerate(25);
    MyCar.apply_force_on_brakes(5);

    MyCar.shift_gears_up();
	MyCar.accelerate(200);

    MyCar.turn_wheel(45);
	MyCar.stop();
    MyCar.apply_force_on_brakes(5);
	MyCar.stop();

    cout << endl;
    return (0);
}