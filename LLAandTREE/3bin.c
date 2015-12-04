#include <stdlib.h>
#include <stdio.h>
#define fflush(stdin) while ((getchar()) != '\n')

//----------------------------------------------------------------------------//
typedef struct nodeT{
    int key;
    struct nodeT* left;
    struct nodeT* right;
    int height;
}node;
//----------------------------------------------------------------------------//
node* newNode(int key) {
    node* newNode = malloc(sizeof(node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
node* insert(node* tree,int key){
    if(tree == NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left,key);
    else
        node->right = insert(node->right,key);
    
    //Height update
    tree->height = max(height(node->left),height(node->right)) + 1;
    
    //Balance tree
    int balance = getBalance(tree);
    
    //4 Casi di albero sbilanciato
        
        //Left Left
        if(balance > 1 && key < tree->left->key)
            return rightRotate(tree);
            
        //Right Right
        if(balance > -1 && key > tree->left->key)
            return leftRotate(tree);
            
        //Right Left
        if(balance > )
            
        
}
int main(){
    return 0;
}