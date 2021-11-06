#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* allocatearray (int size) {
    int* ret = calloc (size, sizeof (int));
    return ret;
}

void deallocatearray (int* array) {
    free (array);
    return;
}

void fillwithones (int* array, int size){
/*sets all elements of 1d array to 1's*/
    int i;
    for (i = 0; i < size; i++){
        array[i] = 1;
    }
    return;

}

void printarray (int* array, int size){
/*prints 1d array*/
    int i;
    for (i = 0; i < size; i++){
        printf ("%d, ", array[i]);
    }
    printf ("\n");
    return;
}

double* approx_e (int* x,int size){
    double* f = calloc (size+1, sizeof (double));
    f[0] = 1;
    int i;
    int factorial = 1;
    for (i = 1; i <= size; i++){
        factorial *=i;
        f[i] = f[i-1] + (pow (x[i-1], i))/factorial;
    }
    return f;
}

void deallocate_approx_e (double* array){
    free(array);
}

void printarray_double (double* array, int size){
/*prints 1d array*/
    int i;
    for (i = 0; i < size; i++){
        printf ("%lf, ", array[i]);
    }
    printf ("\n");
    return;
}

void print_results (double* array, int size){
/*prints 1d array*/
    int i;
    for (i = 0; i < size; i++){
        printf ("\tf(%d) = %lf\t\tf(%d) - e = %.5e\n",
                i, array[i], i, array[i]-exp(1));
    }
    printf ("\n");
    return;
}




int main (int argc, char* argv[]){
    int size;
    printf("Enter order of approximation: ");
    scanf("%d", &size);
    
    int* A;
    A = allocatearray (size);
    //*
    //printarray (A, size);
    fillwithones (A, size);
    //printarray (A, size);//*/
    
    double* f = approx_e(A, size);
    //printarray_double (f, size+1);
    print_results (f, size+1);
    
    deallocate_approx_e (f);
    deallocatearray (A);
    
    return 0;
}
