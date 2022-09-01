class Solution {
public:
    
    // Every land(1) will be a part of exactly one island
    
    void findJoinedLands(vector<vector<char>> &grid, int i, int j, int m, int n) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = -1;
        findJoinedLands(grid, i, j+1, m, n);
        findJoinedLands(grid, i, j-1, m, n);
        findJoinedLands(grid, i+1, j, m, n);
        findJoinedLands(grid, i-1, j, m, n);  
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands = 0;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                   findJoinedLands(grid, i, j, grid.size(), grid[0].size());
                    numOfIslands++;
                }
            }
        }
        return numOfIslands;
    }
};
