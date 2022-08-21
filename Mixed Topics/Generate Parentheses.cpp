class Solution {
public:
    
    void backtrack(vector<string> &res, string curr_str, int curr_sum, int n) {
        
        if (curr_str.size() == 2*n) {
            if(curr_sum == 0) {
                res.push_back(curr_str);
            }
            return;
        }
        
        if(curr_sum >= 0) {
            backtrack(res, curr_str+'(', curr_sum+1, n);
        } 
        
        if(curr_sum > 0) {
            backtrack(res, curr_str+')', curr_sum-1, n);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, n);
        return res;
    }
};

