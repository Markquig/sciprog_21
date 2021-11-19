#include <stdio.h>

int GCD_itterative (int a, int b){
    int temp;           //holds value of b when updateing
    while (b != 0){     //only if GCD has not been reached
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int GCD_recursive (int* a, int* b){
/*Pass by referenct to avoid creation of new varaibles each time
  Only new variable created is temp*/
    int temp;
    if (*b != 0){   //when GCD was not been reached
        temp = *b;
        (*b) = (*a)%(*b);
        (*a) = temp;
        return GCD_recursive (a, b);    //quick escape when returned value passed
    }
    else {          //when GCD has been reached
        return *a;
    }
}


int main (int argc, char* argv[]){
    //input values
    int a = 222;
    int b = 102;
    //222,102 = 6       //test values
    //8, 12 = 4
    
    //find GCD by both functions
    int GCD_itt = GCD_itterative (a, b);
    int a_pass = a, b_pass = b;     //pass these so a & b remain unchanged
    int GCD_rec = GCD_recursive (&a_pass, &b_pass);
    
    //print output
    printf ("GCD_itt = %d\n", GCD_itt);
    printf ("GCD_rec = %d\n", GCD_rec);
    
    return 0;
}

//gcc practical_8.c -o p_8.out -Wall
//./p_8.out 
