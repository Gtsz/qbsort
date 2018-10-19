#include "algorithm.h"

#include <iostream> //test
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

//void qbsort(unitype* begin, unitype* end, int p)
//{
//    if (begin >= end - 1) return;
//    if (p < 0) return;
//
//    unitype* lhs = begin;
//    unitype* rhs = end - 1;
//    unitype temp;
//
//    for (;;)
//    {
//        /*
//        printf("%X %X %d\n", lhs, rhs, p);
//        for (unitype* it = begin; it < end; ++it) { printb(*it); printf(" "); } printf("\n");
//        for (unitype* it = begin; it < end; ++it) printf("%.1X ", (*it >> (p + 1)) & 1); printf("\n");
//        for (unitype* it = begin; it < end; ++it) printf("%.1X ", (*it >> p) & 1); printf("\n");
//        //for (unitype* it = begin; it < end; ++it) printf("%.1X ", (*it >> (p - 1)) & 1); printf("\n");
//        printf("\n");
//        */
//
//        while (((*lhs >> p) & 1) != 0 && lhs != end) ++lhs; // { ++lhs; printf("lhs++\n"); }
//        while (((*rhs >> p) & 1) != 1 && rhs != begin - 1) --rhs; // { --rhs; printf("rhs--\n"); }
//        //while (((*lhs >> p) & 1) != 0) ++lhs; // { ++lhs; printf("lhs++\n"); }
//        //while (((*rhs >> p) & 1) != 1 && rhs != begin - 1) --rhs; // { --rhs; printf("rhs--\n"); }
//        //while (((*lhs >> p) & 1) != 0 && lhs != end) ++lhs; // { ++lhs; printf("lhs++\n"); }
//        //while (((*rhs >> p) & 1) != 1) --rhs; // { --rhs; printf("rhs--\n"); }
//        //while (!((*lhs >> p) & 1) && lhs != end    ) ++lhs; // { ++lhs; printf("lhs++\n"); }
//        //while ( ((*rhs >> p) & 1) && rhs != begin-1) --rhs; // { --rhs; printf("rhs--\n"); }
//        if (lhs < rhs)
//        { // swap
//            temp = *lhs;
//            *lhs = *rhs;
//            *rhs = temp;
//        }
//        else if (lhs > rhs) break;
//    }
//
//    qbsort(begin, lhs, p - 1);
//    qbsort(lhs, end, p - 1);
//}


void qbsort(unitype* begin, unitype* end, int p)
{ // A mutation from quick sort with linear time complexity.
  // It works within the range [begin, end)
  // A bit array represents the p th digits of the sorting array.

    if (begin >= end - 1) return; // A case that the bit array is empty
    if (p < 0) return; // A case that the call reachs a leaf

    unitype* lhs = begin;
    unitype* rhs = end - 1;
    unitype temp;

    for (;;)
    {
        // Finding the first 0 or 1 (according to the sort order) 
        // from edge to median.
        while (((*lhs >> p) & 1) != 1 && lhs != end) ++lhs;
        while (((*rhs >> p) & 1) != 0) --rhs;
        if (lhs < rhs) // It means the bit array is not sorted completely
        { // Swap
            temp = *lhs;
            *lhs = *rhs;
            *rhs = temp;
        }
        else if (lhs > rhs) break;
        // There is no case that lhs==rhs because we want lhs exceeds rhs so
        // that lhs is able to become the "end" for recursive call.
    }

    /* 
    *  The left subarray should be call first in single-thread
    *  so that the compiler can do tail optimization if the current bit
    *  array is all 0
    */
    qbsort(lhs, end, p - 1);
    qbsort(begin, lhs, p - 1);
}

void qbsort_reverse(unitype* begin, unitype* end, int p)
{ // A reverse version to qbsort
    if (begin >= end - 1) return;
    if (p < 0) return;

    unitype* lhs = begin;
    unitype* rhs = end - 1;
    unitype temp;

    for (;;)
    {
        while (((*lhs >> p) & 1) != 0 && lhs != end) ++lhs;
        while (((*rhs >> p) & 1) != 1) --rhs;
        if (lhs < rhs)
        {
            temp = *lhs;
            *lhs = *rhs;
            *rhs = temp;
        }
        else if (lhs > rhs) break;
    }

    qbsort_reverse(lhs, end, p - 1);
    qbsort_reverse(begin, lhs, p - 1);
}

void qbsort_stable(unitype* begin, unitype* end, int p)
{
    if (begin >= end - 1) return;
    if (p < 0) return;

    unsigned count1 = 0;
    for (unitype* it = begin; it != end; ++it)
        if ((*it >> p) & 1) ++count1;

    unitype* devide = end - count1;
    unitype* fs0 = begin;
    unitype* fs1 = devide;
    unitype temp;

    for (;;)
    {
        while (((*fs0 >> p) & 1) != 1 && fs0 != devide) ++fs0; // find the first "1" in range[begin,divide)
        while (((*fs1 >> p) & 1) != 0 && fs1 != end) ++fs1;
        if (fs0 != devide && fs1 != end)
        {
            temp = *fs0;
            *fs0 = *fs1;
            *fs1 = temp;
        }
        else break;
    }

    qbsort_stable(begin, devide, p - 1);
    qbsort_stable(devide, end, p - 1);
}

void qbsort(unitype* begin, unitype* end)
{
    qbsort(begin, end, sizeof(unitype) * 8 - 1);
}

void qbsort_stable(unitype* begin, unitype* end)
{
    qbsort_stable(begin, end, sizeof(unitype) * 8 - 1);
}

void qbsort_signed(sigtype* begin, sigtype* end)
{ // Reversely sort the first digits
    if (begin >= end - 1) return;
    int p = sizeof(sigtype) * 8 - 1;

    sigtype* lhs = begin;
    sigtype* rhs = end - 1;
    sigtype temp;

    for (;;)
    {
        while (((*lhs >> p) & 1) != 0 && lhs != end) ++lhs;
        while (((*rhs >> p) & 1) != 1) --rhs;
        if (lhs < rhs)
        {
            temp = *lhs;
            *lhs = *rhs;
            *rhs = temp;
        }
        else if (lhs > rhs) break;
    }

    qbsort((unitype*) begin, (unitype*) lhs, p - 1);
    qbsort((unitype*) lhs, (unitype*) end, p - 1);
}

void qbsort_float(flotype* begin, flotype* end)
{
    sigtype* ibegin = (sigtype*) begin;
    sigtype* iend = (sigtype*) end;

    if (begin >= end - 1) return;
    int p = sizeof(sigtype) * 8 - 1;

    sigtype* lhs = ibegin;
    sigtype* rhs = iend - 1;
    sigtype temp;

    for (;;)
    {
        while (((*lhs >> p) & 1) != 0 && lhs != iend) ++lhs;
        while (((*rhs >> p) & 1) != 1) --rhs;
        if (lhs < rhs)
        {
            temp = *lhs;
            *lhs = *rhs;
            *rhs = temp;
        }
        else if (lhs > rhs) break;
    }

    qbsort_reverse((unitype*) ibegin, (unitype*) lhs, p - 1);
    qbsort((unitype*) lhs, (unitype*) iend, p - 1);
}