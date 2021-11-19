#include <stdio.h>
#include <stdlib.h>
//#include <fstream>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC

#include "magic_square.h"

//*
int** read_matrix (FILE* input_file, int* size){
    fscanf (input_file, "%d", size);                //read in size of matrix
    
    int** ret = calloc ( (*size), sizeof (int*));   //hold matrix to pass out
    int test = 1;       //used to check if end of file had been returened
    int i, j;   //loop over rows and cols
    for (i = 0; (i < (*size)) & (test != EOF); i++){
        ret[i] = calloc ( (*size), sizeof (int));   //memory for row
        for (j = 0; (j < (*size)) & (test != EOF); j++){
            test = fscanf (input_file, "%d", &ret[i][j]);   //read in one number
        }
    }
    
    if (test == EOF) {
        printf ("Error, incorect matrix size provided\n");
    }
    
    return ret; //pass read in matrix
}//*/

//*
void read_matrix_deallocate (int** M, int size){
/*frees memory allocated by read_matrix*/
    int i;
    for (i = 0; i < size; i++){
        free (M[i]);
    }
    free (M);
}//*/

//code from practical_6.c
void matrix_print (int** M, int n_row, int n_col){
    int i, j;
    for (i = 0; i < n_row; i++){
        for (j = 0; j < n_col; j++){
            printf ("\t%d", M[i][j]);
        }
        printf ("\n");  //new line at end of row
    }
    printf ("\n");      //again to seproate output
    return;
}//*/


/*Argubly I should have created a struct to hold the matrix and had size
   but since this is such a small task and I only have to deal with one
   matrix this would have been a bit much.
  Instead I passed the size by reference so that the one function can to
   all the reading from the file
  Mayby I should have passed the argv to read_matrix, but I just like to
   keep argv in the main when possable*/

//*
int main (int argc, char* argv[]){
    
    FILE* input_file;   //use to acces file
    int size;           //holds dimension of matrix
    input_file = fopen (argv[1], "r");
    int** matrix = read_matrix (input_file, &size);
    fclose (input_file);    //stop reading from the file
    //matrix_print (matrix, size, size);
    
    int test = isMagicSquare (matrix, size);    //check from magic square
    
    //printf ("test = %d\n", test);               //print result
    if (test == 1) {
        printf ("The provided matrix is a magic square\n");
    }
    else {
        printf ("The provided matrix is not a magic square\n");
    }
    
    read_matrix_deallocate (matrix, size);      //free memory
    
    
    return 0;
}//*/

/* to test run time
int main (int argc, char* argv[]){
    

    FILE* input_file;   //use to acces file
    int size;           //holds dimension of matrix
    input_file = fopen (argv[1], "r");
    int** matrix = read_matrix (input_file, &size);
    fclose (input_file);    //stop reading from the file

    clock_t begin = clock();
    int i;
    int num_loops = 100;
    for (i = 0; i < 100; i++){
        //matrix_print (matrix, size, size);
        
        int test = isMagicSquare (matrix, size);    //check from magic square
        
        //printf ("test = %d\n", test);               //print result
        
    }
    clock_t end = clock();
    printf("Average time spent on each run was %.2e seconds",
           (double)(end - begin) / (CLOCKS_PER_SEC*num_loops));


    read_matrix_deallocate (matrix, size);      //free memory
    
    return 0;
}//*/




/*isMagicSquare is of O(n^2)*/

//main.c -o p_9.out
//./p_9.out input.txt 
//./p_9.out input_2.txt 
//./p_9.out input_52_2_2,570,136,705.txt 
