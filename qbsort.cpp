#include "algorithm.h"

//#include <iostream> //test
//using std::cout;
/*
void printb(unitype x)
{
    for (int i = 0; i < sizeof(unitype)*8; ++i)
    {
        if (x & 1) printf("1");
        else printf("0");
        x >>= 1;
    }
}
*/

//template <class unitype>
//typedef unsigned int unitype;
void qbsort(unitype* begin, unitype* end, int p)
{
    if (begin >= end - 1) return;
    if (p < 0) return;

    unitype* lhs = begin;
    unitype* rhs = end - 1;

    for (;;)
    {
        /*
        printf("%X %X %d\n", lhs, rhs, p);
        for (unitype* it = begin; it < end; ++it) { printb(*it); printf(" "); } printf("\n");
        for (unitype* it = begin; it < end; ++it) printf("%.1X ", (*it >> (p + 1)) & 1); printf("\n");
        for (unitype* it = begin; it < end; ++it) printf("%.1X ", (*it >> p) & 1); printf("\n");
        //for (unitype* it = begin; it < end; ++it) printf("%.1X ", (*it >> (p - 1)) & 1); printf("\n");
        printf("\n");
        */

        while (((*lhs >> p) & 1) != 1 && lhs <= end - 1) ++lhs; // { ++lhs; printf("lhs++\n"); }
        while (((*rhs >> p) & 1) != 0 && rhs >= begin) --rhs; // { --rhs; printf("rhs--\n"); }
        if (lhs < rhs)
        {
            unitype temp = *lhs;
            *lhs = *rhs;
            *rhs = temp;
        }
        else if (lhs > rhs) break;
    }

    qbsort(begin, lhs, p - 1);
    qbsort(lhs, end, p - 1);
}

void qsort(unitype* begin, unitype* end)
{
    qbsort(begin, end, sizeof(unitype) * 8 - 1);
}