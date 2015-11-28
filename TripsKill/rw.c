#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    FILE* text = fopen("1krndint","w");
    int i,j,n,m,x;
    printf("Inserisci il numero di numeri: ");
    scanf("%d",&x);
    printf("Inserisci dimensioni matrice\n");
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<x;i++){
        fprintf(text," %d",rand() % 1000+1);
    }
    if((n*m) > x){printf("Numero di valori insufficente, creazione matrice incompleta ...\n");}
    freopen("1krndint","r",text);
    int mtx[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            fscanf(text,"%d",&mtx[i][j]);
        }
    }
    fclose(text);
    for(i = 0; i < n; i++){
        printf("|------");
        for(j = 1; j < m; j++)
            printf("+------");
        printf("|\n");
        for(j = 0; j < m; j++)
            printf("| %04d ",mtx[i][j]);
        printf("|\n");
    }
        printf("|------");
        for(j = 1; j < m; j++)
             printf("+------");
        printf("|\n");
    
    return EXIT_SUCCESS;
}


