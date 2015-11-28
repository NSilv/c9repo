#include <stdlib.h>
#include <stdio.h>
#define fflush(stdin) while ((getchar()) != '\n')

//----------------------------------------------------------------------------//
typedef struct vertexT{
    char vName;
    struct edgeT* eNext;
    struct vertexT* next;
}vertex;
typedef struct edgeT{
    int weight;
    struct vertexT* arc;
    struct edgeT* next;
}edge;
//----------------------------------------------------------------------------//
void addVertex(vertex** graph,char name) {
    vertex* newVert = malloc(sizeof(vertex));
    vertex* last = *graph;
    while(last!=NULL)
    {
        if(last->vName == name)
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
void addEdge(vertex* graph,char srcname,char destname,int edgeweight){
    if(graph == NULL){return;}
    vertex* src = graph;
    vertex* dest = graph;
    while(src->vName != srcname){
        src= src->next;
        if(src == NULL){
            printf("Error 404.1: Source node not found\n");
            return;
        }
    }
    while(dest->vName != destname){
        dest= dest->next;
        if(dest == NULL){
            printf("Error 404.2: Destination node not found\n");
            return;
        }
    }
    edge* newEdge = malloc(sizeof(edge));
    newEdge->arc = dest;
    newEdge->weight = edgeweight;
    newEdge->next = NULL;
    edge* last = src->eNext;
    while(last!=NULL)
    {
        if(last->arc->vName == destname)
        {
            printf("Error: Edge is already existent\n");
            return;
        }
        last = last->next;
    }
    if(src->eNext == NULL)
        src->eNext = newEdge;
    else{
        last = src->eNext;
        while(last->next != NULL){
            last=last->next;
        }
        last->next=newEdge;
    }
}