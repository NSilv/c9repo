#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void* thread_countdown(void* arg)
{
    int* ciao = (int*)(arg);
    for(int i = ciao[0]; i>0;i--)
    {
        printf("%d\n",i);
        sleep(1);
    }
    return (void*)ciao;
}
int main(){
    pthread_t firsthread;
    int* ciao;
    int x[] ={10, 5};
    if(pthread_create(&firsthread, (void*)ciao, &thread_countdown, (void*)(&x)) != 0)
        printf("errore\n");
    
    return 0;
}