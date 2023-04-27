/***
 * File: dotprod_omp.cpp
 * Description: Dot product application parallelized with OpenMP
 * Author: Bruno R. de Abreu  |  babreu at illinois dot edu
 * National Center for Supercomputing Applications (NCSA)
 *
 * Creation Date: Tuesday, 25th January 2022, 1:51:47 pm
 * Last Modified: Tuesday, 25th January 2022, 1:51:52 pm
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

/****
 ***    This is a solution to the SAXPY exercise.
 ***    I recommend you do not read this file any further
 ***    unless you are sure you checked all the hints and
 ***    tried your best to code it yourself.
 ****/


#include <iostream>
#include <vector>
#include "omp.h"

#define ORD 1 << 28 // size of arrays

using namespace std;

int main()
{
    // declare variables
    vector<double> v1, v2; // vectors
    double r;              // this will hold random numbers
    double dotp;           // this will hold the dot product
    int i;                 // index that runs over vectors
    double startT, stopT;  // stopwatch variables

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
    startT = omp_get_wtime(); // trigger stopwatch
    dotp = 0.0;
    #pragma omp parallel shared(v1, v2)
    {
        #pragma omp for reduction(+:dotp)
        for (i = 0; i < ORD; i++)
        {
            dotp = dotp + v1[i] * v2[i];
        }
    }
    stopT = omp_get_wtime(); // trigger stopwatch

    // print execution time
    cout << "Dotprod execution time (s): " << (stopT - startT) << endl;

    // print result
    cout << "Dot product is: " << dotp << endl;

    // check results
    cout << "<v1, v2> / N = " << dotp / double(ORD) << endl;

    // goodbye
    return 0;
}
