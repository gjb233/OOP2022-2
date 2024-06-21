#pragma once
#include <iostream>
using namespace std;
class Vehicle{
public:
    int wheel_num = 0;
    int wing_num = 0;
    int max_wheel_num;
    int max_wing_num;
    void set_max_wheel_num(int n){
        max_wheel_num = n;
    }
    void set_max_wing_num(int n){
        max_wing_num = n;
    }
    void add_wheel(){
        wheel_num++;
    }
    void add_wing(){
        wing_num++;
    }
    virtual bool finished(){
        return wheel_num >= max_wheel_num;
    };
    virtual void run(){
        cout << "I'm runing" << endl;
    };
};