#pragma once
#include <functional>

int binSearch(int low, int high, const std::function<bool(int)> fun);
int binSearchP(int low, int high, bool (*fun)(int) );

// [low, high)
int binSearch(int low, int high, const std::function<bool(int)> fun)
{
    // 和可能造成溢出
    // low <= mid < high
    int mid = (low + high)>>1;

    if( mid == low )
    {
        return low;
    }
    
    if( fun(mid) )
    {
        return binSearch(mid, high, fun);
    }else
    {
        return binSearch(low, mid, fun);
    }
}

// [low, high)
int binSearchP(int low, int high, bool (*fun)(int) )
{
    // 和可能造成溢出
    // low <= mid < high
    int mid = (low + high)>>1;

    if( mid == low )
    {
        return low;
    }
    
    if( fun(mid) )
    {
        return binSearchP(mid, high, fun);
    }else
    {
        return binSearchP(low, mid, fun);
    }
}