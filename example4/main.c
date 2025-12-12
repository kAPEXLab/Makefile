/**
 * @file    main.cpp
 * @brief   Entry point of the program that prints a hello message and performs addition.
 * @details This file includes "hello.h" and "add.h" headers. It calls the print_hello() function
 *          to display a greeting message and uses add() to compute the sum of two integers.
 * @author  KPIT APEX Lab
 * @date    2025-12-12
 */


#include <stdio.h>
#include "hello.h"
#include "add.h"

int main() {
    print_hello();
    printf("Addition result = %d\n", add(4,5));
    return 0;
}