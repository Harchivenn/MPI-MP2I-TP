#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"

void print_node(node_t* node){
    printf("Value : %d\n", node->value);
}

int main(){
    node_t* node1 = create_node(5);
    int_list_t* list1 = create_empty_list();
    //print_node(node1);
    add(list1, 6);
    add(list1, 7);
    //print_node(list1);
    print_int_list(list1);
    printf("Valeur de la tete de la liste : %d \n", head(list1));
    int_list_t* list1_tail = tail(list1);
    print_int_list(list1_tail);
    print_int_list(list1);
    remove_head(list1);
    print_int_list(list1);
    add(list1, 3);
    add(list1, 12);
    print_int_list(list1);
    printf("Lenght of list1 : %d \n", lenght(list1));

    int_list_t* reverse_list1 = copy_reverse(list1);
    print_int_list(reverse_list1);

    int_list_t* copy_list1 = copy(list1);
    print_int_list(list1);

    printf("Is list1 == reverse_list ? : %d\n", list_equal(list1, reverse_list1));
    printf("Is list1 == copy_list1 ? : %d\n", list_equal(list1, copy_list1));

    int_list_t* cat_list = cat(list1, reverse_list1);
    print_int_list(cat_list);  

    //Espace de liberation de la memoire
    free_list(cat_list);
    free_list(reverse_list1);
    free_list(copy_list1);
    free_list(list1);
    free(node1);
    return 0;
}