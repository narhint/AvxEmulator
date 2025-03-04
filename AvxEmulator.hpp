#include <iostream>
#include <array>
#include <cstdint>
#include <immintrin.h>
#include <stdexcept>
#include <vector>
#include <string>
#include <unordered_map>

class AvxEmulator {
public:
    AvxEmulator() {
        for (int i = 0; i < 16; ++i) {
            xmm[i] = _mm_setzero_si128(); // Initialize XMM registers to zero
            ymm[i] = _mm256_setzero_si256(); // Initialize YMM registers to zero
        }
        memory.resize(1024); // Simple memory model
    }

    // Integer Operations
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

    // Floating-Point Operations
    __m128 emulated_sse2_add_float(__m128 a, __m128 b) {
        return _mm_add_ps(a, b);
    }

    __m256 emulated_avx2_add_float(__m256 a, __m256 b) {
        return _mm256_add_ps(a, b);
    }

    // Memory Operations
    void store_to_memory(int address, __m128i value) {
        if (address < 0 || address + sizeof(__m128i) > memory.size()) {
            throw std::out_of_range("Memory access out of bounds");
        }
        std::memcpy(&memory[address], &value, sizeof(__m128i));
    }

    __m128i load_from_memory(int address) {
        if (address < 0 || address + sizeof(__m128i) > memory.size()) {
            throw std::out_of_range("Memory access out of bounds");
        }
        __m128i value;
        std::memcpy(&value, &memory[address], sizeof(__m128i));
        return value;
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

        // Example of memory operations
        store_to_memory(0, a_sse2);
        std::cout << "Loaded from Memory: ";
        print_m128i(load_from_memory(0));
    }

private:
    __m128i xmm[16]; // Array of 16 XMM registers (128-bit)
    __m256i ymm[16]; // Array of 16 YMM registers (256-bit)
    std::vector<uint8_t> memory; // Simple memory model

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
