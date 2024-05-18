#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* Hello(void *rank) {
    int my_rank = (long)rank;
    printf("Hello from thread %d!\n", my_rank);
    return NULL;
}

int main(int argc, char *argv[]) {
    long thread_count = strtol(argv[1],NULL,10);
    pthread_t *thread_handles = malloc(thread_count*sizeof(pthread_t));
    for (long i=0; i<thread_count; i++)
        pthread_create(&thread_handles[i], NULL, &Hello, (void*)i);
    printf("Hello from the parent thread!\n");
    for (long i=0; i<thread_count; i++)
        pthread_join(thread_handles[i], NULL);
    free(thread_handles);
}