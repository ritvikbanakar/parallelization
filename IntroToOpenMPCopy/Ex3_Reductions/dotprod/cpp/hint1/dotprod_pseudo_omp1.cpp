/***
 * File: dotprod_pseudo_omp1.cpp
 * Description: Hints to parallelize Dot Product with OpenMP
 * Author: Bruno R. de Abreu  |  babreu at illinois dot edu
 * National Center for Supercomputing Applications (NCSA)
 *
 * Creation Date: Tuesday, 25th January 2022, 3:06:52 pm
 * Last Modified: Tuesday, 25th January 2022, 3:06:54 pm
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
// !! HINT1 include OpenMP library here !!

#define ORD 1 << 29 // size of arrays

using namespace std;

int main()
{
    // declare variables
    vector<double> v1, v2; // vectors
    double r;              // this will hold random numbers
    double dotp;           // this will hold the dot product
    int i;                 // index that runs over vectors
    // !! HINT1 add variables to track execution time !!

    // start random number generator, fill up vectors
    srand(time(NULL));
    for (i = 0; i < ORD; i++)
    {
        r = double(rand() % RAND_MAX) / RAND_MAX; // random number between 0 and 1
        v1.push_back(r);
        r = double(rand() % RAND_MAX) / RAND_MAX;
        v2.push_back(r);
    }

    // calculate dot product
    dotp = 0.0;
    // !! HINT1 trigger stopwatch !!
    // !! HINT1 open omp parallel region -- what variables are shared? !!
    // !! HINT1 insert omp for -- what's the schedule? who is private to each thread? !!
    for (i = 0; i < ORD; i++)
    {
        dotp = dotp + v1[i] * v2[i];
    }
    // !! HINT1 close omp directives, check time !!

    // !! HINT1 print execution time !!

    // print result
    cout << "Dot product is: " << dotp << endl;

    // !! HINT1 check your results here !!

    // goodbye
    return 0;
}
