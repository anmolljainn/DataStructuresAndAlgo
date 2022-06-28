class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx_ele = 0,mx_profit=0;
        for(int i=n-1;i>=0;i--){
            mx_ele = max(mx_ele,prices[i]);
            mx_profit = max(mx_profit,mx_ele-prices[i]);
        }
        return mx_profit;
    }
};