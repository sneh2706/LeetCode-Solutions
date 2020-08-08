/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

*/


class Solution {
public:
    int find(vector<int> &nums, int target, int flag) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int ind = -1;
        
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target) {
                ind = mid;
                if(flag==0) hi = mid-1;
                else lo = mid+1;
            }
            else if(nums[mid]<target) lo = mid+1;
            else hi = mid-1;
        }
        return ind;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first_occ = find(nums,target,0);
        int last_occ = find(nums,target,1);
        vector<int> res(2);
        res[0] = first_occ;
        res[1] = last_occ;
        
        return res;
    }
};
