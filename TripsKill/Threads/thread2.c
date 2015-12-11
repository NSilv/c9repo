#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
void* rndprint(void* arg)
{
    int a=1;
    printf("cosa!??? uw8m8");
    pthread_exit((void*)&a);
}
void* namez(void* arg)
{
    int b;
    printf("Nicholas Silvestrin");
    pthread_exit((void*)&b);
}
int main()
{
    int* value;
    pthread_t a;
    pthread_t b;
    if(pthread_create(&a,NULL,&rndprint,NULL)!= 0);
        printf("errore");
    if(pthread_create(&b,NULL,&namez,NULL)!=0);
        printf("errore");
    void* av = (void*)value;
    pthread_join(a,&av);
    void* bv = (void*)value;
    pthread_join(b,&bv);
    sleep(4);
    return 0;
}