/*

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

*/

class Solution {
public:
    int mySqrt(int x) 
    {
        if(x<=1)
            return x;
        int lo=1, hi=x, res;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(mid <= x/mid)
            {
                res = mid;
                lo = mid+1;
            }
            
            else
                hi=mid-1;
        }
        
        return res;
    }
};
