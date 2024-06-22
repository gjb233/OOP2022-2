#pragma once
#include<iostream>
#include"Animal.h"
using namespace std;
class Bird : public Animal{
public:
    Bird(int _color) : Animal(_color){
    }
    void sing() override{
        if(color){
            cout << "Blue ";
        }
        else{
            cout << "Red ";
        }
        cout << "bird is singing." << endl;
    }
    void swim() override{
        cout << "Bird can not swim." << endl;
    }
    ~Bird(){
        if(color){
            cout << "Blue ";
        }
        else{
            cout << "Red ";
        }
        cout << "bird is gone." << endl;
    }
};