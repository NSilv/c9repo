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
    newNode->name = myname;
    newNode->left = NULL;
    newNode->right = NULL;
    if(*tree == NULL)
        *tree = newNode;
    else{
        node* last = *tree;
        do{
            if(last!= NULL){
                last = indirection(last);
            }
        }while(last->right != NULL || last->left != NULL);
        char way;
        printf("Inserichi la direzione");
        scanf("%c",&way);
        if(way == 'l'){
            last->left = newNode;
        }else if(way == 'r'){
            last->right = newNode;
        }
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
    return last;
}