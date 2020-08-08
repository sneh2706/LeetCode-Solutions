/*

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        int n = A.size();
        unordered_map<int,int> umap1,umap2;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                umap1[A[i]+B[j]]++;
                umap2[C[i]+D[j]]++;
            }
        }
        
        int counts = 0;
        for(auto it=umap1.begin(); it!=umap1.end(); ++it)
        {
            int x = (*it).first;
            int y = (*it).second;
            int z = -1*x , t;
            if(umap2.find(z)==umap2.end())
                t=0;
            else
                t = umap2[z];
            
            counts += (t*y);
        }
        
        return counts;
    }
};