class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0 || s=="") return 0;
        int left = 0, right = 0, maxCount = INT_MIN, maxFreq = 0;
        vector<int> freq(26,0);
        while(right<s.size()){
            
            int pos = s[right] - 'A';
            freq[pos]++;
            maxFreq = max(maxFreq, freq[pos]);
            while(right-left+1 - maxFreq > k){
                freq[s[left]-'A']--;
                left++;
            }
            maxCount = max(maxCount, right-left+1);
            right++;
            
        }
        return maxCount;
    }
};
