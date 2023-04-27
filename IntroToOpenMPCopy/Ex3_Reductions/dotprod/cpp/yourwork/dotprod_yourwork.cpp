#include <iostream>
#include <vector>
#include "omp.h"

#define ORD 1 << 28 // size of arrays

using namespace std;

int main()
{
    // variables to track time
    double startT, stopT;
    // declare variables
    vector<double> v1, v2; // vectors
    double r;              // this will hold random numbers
    double dotp;           // this will hold the dot product
    int i;                 // index that runs over vectors

    // start random number generator, fill up vectors
    srand(time(NULL));
    for (i = 0; i < ORD; i++)
    {
        r = double(rand() % RAND_MAX) / RAND_MAX; // random number between 0 and 1
        v1.push_back(r);
        r = double(rand() % RAND_MAX) / RAND_MAX;
        v2.push_back(r);
    }

    startT = omp_get_wtime();
    #pragma omp parallel shared(v1, v2)
{
    // calculate dot product
    // keeps dotp private but adds all thread results together
    dotp = 0.0;
    #pragma omp for reduction(+:dotp)
    for (i = 0; i < ORD; i++)
    {
        dotp = dotp + v1[i] * v2[i];
    }


}
    stopT = omp_get_wtime();
    // print result
    cout << "Dot product is: " << dotp << endl;
    cout << "Execution time is: " << (stopT - startT) << endl;

    // goodbye
    return 0;
}
