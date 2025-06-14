// Threaded Calculator
    // A thread does addition, one subtraction, one multiplies, one divides — all in parallel. Print results in order.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

pthread_mutex_t lock;

struct Numbers
{
    int a;
    int b;
};


void *(*func[4])(void *);
void *add(void *args);
void *subtract(void *args);
void *divide(void *args);
void *multiply(void *args);

int main(){
    pthread_t tid[4];
    pthread_mutex_init(&lock, NULL);

    func[0] = add;
    func[1] = subtract;
    func[2] = divide;
    func[3] = multiply;

    struct Numbers cal_num;
    cal_num.a = 5;
    cal_num.b = 6;

    for (int i = 0; i < 4; i++)
    {
        if(pthread_create(&tid[i], NULL, func[i], (void *)&cal_num) != 0){
            perror("Could not create thread!\n");
            exit(0);
        };
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}

void *add(void *args)
{
    struct Numbers *nums = (struct Numbers *)args;
    int a = nums->a;
    int b = nums->b;
    pthread_mutex_lock(&lock);
    printf("%d plus %d equals %d\n", a, b , a + b);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *subtract(void *args)
{
    struct Numbers *nums = (struct Numbers *)args;
    int a = nums->a;
    int b = nums->b;
    pthread_mutex_lock(&lock);
    if (a < b)
    {
        printf("%d minus %d equals %d\n", b, a , b - a);
    } else
    {
        printf("%d minus %d equals %d\n", a, b , a - b);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *divide(void *args)
{
    struct Numbers *nums = (struct Numbers *)args;
    int a = nums->a;
    int b = nums->b;
    pthread_mutex_lock(&lock);
    if (b == 0)
    {
        printf("%d divided  by %d equals %d\n", a, 10 , a / 10);
    } else
    {
        printf("%d divided by %d equals %d\n", a, b , a / b);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *multiply(void *args)
{
    struct Numbers *nums = (struct Numbers *)args;
    int a = nums->a;
    int b = nums->b;
    pthread_mutex_lock(&lock);
    printf("%d times %d equals %d\n", a, b , a * b);
    pthread_mutex_unlock(&lock);
    return NULL;
}
