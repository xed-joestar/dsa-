 class Solution {
public:

    int answer(vector<int> & prices, int buy, int index, vector<vector<int>> &ans){
        if(index==prices.size()) return 0;
        if(ans[index][buy]!=-1) return ans[index][buy];
        if(buy){
            int a = -prices[index] + answer(prices,0,index+1,ans);
            int b = answer(prices,1,index+1,ans);
            return ans[index][buy] = max(a,b);
        }
        else{
            int a = prices[index] + answer(prices,1,index+1,ans);
            int b = answer(prices,0,index+1,ans);
            return ans[index][buy] = max(a,b);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(2,0),curr(2,0);
        for(int index = n-1; index>=0; index--){
            for(int buy = 0; buy<2; buy++){
                if(buy){
                    int a = -prices[index] + ans[0];
                    int b = ans[1];
                    curr[buy] = max(a,b);
                }
                else{
                    int a = prices[index] + ans[1];
                    int b = ans[0];
                    curr[buy] = max(a,b);
                }
            }
            ans = curr;
        }
        return ans[1];
    }
};