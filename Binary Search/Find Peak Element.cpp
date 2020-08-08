/*

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

*/

class Solution {
public:
    int find_peak(vector<int> &v,int lo,int hi) {
    int n = v.size();
    int mid = lo+(hi-lo)/2;
    if((mid==0 || v[mid-1]<=v[mid]) && (mid==n-1 || v[mid]>=v[mid+1]))
    return mid;
    else if(mid>0 && v[mid-1]>v[mid])
    return find_peak(v,lo,mid-1);
    else
    return find_peak(v,mid+1,hi);
   }
    
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return find_peak(nums,0,n-1);
    }
};
