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
void addNode(node** tree, char[2] myname) {
    node* newNode = malloc(sizeof(node));
    node* last = *tree;
    while(last!=NULL)
    {
        if(last->name == name[0] && last->name[1] == name[1])
        {
            printf("Error: Vertex is already existent\n");
            return;
        }
        last = last->next;
    }
    node->name = name;
    node->left = NULL;
    node->right = NULL;
    if(*graph == NULL)
        *graph = newVert;
    else{
        if(direction =='l'){
        last = *graph; 
        while(last != NULL)
            last=last->left;
        last->next=newVert;
        }
    }
}