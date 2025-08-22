struct dyn_int_array_s{
    int size;
    int capacity;
    int* data;
};
typedef struct dyn_int_array_s dyn_int_array_t;

//Cree un tableau redimensionnable de taille 0 et vide
dyn_int_array_t* create_dyn_array(int capacity);

//Ajoute un element a la fin du tableau et met a jour le taille de la liste (et verfier si c'est possible)
void push_value(dyn_int_array_t* array, int value);

//Supprime le dernier element du tableau et le renvoie
int pop_value(dyn_int_array_t* array);

//Initialise un tableau vide ou les nb_elem premier element contient la valeur value
void fill_array(dyn_int_array_t* array, int nb_elem, int value);

//Renvoie l'element en position de l'index verifie si l'element est accessible
int get_value(dyn_int_array_t* array, int index);

//Fixe le contenu de la case de numero index a value
void set_value(dyn_int_array_t* array, int index, int value);

//Affiche le contenu des cases occupee par le tableau
void print_dyn_array(dyn_int_array_t* array);

//Libere la memoire reserve par le tableau dynamique
void free_dyn_array(dyn_int_array_t* array);

//Modifie la capacite d'un tableau dynamique
void change_capacity(dyn_int_array_t* array, int new_capacity);

//Insere un element en decalant tous les elements a sa droite
void insere_at(dyn_int_array_t* array, int index, int value);

//Supprime un element et decale les elements de sa droite a gauche
void delete_at(dyn_int_array_t* array, int index);

//Trie un tableau (par insertion)
dyn_int_array_t* insertion_sort(dyn_int_array_t* array);

//Somme les elements des deux tableaux independamment de la taille
dyn_int_array_t* sum_dyn_array(dyn_int_array_t* array1, dyn_int_array_t* array2);

//Multiplie les elements des deux tableaux independants de la taille
dyn_int_array_t* prod_dyn_array(dyn_int_array_t* array1, dyn_int_array_t* array2);