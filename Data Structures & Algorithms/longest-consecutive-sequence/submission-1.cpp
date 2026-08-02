class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> s;
        int maxLen = INT_MIN;
        for(int i: nums){
            s.insert(i);
        }

        for(int i : nums){
            if (!s.count(i-1)){
                int len = 0;
                while(s.count(i+len)) len++;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
