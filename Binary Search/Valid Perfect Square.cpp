/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

*/

class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num<=1) return true;
        if(num<=3) return false;
        long long int lo=1, hi=num/2;
        while(lo<=hi)
        {
            long long int mid = lo+(hi-lo)/2;
            if(mid*mid==num) return true;
            else if(mid*mid>num)
                hi=mid-1;
            else
                lo=mid+1;
        }
        if(lo*lo==num) return true;
        return false;
    }
};
