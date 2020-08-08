/*

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int i=0, j=numbers.size()-1, mid;
        vector<int> v;
        while(i<j)
        {
            mid = (numbers[i]+numbers[j]);
            if(mid==target)
            {
                v.push_back(i+1); v.push_back(j+1);
                return v;
            }
            
            else if(mid>target)
                j--;
            else
                i++;
        }
        
        v.push_back(i+1); v.push_back(j+1);  return v;
    }
};
