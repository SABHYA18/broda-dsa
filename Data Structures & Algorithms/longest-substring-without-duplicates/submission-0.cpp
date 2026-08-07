class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s=="") return 0;
        unordered_set<char> dup;

        int left = 0, right = 0, longest = INT_MIN;

        while(right<s.size()){
            
            while(dup.find(s[right])!=dup.end()){
                dup.erase(s[left]);
                left++;
            }
            longest = max(longest, right-left+1);
            dup.insert(s[right]);
            right++;
        }
        return longest;
    }
};
