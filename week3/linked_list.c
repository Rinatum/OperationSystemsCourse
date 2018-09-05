#include <stdlib.h>
#include <printf.h>
#include <math.h>

typedef struct Node
{
    int value;
    struct Node* prev;
    struct Node* next;
} Node ;

Node* head = NULL;

Node* tail = NULL;

int size = 0;

int insert_node(int value){
    size++;
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    if (head == NULL){
        head = node;
        tail = node;
    }
    else if (head == tail){
        tail = node;
        tail->prev = head;
        head->next = tail;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }
    return 0;
}
int delete_node(int index){
    if (index < 0 || index >= size){
        printf("%s", "Wrong index");
        return -INFINITY;
    }
    if (head == NULL){
        printf("%s", "Try to delete node from empty list!");
        return -INFINITY;
    } else{
        size--;
        Node* runer = head;
        for (int i = 0; i < index; i++){
            runer = runer->next;
        }
        if (runer == head){
            if (runer->next == NULL){
                free(head);
                head = NULL;
                tail = NULL;
            } else{
                if(runer->next == tail){
                    free(head);
                    tail->prev = NULL;
                    head = tail;
                } else{
                    head = head->next;
                    free(head->prev);
                    head->prev = NULL;
                }
            }
        } else if (runer == tail){
            if (runer->prev == NULL){
                free(tail);
                head = NULL;
                tail = NULL;
            } else{
                if (runer->prev == head){
                    free(tail);
                    head->next = NULL;
                    tail = head;
                } else{
                    tail = tail->prev;
                    free(tail->next);
                    tail->next = NULL;
                }
            }
        } else{
            runer->prev->next = runer->next;
            runer->next->prev = runer->prev;
            free(runer);
        }
    }
    return 0;
}
int print_list(){
    Node* runer = head;
    while(runer != NULL){
        printf(" [");
        printf("%i",runer->value);
        printf("] -->");
        runer = runer->next;
    }
    printf("\n");
    return 0;
}


