class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n-1, maxWater = INT_MIN;

        while(i<j){

            int water = (j-i)*min(heights[i], heights[j]);

            maxWater = max(maxWater, water);
            if(heights[i]>heights[j]) j--;
            else i++;

        }
        return maxWater;
    }
};
