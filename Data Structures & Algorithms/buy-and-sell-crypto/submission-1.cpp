class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        int right = 1, left= 0, maxPro = INT_MIN;
        while(right<n){
            while(prices[left]>prices[right]){
                left++;
            }
            int currProf = prices[right] - prices[left];
            maxPro = max(maxPro, currProf);
            right++;
        }

        return maxPro;
    }
};
