 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define null NULL

void *fact(void *var){
int mat=*(int *)var;
int sum=1;
for(int i=1;i<=mat;i++){
    sum=sum*i;
}
pthread_exit((void *) sum);

}

int main()
{
int n;
int add=0;
scanf("%d",&n);

pthread_t t_id[n];

for(int i=1;i<n+1;i++)
{

    pthread_create(&t_id[i],NULL, fact,(void *) &i);
    void *threadReturn;
    pthread_join(t_id[i],&threadReturn);
    add=add+( int )threadReturn;

    printf("This is Thread %d, factorial = %d \n",i,( int )threadReturn);

}

printf("This is main thread, Value of A = %d ",add);
return 0;

}

