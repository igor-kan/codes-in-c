#include "interface.h"
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    const uint8_t** srcs;
    const size_t* lens;
    size_t* out_counts;
    size_t idx;
} lz77_job_t;

static void* lz77_worker(void* arg) {
    lz77_job_t* j = (lz77_job_t*)arg;
    size_t n = j->lens[j->idx];
    lz77_token_t* tmp = (lz77_token_t*)malloc((n + 1) * sizeof(lz77_token_t));
    size_t cnt = 0;
    if (tmp) {
        lz77_sliding_codec_encode_fast(j->srcs[j->idx], n, tmp, n + 1, &cnt);
        free(tmp);
    }
    j->out_counts[j->idx] = cnt;
    return NULL;
}

lz77_sliding_codec_err_t lz77_sliding_codec_batch_encode(const uint8_t** srcs, const size_t* lens, size_t* out_counts, size_t batch_size) {
    if (!srcs || !lens || !out_counts) return LZ77_SLIDING_CODEC_ERR_NULL;
    if (batch_size == 0) return LZ77_SLIDING_CODEC_OK;
    if (batch_size > 16) batch_size = 16;
    pthread_t th[16];
    lz77_job_t jobs[16];
    for (size_t i = 0; i < batch_size; ++i) {
        jobs[i] = (lz77_job_t){srcs, lens, out_counts, i};
        pthread_create(&th[i], NULL, lz77_worker, &jobs[i]);
    }
    for (size_t i = 0; i < batch_size; ++i) pthread_join(th[i], NULL);
    return LZ77_SLIDING_CODEC_OK;
}
