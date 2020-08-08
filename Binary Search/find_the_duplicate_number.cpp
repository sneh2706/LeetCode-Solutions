// Another approach - Using bits (will be implementing later.)

class Solution {
public:  
    int solve(int x, vector<int> &v)
    {
        int n = v.size();
        int lo = 0, hi = n-1, mid;
        
        int res = 0;
        
        while(lo<=hi)
        {
            mid = lo+(hi-lo)/2;
            if(v[mid]>=x)
            {
                res = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        
        lo = 0, hi = n-1;
        int res1 = 0;
        
        while(lo<=hi)
        {
            mid = lo+(hi-lo)/2;
            if(v[mid]<=x)
            {
                res1 = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        
        return abs(res-res1);
    }
    
    int findDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set<int> s;
        int n = nums.size();
        
        for(int i=0; i<n; ++i)
            s.insert(nums[i]);
        
        for(auto it=s.begin(); it!=s.end(); ++it)
        {
            int x = (*it);
            if(solve(x,nums)==0)
                continue;
            else
                return x;
        }
        
        return 0;
    }
};

// Complexity of above solution - Time: O(nlogn), space : O(n)
