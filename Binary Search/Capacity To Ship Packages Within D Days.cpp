/*

A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

*/

class Solution {
public:
    bool possible(vector<int> &weights, int x, int d)
    {
        int sum = x, count=1, n=weights.size(),i=0;
        while(i<n)
        {
            if(sum-weights[i]<0)
            {
                count++;
                sum = x;
            }
            
            else
            {
                sum -= weights[i];
                i++;
            }
            
            if(count>d)
                return false;
        }
        
        return true;
        
    }
    
    int shipWithinDays(vector<int>& weights, int d) 
    {
        int sum=0, n= weights.size();
        
        int minm = INT_MIN;
        for(int i=0; i<n; ++i) minm = max(minm,weights[i]);
        
        for(int i=0; i<n; ++i)
            sum += weights[i];
        
        int lo=minm, hi=sum, ans=INT_MAX;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(possible(weights,mid,d))
            {
                ans = min(ans,mid);
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        
        return ans;
        
    }
};
