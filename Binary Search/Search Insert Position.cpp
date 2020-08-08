/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

*/

class Solution {
public:
    int res;
    
    bool found(vector<int> &v, int x)
    {
        int n = v.size(), lo = 0, hi = n-1, mid;
        
        while(lo<=hi)
        {
            mid = lo+(hi-lo)/2;
            if(v[mid]==x)
            {
                res = mid;
                return true;
            }
            
            else if(v[mid]>x)
                hi = mid-1;
            else
                lo = mid+1;
        }
        
        return false;
    }
    
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size(), lo = 0, hi = n-1,mid;
        
        if(target>nums[n-1])
            return n;
        
        if(found(nums,target))
            return res;
        
        
        
        while(lo<hi)
        {
            mid = lo+(hi-lo)/2;
            if(nums[mid]<=target)
                lo = mid+1;
            else
                hi = mid;
        }
        
        return lo;
    }
};
