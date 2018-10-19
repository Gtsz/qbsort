#pragma once


typedef unsigned int unitype;
void qbsort(unitype* begin, unitype* end);
void qbsort_stable(unitype* begin, unitype* end);

typedef signed int sigtype;
void qbsort_signed(sigtype* begin, sigtype* end);

typedef float flotype;
void qbsort_float(flotype* begin, flotype* end);

union unit32
{
    unsigned int u;
    signed int d;
    float f;
    unsigned char b[4];
};

union unit64
{
    unsigned long long int u;
    signed long long int d;
    double f;
    unsigned char b[8];
};