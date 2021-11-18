#include <stdio.h>  //standard input & output
#include <math.h>   //for pow(), log(), fabs(), etc.
#include <stdlib.h> //for calloc() and free()

double artanh1 (double x, double delta)
/*Maclaurin series*/
{   //step 0
    double arctanh_old = -x;
    double arctanh_new = x;
    
    int i;
    for (i = 1; fabs(arctanh_new - arctanh_old) > delta ; i++){
        arctanh_old = arctanh_new;
        arctanh_new = arctanh_new + ( pow (x, 2*i + 1 ) / (2*i + 1) );
    }
    //printf ("\ti = %d\n", i);
    
    return arctanh_new;
}

double artanh2 (double x, double delta)
/**/
{
    return ((double)1/2)*( log(1+x) - log(1-x) );
}


int main (int argc, char *argv[]){
    //cangable paramater
    double x_min = -0.9; //min angle to be calculatex
    double x_max = 0.9;  //max angle to be calculatex
    double dx = 0.01;    //delta x, the step size
    double delta;        //user provided value
    printf ("Please provide a delta value: \n");    //prompt user
    scanf ("%lf", &delta);                          //read in provided value
    if (delta < 0){
        printf ("%lf is an invalid value for delta\n", delta);
        return (1);
    }
    //printf ("delta = %lf\n", delta);
    
    //*
    //allocate memory for arrays
    int size = ((x_max - x_min)/0.01) + 1;  //no. steps for x, & size of arrays
    double* X = calloc(size, sizeof(double));           //hold values of x
    double* Artanh1_x = calloc (size, sizeof (double)); //holds artanh1(x)
    double* Artanh2_x = calloc (size, sizeof (double)); //holds artanh2(x)
    double* D_artanh  = calloc (size, sizeof (double)); //artanh2(x) - artanh1(x)

    //find artanh(x) and fill arrays
    printf ("i,\tx[i],\tArtanh1_x[i],\tArtanh2_x[i],\tdifference\n");
    int i;
    for (i = 0; i < size; i++ ) {
        X[i] = x_min + i*dx;                    //update x value
        Artanh1_x[i] = artanh1 (X[i], delta);   //calculate long method
        Artanh2_x[i] = artanh2 (X[i], delta);   //calculate short method
        D_artanh[i] = Artanh2_x[i] - Artanh1_x[i];  //find difference
        printf ("%d,\t%lf,\t%lf,\t%lf,\t%.9e\n",   //print results
                i, X[i], Artanh1_x[i], Artanh2_x[i], D_artanh[i]);
    }
    
    //release callocs
    free (X);
    free (Artanh1_x);
    free (Artanh2_x);
    free (D_artanh);//*/
    
    return (0);
}

//gcc practical_5_hyp_tan.c -o p_5_hyp_tan.out -lm -Wall
//./p_5_hyp_tan.out 
