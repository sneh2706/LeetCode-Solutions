/*

You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

*/

class Solution {
public:
    int arrangeCoins(int n) 
    {
        long lo=0, hi=n;
        while(lo<hi)
        {
            long mid = lo+(hi-lo+1)/2;
            if(mid*(mid+1)/2.0 <= n)
                lo = mid;
            else
                hi = mid-1;
        }
        
        return hi;
    }
};
