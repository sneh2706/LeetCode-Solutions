/*

Given a non-empty array of integers, return the k most frequent elements.

*/

class Solution {
public:
    struct nodes{
      int val;
      int times;
    };
    
    struct compare{
      bool operator()(const nodes &n1, const nodes &n2)
      {
          return n1.times < n2.times;
      }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> umap;
        int n = nums.size();
        
        for(int i=0; i<n; ++i)
            umap[nums[i]]++;
        
        priority_queue<nodes, vector<nodes>, compare> pq;
        
        for(auto it=umap.begin(); it!=umap.end(); ++it)
        {
            nodes temp;
            temp.val = (*it).first;
            temp.times = (*it).second;
            pq.push(temp);
        }
        
        vector<int> res;
        while(k>0)
        {
            res.push_back((pq.top()).val);
            pq.pop();
            k--;
        }
        
        return res;
        
    }
};
