#pragma once
#include<iostream>
#include"Animal.h"
using namespace std;
class Fish : public Animal{
public:
    Fish(int _color) : Animal(_color){
    }
    void swim() override{
        if(color){
            cout << "Blue ";
        }
        else{
            cout << "Red ";
        }
        cout << "fish is swimming." << endl;
    }
    void sing() override{
        cout << "Fish can not sing." << endl;
    }
    ~Fish(){
        if(color){
            cout << "Blue ";
        }
        else{
            cout << "Red ";
        }
        cout << "fish is gone." << endl;
    }
};