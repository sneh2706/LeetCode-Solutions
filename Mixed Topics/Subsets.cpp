class Solution {
public:
    void backtrack(
        int num_len, 
        int curr_pos, 
        vector<vector<int>> &res, 
        vector<int> curr_vec,
        vector<int> &nums) {
        
        if(curr_pos == num_len){
            return;
        }
        
        vector<int> include = curr_vec;
        include.push_back(nums[curr_pos]);
        res.push_back(include);
        
        
        backtrack(num_len, curr_pos+1, res, include, nums);
        backtrack(num_len, curr_pos+1, res, curr_vec, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        res.push_back(curr);
        backtrack(nums.size(), 0, res, curr, nums);
        return res;
    }
};
