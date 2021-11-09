#include <stdio.h>
#include <stdlib.h>
//#include <fstream>

#include "magic_square.h"

//*
int** read_matrix (FILE* input_file, int* size){
    fscanf (input_file, "%d", size);
    
    int** ret = calloc ( (*size), sizeof (int*));
    
    int i, j;
    for (i = 0; i < (*size); i++){
        ret[i] = calloc ( (*size), sizeof (int));
        for (j = 0; j< (*size); j++){
            fscanf (input_file, "%d", &ret[i][j]);
        }
    }
    
    return ret;
}//*/

//*
void read_matrix_deallocate (int** M, int size){
    int i;
    for (i = 0; i < size; i++){
        free (M[i]);
    }
    free (M);
}//*/

//code from practical_6_2.c
void matrix_print (int** M, int n_row, int n_col){
    int i, j;
    for (i = 0; i < n_row; i++){
        for (j = 0; j < n_col; j++){
            printf ("\t%d", M[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
    return;
}//*/



int main (int argc, char* argv[]){
    FILE* input_file;
    int size;
    input_file = fopen (argv[1], "r");
    int** matrix = read_matrix (input_file, &size);
    fclose (input_file);
    matrix_print (matrix, size, size);
    
    int test = isMagicSquare (matrix, size);
    
    printf ("test = %d\n", test);
    
    
    read_matrix_deallocate (matrix, size);
    
    
    return 0;
}
