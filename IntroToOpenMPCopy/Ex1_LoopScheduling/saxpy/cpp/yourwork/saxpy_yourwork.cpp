#include <iostream>
#include <vector>
#include "omp.h"

#define ORD 1 << 27 // size of array

using namespace std;

int main()
{
    // create variables to store time
    double startT;
    double stopT;
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
    startT = omp_get_wtime();
    #pragma omp parallel 
    {
    // perform SAXPY
    //#pragma omp for schedule(static) total workload evenly distributed
    //	good for when workload stays the same per iteration
    //#pragma omp for schedule(dynamic, R) control chunk each thread does (loops) 
    //#pragma omp for schedule(guided, R) redistribute load as chunks finish
    //	good for when workload increases with index
    #pragma omp for schedule(static)
 	for (int i = 0; i < x.size(); i++)
    	{
       	 y[i] = a * x[i] + y[i];
    	}
    }
    stopT = omp_get_wtime();
    std::cout << "Execution Time " << (stopT - startT) << std::endl;
    // goodbye
    return 0;
}

