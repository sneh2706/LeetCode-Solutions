/*

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

*/

class Solution {
public:
    int search(vector<vector<int>> &grid, int row)
    {   
        int m = grid.size(), n = grid[0].size(), lo=0, hi=n-1;
        while(lo<hi)
        {
            int mid = lo+(hi-lo)/2;
            if(grid[row][mid]>=0)
                lo = mid+1;
            else
                hi = mid;
        }
        
        return lo;
    }
    
    
    int countNegatives(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        
        for(int i=0; i<m; ++i)
        {
            if(grid[i][n-1]>=0)
                continue;
            else if(grid[i][0]<0)
                res += n;
            else
            {
                int ind = search(grid,i);
                res += (n-ind);
            }
        }
        
        return res;
    }
};
