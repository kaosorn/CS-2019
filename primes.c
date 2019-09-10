//This program generates prime numbers (from lower bound to upper bound) using the Sieve of Eratosthenes algorithm. 
//Project 1 in CS 232

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

generatePrimes(int lowerBound, int upperBound){
     
     //Using Sieve of Eratosthenes 
     
    unsigned long long int i, j; //allocating memory
    int *primes;
    primes = malloc(sizeof(int) * upperBound);
    

    for (i = 2; i <= upperBound; i++) { // this sets all the numbers from 2 to upperbound to be all true, or all primes
       
        primes[i] = 1;
    }

    for (i = 2; i <= upperBound; i++) { // this makes all non prime numbers and their multiples to be set to false
    
        if (primes[i]) {
            
            for (j = i; i * j <= upperBound; j++) {
                
                primes[i * j] = 0;
                
            }
        }
    }

    for (i = 2; i <= upperBound; i++) { //this takes the remaining numbers, which should all be true/primes
        if (primes[i]) {               //and compares if it is in between our bounds, if it is then it prints out the prime number
            if (i > lowerBound && i <= upperBound) {
                printf("%llu \n", i);
            }
        }
    }
     
     
    }

int main ( int argc, char *argv[] ){

    if(argc != 3) {
        printf("Only enter two integer arguments, please");
    }
    else{
        int lowerBound = atoi(argv[1]);
        int upperBound = atoi(argv[2]);
        generatePrimes(lowerBound, upperBound);
    }



}