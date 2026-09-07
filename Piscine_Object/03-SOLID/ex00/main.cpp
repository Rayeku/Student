#include "Car.hpp"

int main() {
    Car MyCar;

    MyCar.start();
    MyCar.stop();

    cout << endl;


    
    Car ErrCar;

    ErrCar.stop();
    ErrCar.start();

    return (0);
}