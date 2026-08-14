class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;

        int n = heights.size(), currH = 0, maxArea = 0;
        stack<int> st;
        for(int i=0; i<=n; i++){
            currH = i==n ? 0:heights[i];
            
            while(!st.empty() && currH<heights[st.top()]){
                int idx = st.top();
                st.pop();
                int h = heights[idx];
                int w = 0;
                w = st.empty()? i : i-st.top()-1;

                maxArea = max(maxArea, h*w);
            }
            st.push(i);
        }
        return maxArea;
    }
};
