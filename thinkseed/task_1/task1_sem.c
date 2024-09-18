#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

//creating even and odd locks 
sem_t even_lock, odd_lock;

//function pointer for even threads 
void *even_thread(void *args)
{
    int count = 0;
    while (count < 100)
    {
        sem_wait(&even_lock);
        sleep(1);
        printf("%d\n", count);
        count += 2;
        sem_post(&odd_lock);
    }
    pthread_exit(0);
}

//function pointer for oodd threads 
void *odd_thread(void *args)
{
    int count = 1;
    while (count < 100)
    {
        sem_wait(&odd_lock);
        sleep(1);
        printf("%d\n", count);
        count += 2;
        sem_post(&even_lock);
    }
    pthread_exit(0);
}

int main()
{
    //threads initialization
    pthread_t thread1 , thread2;
    
    sem_init(&even_lock, 0, 1);
    sem_init(&odd_lock, 0, 0);

    printf("Output for even and odd threads : \n");

    //Used to create the threads  
    pthread_create(&thread1, NULL, even_thread, NULL);
    pthread_create(&thread2, NULL, odd_thread, NULL);

    //used to manage the hread execution and ensuring that resources are properly released in a multithreaded program.
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    //used to destroy the semophere locks 
    sem_destroy(&even_lock);
    sem_destroy(&odd_lock);
    return 0;
}
