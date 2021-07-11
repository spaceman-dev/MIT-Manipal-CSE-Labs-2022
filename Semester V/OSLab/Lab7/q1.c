#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int buf[5], f, r;
sem_t mutex, full, empty;
void *produce(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("Produced item is: '%d'\n", i);
        buf[(++r) % 10] = i;
        sleep(1);
        sem_post(&mutex);
        sem_post(&full);
    }
}
void *consume(void *arg)
{
    int item;
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        item = buf[(++f) % 10];
        printf("Consumed item is: '%d'\n", item);
        sleep(1);
        sem_post(&mutex);
        sem_post(&empty);
    }
}
int main()
{
    pthread_t t1, t2;
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 1);
    sem_init(&empty, 0, 10);
    pthread_create(&t1, NULL, produce, NULL);
    pthread_create(&t2, NULL, consume, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}