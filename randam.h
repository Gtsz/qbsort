#pragma once

typedef unsigned long long int uint;
// uint type can be changed to any unsigned
// the bigger the better
const uint K = sizeof(uint) * 8 / 2 - 1;
// (sqrt) -> (/2) and (/2) –> (-1)
const uint M = -1; // the largest
static uint n;

uint rand64()
{ // bit form to m := 4 * m * (1 - m)
  // where m <- (0,1) and n <- (0,M)
  // where (0,M) -> (0,1)
    n = (n >> K) * (~n >> K) | (n >> K) & 1;
    return n;
}

void srand64(uint seed)
{ // let V = (0,M)\{M/2,M/2+1}
  // if seed <- V
  // then n </- V (n <- Z+)
    if (seed == 0 || seed == M / 2
        || seed == M / 2 + 1 || seed == M)
        seed += M / 3; // shift if invalid
    n = seed << K; // sensitive to ones
    for (uint i = 0; i<20; ++i)
        rand64(); // initializing
}