/*

Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

*/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<pair<int,int>> v;
        for(int i=0; i<mat.size(); ++i)
        {
            int counts = 0;
            for(int j=0; j<mat[i].size(); ++j)
                if(mat[i][j]==1)
                    counts++;
            v.push_back(make_pair(counts,i));
        }
        
        sort(v.begin(), v.end());
        
        vector<int> ans;
        for(int i=0; i<k&&i<v.size(); ++i)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
