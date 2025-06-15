class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo(triangle.size(), vector<int>(triangle.size(), -1));
        return helper(triangle, 0, 0, memo);
    }
    
    int helper(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& memo) {
        if(row == triangle.size()-1) 
            return triangle[row][col];
        if(memo[row][col] != -1) 
            return memo[row][col];
        
        int left = helper(triangle, row+1, col, memo);
        int right = helper(triangle, row+1, col+1, memo);
        
        return memo[row][col] = triangle[row][col] + min(left, right);
    }
};