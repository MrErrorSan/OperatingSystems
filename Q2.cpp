#include <pthread.h>
#include <semaphore.h>
#include <iostream>
using namespace std;
#define N 5
#define think 2
#define hungry 1
#define eating 0
#define l (pno + 4) % N
#define r (pno + 1) % N

int condition[N];
int p[N] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t S[N];

void check(int pno)
{
    if (condition[pno] == hungry && condition[l] != eating && condition[r] != eating)
    {
        condition[pno] = eating;
        cout << "Philospher " << pno + 1 << " takes fork " << l + 1 << " and " << pno + 1 << endl;
        cout << "Philospher " << pno + 1 << " is eating" << endl;
        sem_post(&S[pno]);
    }
}
void pickFork(int pno)
{

    sem_wait(&mutex);
    condition[pno] = hungry;
    cout << "Philospher " << pno + 1 << " is hungry" << endl;
    check(pno);
    sem_post(&mutex);
    sem_wait(&S[pno]);
}
void dropFork(int pno)
{
    sem_wait(&mutex);
    condition[pno] = think;
    cout << "Philospher " << pno + 1 << " is droping fork " << l + 1 << " and " << pno + 1 << endl;
    cout << "Philospher " << pno + 1 << " is thinking" << endl;
    check(l);
    check(r);

    sem_post(&mutex);
}

void *driver(void *num)
{

    while (1)
    {

        int *i = (int *)num;
        pickFork(*i);
        dropFork(*i);
    }
}

int main()
{

    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);

    for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);
    for (i = 0; i < N; i++)
    {
        pthread_create(&thread_id[i], NULL,
                       driver, &p[i]);
        cout << "Philospher " << i + 1 << " is thinking" << endl;
    }
    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);
}