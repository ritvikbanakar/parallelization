#include <iostream>
#include <vector>
#include <cmath>
#include "omp.h"

#define ORD 1 << 14          // size of array
#define PI -4.0 * atan(-1.0) // pi ;D

using namespace std;

int main()
{
    // create variables to track time
    double startT, stopT;
    // variables
    vector<vector<double>> M; // matrix
    vector<double> v;         // vector
    float r;                  // this will hold random numbers
    srand(time(NULL));        // choose random seed for random number generator
    int i, j;                 // these will run over M
    int shuff_i, shuff_j;     // these will be the shuffled index
    int r1, r2, r3, r4;       // these will help us check resutls

    // instantiate M with random numbers
    for (i = 0; i < ORD; i++)
    {
        for (j = 0; j < ORD; j++)
        {
            r = float(rand() % RAND_MAX); // get a random integer
            v.push_back(r);               // push it to vector
        }
        M.push_back(v); // push it to matrx
        v.clear();      // clear vector
    }
    // print a couple of elements
    cout << "Some elements of M before shuffling: " << endl;
    r1 = rand() % int(ORD);
    r2 = rand() % int(ORD);
    r3 = rand() % int(ORD);
    r4 = rand() % int(ORD);
    cout << "i\t" << "j\t" << "M[i][j]" << endl;
    cout << r1 << "\t" << r2 << "\t" << M[r1][r2] << endl;
    cout << r3 << "\t" << r4 << "\t" << M[r3][r4] << endl;

    // now perform some funky matrix shuffling 
    startT = omp_get_wtime();
    #pragma omp parallel
{
   // private(i, j) ensures that threads have private copies of each
   // this avoids race conditions where multiple threads are changing
   // loop index values (creates nondeterministic unwanted behavior)
    #pragma omp for schedule(static) private(j)
    for (i = 1; i < ORD; i++)
    {
        for (j = 1; j < ORD; j++)
        {
            shuff_i = (float(ORD) / 2.0) * abs((cos(PI * float(i) / float(j)) + sin(PI * float(j) / float(i)))) - 1;
            shuff_j = (float(ORD) / 2.0) * abs((cos(PI * float(j) / float(i)) + sin(PI * float(i) / float(j)))) - 1;
            M[i][j] = M[shuff_i][shuff_j];
        }
    }

}    // print output
    stopT = omp_get_wtime();
    cout << "\nThe same elements of M after shuffling: " << endl;
    cout << r1 << "\t" << r2 << "\t" << M[r1][r2] << endl;
    cout << r3 << "\t" << r4 << "\t" << M[r3][r4] << endl;

    cout << "\nThe execution time is: " << (stopT - startT) << endl;

    // goodbye
    return 0;
}
