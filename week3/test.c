//
// Created by Ринат Муллахметов on 05/09/2018.
//
#include <printf.h>
#include "linked_list.h"
#include "bubble_sort.h"
int main(){
    printf("Bubble sort task:\n");
    int arr[] = {1,8,2,7,-5,0};
    printArray(arr, 6);
    bubble_sort(arr, 6);
    printArray(arr, 6);
    printf("Linked list task:\n");
    insert_node(5);
    insert_node(3);
    insert_node(6);
    insert_node(7);
    print_list();
    delete_node(1);
    delete_node(0);
    print_list();
    insert_node(5);
    insert_node(4);
    delete_node(3);
    print_list();
    return 0;
}