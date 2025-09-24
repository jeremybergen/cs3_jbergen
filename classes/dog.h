#pragma once
#include "animal.h"
#include <iostream>

using namespace std;

class Dog : public Animal
{
    private:
        string _breed;

    public:
        Dog(string breed) { _breed = breed; }
};