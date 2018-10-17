### QBSort

I don't ensure its time complexity. It is a mutation from quick sort, but with a constant maximum depth of recursion which is 63 for 64-bit ints, 31 for 32-bit ints, and 7 for bytes. It is diffenent from original quick sort that has average log n depth. By my experience, compared to the built-in std::sort algorithm in VS2017, this might be 5-25% slower if the array size is less than 2.2e9, than its speed exceeds.
For signed type, the first round function call should be inverse to make the result correct.

The core is simple:
"""
void qbsort(unitype* begin, unitype* end, int p)
{
    if (begin >= end - 1) return; // A case that the bit array is empty
    if (p < 0) return; // A case that the call reachs a leaf

    unitype* lhs = begin;
    unitype* rhs = end - 1;
    unitype temp;

    for (;;)
    {
        while (((*lhs >> p) & 1) != 1 && lhs != end) ++lhs;
        while (((*rhs >> p) & 1) != 0) --rhs;
        if (lhs < rhs
        {
            temp = *lhs;
            *lhs = *rhs;
            *rhs = temp;
        }
        else if (lhs > rhs) break;
    }
    qbsort(lhs, end, p - 1);
    qbsort(begin, lhs, p - 1);
}

void qsort(unitype* begin, unitype* end)
{
    qbsort(begin, end, sizeof(unitype) * 8 - 1);
}
"""
In above code, a unitype can be any type with fixed length. I have not made it to be a template function due to my leak of ability :(