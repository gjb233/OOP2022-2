#pragma once
class Animal{
public:
    int color;
    Animal(int _color) : color(_color){
    }
    virtual void sing() = 0;
    virtual void swim() = 0;
    virtual ~Animal(){
    }
};