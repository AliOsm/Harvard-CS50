#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cs50.h"

struct node {
   int info;
   struct node *next;
};

struct node *root = NULL;
struct node *current = NULL;

void printList() {
   struct node *ptr = root;

   while(ptr != NULL) {
      printf("%d\n", ptr->info);
      ptr = ptr->next;
   }
}

void insertFirst(int n) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));

    new_node->info = n;
    new_node->next = root;
    root = new_node;
}

int main(void)
{
    int tmp;
    
    while(scanf("%d", &tmp) == 1)
        insertFirst(tmp);
    
    printList();
}
