#include "interface.h"
#include <pthread.h>

typedef struct {
    size_t trials;
    int ok;
} kf_job_t;

static void* kf_worker(void* arg) {
    kf_job_t* j = (kf_job_t*)arg;
    uint8_t store[64], chunk[23], out[23];
    kfifo_t q;
    kfifo_init(&q, store, 64);
    for (size_t t = 0; t < j->trials; ++t) {
        for (size_t i = 0; i < 23; ++i) chunk[i] = (uint8_t)(t + i);
        if (kfifo_in(&q, chunk, 23) != 23 || kfifo_out(&q, out, 23) != 23) { j->ok = 0; break; }
        for (size_t i = 0; i < 23; ++i) if (chunk[i] != out[i]) j->ok = 0;
    }
    return NULL;
}

kfifo_power2_ring_err_t kfifo_mt_test_batches(size_t trials) {
    pthread_t th[2];
    kf_job_t args[2] = {{trials, 1}, {trials, 1}};
    for (int i = 0; i < 2; ++i) pthread_create(&th[i], NULL, kf_worker, &args[i]);
    for (int i = 0; i < 2; ++i) pthread_join(th[i], NULL);
    return (args[0].ok && args[1].ok) ? KFIFO_POWER2_RING_OK : KFIFO_POWER2_RING_ERR_INVARIANT;
}
