#include "sha256.h"


static const uint32_t K256[64] = {
    0x428a2f98UL, 0x71374491UL, 0xb5c0fbcfUL, 0xe9b5dba5UL,
    0x3956c25bUL, 0x59f111f1UL, 0x923f82a4UL, 0xab1c5ed5UL,
    0xd807aa98UL, 0x12835b01UL, 0x243185beUL, 0x550c7dc3UL,
    0x72be5d74UL, 0x80deb1feUL, 0x9bdc06a7UL, 0xc19bf174UL,
    0xe49b69c1UL, 0xefbe4786UL, 0x0fc19dc6UL, 0x240ca1ccUL,
    0x2de92c6fUL, 0x4a7484aaUL, 0x5cb0a9dcUL, 0x76f988daUL,
    0x983e5152UL, 0xa831c66dUL, 0xb00327c8UL, 0xbf597fc7UL,
    0xc6e00bf3UL, 0xd5a79147UL, 0x06ca6351UL, 0x14292967UL,
    0x27b70a85UL, 0x2e1b2138UL, 0x4d2c6dfcUL, 0x53380d13UL,
    0x650a7354UL, 0x766a0abbUL, 0x81c2c92eUL, 0x92722c85UL,
    0xa2bfe8a1UL, 0xa81a664bUL, 0xc24b8b70UL, 0xc76c51a3UL,
    0xd192e819UL, 0xd6990624UL, 0xf40e3585UL, 0x106aa070UL,
    0x19a4c116UL, 0x1e376c08UL, 0x2748774cUL, 0x34b0bcb5UL,
    0x391c0cb3UL, 0x4ed8aa4aUL, 0x5b9cca4fUL, 0x682e6ff3UL,
    0x748f82eeUL, 0x78a5636fUL, 0x84c87814UL, 0x8cc70208UL,
    0x90befffaUL, 0xa4506cebUL, 0xbef9a3f7UL, 0xc67178f2UL
};

void SHA256::Init(uint32_t *s) {
	/*
	 These constants are the first 32 bits
	 of the fractional square roots of the
	 first eight simple numbers(2, 3, 5, 7, 11, 13, 17, 19)
	*/
	s[0] = 0x6a09e667UL;
	s[1] = 0xbb67ae85UL;
	s[2] = 0x3c6ef372UL;
	s[3] = 0xa54ff53aUL;
	s[4] = 0x510e527fUL;
	s[5] = 0x9b05688cUL;
	s[6] = 0x1f83d9abul;
	s[7] = 0x5be0cd19UL;
}

void SHA256::Transform() {
    
}

uint32_t SHA256::sigma0(uint32_t x) {
    return this->Rotr(x, 7) ^ this->Rotr(x, 18) ^ (x >> 3);
}

uint32_t SHA256::sigma1(uint32_t x) {
    return this->Rotr(x, 17) ^ this->Rotr(x, 19) ^ (x >> 10);
}

uint32_t SHA256::Sigma0(uint32_t x) {
    return this->Rotr(x, 2) ^ this->Rotr(x, 13) ^ (x >> 22);
}

uint32_t SHA256::Sigma1(uint32_t x) {
    return this->Rotr(x, 6) ^ this->Rotr(x, 11) ^ (x >> 25);
}

uint32_t SHA256::Rotr(uint32_t x, uint32_t n) {
    // Returns the result of bitwise right-rotating the value of x by n positions
    return (x >> n) | (x << (32 - n));
}

SHA256::SHA256() {
	this->Init(s);
}