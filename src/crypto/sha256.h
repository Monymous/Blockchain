#pragma once
#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <stdint.h>
#include <cstdlib>

class SHA256 {
private:
	uint32_t s[8];
	void Init(uint32_t *s);
	void Transform();

	uint32_t sigma0(uint32_t x);
	uint32_t sigma1(uint32_t x);
	uint32_t Sigma0(uint32_t x);
	uint32_t Sigma1(uint32_t x);
	uint32_t Rotr(uint32_t x, uint32_t n);

public:
	SHA256();
};

#endif // !SHA256_
