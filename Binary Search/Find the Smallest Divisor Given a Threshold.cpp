/*

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

*/

class Solution {
public:
    int predicate(vector<int> &nums, int sums)
    {
        int sum=0;
        for(int i=0; i<nums.size(); ++i)
            sum += (ceil((float)nums[i]/sums));
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int maxm = INT_MIN;
        for(int i=0; i<nums.size(); ++i)
            maxm = max(maxm,nums[i]);
        
        int low = 1, high = maxm , mid;
        
        while(low<high)
        {
            mid = low+(high-low)/2;
            if(predicate(nums,mid)<=threshold)
                high = mid;
            else
                low = mid+1;
        }
        
        return low;
    }
};