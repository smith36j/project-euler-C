//
//  main.c
//  Project-Euler-C
//
// Problem 1: Find the sum of all the multiples of 3 and 5 below 1000
//
// Generalization: Take user input 3 integers: x,y z; find the sum of all the multiples of x and y below z
//
//  Created by Jerrod Smith on 2017-04-22.
//  Copyright © 2017 Jerrod Smith. All rights reserved.
//

#include <stdio.h>

int main() {
    // Declare variabes
    int x,y,z; // user input: find the sum of all multiples of x and y that are less than z
    int sum; // the result of the sum of all multiples of x and y that are less than z
    int x_into_z, y_into_z, xy_into_z; // the largerst number such that ? * ?_into_z is less than z
    
    // Greet the user and ask for input
    printf("Hello there, let's do some math! \n");
    printf("I'm going to ask you for three integers: x, y and z. \n Then I'll tell you the sum of all multiplies of x and y that are less than z. \n");
    // Ask for a value of x and take input
    printf("What value do you want for x? \n");
    scanf("%d", &x);
    // Repeat input for x
    printf("You entered %d for x \n", x);
    
    // Ask for a value of y and take input
    printf("What value do you want for y? \n");
    scanf("%d", &y);
    // Repeat input for y
    printf("You entered %d for y \n", y);
    
    // Ask for a value of z and take input
    printf("What value do you want for z? \n");
    scanf("%d", &z);
    // Repeat input for x
    printf("You entered %d for z \n", z);
    
    //Compute the sum of all multiples of x and y that are less than z
    //sum = x*(z/x)*(z/x +1)/2) + y*((z/y)*(z/y + 1)/2) - x*y*(z/(x*y)*(z/(x*y)+1)/2);
    // The above isn't correct
    // 1 - it doesn't compile so my syntax is wrong
    // 2 - the formula is actually incorrect, it doesn't account for the case that x, y divide z
    //
    // Solution: going to define some new intermediate variables to simplifiy the above formula
    //
    // Determine the number of multiples of x, y and xy that are less than z
    // Return the results to the user
    if(z - (z/x)*x == 0)
    {
        x_into_z = z/x -1;
    }
    else
    {
        x_into_z = z/x;
    }
    printf("There are %d multiples of x that are less than z\n", x_into_z);
    if(z - (z/y)*y == 0)
    {
        y_into_z = z/y -1;
    }
    else
    {
        y_into_z = z/y;
    }
     printf("There are %d multiples of y that are less than z\n", y_into_z);
    if(z - (z/(x*y))*x*y == 0)
    {
        xy_into_z = z/(x*y) -1;
    }
    else
    {
        xy_into_z = z/(x*y);
    }
     printf("There are %d multiples of xy that are less than z\n", xy_into_z);
    //Compute the sum of all multiples of x and y that are less than z
    sum = x*x_into_z*(x_into_z + 1)/2 + y*y_into_z*(y_into_z + 1)/2 - (x*y)*xy_into_z*(xy_into_z + 1)/2;
    
    // Return the result to the user
    printf("The sum of all multiples of x and y that are less than z is equal to: %d \n", sum);
    
    printf("Wasn't that fun!?\n Bye!\n");
    return 0;
}
