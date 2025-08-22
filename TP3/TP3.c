#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Fonctions auxiliaire

//Affiche les elements du tableau
void print_int_array(int* array, int array_size){
    printf("[");
    for (int i = 0; i < array_size; i++){
        printf("%d", array[i]);
        if (i < array_size-1){
            printf(" ");
        }
    }
    printf("]\n");
}

//Renvoie un tbaleau contenant des valeur aleatoire antre 0 et 10 de taille n
int* generate_array(int n){
    int* array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        array[i] = rand() % 11;
    }
    return array;
}

//2 - Q1/2
//Renvoie un pointeur sur un tableau contenant des 0
int* init_int_array(int n){
    int* array = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        array[i] = 0;
    }
    return array;
}

//2 - Q3
//Renvoie un pointeur sur un tableau contenant a la case i la i-ieme valeur de la suite de fibo
int* init_fibo_array(int n){
    int* array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        if (i == 0){
            array[i] = 0;
        }
        else if (i == 1){
            array[i] = 1;
        }
        else{
            array[i] = array[i-1] + array[i-2];
        }
    }
    return array;
}

//2 - Q4
//Renvoie un tableau contenant en case t[i] = 2*t[i-1] + i%37 et t[0] = 1
int* init_f1_array(int n){
    int* array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        if(i == 0){
            array[i] = 1;
        }
        else{
            array[i] = 2*array[i-1] + i%37;
        }
    }
    return array;
}

//2 - Q5
//Renvoie l'indice du triplet dans la somme est maximal dans un tableau -> [4;2;1;6;3] -> 2
//On suppose que la taille du tableau >= 3
int max_array_tuple(int* array, int array_size){
    int max_tuple = 0;
    int index_max_tuple = 0;
    for (int i = 0; i < array_size-2; i++){
        if (array[i] + array[i+1] + array[i+2] > max_tuple){
            max_tuple = array[i] + array[i+1] + array[i+2];
            index_max_tuple = i;
        }
    }
    return index_max_tuple;
}

//2 - Q6.a
//Renvoie un tableau pseudo-aleatoire en utiliser la methode de fibonacci a retardement

//k est fixe et k > n ainsi pour generer la premiere valeur on fait ceci avecv k = 3 , n = 5, m = 10
/*
[v0 = 0, v1 = 1, v2 = 2] Calculons v3 = v2 + v(3-3) = v2 + v0 = 2[10] = 2
[v0 = 0, v1 = 1, v2 = 2, v3 = 2] Calculons v4 = v3 + v(4-3) = 2+1[10] = 3 
*/
int* generate_array_fibo(int n, int k, int m){
    int* array = malloc(sizeof(int)*n);
    //Initialisation de array
    for(int i = 0; i < n; i++){
        if (i <= k){
            array[i] = i;
        }
        else{
            array[i] = (array[i-1] + array[i-k]) % m;
        }
    }
    return array;
}

//2 - Q6.a
//Renvoie la valeur max dans un tableau
int max(int* array, int array_size){
    int max_value = array[0];
    for (int i = 0; i < array_size; i++){
        if (array[i] > max_value){
            max_value = array[i];
        }
    }
    return max_value;
}

//Compte le nombre d'occurance dans un tableau ou est case i il y a le nombre d'occurrance de i
int* occurrence(int* array, int array_size){
    int max_value = max(array, array_size);
    int* occ = init_int_array(max_value+1);
    for (int i = 0; i < array_size; i++){
        occ[array[i]]++;
    }
    return occ;
}

//----------------------- Algorithmes de trie ----------------------


int main(){
    srand(time(NULL));
    int array_size = 12;
    int* arr1 = init_int_array(array_size);
    //print_int_array(arr1, array_size);

    int* arr2 = init_fibo_array(array_size);
    print_int_array(arr2, array_size);

    int* arr3 = init_f1_array(array_size);
    print_int_array(arr3, array_size);

    int* arr4 = generate_array(array_size);
    print_int_array(arr4, array_size);
    printf("Indice max triplet un arr4 = %d\n", max_array_tuple(arr4, array_size));

    int array_size2 = 10;
    int modulo = 10;
    int k = 2;
    int* arr5 = generate_array_fibo(array_size2, k, modulo);
    print_int_array(arr5, array_size2);
    int max_val = max(arr5, array_size2);
    printf("Max value of arr5 = %d\n", max_val);
    int* occ = occurrence(arr5, array_size2);
    print_int_array(occ, max_val+1);

    //Liberation des objets
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
    free(occ);
    return 0;
}