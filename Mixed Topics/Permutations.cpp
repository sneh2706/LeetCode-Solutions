class Solution {
public:
    void findPermutations(vector<vector<int>> &res, vector<int> currPermut, int i, vector<int> &nums) {
        if(i == nums.size()) {
            res.push_back(currPermut);
            return;
        } 
        int currPermutSz = currPermut.size();
        for(int a=0; a<=currPermutSz; ++a) {
            vector<int> newCurrPermut = currPermut;
            vector<int>:: iterator it = newCurrPermut.begin() + a;
            newCurrPermut.insert(it, nums[i]);
            findPermutations(res, newCurrPermut, i+1, nums);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currPermut;
        findPermutations(res, currPermut, 0, nums);
        return res;
    }
};
