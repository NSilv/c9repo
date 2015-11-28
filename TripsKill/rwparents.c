#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int search(int vett[],int left, int right, int value){
    int i;
    for(i = left;i<right;i++)
    {
        if(vett[i] == value)
            return i;
    }
}
int main(){
    FILE* text = fopen("vettore","r");
    int i=0,n,x,c;
    do{
        
        fscanf(text,"%d",&c);
        
            n++;
    }while (c != EOF);
    int vect[n];
    while ((fscanf(text,"%d",&c))!=0xA){
        vect[i] = c;
        getchar();
        i++;
    }
    printf("Che numero vuoi cercare");
    scanf("%d",&x);
    pid_t pid[4];  //array di nome pid fatto da num_figli elementi di tipo pid_t	*
    for(i=0; i<4; i++)
	{
		if ((pid[i] = fork()) < 0)
		{
			printf("Errore nella fork().\n");
		}
		if(!pid[i] && i==0)
		{
		    search(vect,0,i/4,x);
			exit(EXIT_SUCCESS);
		}
		if(!pid[i] && i==1)
		{
		    search(vect,i/4,i/2,x);
			exit(EXIT_SUCCESS);
		}
		if(!pid[i] && i==2)
		{
		    search(vect,i/2,i*3/2,x);
			exit(EXIT_SUCCESS);
		}
		if(!pid[i] && i==3)
		{
		    search(vect,i*3/2,n,x);
			exit(EXIT_SUCCESS);
		}
	}
	for(i=0; i<4; i++)
	{
		waitpid(pid[i],NULL,0);
	}
    return EXIT_SUCCESS;
}


