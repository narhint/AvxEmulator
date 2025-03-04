#include <iostream>
#include <array>
#include <cstdint>
#include <immintrin.h>

class AvxEmulator {
public:
    AvxEmulator() {
        for (int i = 0; i < 16; ++i) {
            xmm[i] = _mm_setzero_si128();
            ymm[i] = _mm256_setzero_si256();
        }
    }

    __m128i emulated_sse2_add(__m128i a, __m128i b) {
        return _mm_add_epi32(a, b);
    }

    __m256i emulated_avx2_add(__m256i a, __m256i b) {
        return _mm256_add_epi32(a, b);
    }

    __m128i emulated_sse2_sub(__m128i a, __m128i b) {
        return _mm_sub_epi32(a, b);
    }

    __m256i emulated_avx2_sub(__m256i a, __m256i b) {
        return _mm256_sub_epi32(a, b);
    }

    __m128i emulated_sse2_mul(__m128i a, __m128i b) {
        return _mm_mullo_epi32(a, b);
    }

    __m256i emulated_avx2_mul(__m256i a, __m256i b) {
        return _mm256_mullo_epi32(a, b);
    }

    void run() {
        __m128i a_sse2 = _mm_set_epi32(1, 2, 3, 4);
        __m128i b_sse2 = _mm_set_epi32(5, 6, 7, 8);
        
        std::cout << "SSE2 Add Result: ";
        print_m128i(emulated_sse2_add(a_sse2, b_sse2));

        std::cout << "SSE2 Subtract Result: ";
        print_m128i(emulated_sse2_sub(a_sse2, b_sse2));

        std::cout << "SSE2 Multiply Result: ";
        print_m128i(emulated_sse2_mul(a_sse2, b_sse2));

        __m256i a_avx2 = _mm256_set_epi32(1, 2, 3, 4, 5, 6, 7, 8);
        __m256i b_avx2 = _mm256_set_epi32(9, 10, 11, 12, 13, 14, 15, 16);
        
        std::cout << "AVX2 Add Result: ";
        print_m256i(emulated_avx2_add(a_avx2, b_avx2));

        std::cout << "AVX2 Subtract Result: ";
        print_m256i(emulated_avx2_sub(a_avx2, b_avx2));

        std::cout << "AVX2 Multiply Result: ";
        print_m256i(emulated_avx2_mul(a_avx2, b_avx2));
    }

private:
    __m128i xmm[16];
    __m256i ymm[16];

    void print_m128i(__m128i vec) {
        int32_t* values = reinterpret_cast<int32_t*>(&vec);
        for (int i = 0; i < 4; ++i) {
            std::cout << values[i] << " ";
        }
        std::cout << std::endl;
    }

    void print_m256i(__m256i vec) {
        int32_t* values = reinterpret_cast<int32_t*>(&vec);
        for (int i = 0; i < 8; ++i) {
            std::cout << values[i] << " ";
        }
        std::cout << std::endl;
    }
};
