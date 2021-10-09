#include <stdio.h>
#include <math.h>

double function (double x) {
    double y = tan(x);
    //printf ("\t\tf(%f) = %f\n", x, y);
    return y;
}

//*
double trapezoid (double start, double end, int count) {
    double step = (double)(end - start)/count;
    //printf ("\tstart = %f\tend = %f\tstep = %f\n", start, end, step);
    double sum = 0; //hold teh summation part of the equation
    double calc;    //holds value of the function at a given value
    calc = function (start);
    sum += calc;
    calc = function (end);
    sum += calc;
    
    int i;
    double x;   //value of x for y to be calculated at
    for (x = (start+step); x < end; x += step) {
        calc = function (x);
        sum += (2*calc);
    }

    double ret = (step/2) * sum;
    return ret;
}//*/

int main (int argc, char *argv[]) {
    printf ("Hello!\n");
    
    /*  used to test values returned by function()
    double x = M_PI/3;
    double hold = function (x);
    printf ("f(%f) = %f\n", x, hold); //*/
    
    /* used to check that the answers converge with more steps
    ans = trapezoid (0, M_PI/3, 5);
    printf ("ans = %f\n", ans);
    
    ans = trapezoid (0, M_PI/3, 10);
    printf ("ans = %f\n", ans);
    
    ans = trapezoid (0, M_PI/3, 20);
    printf ("ans = %f\n", ans);
    
    ans = trapezoid (0, M_PI/3, 50);
    printf ("ans = %f\n", ans);

    ans = trapezoid (0, M_PI/3, 500);
    printf ("ans = %f\n", ans);
    
    ans = trapezoid (0, M_PI/3, 5000);
    printf ("ans = %f\n", ans);
    //*/

    
    double ans = trapezoid (0, M_PI/3, 12);
    printf ("ans = %f\n", ans);

    
    
    return 0;
}
