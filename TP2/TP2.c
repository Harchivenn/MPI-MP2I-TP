#include <stdio.h>
#include <stdlib.h>

//Ex4 - Q1
//Incremente la valeur pointer par le pointeur
void increment(int* p){
    *p = *p + 1;
}

//Ex4 - Q2
//Renvoie le minimum entre a et b
int min_value(int a, int b){
    if (a <= b){
        return a;
    }
    else{
        return b;
    }
}

//Incremente la valeur du pointeur le plus petit
void dual_increment(int* p_x, int* p_y){
    if (min_value(*p_x, *p_y) == *p_x){
        increment(p_x);
    }
    else{
        increment(p_y);
    }
}

//Ajoute aux pointeur min et max entre x et y
void min_and_max(int x, int y, int* min, int* max){
    if (x <= y){
        *min = x;
        *max = y;
    }
    else{
        *min = y;
        *max = x;
    }
}

//Ajoute aux pointeur le division euclidienne entre a et b
void euclidean_div(int a, int b, int *q, int *r){
    *r = a%b;
    *q = a/b;
}

int main(){
    int x = 1;
    int* p_x = &x;
    printf("x = %d before \n", *p_x);
    increment(p_x);
    printf("x = %d after \n", *p_x);

    int y = 11;
    int* p_y = &y;
    printf("x = %d | y = %d \n", *p_x, *p_y);
    dual_increment(p_x, p_y);
    printf("x = %d | y = %d \n", *p_x, *p_y);

    int min_tmp = 2;
    int max_tmp = 3;
    int* min = &min_tmp;
    int* max = &max_tmp;
    //printf("x = %d | y = %d | min = %d | max = %d \n", x, y, *min, *max);
    min_and_max(x,y,min,max);
    printf("x = %d | y = %d | min = %d | max = %d \n", x, y, *min, *max);

    int a = 34;
    int b = 6;
    int r_tmp = 1;
    int q_tmp = 1;
    int* q = &q_tmp;
    int* r = &r_tmp;
    euclidean_div(a,b,q,r);
    printf("a = %d | b = %d | q = %d | r = %d \n", a, b, *q, *r);
    return 0;
}