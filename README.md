# RSA-simulation
=========
Simulate and see working of RSA with various helper functions like jacobi calculation, fermats primality tests,miller rabbin test, Solvey strassman test, sieve of eranthoses. The code is written in c++ . this code was developed based on topics learnt in Number Theory and Cryptography course in 5th Semester.

## Installation
$ git pull https://github.com/Gdarkstar/RSA-simulation

## system requirements
gnu gcc g++
text editor to change the main code

##to run the code 
open RSA.cpp in your favorite text editor
create objects of rsa class in main
>>> RSA A;
>>> RSA B;
>>> RSA C;

A creates a message to be read by B
>>>uint64_t ciphertext_B = A.encrypt_block(121, B.public_key);
>>>uint64_t text= B.decrypt_block(ciphertext_B);
>>>121

if C tries to decrypt
>>>uint64_t text= C.decrypt_block(ciphertext_B);
>>>q2w3f4

### isprime

Check whether a number is prime or not 
in main add the code
cout<<miller_rabin(13);
cout<<fermats_test(13);
cout<<solovay_strassen(13);

