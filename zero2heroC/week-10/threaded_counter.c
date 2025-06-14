// Threaded Counter
    // Spawn two threads that both increment a shared counter
    // First, run it without a mutex — watch it glitch
    // Then add a pthread_mutex_t to protect the critical section

#include <pthread.h>
#include <stdio.h>


void *increment(void *args);
int counter = 0;
pthread_mutex_t lock;

int main(){
    pthread_t tid;
    pthread_t tid_2;
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 10000; i++) 
    {
        counter = 0;
        if(pthread_create(&tid, NULL, increment, &counter) != 0)
        {
            perror("Failed to start thread!");
            return 1;
        }

        if(pthread_create(&tid_2, NULL, increment, &counter) != 0)
        {
            perror("Failed to start thread!");
            return 1;
        }

        pthread_join(tid, NULL);
        pthread_join(tid_2, NULL);

        if (counter != 2) {
            printf("Race condition caught! Counter = %d\n", counter);
            break;
        }
    }
    pthread_mutex_destroy(&lock);
    return 0;
}

void *increment(void *args){
    pthread_mutex_lock(&lock);
    int *num = (int *)args;
    (*num)++;
    pthread_mutex_unlock(&lock);
    return NULL;
}