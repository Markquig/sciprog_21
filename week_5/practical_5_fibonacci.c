#include <stdio.h>

void fibonacci_iterate (int* fn_1, int* fn)
/*provides the next step in a fibonacci sequence given:
  fn: point to the value of the previous step, that is step n
  fn_1: point to the value of the step prior to that, that is n-1
 */
{
    //change value of each object pointed too
    int hold = *fn;
    *fn += *fn_1;
    *fn_1 = hold;
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
    if (n == 0) {   //exit if n=0
        return 0;
    }
    
    int f_1 = 1;    //step n=1
    printf ("\tf_1 = %d\n", f_1);
    if (n == 1) {   //exit if n=1
        return 0;
    }
    
    int i;
    for (i = 1; i < n; i++){                //iterate until nth element reached
        fibonacci_iterate (&f_0, &f_1);     //update values
        printf ("\tf_%d = %d\n", i+1, f_1); //print output
    }
    return 0;
}

//gcc practical_5_fibonacci.c -o p_5_fibonacci.out -Wall
//./p_5_fibonacci.out 
