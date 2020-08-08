class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) 
    {
         int n = nums.size(), low=0, high=n-1, mid;

        while(low<high)
        {
            mid = low+ (high-low)/2;
            if(nums[mid]>nums[mid+1])
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};
