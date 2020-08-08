/*

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) 
    {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        int res = INT_MIN;
        
        for(int i=m-1; i>=0; --i)
        {
            for(int j=n-1; j>=0; --j)
                res = max(res, dp[i][j] = A[i]==B[j]?1+dp[i+1][j+1]:0);
        }
        return res;
    }
};