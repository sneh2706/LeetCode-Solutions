/*

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        int le = matrix[0][0], ri = matrix[n-1][n-1];
        
        int mid;
        
        while(le<ri)
        {
            mid = le+(ri-le)/2;
            int cnt = 0, j=n-1;
            
            for(int i=0; i<n; ++i)
            {
                while(j>=0 && matrix[i][j]>mid)
                    j--;
                
                cnt += (j+1);
            }
            
            if(cnt<k)
                le = mid+1;
            else
                ri = mid;
        }
        
        return le;
    }
};
