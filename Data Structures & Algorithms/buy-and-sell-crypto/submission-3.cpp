class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;

        int maxProfit = 0;
        int i = 0, j = 1;
        while(j<prices.size()){
            while(prices[i]>prices[j]){
                i++;
            }
            maxProfit = max(maxProfit, prices[j] - prices[i]);
            j++;
        }
        return maxProfit;
    }
};
