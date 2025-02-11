#include "__preprocessor__.h"
#include "__time_stamp__.h"
#include <immintrin.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    UTILS::clear_terminal();
    time_stamp("It just works");

    unsigned int how_many_times = -1;

    int32_t iter_result[8] = {0};
    for (unsigned int i = 0; i < how_many_times; i++)
    {
        int32_t a[8] = {10, 9, 8, 7, 6, 5, 4, 3};
        int32_t b[8] = {3, 4, 5, 6, 7, 8, 9, 10};

        for (int index = 0; index < 8; index++)
        {
            iter_result[index] = a[index] + b[index];
        }
    }
    time_stamp("Iterative");

    int32_t* res{};
    for (unsigned int i = 0; i < how_many_times; i++)
    {
        __m256i a = _mm256_set_epi32(10, 9, 8, 7, 6, 5, 4, 3);
        __m256i b = _mm256_set_epi32(3, 4, 5, 6, 7, 8, 9, 10);

        __m256i result = _mm256_add_epi32(a, b);
        res = (int32_t*)&result;
    }
    time_stamp("SIMD");

    float iter_result_float[8] = {0};
    for (unsigned int i = 0; i < how_many_times; i++)
    {
        float a[8] = {10.f, 9.f, 8.f, 7.f, 6.f, 5.f, 4.f, 3.f};
        float b[8] = {3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f};

        for (int index = 0; index < 8; index++)
        {
            iter_result_float[index] = a[index] + b[index];
        }
    }
    time_stamp("Iterative - float");

    float* float_res{};
    for (unsigned int i = 0; i < how_many_times; i++)
    {
        __m256 a = _mm256_set_ps(10.f, 9.f, 8.f, 7.f, 6.f, 5.f, 4.f, 3.f);
        __m256 b = _mm256_set_ps(3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f);

        __m256 result = _mm256_add_ps(a, b);
        float_res = (float*)&result;
    }
    time_stamp("SIMD - float");

    time_stamp("DONE");
    return 0;
}