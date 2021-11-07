#include <stdio.h>

int GCD_itterative (int a, int b){
    int temp;
    while (b != 0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int GCD_recursive (int a, int b){
    //printf ("\ta = %d\tb = %d\n", a, b);
    int GCD, temp;
    if (b != 0){
        temp = b;
        b = a%b;
        a = temp;
        GCD = GCD_recursive (a, b);
    }
    else {
        return a;
    }
    return GCD;
}


int main (int argc, char* argv[]){
    int a = 222;
    int b = 102;
    //222,102 = 6
    //8, 12 = 4
    
    int GCD_itt = GCD_itterative (a, b);
    int GCD_rec = GCD_recursive (a, b);
    
    printf ("GCD_itt = %d\n", GCD_itt);
    printf ("GCD_rec = %d\n", GCD_rec);
}
