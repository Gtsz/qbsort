#include "algorithm.h"
#include "algorithm_m.h"

#include <iostream>
//#include <cstdlib>
#include "randam.h"
#include <algorithm>
#include <chrono>

using namespace std::chrono;

int main()
{
    microseconds t1, t2;
    unsigned BASE = 100; //2000000000;
    unsigned STEP = 1000; //100000000;
    unsigned TRIAL = 1; //25

    /*
    printf("qbsort_m:\n");
    for (unsigned n = BASE, k = 1; k <= TRIAL; ++k)
    {
        printf("Round %d: Sorting %d integers\n", k, n);
        unitype* nums = new unitype[n];
        srand(21);
        for (unsigned i = 0; i < n; ++i) nums[i] = rand() | rand() << 16 | rand() << 32 | rand() << 48;

        //printf("Unsorted:\n");  for (int i = 0; i < N; ++i) printf("%.8X ", nums[i]); printf("\n");
        t1 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        qsort_m(nums, nums + n);
        t2 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        //printf("Sorted:\n");  for (int i = 0; i < N; ++i) printf("%.8X ", nums[i]); printf("\n");

        for (unsigned i = 1; i < n; ++i) if (nums[i - 1] > nums[i])
        {
            printf("Wrong sort at %d\n", i);
            break;
        }

        printf("Time used: %dus\n", t2 - t1);

        delete[] nums;

        n *= MULTIPLE;
    }
    */

    printf("qbsort:\n");
    for (unsigned n = BASE, k = 1; k <= TRIAL; ++k)
    {
        printf("Round %d: Sorting %u integers\n", k, n);
        unitype* nums = new unitype[n];
        srand64(21);
        for (unsigned i = 0; i < n; ++i) nums[i] = rand64(); // rand() | rand() << 16;

        //printf("Unsorted:\n");  for (int i = 0; i < n; ++i) printf("%.8X ", nums[i]); printf("\n");
        t1 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        qbsort(nums, nums + n);
        t2 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        //printf("Sorted:\n");  for (int i = 0; i < n; ++i) printf("%.8X ", nums[i]); printf("\n");

        for (unsigned i = 1; i < n; ++i) if (nums[i - 1] > nums[i])
        {
            printf("Wrong sort at %u\n", i);
            break;
        }

        printf("Time used: %dus\n", t2 - t1);

        delete[] nums;

        n += STEP;
    }

    printf("qbsort_stable:\n");
    for (unsigned n = BASE, k = 1; k <= TRIAL; ++k)
    {
        printf("Round %d: Sorting %u integers\n", k, n);
        unitype* nums = new unitype[n];
        srand64(21);
        for (unsigned i = 0; i < n; ++i) nums[i] = rand64(); // rand() | rand() << 16;

        //printf("Unsorted:\n");  for (int i = 0; i < n; ++i) printf("%.8X ", nums[i]); printf("\n");
        t1 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        qbsort_stable(nums, nums + n);
        t2 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        //printf("Sorted:\n");  for (int i = 0; i < n; ++i) printf("%.8X ", nums[i]); printf("\n");

        for (unsigned i = 1; i < n; ++i) if (nums[i - 1] > nums[i])
        {
            printf("Wrong sort at %u\n", i);
            break;
        }

        printf("Time used: %dus\n", t2 - t1);

        delete[] nums;

        n += STEP;
    }

    printf("qbsort_signed:\n");
    for (unsigned n = BASE, k = 1; k <= TRIAL; ++k)
    {
        printf("Round %d: Sorting %u integers\n", k, n);
        sigtype* nums = new sigtype[n];
        unitype* raws = (unitype*) nums;
        srand64(21);
        for (unsigned i = 0; i < n; ++i) raws[i] = rand64(); // rand() | rand() << 16;

        //printf("Unsorted:\n");  for (int i = 0; i < n; ++i) printf("%d ", nums[i]); printf("\n");
        t1 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        qbsort_signed(nums, nums + n);
        t2 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        //printf("Sorted:\n");  for (int i = 0; i < n; ++i) printf("%d ", nums[i]); printf("\n");

        for (unsigned i = 1; i < n; ++i) if (nums[i - 1] > nums[i])
        {
            printf("Wrong sort at %u\n", i);
            break;
        }

        printf("Time used: %dus\n", t2 - t1);

        delete[] nums;

        n += STEP;
    }

    printf("qbsort_float:\n");
    for (unsigned n = BASE, k = 1; k <= TRIAL; ++k)
    {
        printf("Round %d: Sorting %u floats\n", k, n);
        flotype* nums = new flotype[n];
        unitype* raws = (unitype*) nums;
        srand64(21);
        for (unsigned i = 0; i < n; ++i) raws[i] = rand64(); // rand() | rand() << 16;

        //printf("Unsorted:\n");  for (int i = 0; i < n; ++i) printf("%g ", nums[i]); printf("\n");
        t1 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        qbsort_float(nums, nums + n);
        t2 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        //printf("Sorted:\n");  for (int i = 0; i < n; ++i) printf("%g ", nums[i]); printf("\n");

        for (unsigned i = 1; i < n; ++i) if (nums[i - 1] > nums[i])
        {
            printf("Wrong sort at %u\n", i);
            break;
        }

        printf("Time used: %dus\n", t2 - t1);

        delete[] nums;

        n += STEP;
    }

    printf("std::sort(uint):\n");
    for (unsigned n = BASE, k = 1; k <= TRIAL; ++k)
    {
        printf("Round %d: Sorting %u integers\n", k, n);
        unitype* nums = new unitype[n];
        srand64(21);
        for (unsigned i = 0; i < n; ++i) nums[i] = rand64(); // rand() | rand() << 16;

        //printf("Unsorted:\n");  for (int i = 0; i < N; ++i) printf("%.8X ", nums[i]); printf("\n");
        t1 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        std::sort(nums, nums + n);
        t2 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        //printf("Sorted:\n");  for (int i = 0; i < N; ++i) printf("%.8X ", nums[i]); printf("\n");

        for (unsigned i = 1; i < n; ++i) if (nums[i - 1] > nums[i])
        {
            printf("Wrong sort at %u\n", i);
            break;
        }

        printf("Time used: %dus\n", t2 - t1);

        delete[] nums;

        n += STEP;
    }

    printf("std::sort(float):\n");
    for (unsigned n = BASE, k = 1; k <= TRIAL; ++k)
    {
        printf("Round %d: Sorting %u integers\n", k, n);
        flotype* nums = new flotype[n];
        unitype* raws = (unitype*) nums;
        srand64(21);
        for (unsigned i = 0; i < n; ++i) raws[i] = rand64(); // rand() | rand() << 16;

        printf("Unsorted:\n");  for (int i = 0; i < n; ++i) printf("%g ", nums[i]); printf("\n");
        t1 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        std::sort(nums, nums + n);
        t2 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        printf("Sorted:\n");  for (int i = 0; i < n; ++i) printf("%g\n", nums[i]); printf("\n");

        for (unsigned i = 1; i < n; ++i) if (nums[i - 1] > nums[i])
        {
            printf("Wrong sort at %u\n", i);
            break;
        }

        printf("Time used: %dus\n", t2 - t1);

        delete[] nums;

        n += STEP;
    }

    /*
    printf("std::stable_sort:\n");
    for (unsigned n = BASE, k = 1; k <= TRIAL; ++k)
    {
        printf("Round %d: Sorting %u integers\n", k, n);
        unitype* nums = new unitype[n];
        srand(21);
        for (unsigned i = 0; i < n; ++i) nums[i] = rand() | rand() << 16 | rand() << 32 | rand() << 48;

        //printf("Unsorted:\n");  for (int i = 0; i < N; ++i) printf("%.8X ", nums[i]); printf("\n");
        t1 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        std::stable_sort(nums, nums + n);
        t2 = duration_cast<microseconds>(system_clock::now().time_since_epoch());
        //printf("Sorted:\n");  for (int i = 0; i < N; ++i) printf("%.8X ", nums[i]); printf("\n");

        for (unsigned i = 1; i < n; ++i) if (nums[i - 1] > nums[i])
        {
            printf("Wrong sort at %u\n", i);
            break;
        }

        printf("Time used: %dus\n", t2 - t1);

        delete[] nums;

        n += MULTIPLE;
    }
    */

    getchar();
    return 0;
}