#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* allocatearray (int size) {
    int* ret = calloc (size, sizeof (int));
    return ret;
}

void deallocatearray (int* array) {
/*frees memory allocated in allocatearray*/
    free (array);
    return;
}

void fillwithones (int* array, int size){
/*loops through 1d array and sets all elements to 1*/
    int i;
    for (i = 0; i < size; i++){
        array[i] = 1;
    }
    return;

}

void printarray (int* array, int size){
/*loops through 1d array to print each element*/
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
/*could have used deallocatearray above, but i like to have a seporate function
   incase approx_e changes*/
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
/*prints results of approximation & error*/
    int i;
    for (i = 0; i < size; i++){
        printf ("\tf(%d) = %lf\t\tf(%d) - e = %.5e\n",
                i,                  //order of approximation
                array[i],           //approximation
                i,                  //order of approximation
                array[i]-exp(1));   //error in approximation
    }
    printf ("\n");      //end output
    return;
}




int main (int argc, char* argv[]){
    int size;
    printf("Enter order of approximation: ");
    scanf("%d", &size);
    
    int* A;
    A = allocatearray (size);   //create memory to hold values
    fillwithones (A, size);     //initalise elements to 1's
    
    double* f = approx_e(A, size);  //returns array with approximates of e
    printarray_double (f, size+1);  //print array f
    print_results (f, size+1);      //print f with index & error in approx
    
    //free memory
    deallocate_approx_e (f);
    deallocatearray (A);
    
    return 0;
}

//gcc practical_7.c -o p_7.out -lm -Wall
//./p_7.out 
