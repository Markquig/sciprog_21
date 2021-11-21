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

double trapezod_area (int no_steps){
/*calculates the area given
  trapezod: a gloabal array of evenly spaced x values
  no_steps: number of steps from start and end
  */
    double sum = 0; //hold the summation part of the equation
    sum += trapezod[1][0];          //first point
    sum += trapezod[1][no_steps];   //last point

    int i;
    for (i = 1; i < (no_steps); i++){
        sum += 2 * trapezod[1][i];      //inbetween points carry double the weight
    }
    
    double size_step = (double)(trapezod[0][no_steps] - trapezod[0][0])/no_steps;
    double ret = (size_step/2) * sum;  //final area calculation
    return ret;
}


int main (int argc, char *argv[]) {
    double start = 0;
    //double end   = M_PI/3;      //angle in radians
    double end   = 60;          //angle in degreese
    int no_steps = 12;          //number of steps from start and end

    //create space for trapezod
    trapezod = (double**)calloc(2, sizeof(double*));
    int i;      //for looping
    for (i = 0; i < 2; i++){
        trapezod[i] = (double*)calloc( (no_steps + 1), sizeof(double));
    }
    
    //* fill array and print it
    double size_step = (double)(end - start)/no_steps;
    printf ("\ti\ttrapezod[0][i]\t trapezod[1][i]\n");
    for (i = 0; i <= no_steps; i++){
        /*  input radians
        trapezod[0][i] = start + (size_step * i);
        trapezod[1][i] = function (trapezod[0][i]);//*/
        //*  input degreese
        trapezod[0][i] = degtorad (start + (size_step * i));
        trapezod[1][i] = function (trapezod[0][i]);//*/

        //print array
        printf ("\t%d\t%f\t %f\n", i, trapezod[0][i], trapezod[1][i]);


    }//*/
        
    double area = trapezod_area (no_steps);     //find area
    printf ("Area = %f\n", area);               //print area
    
    //release trapezod from calloc
    for (i = 0; i < 2; i++){
        free(trapezod[i]);
    }
    free(trapezod);
    
    return 1;
}

//gcc practical_4.c -o p_4.out -lm
//./p_4.out

