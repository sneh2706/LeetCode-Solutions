/*

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = nums.size();
        for(int i=0; i<n; ++i)
        {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        
        return pq.top();
    }
};
