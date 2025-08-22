#include <stdbool.h>

struct node_s{
    int value;
    struct node_s* next;
};
typedef struct node_s node_t;

typedef node_t* int_list_t;

//Cree un maillon contenant un entier
node_t* create_node(int value);

/*
Cree un pointeur vers une liste vide 
NB : car une fonctions fait une copie locale de int_list_t*, 
donc on ne peut modifier que ce qui pointe ici c'est une int_list_t donc ok sinon c'etait des node_t, 
ca marche pas car les noeud suivant sont des node_t*
*/
int_list_t* create_empty_list();

//Ajoute un element a une liste
void add(int_list_t* list, int value);

//Renvoie l'element en tete de liste
int head(int_list_t* list);

//Renvoie la liste qui suit le premier element
int_list_t* tail(int_list_t* list);

//Affiche le contenu d'une liste
void print_int_list(int_list_t* list);

//Libere l'espace memoire associe a la liste
void free_list(int_list_t* list);

//Supprime le premier element de la liste
void remove_head(int_list_t* list);

//Renvoie la taille de la liste
int lenght(int_list_t* list);

//Renvoie une liste dont l'ordre des element sont inverser
int_list_t* copy_reverse(int_list_t* list);

//Renvoie une copie de la liste
int_list_t* copy(int_list_t* list);

//Verifie si les deux listes son egales
bool list_equal(int_list_t* list1, int_list_t* list2);

//Renvoie la liste concatene de la list1 a la list2
int_list_t* cat(int_list_t* list1, int_list_t* list2);