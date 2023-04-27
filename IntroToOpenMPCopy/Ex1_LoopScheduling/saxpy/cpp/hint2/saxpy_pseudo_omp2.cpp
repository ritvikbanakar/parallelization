/***
* File: saxpy_pseudo_omp2.cpp
* Description: SAXPY simple implementation with hints for OpenMP directives.
* Author: Bruno R. de Abreu  |  babreu at illinois dot edu
* National Center for Supercomputing Applications (NCSA)
*  
* Creation Date: Wednesday, 19th January 2022, 9:30:42 am
* Last Modified: Thursday, 20th January 2022, 10:20:29 am
*  
* Copyright (c) 2022, Bruno R. de Abreu, National Center for Supercomputing Applications.
* All rights reserved.
* License: This program and the accompanying materials are made available to any individual
*          under the citation condition that follows: On the event that the software is
*          used to generate data that is used implicitly or explicitly for research
*          purposes, proper acknowledgment must be provided in the citations section of
*          publications. This includes both the author's name and the National Center
*          for Supercomputing Applications. If you are uncertain about how to do
*          so, please check this page: https://github.com/babreu-ncsa/cite-me.
*          This software cannot be used for commercial purposes in any way whatsoever.
*          Omitting this license when redistributing the code is strongly disencouraged.
*          The software is provided without warranty of any kind. In no event shall the
*          author or copyright holders be liable for any kind of claim in connection to
*          the software and its usage.
***/

#include <iostream>
#include <vector>
// !! HINT1 include the OpenMP library  !!

#define ORD 1 << 27 // size of array

using namespace std;

int main()
{
    // instantiate vectors and attribute values
    vector<float> x, y;
    float r, elmnt;
    srand(time(NULL)); // random number generator seed
    for (int i = 0; i < ORD; i++)
    {
        r = rand() % RAND_MAX;         // get a random integer
        elmnt = float(r) / (RAND_MAX); // normalize it
        x.push_back(elmnt);            // x is noise
        y.push_back(1.0);              // y is just ones
    }
    float a = 2.0; // scalar multiplier (y -> a*x + y)
    // !! HINT1 add a couple of doubles to track execution time !!


    // perform SAXPY
    // !! HINT1 trigger stopwatch !!
    // !! HINT1 open omp parallel region here !!
    // !! HINT1 open omp for directive here !! 
    // !! HINT2 choose loop scheduling along with the loop directive !!
    for (int i = 0; i < x.size(); i++)
    {
        y[i] = a * x[i] + y[i];
    }
    // !! HINT1 close omp parallel region !!
    // !! HINT1 tigger stopwatch

    // !! HINT1 print execution time here !!

    // !! HINT1 check your results here !!
    // !! HINT2 pick a few random elements from y and verify they are different than one !!

    // goodbye
    return 0;
}
