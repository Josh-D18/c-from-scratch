// Parallel Hello
    // Spawn 5 threads, each prints a unique greeting (pass different args).

#include <pthread.h>
#include <stdio.h>

void *printGreeting(void *args);
pthread_mutex_t lock;

int main(){
    pthread_mutex_init(&lock, NULL);
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    pthread_t thread5;

    const char *messages[] = {
        "Hello User, I am thread one!\n",
        "Hello User, I am thread two!\n",
        "Hello User, I am thread three!\n",
        "Hello User, I am thread four!\n",
        "Hello User, I am thread five!\n"
    };

    pthread_t threads[5];

    for (int i = 0; i < 5; ++i) {
        if (pthread_create(&threads[i], NULL, printGreeting, (void *)messages[i]) != 0) {
            perror("Error starting thread");
            return 1;
        }
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }


    pthread_mutex_destroy(&lock);
    return 0;
}

void *printGreeting(void *args)
{
    pthread_mutex_lock(&lock);
    printf("%s", (char *)args);
    pthread_mutex_unlock(&lock);
    return NULL;
}