#include <stdlib.h>
#include <stdio.h>
#define fflush(stdin) while ((getchar()) != '\n')

//----------------------------------------------------------------------------//
typedef struct nodeT{
    char name[2];
    struct nodeT* left;
    struct nodeT* right;
}node;
//----------------------------------------------------------------------------//
void addNode(node** tree, char[2] myname,char direction) {
    node* newNode = malloc(sizeof(node));
    node* last = *tree;
    while(last!=NULL)
    {
        if(last->name[0] == name[0] && last->name[1] == name[1])
        {
            printf("Error: Vertex is already existent\n");
            return;
        }
        last = last->next;
    }
    newVert->vName = name;
    newVert->eNext = NULL;
    newVert->next = NULL;
    if(*graph == NULL)
        *graph = newVert;
    else{
        last = *graph; 
        while(last->next != NULL)
            last=last->next;
        last->next=newVert;
    }
}