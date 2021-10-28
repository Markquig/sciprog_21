#include <stdio.h>  //standard input & output
#include <math.h>   //for pow(), log(), fabs(), etc.
#include <stdlib.h> //for calloc() and free()

double artanh1 (double x, double delta)
/*Maclaurin series*/
{   //step 0
    double arctanh_old = -x;
    double arctanh_new = x;
//    double test = fabs(arctanh_new - arctanh_old);
//    printf ("\ttest = %lf\n", test);
//    printf ("\ttest < delta = %d\n", (test<delta));
    
    int i;
    //for (i = 1; test > delta ; i++){
    for (i = 1; fabs(arctanh_new - arctanh_old) > delta ; i++){
        arctanh_old = arctanh_new;
        arctanh_new = arctanh_new + ( pow (x, 2*i + 1 ) / (2*i + 1) );
//        test = fabs(arctanh_new - arctanh_old);
    }
//    printf ("\ti = %d\n", i);
    
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
    double dx = 0.01;   //delta x, the step size
    double delta;       //user provided value
    printf ("Please provide a delta value: \n");    //prompt user
    scanf ("%lf", &delta);                          //read in provided value
    //printf ("delta = %lf\n", delta);
    
    /*  testing functions
    double artanh;
    artanh = artanh1 (0.9, delta);
    printf ("artanh1 = %lf\n", artanh);
    artanh = artanh2 (0.9, delta);
    printf ("artanh2 = %lf\n", artanh);//*/

    //*
    //allocate memory for arrays
    int size = ((x_max - x_min)/0.01) + 1;  //no. steps for x, & size of arrays
    double* X = calloc(size, sizeof(double));           //hold values of x
    double* Artanh1_x = calloc (size, sizeof (double)); //holds artanh1(x)
    double* Artanh2_x = calloc (size, sizeof (double)); //holds artanh2(x)
    double* D_artanh  = calloc (size, sizeof (double)); //artanh2(x) - artanh1(x)

    //find artanh(x) and fill arrays
    printf ("i,\tx[i],\tArtanh1_x[i],\tArtanh2_x[i],\tD_artanh[i]\n");
    int i;
    for (i = 0; i < size; i++ ) {
        X[i] = x_min + i*dx;
        Artanh1_x[i] = artanh1 (X[i], delta);
        Artanh2_x[i] = artanh2 (X[i], delta);
        D_artanh[i] = Artanh2_x[i] - Artanh1_x[i];
        printf ("%d,\t%lf,\t%lf,\t%lf,\t%.10e\n",
                i, X[i], Artanh1_x[i], Artanh2_x[i], D_artanh[i]);
    }
    
    //release callocs
    free (X);
    free (Artanh1_x);
    free (Artanh2_x);
    free (D_artanh);//*/
}
