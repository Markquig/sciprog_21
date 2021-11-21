#include <stdio.h>
#include <stdlib.h>

int* initalize_rod (int size, int first){
    int* rod = calloc (size+1, sizeof(int));
    if (first == 1){    //only when it's the first rod
        int i;
        for (i = 0; i < size; i++){
            rod[i] = (size-i);
        }
    }
    return rod;
}

void free_initalize_rod (int* rod){
/*deallocates memory from initalize_rod*/
    free (rod);
}

void print_rod (int* rod, int size){
    int i;
    for (i = 0; i < size; i++){
        if (rod[i] == 0 ){  //when element is empty
            printf ("-, ");
        }
        else {
            printf ("%d, ", rod[i]);    //disc size
        }
    }
    printf ("\n");
}

void print_all_rods (int* rod_1, int* rod_2, int* rod_3, int size){
    printf ("rod_1:\t");
    print_rod (rod_1, size);
    printf ("rod_2:\t");
    print_rod (rod_2, size);
    printf ("rod_3:\t");
    print_rod (rod_3, size);
    printf ("\n");
}

void move_rods (int* rod_giver, int* rod_taker){
    int i, j;
    for (i = 0; ; i++){ //find last element of rod_giver
        if (rod_giver[i] == 0){
            i--;
            break;
        }
    }
    for (j = 0; ; j++){ //find last element of rod_taker
        if (rod_taker[j] == 0){
            break;
        }
    }
    
    //swap disc
    rod_taker[j] = rod_giver[i];
    rod_giver[i] = 0;
}

/*
void hanoi (int n, int source, int dest, int mid){
    if (n == 1){
        printf ("move disc %d from %d to %d\n", n, source, dest);
    }
    else {
        hanoi (n-1, source, mid, dest);
        printf ("move disc %d from %d to %d\n", n, source, dest);
        hanoi (n-1, mid, dest, source);
    }
}//*/

//*
void hanoi (int n, int* rod_giver, int* rod_taker, int* rod_other,
            int giver, int taker, int other){
    if (n == 1){    //when at last disc
        printf ("from rod_%d move disc %d to rod_%d\n", giver, n, taker);
        move_rods (rod_giver, rod_taker);
    }
    else {          //other discs
        hanoi (n-1, rod_giver, rod_other, rod_taker, giver, other, taker);
        printf ("from rod_%d move disc %d to rod_%d\n", giver, n, taker);
        move_rods (rod_giver, rod_taker);
        hanoi (n-1, rod_other, rod_taker, rod_giver, other, taker, giver);
    }
}//*/


int main (int argc, char* argv[]){
    int n = 5;
    
    //create rods
    int* rod_1 = initalize_rod (n, 1);
    int* rod_2 = initalize_rod (n, 0);
    int* rod_3 = initalize_rod (n, 0);
    
    
    //print_all_rods (rod_1, rod_2, rod_3, n);
    
    //hanoi (n, 1, 3, 2);
    hanoi (n, rod_1, rod_3, rod_2, 1, 3, 2);    //find steps
    printf ("\n");
    //print_all_rods (rod_1, rod_2, rod_3, n);
    
    //free memory
    free_initalize_rod (rod_1);
    free_initalize_rod (rod_2);
    free_initalize_rod (rod_3);
    
    return 0;
}

//gcc practical_10.c -o p_10.out -Wall
//./p_10.out 

/*I know that the arrays rod_1, rod_2, rod_3, but they were usfull to make
   sure I was updating them corectly, and can show that the steps to work*/
