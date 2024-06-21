#include<iostream>
#include"Vehicle.h"
using namespace std;
class Plane : public Vehicle{
public:
    Plane(){
        set_max_wheel_num(3);
        set_max_wing_num(2);
    }
    bool finished() override{
        return (wheel_num >= max_wheel_num) && (wing_num >= max_wing_num);
    };
    void run() override{
        cout << "I'm flying and running" << endl;
    }
};