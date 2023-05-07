#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

//reader writer problem
// semaphor wrt  where writer writes
// mutex when reader writes and leaves and whenever readcnt is updated
sem_t wrt;
pthread_mutex_t mutex;
int readcnt=0;
int cnt;

void* writer(void* wno){
    
    sem_wait(&wrt);
    cnt=cnt*2;
    printf("\nWriter %d  has written into database: %d",*(int*)wno,cnt);
    sem_post(&wrt);
    
}
void * reader(void*rno){
    
    pthread_mutex_lock(&mutex);
    //entering critical section
    readcnt++;
    
    if(readcnt==1){
        //more readers can entering
        sem_wait(&wrt);
        
    }
    pthread_mutex_unlock(&mutex);
    //perform reading 
    cnt=cnt+1;
    printf("\nReader %d is reading: %d ",*(int*)rno,cnt);
    
    pthread_mutex_lock(&mutex);
    //entering critical section
    readcnt--;
    
    if(readcnt==0){
        //now readers have finished reading , wroter can enter hence signal wrt
        sem_post(&wrt);
        
    }
    pthread_mutex_unlock(&mutex);
}

int main(){
    
    pthread_t write[3],read[3];
    sem_init(&wrt,0,1);
    pthread_mutex_init(&mutex,NULL);
    int a[3]={1,2,3};
    
    //create threads
    for(int i=0;i<3;i++){
        pthread_create(&read[i],NULL,(void*) reader,(void*)&a[i]);
    }
    for(int i=0;i<3;i++){
        pthread_create(&write[i],NULL,(void*) writer,(void*)&a[i]);
    }
    //join
    for(int i=0;i<3;i++){
        pthread_join(read[i],NULL);
    }
    for(int i=0;i<3;i++){
        pthread_join(write[i],NULL);
    }
    //destroy
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    
    return 0;
}

