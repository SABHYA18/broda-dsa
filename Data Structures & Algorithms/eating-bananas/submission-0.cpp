class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 1, right = piles[piles.size()-1], k=0;
        while(left<right){
            int mid = left + (right-left)/2;
            int totalHours = 0;

            for(int p: piles){
                totalHours += (p+mid-1)/mid;
            }
            if(totalHours<=h) right = mid;
            else left = mid+1;
        }
        return left;
    }
};
