#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
int search(int vett[],int left, int right, int value){
    int i;
    for(i = left;i<right;i++)
    {
        if(vett[i] == value)
            return i;
    }
    return -1;
}
int main(){
    FILE* text = fopen("vettore","r");
    int i=0,n=0,x,c = 48;
    while((fscanf(text,"%d ",&c)) != -1)
	{
		n=n+1;
	}
    int vect[n];
	freopen("vettore","r",text);
    while((fscanf(text,"%d ",&c)) != -1)
	{
		vect[i] = c;
		i++;
	}
    printf("Che numero vuoi cercare: ");
    scanf("%d",&x);
    pid_t pid[4];  //array di nome pid fatto da num_figli elementi di tipo pid_t *
    for(i=0; i<4; i++)
	{
		if ((pid[i] = fork()) < 0)
		{
			printf("Errore nella fork().\n");
		}
		if(!pid[i] && i==0)
		{
		    if((c = search(vect,0,n/4,x)) != -1)
		    	printf("pid: %d , elemento trovato in posizione: %d",i,c);
			exit(EXIT_SUCCESS);
		}
		if(!pid[i] && i==1)
		{
		    if((c = search(vect,n/4,n/2,x)) != -1)
		    	printf("pid: %d , elemento trovato in posizione: %d",i,c);
			exit(EXIT_SUCCESS);
		}
		if(!pid[i] && i==2)
		{
		    if(( c = search(vect,n/2,n*3/4,x)) != -1)
		    	printf("pid: %d , elemento trovato in posizione: %d",i,c);
			exit(EXIT_SUCCESS);
		}
		if(!pid[i] && i==3)
		{
		    if(( c = search(vect,n*3/4,n,x)) != -1 )
		    	printf("pid: %d , elemento trovato in posizione: %d",i,c);
			exit(EXIT_SUCCESS);
		}
	}
	for(i=0; i<4; i++)
	{
		waitpid(pid[i],NULL,0);
	}
	fclose(text);
    return EXIT_SUCCESS;
}


