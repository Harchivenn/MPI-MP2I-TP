#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Structure qui represente un nombre rationnel
struct frac_s{
    int num;
    int denom;
};
typedef struct frac_s fraction_t;

//Fonctions donne en enonce

//Initialise une fraction 
fraction_t init_fraction(int num, int denom){
    fraction_t result = {.num = num, .denom = denom};
    if (denom == 0){ // Par convention x/0 = x
        result.denom = 1;
    }
    return result;
}

//Renvoie le produit entre deux fractions
fraction_t prod_fraction(fraction_t frac1, fraction_t frac2){
    fraction_t result = {.num = frac1.num * frac2.num , .denom = frac1.denom * frac2.denom};
    return result;
}

//Initialise une fonction par reference
fraction_t* init_fraction_ref(int num, int denom){
    fraction_t* result = malloc(sizeof(fraction_t));
    result->num = num;
    if (denom == 0){
        result->denom = 1;
    }
    else{
        result->denom = denom;
    }
    return result;
}

//Fait le produit de fraction par reference
fraction_t* prod_fraction_ref(fraction_t* frac1, fraction_t* frac2){
    fraction_t* result = malloc(sizeof(fraction_t));
    result->num = frac1->num * frac2-> num;
    result->denom = frac1->denom * frac2->denom;
    return result;
}

//Fonctions auxiliaire
void print_fraction(fraction_t frac){
    printf("%d/%d\n", frac.num, frac.denom);
}

void print_fraction_ref(fraction_t* frac){
    printf("%d/%d\n", frac->num, frac->denom);
}

//Ex1.2 - Q1
//Calcule la somme de deux fractions
fraction_t sum_fraction(fraction_t frac1, fraction_t frac2){
    fraction_t result = init_fraction(1,1);
    if (frac1.denom == frac2.denom){
        result.num = frac1.num + frac2.num;
        result.denom = frac1.denom;
    }
    else{
        result.num = frac1.num * frac2.denom + frac2.num * frac1.denom;
        result.denom = frac1.denom * frac2.denom;
    }
    return result;
}

//Ex1.2 - Q2
//Renvoie l'oppose de la fraction i.e (-1)*frac
fraction_t opposite_fraction(fraction_t frac){
    fraction_t result = init_fraction(frac.num, frac.denom);
    if((frac.num < 0 && frac.denom < 0) || (frac.num > 0 && frac.denom < 0)){ // -x/-y ou x/-y -> (-1)*y
        result.denom = (-1)*frac.denom;
        return result;
    }
    else{ // -x/y ou x/y -> (-1)*x
        result.num = (-1)*frac.num;
        return result;
    }
}

//Ex1.2 - Q3
//Renvois la soustraction de deux fractions on remarque que a-b = a + (-b)
fraction_t substract_fraction(fraction_t frac1, fraction_t frac2){
    fraction_t result = sum_fraction(frac1, opposite_fraction(frac2));
    return result;
}

//Ex1.2 - Q4
//Renvoie l'inverse d'une fraction passe en reference
fraction_t* inverse_fraction(fraction_t* frac){
    fraction_t* result = init_fraction_ref(frac->denom, frac->num); //Definit un comportement dans le cas ou le denominateur vaut 0
    return result;
}

//Ex1.2 - Q5 
//Renvoie la division entre deux fractions
fraction_t* divide_fraction(fraction_t* frac1, fraction_t* frac2){
    fraction_t* frac1_def = init_fraction_ref(frac1->num, frac1->denom);
    fraction_t* frac2_inv_def = inverse_fraction(frac2);
    fraction_t* result = prod_fraction_ref(frac1_def, frac2_inv_def);
    free(frac1_def);
    free(frac2_inv_def);
    return result;
}

//Ex1.2 - Q6
//Calcule le pgcd de deux nombres
int pgcd(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return pgcd(b, a%b);
    }

}

void simplify_fraction(fraction_t* frac){
    int m = pgcd(frac->num, frac->denom);
    frac->num = frac->num/m;
    frac->denom = frac->denom/m;
}

//Empaqueter la taille d'un tableau dans son contenu
//Ex1.3 - Q1
struct int_array_s{
    int size;
    int* data;
};
typedef struct int_array_s int_array_t;

//Ex1.3 - Q2
//Initialsise un tableau contenant des 0 (en valeur et en reference)
int_array_t init_int_array(int size){
    int* data = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++){
        data[i] = 0;
    }
    int_array_t result = {.size = size, .data = data};
    return result;
}

//Ex1.3 - Q3
int_array_t* init_int_array_ref(int size){
    int_array_t* int_array = malloc(sizeof(int_array_t));
    int* data = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++){
        data[i] = 0;
    }
    int_array->size = size;
    int_array->data = data;
    return int_array;
}

//Ex 1.3 - Q4
//Affiche les elements du tableau (en valeur et en reference)
void print_int_array(int_array_t array){
    printf("[");
    for (int i = 0; i < array.size; i++){
        printf("%d", array.data[i]);
        if (i < array.size-1){
            printf(" ");
        }
    }
    printf("]\n");
}

void print_int_array_ref(int_array_t* array){
    printf("[");
    for (int i = 0; i < array->size; i++){
        printf("%d", array->data[i]);
        if (i < array->size-1){
            printf(" ");
        }
    }
    printf("]\n");
}

//Ex1.3 - Q5
// Change le contenu dans la case d'indice index par value dans array
void set_value(int_array_t array, int index, int value){
    assert (index >= 0 && index < array.size); //verifie la validite de l'acces a la case
    array.data[index] = value;
}

//Ex1.3 - Q6
//Renvoie le contenu de la case index dans array
int get_value(int_array_t array, int index){
    assert (index >= 0 && index < array.size);
    return array.data[index];    
}

//Ex1.3 - Q7
void free_array(int_array_t array){
    free(array.data);
}

//Ex1.3 - Q8
void free_array_ref(int_array_t* array){
    free(array->data);
    free(array);
}

//Ex1.3 - Q9
//Renvoie un tableau contenant les size premiers valeur de fibonacci
int_array_t init_fibonacci(int size){
    int_array_t fibo_array = init_int_array(size);
    for (int i = 0; i < size; i++){
        if (i == 0){
            fibo_array.data[i] = 0;
        }
        else if (i == 1){
            fibo_array.data[i] = 1;
        }
        else{
            fibo_array.data[i] = fibo_array.data[i-1] + fibo_array.data[i-2];
        }
    }
    return fibo_array;
}

//Ex1.3 - Q10
//Renvoie le max entre deux valeurs
int max(int n_1, int n_2){
    if (n_1 < n_2){
        return n_2;
    }
    else{
        return n_1;
    }
}

//Renvoie un tableau contenant en case i la somme des deux tableaux
int_array_t sum_int_array(int_array_t array1, int_array_t array2){
    int max_size = max(array1.size, array2.size);
    int_array_t sum_array = init_int_array(max_size);
    for (int i = 0; i < max_size; i++){
        if (i >= array1.size){
            sum_array.data[i] = array2.data[i];
        }
        else if (i >= array2.size){
            sum_array.data[i] = array1.data[i];
        }
        else{
            sum_array.data[i] = array1.data[i] + array2.data[i];
        }
    }
    return sum_array;
}
