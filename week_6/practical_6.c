#include <stdio.h>
#include <stdlib.h>
//*
void matrix_print (double** M, int n_row, int n_col){
    int i, j;
    for (i = 0; i < n_row; i++){
        for (j = 0; j <n_col; j++){
            printf ("\t%lf", M[i][j]);
        }
        printf ("\n");  //after each row
    }
    printf ("\n");      //after end of matrix
    return;
}//*/


int main (int agrc, char* argv[]){
    int n = 5;
    int p = 3;
    int q = 4;
    
    //allocate memory and initalize
    /*I used dynamically allocated memory as it is more usable, such as passing
       by reference to print_matrix to print the results.
      In the name of efficiency, calloc should probably be replaced by malloc, but
       calloc is my preferec method to catch mistakes, and it is need to initalize
       C to 0's
     */
    int i, j, k;
    double** A = (double**) calloc(n, sizeof(double*)); //allocate for array of pointers
    for (i = 0; i < n; i++){
        A[i] = (double*) calloc (p, sizeof (double));   //allocate for 1d array
        for (j = 0; j < p; j++){
            A[i][j] = i + j;                            //initalize
        }
    }
    double** B = (double**) calloc(p, sizeof(double*)); //allocate for array of pointers
    for (i = 0; i < p; i++){
        B[i] = (double*) calloc (q, sizeof (double));   //allocate for 1d array
        for (j = 0; j < q; j++){
            B[i][j] = i - j;                            //initalize
        }
    }
    double** C = (double**) calloc(n, sizeof(double*)); //allocate for array of pointers
    for (i = 0; i < n; i++){
        C[i] = (double*) calloc (q, sizeof (double));   //allocate for 1d array
        for (j = 0; j < q; j++){
            for (k = 0; k < p; k++){
                C[i][j] += (A[i][k] * B[k][j]);         //matrix multiplication
            }
        }
    }
    
    
    //print output
    printf ("A = ");
    matrix_print (A, n, p);
    printf ("B = ");
    matrix_print (B, p, q);
    printf ("C = ");
    matrix_print (C, n, q);


    //dealocate memory
    for (i = 0; i < n; i++){
        free (A[i]);
    }
    free (A);
    for (i = 0; i < p; i++){
        free (B[i]);
    }
    free (B);
    for (i = 0; i < n; i++){
        free(C[i]);
    }
    free (C);

    
    return 0;
}

//gcd practical_6.c -o p_6.out
//./p_6.out
