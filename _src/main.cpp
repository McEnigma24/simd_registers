#include "__preprocessor__.h"
#include "__time_stamp__.h"

// #include "hwy/highway.h"

// HWY_BEFORE_NAMESPACE();
// namespace hwy
// {
//     namespace HWY_NAMESPACE
//     {

//         void AddVectors(const float* HWY_RESTRICT a,
//                         const float* HWY_RESTRICT b, float* HWY_RESTRICT
//                         result, size_t length)
//         {
//             const HWY_FULL(float) d;
//             for (size_t i = 0; i < length; i += Lanes(d))
//             {
//                 const auto va = Load(d, a + i);
//                 const auto vb = Load(d, b + i);
//                 const auto vresult = Add(va, vb);
//                 Store(vresult, d, result + i);
//             }
//         }

//     } // namespace HWY_NAMESPACE
// } // namespace hwy
// HWY_AFTER_NAMESPACE();

// #if HWY_ONCE
// namespace hwy
// {
//     HWY_EXPORT(AddVectors);
// } // namespace hwy
// #endif

// const size_t length = 1024;
// float a[length], b[length], result[length];
// // Inicjalizacja a i b danymi
// hwy::AddVectors(a, b, result, length);

#include <immintrin.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    UTILS::clear_terminal();
    time_stamp("It just works");

    __m256i a = _mm256_set_epi32(10, 9, 8, 7, 6, 5, 4, 3);
    __m256i b = _mm256_set_epi32(3, 4, 5, 6, 7, 8, 9, 10);

    __m256i result = _mm256_add_epi32(a, b);

    int32_t* res = (int32_t*)&result;

    std::cout << "Wynik dodawania: ";
    for (int i = 0; i < 8; i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;

    time_stamp("DONE");
    return 0;
}
