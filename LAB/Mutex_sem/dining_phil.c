#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

//DINING PHILOSOPHER
//5 semaphors for the 5 philosophers 

sem_t chopsticks[5];

void* philosopher(void* n){
    int ph=*(int*)n;
    
    printf("\nphilosopher is thinking");
    printf("\nphilosopher is hungry");
    printf("\nphilosopher is PICKING UP LEFT FORK");
    
    sem_wait(&chopsticks[ph]);
    
    printf("\nphilosopher is PICKING UP RIGHT FORK");
    sem_wait(&chopsticks[(ph+1)%5]);
    
    eat();
    
    
    sem_post(&chopsticks[(ph+1)%5]);
    printf("\nphilosopher is PUTTING DOWN RIGHT FORK");
    sem_post(&chopsticks[ph]);
    printf("\nphilosopher is PUTTING DOWN LEFT FORK");
    printf("\n=========FINISHED EATING==========");
}

void eat(){
    printf("\nphilosopher is eating");
    sleep(2);
}

int main()
{
    pthread_t phil[5];
    int n[5];
    for(int i=0;i<5;i++){
        n[i]=i;
        pthread_create(&phil[i],NULL,(void*)philosopher,(void*)&n[i]);
        
    }
    for(int i=0;i<5;i++){
    
        pthread_create(&chopsticks[i],NULL,(void*)philosopher,(void*)&n[i]);
        
    }
    for(int i=0;i<5;i++){
        n[i]=i;
        pthread_join(phil[i],NULL);
        
    }
    sem_destroy(&chopsticks);
    return 0;
    
    
    
}


