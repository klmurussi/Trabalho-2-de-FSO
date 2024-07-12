#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int time;
} mem;

typedef struct {
    mem *mem;
    int Q;
    int N;
    int index;
    int pageFault;
    int lastTime;
} LRUCache;

LRUCache *createLRUCache(int Q, int N) {
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->mem = (mem *)malloc(Q * sizeof(mem));
    cache->Q = Q;
    cache->N = N;
    cache->index = 0;
    cache->pageFault = 0;
    cache->lastTime = 0;

    for (int i = 0; i < Q; i++) {
        cache->mem[i].data = -1;
        cache->mem[i].time = 0;
    }

    return cache;
}

void insert(LRUCache *cache, int P) {
    int find = 1;

    for (int j = 0; j < cache->Q; j++) {
        if (P == cache->mem[j].data) {
            find = 0;
            cache->mem[j].time = ++cache->lastTime;
            break;
        }
    }

    if (find == 1) {
        cache->pageFault++;
        cache->mem[cache->index].data = P;
        cache->mem[cache->index].time = ++cache->lastTime;
    }

    int menor = cache->mem[0].time;
    cache->index = 0;
    for (int i = 0; i < cache->Q; i++) {
        if (cache->mem[i].time < 0) {
            cache->index = i;
            break;
        }
        else {
            if (cache->mem[i].time < menor) {
                menor = cache->mem[i].time;
                cache->index = i;
            }
        }
    }
}

int main () {
    int Q;
    scanf("%d", &Q);
    int N;
    scanf("%d", &N);

    LRUCache *cache = createLRUCache(Q, N);

    for (int i = 0; i < N; i++) {
        int P;
        scanf("%d", &P);
        insert(cache, P);
    }

    printf("%d\n", cache->pageFault);
    return 0;
}