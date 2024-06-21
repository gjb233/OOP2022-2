#pragma once
#include<iostream>
#include<vector>
#include"Instruction.h"
#define varName(x) #x
using namespace std;
class MagicArray;
class plusInt : public Instruction{
private:
    int index;
    int argument;
public:
    plusInt(int _index, int _argument) : index(_index), argument(_argument){
    }
    void apply(std::vector<int> &vec) override{
        vec[index] += argument;
    }
    void apply(std::vector<double> &vec) override{
        vec[index] += argument;
    }
    void output(){
        cout << "arr[" << index << "] += " << argument << endl;
    }
};

class element{
private:
    MagicArray* array;
    int index;
public:
    element(MagicArray* _array, int _index) : array(_array), index(_index){
    }
    void operator+=(int i);
    
};

class MagicArray : public Instruction{
private:
    vector<element> virtualArray;
    int num;
    vector<Instruction*> instructions;
public:
    MagicArray(int n) : num(n){
        for(int i = 0; i < n; i++){
            virtualArray.push_back(element(this, i));
        }
    }
    element operator[](int i){
        return virtualArray[i];
    }
    void apply(std::vector<int> &vec) override{
        for(auto iter = instructions.begin(); iter != instructions.end(); iter++){
            (*iter)->apply(vec);
        }
    }
    void apply(std::vector<double> &vec) override{
        for(auto iter = instructions.begin(); iter != instructions.end(); iter++){
            (*iter)->apply(vec);
        }
    }
    void output() override{
        for(auto iter = instructions.begin(); iter != instructions.end(); iter++){
            (*iter)->output();
        }
    }
    vector<Instruction*>& getInstructions(){
        return instructions;
    }
};

void element::operator+=(int i){
    Instruction* in = new plusInt(index, i);
    array->getInstructions().push_back(in);
}