// Timer Threads
    // Each thread sleeps for n seconds then prints. Launch multiple at once.

#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

void *waitFunc(void *args);
pthread_mutex_t lock;

int main(){
    pthread_mutex_init(&lock, NULL);
    int counter = 0;
    pthread_t tid[10];
    int sleep_times[10];



    for (int i = 0; i < 10; i++)
    {
        counter++;
        sleep_times[i] = i + 1;
        if(pthread_create(&tid[i], NULL, waitFunc, &sleep_times[i]) != 0){
            perror("Error creating thread!");
            exit(0);
        };        
    }

    for (int i = 0; i < 10; i++)
    {
        pthread_join(tid[i], NULL);
    }
    
    pthread_mutex_destroy(&lock);
    return 0;
}

void *waitFunc(void *args){
    int *time = (int *)args;
    pthread_mutex_lock(&lock);
    printf("Sleeping %d seconds....\n", *time);
    pthread_mutex_unlock(&lock);

    sleep(*time);

    pthread_mutex_lock(&lock);
    printf("Waking up from %d seconds....\n", *time);
    pthread_mutex_unlock(&lock);
    return NULL;
}