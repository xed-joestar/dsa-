class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            stack<int> st;
            for (int j = 0; j <= m; j++) {
                int h = (j == m) ? 0 : heights[j];   
                while (!st.empty() && h < heights[st.top()]) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    max_area = max(max_area, height * width);
                }
                st.push(j);
            }
        }
        return max_area;
    }
};