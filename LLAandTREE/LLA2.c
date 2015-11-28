#include "macro.h"
void printInc(char** array,int m, int n){   //Stampa matrici su file
    FILE* text = fopen("ematrix","w");      //ematrix -> matrice delle incidenze
    int i,j;
    for(i = 0; i < m; i++){
        if(i != 1 || i != 2){
            fprintf(text,"|----");
            for(j = 1; j < n; j++)
                fprintf(text,"+----");
            fprintf(text,"|\n");
        }
        for(j = 0; j < n; j++)
            fprintf(text,"| %c ",array[i][j]);
        fprintf(text,"|\n");
    }
        fprintf(text,"|----");
        for(j = 1; j < n; j++)
            fprintf(text,"+----");
        fprintf(text,"|\n");
    fclose(text);
}
//Ricerca esistenza edge
int isReachable(vertex* graph, char srcname, char destname,char mode){
    if(graph == NULL){
        printf("Can't search in empty list. Aborting function.\n");
        return 0;
    }
    vertex* srcvert = graph;
    while(srcvert->vName != srcname){
        srcvert= srcvert->next;
        if(srcvert == NULL){
            if(mode != 'c'){printf("Error 404.1: Source node non existent\n");}
            return 78;
        }
    }
    edge* destedge;
    if((destedge = srcvert->eNext) == NULL)
    {
        if(mode != 'c'){printf("Error: source doesn't have edges");}
        return 78;
    }
    while(destedge->arc->vName != destname){
        destedge= destedge->next;
        if(destedge == NULL){
            if(mode != 'c'){printf("Can't find edge\n");}
            return 78;
        }
    }
    if(mode != 'c'){printf("Operation completed, edge found successfully\n");}
    return 1;
}

void fpmllist(vertex* graph){                   //Stampa graph su file
    FILE* text = fopen("graph","w");
    if(graph == NULL){
        fprintf(text,"Can't print NULL list. Aborting function.\n");
        return;
    }
    fprintf(text,"./=====\\.\n");
    while(graph!=NULL){
        edge* lastedge = graph->eNext;
        fprintf(text,"||=====||");
        while(lastedge!=NULL){
            if(lastedge->weight<10)
                 fprintf(text,"  %d  .",lastedge->weight);
            else
                fprintf(text,"  %d .",lastedge->weight);
            lastedge = lastedge->next;
        }
        lastedge = graph->eNext;
        fprintf(text,"\n||-----||");
        while(lastedge!=NULL){
             fprintf(text,"-----|");
             lastedge = lastedge->next;
        }
        fprintf(text,"\n||");
        lastedge = graph->eNext;
        fprintf(text,"  %c  ||",graph->vName);
        while(lastedge!=NULL){
             fprintf(text,"  %c  |",lastedge->arc->vName);
             lastedge = lastedge->next;
        }
        fprintf(text,"\n||-----||");
        lastedge = graph->eNext;
        while(lastedge!=NULL){
             fprintf(text,"-----|");
             lastedge = lastedge->next;
        }
        fprintf(text,"\n");
        graph = graph->next;
    }
    fprintf(text,"||=====||\n");
    fprintf(text,"°\\=====/°\n");
    fclose(text);
}
void vertexInit(vertex** graph){            //Inizializzazione manuale graph
    char ch,a;
    do{
        printf("Do u want to add a new vertex? [y/n]: ");
        scanf("%c",&ch);
        fflush(stdin);
        if(ch != 'n' && ch != 'y'){
            printf("invalid character input\n");
            ch = 'y';
        }
        else if(ch == 'y'){
            printf("Insert vertex name (max 1 char): ");
            char a;
            scanf("%c",&a);
            fflush(stdin);
            addVertex(graph,a);
            fpmllist(*graph);
        }
    }while(ch == 'y');
//-------------------------------------------------------------------------------------//
    /*printf("You completed the vertex input, do u want to print the list? [y/n]: ");
    do{
        scanf("%c",&ch);
        fflush(stdin);
        if(ch == 'y'){pmllist(*graph);}
        else if (ch!='n'){
            printf("invalid character input\n");
        }
    }while(ch != 'y' && ch != 'n');*/
//-------------------------------------------------------------------------------------//
    do{
        printf("Do u want to add a new edge? [y/n]: ");
        scanf("%c",&ch);
        fflush(stdin);
        if(ch != 'n' && ch != 'y'){
            printf("invalid character input\n");
            ch = 'y';
        }
        else if(ch == 'y'){
            char b;
            int c;
            printf("Insert vertex name (max 1 char): ");
            scanf("%c",&a);
            fflush(stdin);
            printf("Insert vertex destination name (max 1 char): ");
            scanf("%c",&b);
            fflush(stdin);
            printf("Insert edge weight: ");
            scanf("%d",&c);
            fflush(stdin);
            addEdge(*graph,a,b,c);
            fpmllist(*graph);
        }
    }while(ch == 'y');
//-------------------------------------------------------------------------------------//
    /*printf("You completed the edge input, do u want to print the list? [y/n]: ");
    do{
        scanf("%c",&ch);
        fflush(stdin);
        if(ch == 'y'){pmllist(*graph);}
        else if (ch!='n'){
            printf("invalid character input\n");
        }
    }while(ch != 'y' && ch != 'n');*/
//-------------------------------------------------------------------------------------*//*
    printf("Graph creation complete.\n");
    do{
        printf("Do u want to search an edge? [y/n]: ");
        scanf("%c",&ch);
        fflush(stdin);
        if(ch != 'n' && ch != 'y'){
            printf("invalid character input\n");
            ch = 'y';
        }
        else if(ch == 'y'){
            char a,b;
            printf("Insert vertex name (max 1 char): ");
            scanf("%c",&a);
            fflush(stdin);
            printf("Insert vertex destination name (max 1 char): ");
            scanf("%c",&b);
            fflush(stdin);
            isReachable(*graph,a,b,'t');
        }
    }while(ch == 'y');
}
int vlength(vertex* graph){     //Conta vertici
    int i=0;
    vertex* tmp = graph;
    while(tmp!=NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
}
int elength(vertex* graph){     //Conta edge
    int i=0;
    edge* counter = malloc(sizeof(edge));
    while(graph!=NULL){
        counter = graph->eNext;
        while(counter != NULL){
            i++;
            counter=counter->next;
        }
        graph=graph->next;
    }
    return i;
}
void adiacenze_mtx(vertex* graph){      //Creazione matrice adiacenze
    int i,j,l=1,N = 1+vlength(graph);
    char amtx[N][N];
    vertex* tmp = graph;
    amtx[0][0] = '-';
    while(tmp!=NULL){
        amtx[0][l]=tmp->vName;
        amtx[l][0]=tmp->vName;
        tmp=tmp->next;
        l++;
    }
    tmp = graph;
    edge* etmp = tmp->eNext;
    for(i=1;i<N;i++){
        for(j=1;j<N;j++){
            if(isReachable(graph,amtx[i][0],amtx[0][j],'c')==1){
                int x = etmp->weight;
                if(x<9)
                    amtx[i][j] = (char)(48+x);
                else{
                    amtx[i][j] = '#';
                    printf("Peso[%c][%c] = %d\n",amtx[i][0],amtx[0][j],x);
                }
                if(etmp->next!=NULL)
                    etmp=etmp->next;
            }
            else
                amtx[i][j] = '~';
        }
        tmp = tmp->next;
        if(tmp != NULL)
            etmp=tmp->eNext;
    }
    FILE* text = fopen("amatrix","w");      //Relativa stampa
    for(i = 0; i < N; i++){
        fprintf(text,"|---");
        for(j = 1; j < N; j++)
            fprintf(text,"+---");
        fprintf(text,"|\n");
        for(j = 0; j < N; j++)
            fprintf(text,"| %c ",amtx[i][j]);
        fprintf(text,"|\n");
    }
        fprintf(text,"|---");
        for(j = 1; j < N; j++)
             fprintf(text,"+---");
        fprintf(text,"|\n");
    fclose(text);
}
void incidenza_mtx(vertex* graph){      //Creazione matrice incidenze
    int i,j,l,N = 3+vlength(graph),M = 1+elength(graph);
    char amtx[N][M];
    vertex* tmpv = graph;
    amtx[0][0] = '-';
    amtx[1][0] = '-';
    amtx[2][0] = '-';
    l=3;
    while(tmpv!=NULL){
        amtx[l][0]=tmpv->vName;
        tmpv=tmpv->next;
        l++;
    }
    tmpv = graph;
    edge* tmpe = malloc(sizeof(edge));
    l = 1;
    while(tmpv!=NULL){
        tmpe = tmpv->eNext;
        while(tmpe!=NULL){
            amtx[0][l]=tmpv->vName;
            amtx[1][l]='v';
            amtx[2][l]=tmpe->arc->vName;
            tmpe = tmpe->next;
            l++;
        }
        tmpv=tmpv->next;
    }
    tmpv = graph;
    vertex* tmpvv = tmpv; 
    i=3,j=1;
    for(i=3;i<N;i++)
        for(j=1;j<M;j++)
            if(amtx[i][0] == amtx[2][j])
                amtx[i][j] = '1';
            else
                amtx[i][j] = '~';
    FILE* text = fopen("ematrix","w");      //Relativa stampa
    for(i = 0; i < N; i++){
        if(i != 1 && i != 2){
            fprintf(text,"|---");
            for(j = 1; j < M; j++)
                fprintf(text,"+---");
            fprintf(text,"|\n");
        }
        for(j = 0; j < M; j++)
            fprintf(text,"| %c ",amtx[i][j]);
        fprintf(text,"|\n");
    }
        fprintf(text,"|---");
        for(j = 1; j < M; j++)
             fprintf(text,"+---");
        fprintf(text,"|\n");
    fclose(text);
}

vertex* list_switch( vertex* l1, vertex* l2 )
{
    l1->next = l2->next;
    l2->next = l1;
    return l2;
}
vertex* sort( vertex* start )
{
    vertex *p;
    vertex *q;
    vertex *top = malloc(sizeof(vertex));
    int changed = 1;
    top->next = start;
    if( start != NULL && start->next != NULL ) {
        while( changed ) {
            changed = 0;
            q = top;
            p = top->next;
            while( p->next != NULL ) {
                if( p->vName > p->next->vName ) {
                    q->next = list_switch( p, p->next );
                    changed = 1;
                }
                q = p;
                if( p->next != NULL )
                    p = p->next;
            }
        }
    }
    p = top->next;
    free( top );
    return p;
}
edge* edge_switch( edge* l1, edge* l2 )
{
    l1->next = l2->next;
    l2->next = l1;
    return l2;
}
edge* edgesort( edge* start )
{
    edge *p;
    edge *q;
    edge *top = malloc(sizeof(edge));
    int changed = 1;
    top->next = start;
    if( start != NULL && start->next != NULL ) {
        while( changed ) {
            changed = 0;
            q = top;
            p = top->next;
            while( p->next != NULL ) {
                if( p->arc->vName > p->next->arc->vName ) {
                    q->next = edge_switch( p, p->next );
                    changed = 1;
                }
                q = p;
                if( p->next != NULL )
                    p = p->next;
            }
        }
    }
    p = top->next;
    free( top );
    return p;
}
vertex* sortGraph(vertex* graph)
{
    vertex* last = graph;
    while(last != NULL)
    {
        last->eNext = edgesort(last->eNext);
        last = last->next;
    }
    graph = sort(graph);
    return graph;
}
void randomGraphCreation(vertex** graph){
    srand(time(NULL));
    int i,n,m,ch;
    printf("Numero di vertici richiesti: ");
    scanf("%d",&n);
    char nodecreated[n];
    char randomletter,startname,destname;
    for(i=0;i<n;i++){
        randomletter = 'A' + (random() % 26);
        addVertex(graph,randomletter);
        nodecreated[i] = randomletter;
    }
    *graph = sort(*graph);
    fpmllist(*graph);
    printf("Numero di edge richiesti: ");
    scanf("%d",&m);
    fflush(stdin);
    int newWeight;
    for(i=0;i<m;i++){
        newWeight = rand() % 30 + 1; 
        startname = nodecreated[rand() % n];
        destname = nodecreated[rand() % n];
        addEdge(*graph,startname,destname,newWeight);
    }
    *graph = sortGraph(*graph);
    fpmllist(*graph);
}
int main () {
    
    vertex* graph = NULL;
    randomGraphCreation(&graph);
    vertexInit(&graph);
    fpmllist(graph);
    adiacenze_mtx(graph);
    incidenza_mtx(graph);
    printf("Vertex creati: %d\nEdge creati: %d",vlength(graph),elength(graph));
    //sleep(5);
    graph = sortGraph(graph);
    fpmllist(graph);
    return 0;
}
