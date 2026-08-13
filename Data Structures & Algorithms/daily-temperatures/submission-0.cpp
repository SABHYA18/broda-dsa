class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int size = temp.size();
        vector<int> ans(size, 0);
        stack<pair<int, int>> st;

        for(int i = 0; i<size; i++){

            while(!st.empty() && temp[i]>st.top().first){
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temp[i], i});
        }

        return ans;
    }
};
