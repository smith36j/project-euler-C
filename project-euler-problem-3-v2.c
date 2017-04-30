//
//  main.c
//  Project-Euler-C3-v2
//
//  Created by Jerrod Smith on 2017-04-30.
//  Copyright © 2017 Jerrod Smith. All rights reserved.
//
//  Going to try to solve Problem 3 again, but this time by writing a function to test if a number is prime
/*
 
 The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of the number 600851475143 ?
 
 */
//
// This program can handle 15 digit numbers in tens of seconds
//
#include <stdio.h> // standard input/output header
#include <math.h> // math header for sqrt function
#include <stdlib.h> // include the standard library of functions
#include <stdbool.h> // include boolean type

bool is_prime (long p);

int main()
{
    long x; // enter a number
    long p; // larget prime factor of x less than sqrt(x) + 1
    long q; // larget prime factor of x/q less than sqrt(x/q) + 1
    
    // Get input
    printf("Please enter a number:\n");
    scanf("%ld", &x);

    //Compute the largest prime factor of x that is less than sqrt(x) + 1
    // start with p = sqrt(x) + 1 and work down to largest prime factor
    for(p= sqrt(x) + 1; p>=2; p = p - 1)
    {
        // determine if p divides x and either p is 2 or p is odd
        if( x % p == 0 && (p == 2 || p %2 >0) ) // add requirement that p = 2 or p is odd
        {
            //determine if p is prime
            if (is_prime (p) == true)
            {
                break; // if p is prime, break the for loop
            }
            // otherwise the loop will continue
        }
        
    }
    
    //Compute the largest prime factor of x/p
    // start with q = x/p and work down to largest prime factor
    for(q= x/p ; q>=2; q = q - 1)
    {
        // determine if q divides x/p and either q is 2 or q is odd
        if( x/p % q == 0 && (q == 2 || q %2 >0) ) // add requirement that q = 2 or q is odd
        {
            //determine if q is prime
            if (is_prime (q) == true)
            {
                break; // if q is prime, break the for loop
            }
            // otherwise the loop will continue
        }
        
    }
    
    // Return the result
    if (p >= q)
    {
    printf("The largest prime factor of %ld is %ld\n", x, p);
    }
    else
    {
     printf("The largest prime factor of %ld is %ld\n", x, q);
    }
    // Print the values of all of the varialbes to see whats happening
    printf("x = %ld, p = %ld, x/p = %ld, q = %ld \n", x, p, x/p, q);
    
    return 0;
}


bool is_prime ( long p )
{
        long i; // counter
    
    // loop: check to see if p has a divisor that is less than sqrt(p)
    for (i = 2; i < sqrt(p)+1; i = i+1)
    {
        if( p % i == 0)
        {
            return false; // if we found a divisor, return false to is_prime
        }
        // otherwise the loop continues
    }
    // if we exit the loop, then p does not have a divisor less than sqrt(p) and p is prime
    // in this case, we return true to is_prime
    return true;
}
