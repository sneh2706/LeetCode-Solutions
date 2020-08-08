/*

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int i=0, j=n-1;
        
        while(i<j) {
            if(nums[i]!=0 && nums[j]==0) {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else if(nums[i]!=0) j--;
            else if(nums[i]==0 && nums[j]==0) i++;
            else if(nums[i]==0) {
                i++;
                j--;
            }
        }
        
        
        for(int k=0; k<n; ++k) {
            if(nums[k]!=0) {
                i=k;
                break;
            }
        }
        
        j=n-1;
        while(i<j) {
            if(nums[i]!=1 && nums[j]==1) {
                swap(nums[i],nums[j]);
                i++;
                j--;
            } 
            else if(nums[i]!=1) j--;
            else if(nums[i]==1 && nums[j]==1) i++;
            else if(nums[i]==1) {
                i++;
                j--;
            }
        }
        
    }
};
