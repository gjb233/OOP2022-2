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
    int arg;
public:
    plusInt(int _index, int _arg) : index(_index), arg(_arg){
    }
    void apply(std::vector<int> &vec) override{
        vec[index] += arg;
    }
    void apply(std::vector<double> &vec) override{
        vec[index] += arg;
    }
    void output(){
        cout << "arr[" << index << "] += " << arg << endl;
    }
};

class copyTo : public Instruction{
private:
    int indexTo, indexFrom;
public:
    copyTo(int i1, int i2) : indexTo(i1), indexFrom(i2){
    }
    void apply(std::vector<int> &vec) override{
        vec[indexTo] = vec[indexFrom];
    }
    void apply(std::vector<double> &vec) override{
        vec[indexTo] = vec[indexFrom];
    }
    void output(){
        cout << "arr[" << indexTo << "] = " <<  "arr[" << indexTo << "]" << endl;
    }
};

class plusTo : public Instruction{
private:
    int indexTo, indexFrom;
public:
    plusTo(int i1, int i2) : indexTo(i1), indexFrom(i2){
    }
    void apply(std::vector<int> &vec) override{
        vec[indexTo] += vec[indexFrom];
    }
    void apply(std::vector<double> &vec) override{
        vec[indexTo] += vec[indexFrom];
    }
    void output(){
        cout << "arr[" << indexTo << "] += " <<  "arr[" << indexTo << "]" << endl;
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
    void operator+=(element a);
    void operator=(element a);
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

void element::operator=(element a){
    Instruction* in = new copyTo(index, a.index);
    array->getInstructions().push_back(in);
}

void element::operator+=(element a){
    Instruction* in = new plusTo(index, a.index);
    array->getInstructions().push_back(in);
}