//#include <stdlib.h>
#include <stdio.h>

int fibonacci_iterate (int f_n_1, int f_n)
/*provides the next step in a fibonacci sequence given
  f_n: the value of the previous step, that is step n
  f_n_1: the value of the step prior to that, that is n-1
 */
{
    return f_n_1 + f_n;
}

int main (int argc, char *argv[]) {
    //get input for number of steps to take
    printf("Enter an int for how much of the fibonacci sequence you want:\n");
    int n;
    scanf("%d", &n);
    if (n < 0 ){    //check of invalid input
        printf ("Error: n = %d is an invalid input. n >= 0\n", n);
        return -1;
    }
    
    //start findinging and printing fibonacci sequence
    printf("\noutput:\n");
    int f_0 = 0;    //step n=0
    printf ("\tf_0 = %d\n", f_0);
    if (n == 0) {   //exit when n=0
        return 0;
    }
    
    int f_1 = 1;    //step n=1
    printf ("\tf_1 = %d\n", f_1);
    if (n == 1) {   //exit when n=1
        return 0;
    }

    int i;          //used for ittereating over
    int f_hold;     //used to hold new value of itteration
    for (i = 1; i < n; i++){
        f_hold = fibonacci_iterate (f_0, f_1);  //find new value
        printf ("\tf_%d = %d\n", i+1, f_hold);  //print output
        f_0 = f_1;      //change values
        f_1 = f_hold;
    }
    return 0;
}
