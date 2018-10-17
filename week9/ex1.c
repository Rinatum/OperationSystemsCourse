#include <stdbool.h>
#include <stdlib.h>
#include <printf.h>

//
// Created by Ринат Муллахметов on 17/10/2018.
//

typedef struct Page{
    bool referenced;
    unsigned int lifespan;
    int page_number;
} Page;

Page create_page(int page_number, unsigned int lifespan){
    Page* ptr = malloc(sizeof(Page));
    ptr->lifespan = lifespan;
    ptr->page_number = page_number;
    ptr->referenced = 0;
    return *ptr;
}
typedef struct PageTable {
    int hit;
    int miss;
    int size;
    Page* array;
    int free_counter;
} PageTable;

PageTable* create_pageTable(int size){
    PageTable* ptr = malloc(sizeof(PageTable));
    ptr->miss = 0;
    ptr->hit = 0;
    ptr->free_counter = 0;
    ptr->size = size;
    ptr->array = malloc(sizeof(Page) * size);
    for (int i = 0; i < size; i++){
        ptr->array[i] = create_page(-1, 0);
    }
    return ptr;
}

void right_ar_shift(int* value){
    *value = *value >> 1;
    *value = *value | 1 << sizeof(*value) * 8 - 1;
}

void append(int number, PageTable* pageTable){
    if (pageTable->free_counter < pageTable->size){
        bool hit = false;
        for(int i = 0; i < pageTable->free_counter; i++){
            pageTable->array[i].lifespan = pageTable->array[i].lifespan >> 1;
            if (pageTable->array[i].page_number == number){
                pageTable->hit++;
                hit = true;
                printf("%d \n", number);
                pageTable->array[i].lifespan = pageTable->array[i].lifespan | 1 << (sizeof(pageTable->array[i].lifespan)*8 - 1);
            }
        }
        if (!hit) {
            pageTable->miss++;
            pageTable->array[pageTable->free_counter].page_number = number;
            pageTable->array[pageTable->free_counter].lifespan = (1 << 31);
        }
        pageTable->free_counter++;
    } else{
        int less_used = 0;
        bool hit = false;
        for (int i = 0; i < pageTable->size; i++){
            if (pageTable->array[i].lifespan < pageTable->array[less_used].lifespan){
                less_used = i;
            }
            if (pageTable->array[i].page_number == number){
                pageTable->array[i].referenced = true;
                hit = true;
                printf("%d \n", number);
                pageTable->hit++;
                break;
            }
        }
        if (hit){
            for (int i = 0; i < pageTable->size; i++) {
                pageTable->array[i].lifespan = pageTable->array[i].lifespan >> 1;
                if (pageTable->array[i].referenced){
                    pageTable->array[i].referenced = false;
                    pageTable->array[i].lifespan = pageTable->array[i].lifespan | 1 << (sizeof(pageTable->array[i].lifespan)*8 - 1);
                }
            }
        } else{
            pageTable->miss++;
            pageTable->array[less_used].page_number = number;
            pageTable->array[less_used].lifespan = (1 << 31);
            pageTable->array[less_used].referenced = true;
            for (int i = 0; i < pageTable->size; i++) {
                pageTable->array[i].lifespan = pageTable->array[i].lifespan >> 1;
                if (pageTable->array[i].referenced){
                    pageTable->array[i].referenced = false;
                    pageTable->array[i].lifespan = pageTable->array[i].lifespan << 1;
                }
            }
        }
    }
}


int main(){
    PageTable* pageTable = create_pageTable(3);
    FILE *fp;

    fp = fopen("input.txt", "r");
    int number;
    while (fscanf(fp, "%d", &number) == 1) {
        append(number, pageTable);
    }
    fclose(fp);
    printf("Hit : %d", (pageTable->hit));
    printf("\nMiss : %d", (pageTable->miss));
    printf("\nRatio : %f", (double)pageTable->hit/pageTable->miss);
}


