#include <stdlib.h>
#include <stdio.h>
#define fflush(stdin) while ((getchar()) != '\n')

//----------------------------------------------------------------------------//
typedef struct nodeT{
    char name;
    struct nodeT* left;
    struct nodeT* right;
}node;
//----------------------------------------------------------------------------//
void addNode(node** tree, char myname) {
    node* newNode = malloc(sizeof(node));
    node* last = *tree;
    node->name = name;
    node->left = NULL;
    node->right = NULL;
    if(*graph == NULL)
        *graph = newVert;
    else{
        last = *graph;
        do{
            last = indirection(last);
        }while(last->next!= NULL);
    }
}
node* indirection(node* last){
    char way;
    printf("Inserichi la direzione");
    scanf("%c",&way);
    if(way == 'l'){
        return last->left;
    }else if(way == 'r'){
        return last->right;
}