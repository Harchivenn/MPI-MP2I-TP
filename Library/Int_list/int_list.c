#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "int_list.h"

//Ex3 - Q2
node_t* create_node(int value){
    node_t* node = malloc(sizeof(node_t));
    node->next = NULL;
    node->value = value;
    return node;
}

//Ex3 - Q4
int_list_t* create_empty_list(){
    int_list_t* list = malloc(sizeof(int_list_t));
    *list = NULL;
    return list;
}

//Ex3 - Q5
void add(int_list_t* list, int value){
    node_t* new_node = create_node(value);
    if (*list == NULL){
        *list = new_node;
    }
    else{
        new_node->next = *list;
        *list = new_node;
    }
}

//Ex3 - Q6
int head(int_list_t* list){
    return (*list)->value;
}

//Ex3 - Q7
int_list_t* tail(int_list_t* list){
    return &((*list)->next);
}

//Ex3 - Q8
void print_int_list(int_list_t* list){
    printf("[ ");
    node_t* head = *list;
    while (head != NULL){
        printf("%d ", head->value);
        head = head->next;
    }
    printf("]\n");
    free(head);
}


//Ex3 - Q9
void free_list(int_list_t* list){
    node_t* head = *list;
    while (head != NULL){
        node_t* to_destroy = head;
        head = head->next;
        free(to_destroy);
    }
    free(head);
    free(list);
}

//Ex3 - Q10
void remove_head(int_list_t* list){
    node_t* to_destroy = *list;
    *list = (*list)->next;
    free(to_destroy);
}

//Ex3 - Q10
int lenght(int_list_t* list){
    node_t* head = *list;
    int lenght = 0;
    while (head != NULL){
        lenght++;
        head = head->next;
    }
    free(head);
    return lenght;
}

//Ex3 - Q12
int_list_t* copy_reverse(int_list_t* list){
    int_list_t* reverse_list = create_empty_list();
    node_t* head = *list;
    while (head != NULL){
        add(reverse_list, head->value);
        head = head->next;
    }
    free(head);
    return reverse_list;
}

//Ex3 - Q13
int_list_t* copy(int_list_t* list){
    int_list_t* reverse_list = copy_reverse(list);
    int_list_t* double_reverse_list = copy_reverse(reverse_list);
    free_list(reverse_list);
    return double_reverse_list;
}

//Ex3 - Q14
bool list_equal(int_list_t* list1, int_list_t* list2){
    int lenght_list1 = lenght(list1);
    int lenght_list2 = lenght(list2);
    int_list_t* list1_copy = copy(list1);
    int_list_t* list2_copy = copy(list2);
    if (lenght_list1 != lenght_list2){
        free_list(list1_copy);
        free_list(list2_copy);
        return false;
    }
    else{
        for (int i = 0; i < lenght_list1; i++){
            if (head(list1_copy) != head(list2_copy)){
                free_list(list1_copy);
                free_list(list2_copy);
                return false;
            }
            else{
                remove_head(list1_copy);
                remove_head(list2_copy);
            }
        }
    }
    free_list(list1_copy);
    free_list(list2_copy);
    return true;
}

//Ex3 - Q15
int_list_t* cat(int_list_t* list1, int_list_t* list2){
    int list1_lenght = lenght(list1);
    int_list_t* copy_list1 = copy_reverse(list1);
    int_list_t* cat_list = copy(list2);
    for (int i = 0; i < list1_lenght; i++){
        add(cat_list, head(copy_list1));
        remove_head(copy_list1);
    }
    free(copy_list1);
    return cat_list;
}