/*

Given two arrays, write a function to compute their intersection.

*/


class Solution {
public:
    bool find(vector<int> &v, int x)
    {
        int lo = 0, hi = v.size()-1, mid;
        while(lo<=hi)
        {
            mid = lo+(hi-lo)/2;
            if(v[mid]==x)
            {
                v.erase(v.begin()+mid);
                return true;
            }
            
            else if(v[mid]>x)
                hi = mid-1;
            else
                lo = mid+1;
        }
        
        return false;
        
    }
    
    vector<int> solve(vector<int> &v1, vector<int> &v2)
    {
        vector<int> res;
        sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
        for(int i=0; i<v1.size(); ++i)
        {
            if(find(v2,v1[i]))
                res.push_back(v1[i]);
        }
        
        return res;
    }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size(), n = nums2.size();
        if(m<n)
            return solve(nums1,nums2);
        else
            return solve(nums2,nums1);
    }
};
