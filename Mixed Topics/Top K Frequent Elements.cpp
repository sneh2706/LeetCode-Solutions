class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; ++i) {
            mp[nums[i]]++;
        }
        priority_queue<tuple<int, int>> pq;
        for(auto it=mp.begin(); it!=mp.end(); ++it) {
            pq.push(make_tuple(it->second, it->first));
        }
        vector<int> res;
        while(!pq.empty() && k>0) {
            res.push_back(get<1>(pq.top()));
            k--;
            pq.pop();
        }
        return res;
    }
};
