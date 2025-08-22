#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Fonctions auxiliaires
//Calcule n^k
int puissance(int n, int k){
    if (k == 0){
        return 1;
    }
    else if(k % 2 == 0){
        return puissance(n, k/2) * puissance(n, k/2);
    }
    else{
        return n * puissance(n, (k-1)/2) * puissance(n, (k-1)/2);
    }
}

//Renvoie un tableau de taille grid_size contenant des 1 ou 0 aleatoirement
void generate_grid(int grid[], int grid_size){
    for (int i = 1; i < (grid_size-1); i++){
        grid[i] = rand() % 2;
    }
}

//Renvoie le plus petit puissance de b pour n
int plus_petit_k_base(int n, int b){
    int k = 0;
    while(n - puissance(b,k) >= 0){
        k++;
    }
    return k;
}


//2.3 - Q2
//Affiche les elements du tableau
void print_int_array(int array[], int array_size){
    printf("[");
    for (int i = 0; i < array_size; i++){
        printf("%d", array[i]);
        if (i < array_size-1){
            printf(" ");
        }
    }
    printf("]\n");
}

//2.3 - Q3
//Renvoie le grand indice tel que 2^k < i si 2^k = i -> 0
int f(int i){
    int k = 1;
    while(puissance(2, k) <= i){
        if (puissance(2, k) == i){
            return 0;
        }
        k++;
    }
    return k-1;
}

//Initialise un tableau contenant f(i) en i
void init_array(int array[], int array_size){
    for (int i = 0; i < array_size; i++){
        array[i] = f(i);
    }
}

//2.3 - Q4
//Renvoie la somme des valeur du tableau
int int_array_sum(int array[], int array_size){
    int sum = 0;
    for (int i = 0; i < array_size; i++){
        sum = sum + array[i];
    }
    return sum;
}

//2.3 - Q5
//Renvoie le minimum du tableau
int int_array_min(int array[], int array_size){
    int min = array[0];
    for (int i = 0; i < array_size; i++){
        if (array[i] < min){
            min = array[i];
        }
    }
    return min;
}

//2.3 - Q6
//Renvoie le maximum du tableau
int int_array_max(int array[], int array_size){
    int max = array[0];
    for (int i = 0; i < array_size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

//2.3 - Q7
//Tous pareil mais avec des type double
void print_double_array(double array[], int array_size){
    printf("[");
    for (int i = 0; i < array_size; i++){
        printf("%f", array[i]);
        if (i < array_size-1){
            printf(" ");
        }
    }
    printf("]\n");
}


void init_double_array(double array[], int array_size){
    for (int i = 0; i < array_size; i++){
        array[i] = (double)f(i);
    }
}

double double_array_sum(double array[], int array_size){
    double sum = 0.;
    for (int i = 0; i < array_size; i++){
        sum = sum + array[i];
    }
    return sum;
}

double double_array_min(double array[], int array_size){
    double min = array[0];
    for (int i = 0; i < array_size; i++){
        if (array[i] < min){
            min = array[i];
        }
    }
    return min;
}

double double_array_max(double array[], int array_size){
    double max = array[0];
    for (int i = 0; i < array_size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

/*-------Automate cellulaires-------------*/

//2.5 - Q4
//Applique la regle associe au triplet d'etats d'entrer
int automata_rule(int left_cell, int current_cell, int right_cell){
    if (left_cell == 0 && current_cell == 0 && right_cell == 0){ // 0 0 0 -> 0
        //return 0;
        return 1;
    }
    else if (left_cell == 0 && current_cell == 0 && right_cell == 1){ // 0 0 1 -> 1
        //return 1;
        return 0;
    }
    else if (left_cell == 0 && current_cell == 1 && right_cell == 0){ // 0 1 0 -> 0
        return 0;
    }
    else if (left_cell == 0 && current_cell == 1 && right_cell == 1){ // 0 1 1 -> 0
        return 1;
    }
    else if (left_cell == 1 && current_cell == 0 && right_cell == 0){ // 1 0 0 -> 1
        return 0;
    }
    else if (left_cell == 1 && current_cell == 0 && right_cell == 1){// 1 0 1 -> 0
        return 0;
    }
    else if (left_cell == 1 && current_cell == 1 && right_cell == 0){// 1 1 0 -> 0
        return 1;
    }
    else{
        return 0;
    }
}

//2.5 - Q5
//Met a jour une ligne en remplissant updated_grid suivant les regles de automata_rule
void update_state(int grid_now[], int updated_grid[], int grid_size){
    //print_int_array(grid_now, grid_size);
    for (int i = 0; i < grid_size; i++){
        if(i == 0){
            updated_grid[i] = automata_rule(grid_now[grid_size-1], grid_now[i], grid_now[i+1]);
        }
        else if (i == grid_size-1){
            updated_grid[i] = automata_rule(grid_now[i-1], grid_now[i], grid_now[0]);
        }
        else{
            //printf("pass\n");
            updated_grid[i] = automata_rule(grid_now[i-1], grid_now[i], grid_now[i+1]);
        }
    }
}

//2.5 - Q6
//Met a joue sans utiliser de tableau annexe suivant les meme regles qu'en haut
void update_state_place(int grid[], int grid_size){
    int first_cell_state = grid[0];
    int cell_state_now = grid[0];
    int left_cell_state = grid[grid_size-1];
    for (int i = 0; i < grid_size; i++){
        if (i == grid_size-1){
            grid[i] = automata_rule(left_cell_state, grid[i], first_cell_state);
        }
        else{
            cell_state_now = grid[i];
            grid[i] = automata_rule(left_cell_state, grid[i], grid[i+1]);
            left_cell_state = cell_state_now;
        }
    }
}

//2.5 - Q9
//Affiche dans le terminal une configuration * -> 1 et " " -> 0
void print_grid_state(int grid[], int grid_size){
    printf("|");
    for (int i = 0; i < grid_size; i++){
        if (grid[i] == 1){
            printf("*");
        }
        else{
            printf(" ");
        }
    }
    printf("|\n");
}

//2.5 - Q7
//Fait une copy de arr1 dans arr2
void copy_array(int arr1[], int arr2[], int array_size){
    for (int i = 0; i < array_size; i++){
        arr2[i] = arr1[i];
    }
}

//Simule l'evolution a partir de la configuration initial et des regle fixe
void run_automata(int init_grid[], int previous_step_grid[], int next_step_grid[], int grid_size, int nb_steps){
    previous_step_grid = init_grid;
    for (int i = 0; i < nb_steps; i++){
        print_grid_state(previous_step_grid, grid_size);
        update_state(previous_step_grid, next_step_grid, grid_size);
        copy_array(next_step_grid, previous_step_grid, grid_size);
    }
}

//La meme chose mais en place
void run_automata_place(int grid[], int grid_size, int nb_step){
    for (int i = 0; i < nb_step; i++){
        print_grid_state(grid, grid_size);
        update_state_place(grid, grid_size);
    }
}

//Cree un fichier image au dimension de la grille et du nombre d'etape a afficher et renvoie ce fichier
FILE* init_picture(char* name, int grid_size, int nb_steps){
    FILE* ppm_file = fopen(name, "w");

    if(!ppm_file){
        printf("Cannot create or open this file \n");
    }

    fprintf(ppm_file, "P1\n");
    fprintf(ppm_file, "%d %d\n", grid_size, nb_steps);
    return ppm_file;
}

//Ecrit dans le fichier image les information necessaire a l'affichage de la grille contenu dans grid_state
void print_state_to_file(FILE* f, int grid_state[], int grid_size){
    for (int i = 0; i < grid_size; i++){
        if (grid_state[i] == 0){
            fprintf(f, "0 ");
        }
        else{
            fprintf(f, "1 ");
        }
    }
    fprintf(f, "\n");
}

//Sauvergarde le fichier
void save_picture(FILE* f){
    fclose(f);
}

//2.6 - Q1
//Simule l'evolution d'un automate mais le resultat est afficher dans un fichhier .pbm
void run_automata_with_picture(int grid[], int grid_size, int nb_steps){
    FILE* file1 = init_picture("Automata/Automata2.ppm", grid_size, nb_steps);
    for (int i = 0; i < nb_steps; i++){
        print_state_to_file(file1, grid, grid_size);
        update_state_place(grid, grid_size);
    }
    save_picture(file1);
}

//2.8 - Q6
//Convertit un tableau d'entier representation binaire en entier avec le premier indice comme le plus puissance de k de la representation
int convert_bin_to_int(int t[]){
    int k = t[0];
    int value = 0;
    for (int i = 1; i <= (k+1);  i++){
        value = value + t[i] * puissance(2,(i-1));
    }
    return value;
}

//2.8 - Q7
//Renvoie le plus petit puissance de 2 pour n
int plus_petit_k(int n){
    int k = 0;
    while (n - puissance(2, k) >= 0){
        k++;
    }
    return k;
}

//Convertit un entier en binaire a l'aide d'un tableau
void convert_int_to_bin(int n, int bin[]){
    int k = plus_petit_k(n);

    int d_j = n%2;
    int n_partielle = d_j;
    bin[0] = d_j;
    for (int j = 1; j < k; j++){
        d_j = ((n - n_partielle)/puissance(2, j)) % 2;
        n_partielle = n_partielle + (d_j * puissance(2, j));
        bin[j] = d_j;
    }
}

//2.8 - Q8
//Applique le regle associe "rule_id" pour ce voisinnage
int apply_rule_on_cell(int left_cell_state, int current_state, int right_cell_state, int rule_id){
    int nei_bin[4] = {2, left_cell_state, current_state, right_cell_state};
    int neightbour_num = convert_bin_to_int(nei_bin);

    int rule_bin[8] = {0};
    convert_int_to_bin(rule_id, rule_bin);
    return rule_bin[7-neightbour_num];

}

//2.8 - Q9
//Met a jour la ligne d'automate
void update_grid(int grid[], int grid_size, int rule_id){
    int first_cell_state = grid[0];
    int cell_state_now = grid[0];
    int left_cell_state = grid[grid_size-1];
    for (int i = 0; i < grid_size; i++){
        if (i == grid_size-1){
            grid[i] = apply_rule_on_cell(left_cell_state, grid[i], first_cell_state, rule_id);
        }
        else{
            cell_state_now = grid[i];
            grid[i] = apply_rule_on_cell(left_cell_state, grid[i], grid[i+1], rule_id);
            left_cell_state = cell_state_now;
        }
    }
}

//simule l'automate a l'aide des regles fixe et une configuration initial 
void run(FILE* file1, int grid[], int grid_size, int nb_steps, int rule_id){
    for (int i = 0; i < nb_steps; i++){
        print_state_to_file(file1, grid, grid_size);
        update_grid(grid, grid_size, rule_id);
    }
}

//2.8 - Q10
//Cree un fichier qui simule chaque regle pour une configuration aleatoire
void generate_all_rules(char* filename, int grid_size, int nb_steps){
    FILE* file1 = init_picture(filename, grid_size, nb_steps*256);
    for (int i = 0; i < 256; i++){
        int init_grid[64] = {0};
        generate_grid(init_grid, grid_size);
        run(file1, init_grid, grid_size, nb_steps, i);
    }
    save_picture(file1);
}

int main(){
    srand(time(NULL));
    //2.3 - Q1
    int arr1[10];
    for (int i = 0; i < 10; i++){
        arr1[i] = i;
    }
    print_int_array(arr1, 10);
    printf("Plus petit k pour 4 : %d \n", f(4));
    printf("Plus petit k pour 15 : %d \n", f(15));

    int arr2[10];
    init_array(arr2, 10);
    print_int_array(arr2, 10);

    printf("sum of arr1 : %d\n", int_array_sum(arr1, 10));
    printf("sum of arr2 : %d\n", int_array_sum(arr2, 10));

    printf("min of arr1 : %d\n", int_array_min(arr1, 10));
    printf("min of arr2 : %d\n", int_array_min(arr2, 10));

    printf("max of arr1 : %d\n", int_array_max(arr1, 10));
    printf("max of arr2 : %d\n", int_array_max(arr2, 10));

    //Pour des doubles
    double arr3[10] = {0};
    double arr4[10] = {0};

    for (int i = 0; i < 10; i++){
        arr3[i] = (double)i;
    }
    print_double_array(arr3, 10);
    init_double_array(arr4, 10);
    print_double_array(arr4, 10);

    printf("sum of arr3 : %f\n", double_array_sum(arr3, 10));
    printf("sum of arr4 : %f\n", double_array_sum(arr4, 10));

    printf("min of arr3 : %f\n", double_array_min(arr3, 10));
    printf("min of arr4 : %f\n", double_array_min(arr4, 10));

    printf("max of arr3 : %f\n", double_array_max(arr3, 10));
    printf("max of arr4 : %f\n", double_array_max(arr4, 10));

    /*-------Tests Automate cellulaires-------------*/
    //int prev_grid[64] = {0};
    //int next_grid[64] = {0};
    int init_grid[256] = {0};
    
    int grid_size = 256;
    int nb_steps = 1000;

    generate_grid(init_grid, grid_size);
    //run_automata(init_grid, prev_grid, next_grid, grid_size, nb_steps);
    printf("------------------En place----------------\n");
    //run_automata_place(init_grid, grid_size, nb_steps);

    run_automata_with_picture(init_grid, grid_size, nb_steps);

    /*Generation de toute les regle pour les automates*/
    int arr5[] = {2, 0, 0, 0};
    printf("000 = %d\n", convert_bin_to_int(arr5));

    int arr6[8] = { 0 };
    convert_int_to_bin(146, arr6);
    print_int_array(arr6, 8);

    printf("0 0 0 on 10010010(146) = %d\n", apply_rule_on_cell(0, 0, 0, 146));

    generate_all_rules("Automata/all_automata.ppm", 64, 100);
    //run(init_grid, grid_size, nb_steps, 146);

    return 0;   
}