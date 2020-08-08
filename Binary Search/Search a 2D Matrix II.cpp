/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

*/

class Solution {
public:
    int search(vector<vector<int>> &matrix, int row, int x)
    {
        int n=matrix[row].size(), lo=0, hi = n-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(matrix[row][mid]==x)
                return 1;
            else if(matrix[row][mid]<x)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return 0;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.size()==0) return false;
        int n = matrix.size();
        
        for(int i=0; i<n; ++i)
        {
            int m = matrix[i].size();
            if(m>0 && target>=matrix[i][0] && target<=matrix[i][m-1] && search(matrix,i,target))
                return true;
        }
        
        return false;
    }
};
