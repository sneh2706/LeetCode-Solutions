/*

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> temp = nums1;
        int i=0, j=0, k=0;
        while(i<m && j<n) {
            if(temp[i] < nums2[j]) {
                nums1[k] = temp[i];
                i++;
            } 
            else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
        
        while(i<m) {
            nums1[k] = temp[i];
            i++;
            k++;
        }
        
        while(j<n) {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
        
    }
};
