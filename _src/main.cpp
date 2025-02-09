#include "__preprocessor__.h"
#include "__time_stamp__.h"

#include "hwy/highway.h"

HWY_BEFORE_NAMESPACE();
namespace hwy
{
    namespace HWY_NAMESPACE
    {

        void AddVectors(const float* HWY_RESTRICT a,
                        const float* HWY_RESTRICT b, float* HWY_RESTRICT result,
                        size_t length)
        {
            const HWY_FULL(float) d;
            for (size_t i = 0; i < length; i += Lanes(d))
            {
                const auto va = Load(d, a + i);
                const auto vb = Load(d, b + i);
                const auto vresult = Add(va, vb);
                Store(vresult, d, result + i);
            }
        }

    } // namespace HWY_NAMESPACE
} // namespace hwy
HWY_AFTER_NAMESPACE();
HWY_EXPORT(AddVectors);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    UTILS::clear_terminal();
    time_stamp("It just works");

    const size_t length = 1024;
    float a[length], b[length], result[length];
    // Inicjalizacja a i b danymi
    hwy::AddVectors(a, b, result, length);

    time_stamp("DONE");
    return 0;
}
