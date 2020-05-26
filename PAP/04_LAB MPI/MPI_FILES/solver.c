#include "heat.h"

/*
 * Blocked Jacobi solver: one iteration step
 */
double relax_jacobi( double *u, double *utmp, unsigned sizex, unsigned sizey )
{
    double diff, sum=0.0;

    for( int i=1; i<sizex-1; i++ ) {
        for( int j=1; j<sizey-1; j++ ) {
            utmp[i*sizey + j] = 0.20 * (u[ i*sizey     + j     ]+  // center
                                        u[ i*sizey     + (j-1) ]+  // left
                                        u[ i*sizey     + (j+1) ]+  // right
                                        u[ (i-1)*sizey + j     ]+  // top
                                        u[ (i+1)*sizey + j     ]); // bottom

            diff = utmp[i*sizey + j] - u[i*sizey + j];
            sum += diff * diff;
        }
    }

    return sum;
}
