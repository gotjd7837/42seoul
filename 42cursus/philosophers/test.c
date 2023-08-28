#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#define NUM_PHILOSOPHERS 5

typedef struct {
    pthread_mutex_t forks[NUM_PHILOSOPHERS];
    int philosopher_id;
} PhilosopherData;

void *philosopher(void *arg) {
    PhilosopherData *data = (PhilosopherData *)arg;
    int philosopher_id = data->philosopher_id;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Think
        printf("Philosopher %d is thinking...\n", philosopher_id);
        usleep(rand() % 2000000);

        // Pick up forks
        pthread_mutex_lock(&data->forks[left_fork]);
        printf("Philosopher %d picked up fork %d (left)\n", philosopher_id, left_fork);
        pthread_mutex_lock(&data->forks[right_fork]);
        printf("Philosopher %d picked up fork %d (right)\n", philosopher_id, right_fork);

        // Eat
        printf("Philosopher %d is eating...\n", philosopher_id);
        usleep(rand() % 2000000);

        // Put down forks
        pthread_mutex_unlock(&data->forks[right_fork]);
        printf("Philosopher %d put down fork %d (right)\n", philosopher_id, right_fork);
        pthread_mutex_unlock(&data->forks[left_fork]);
        printf("Philosopher %d put down fork %d (left)\n", philosopher_id, left_fork);
    }

    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    PhilosopherData *philosopher_data[NUM_PHILOSOPHERS];

    // Initialize mutexes for forks and philosopher data
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosopher_data[i] = (PhilosopherData *)malloc(sizeof(PhilosopherData));
        if (philosopher_data[i] == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        memset(philosopher_data[i], 0, sizeof(PhilosopherData));
        pthread_mutex_init(&philosopher_data[i]->forks[i], NULL);
        philosopher_data[i]->philosopher_id = i;

        pthread_create(&philosophers[i], NULL, philosopher, philosopher_data[i]);
        pthread_detach(philosophers[i]);
    }

    // Let the philosophers run for a while
    usleep(10000000); // Run for approximately 10 seconds

    // Clean up
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_destroy(&philosopher_data[i]->forks[i]);
        free(philosopher_data[i]);
    }

    return 0;
}