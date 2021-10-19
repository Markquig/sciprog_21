#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double **trapezod;      //2 * no_step matrix, first row x, second row function(x)

double function (double x) {
    double y = tan(x);
    //printf ("\t\tf(%f) = %f\n", x, y);
    return y;
}

float degtorad(float arg) {
/*addapted from lecture to use M_PI from math.h insted of a global variable*/
    return( (M_PI * arg)/180.0 );
}

double trapezod_area (double* size_step, int no_steps){
/*calculates the area given
 trapezod: a gloabal array of evenly spaced x values
  size_step: pointer to an the value of the step size
  no_steps: the number of points -1  inbetween stat and end values of trapezod 
  */
    double sum = 0; //hold the summation part of the equation
    sum += trapezod[1][0];          //firts point
    sum += trapezod[1][no_steps];   //last point

    int i;
    for (i = 1; i < (no_steps); i++){
        sum += 2 * trapezod[1][i];      //inbetween points carry double the weight
    }
    
    double ret = (*size_step/2) * sum;  //final area calculation
    return ret;
}


int main (int argc, char *argv[]) {
    double start = 0;
    double end   = M_PI/3;      //=60 deg
    int no_steps = 12;          //number of steps from stat and end

    //create space for trapezod
    trapezod = (double**)calloc(2, sizeof(double*));
    int i;      //for looping
    for (i = 0; i < 2; i++){
        trapezod[i] = (double*)calloc( (no_steps + 1), sizeof(double));
    }
    
    double size_step = (double)(end - start)/no_steps;
    for (i = 0; i < (no_steps + 1); i++){
        trapezod[0][i] = start + (size_step * i);
        trapezod[1][i] = function (trapezod[0][i]);
        //printf ("\t%d: f(%f) = %f\n", i, trapezod[0][i], trapezod[1][i]);
    }
    
    double area = trapezod_area (&size_step, no_steps);   //find area
    printf ("Area = %f\n", area);       //print area
    
    //release trapezod from calloc
    for (int i = 0; i < 2; i++){
        free(trapezod[i]);
    }
    free(trapezod);
    
    return 1;
}



