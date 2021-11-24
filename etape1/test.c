//
// Created by Hugo on 24/11/2021.
//


// A simple C program to demonstrate callback
#include<stdio.h>

void A()
{
    printf("I am function A\n");
}

// callback function
void B(void (*SquareChangeCallback)())
{
    (*SquareChangeCallback) (); // callback to SquareChangeCallback
}

int main()
{
    void (*SquareChangeCallback)() = &A;

    // calling function B and passing
    // address of the function SquareChangeCallback as argument
    B(SquareChangeCallback);

    return 0;
}