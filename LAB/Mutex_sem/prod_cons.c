#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

//producer consumer
sem_t empty;
sem_t full;

pthread_mutex_t mutex;
int Buffer[5];
int in =0;
int out=0;

void* producer(void* pno){
    int item;
    for(int i=0;i<5;i++){
        item=rand();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        //producer produces
        Buffer[in]=item;
        printf("\nProducer %d is producing %d",*(int*)pno,item);
        in=(in+1)%5;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        
        

    }
}

void* consumer(void* cno){
    int item;
    for(int i=0;i<5;i++){
        
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        //producer produces
        int item = Buffer[out];
        printf("\nconsumer %d is consuming %d",*(int*)cno,out);
        out=(out+1)%5;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        

    }
}
int main(){
    
    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&full,0,0);
    sem_init(&empty,0,5);
    int a[5]={1,2,3,4,5};
    
    for(int i=0;i<5;i++){
        pthread_create(&pro[i],NULL,(void*) producer,(void*)&a[i]);
    }
    for(int i=0;i<5;i++){
        pthread_create(&con[i],NULL,(void*) consumer,(void*)&a[i]);
    }
    for(int i=0;i<5;i++){
        pthread_join(pro[i],NULL);
    }
    for(int i=0;i<5;i++){
        pthread_join(con[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
    
    
    
    
}


