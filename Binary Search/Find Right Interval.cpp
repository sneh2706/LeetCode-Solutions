/*

Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:

You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.

*/

class Solution {
public:
    int search(vector<pair<int,int>> &v, int x)
    {
        int n = v.size(), lo=0, hi=n-1;
        
        if(x<v[0].first || x>v[n-1].first)
            return -1;
    
        while(lo<hi)
        {
            int mid = lo+(hi-lo)/2;
            if(v[mid].first < x)
                lo = mid+1;
            else
                hi = mid;
        }
        
        return v[lo].second;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; ++i)
            v.push_back(make_pair(intervals[i][0],i));
        
        sort(v.begin(),v.end());
        
        // for(int i=0; i<n; ++i)
            // cout << v[i].first << " " << v[i].second << endl;
         
        vector<int> ans(n);
        for(int i=0; i<n; ++i)
        {
            int x = intervals[i][1];
            ans[i] = search(v,x);
        }
        
        return ans;
    }
};