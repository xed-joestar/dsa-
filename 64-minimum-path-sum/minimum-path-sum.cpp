class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(grid, 0, 0, memo);
    }
    
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo) {
        if(i == grid.size()-1 && j == grid[0].size()-1) 
            return grid[i][j];
        if(i >= grid.size() || j >= grid[0].size()) 
            return INT_MAX;
        if(memo[i][j] != -1) 
            return memo[i][j];
        
        int right = helper(grid, i, j+1, memo);
        int down = helper(grid, i+1, j, memo);
        
        return memo[i][j] = grid[i][j] + min(right, down);
    }
};