//
//  main.c
//  Project-Euler-C-3
//
//  Created by Jerrod Smith on 2017-04-28.
//  Copyright © 2017 Jerrod Smith. All rights reserved.
//
/*
 
 The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of the number 600851475143 ?
 
 */
// the following code appears to be correct; however it isn't running correctly for very large inputs
// add the condition that we only care about p odd

// Development notes

// problem 1 int only holds 10 digit integers: solution use long or long long
// use %ld to print and scan for long

// code will run on 11 digit numbers within 5 minutes

// problem 2: code too inefficient, wont run under an hour on 12 digit numbers
// took about 1.5 ~ 2 hours to run with input 600851475143; however prodced correct result

// Note: changed to start at p = sqrt(x) + 1 -- resolves previous issues
// Now runs on 18 digit numbers in about 15 seconds

#include <stdio.h>
#include <math.h> // for square roots

int main()
{
    
    long x; // enter a number
    long p; // larget prime factor of x
    long i; // counter
    
    // Get input
    printf("Please enter a number:\n");
    scanf("%ld", &x);
    
    //Compute the largest prime factor of x
    // Originally started with p =x, then if x is prime we end up returning x=p
    // Here, start with p = sqrt(x) + 1 to cut down A LOT of computation time...
    // However this causes the program to retrun 1 if x is a prime bigger than 2
    for(p=sqrt(x) +1; p>=2; p = p - 1)
    {
        // start with p = x and work down to largest prime factor
    if( x % p == 0 && (p == 2 || p %2 >0) ) // add requirement that p = 2 or p is odd
        {
            //determine if p is prime
            // if p is prime break the loop
            // equivalently, if p is not prime continue the loop else break the loop
            for(i=3; i < p ; i=i+2)
                // start with i at 3 and only check for odd divisors -- add break condition if p=2 below
            {
                if ( p % i > 0 ) {continue;}
                else {break;}
            }
            // i will make it to i = p only if i doesn't divide p for all odd 3 < i < p
            // then we break the loop
            if (i == p || p == 2) {break;}
        }
    
    }
    
    // Return the result
    printf("The largest prime factor of %ld is %ld\n", x, p);
    if(p==1)
    {
    printf("Since the result was 1, the number %ld is prime.\n", x);
    }
    
    return 0;
}
