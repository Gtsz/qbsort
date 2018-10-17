#pragma once
#define THRESHOLD 65536*2

#include <thread>
#include <list>

typedef unsigned int unitype;

void qbsort_m(unitype* begin, unitype* end, int p, std::list<std::thread>*);
void qsort_m(unitype* begin, unitype* end);
