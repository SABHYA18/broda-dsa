class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";

        unordered_map<char, int> countT, window;

        for(auto it: t){
            countT[it]++;
        }

        int minWindow = INT_MAX, left = 0, right = 0, have = 0, need = countT.size();
        pair<int, int> track;

        while(right<s.size()){
            char c = s[right];

            window[c]++;

            if(countT.contains(c)&& window[c]==countT[c]){
                have++;
            }

            while(have==need){
                if(right-left+1 < minWindow){
                    track = {left, right};
                    minWindow = right - left+1;
                }

                window[s[left]]--;
                if(countT.contains(s[left])&& window[s[left]] < countT[s[left]]){
                    have--;
                }
                left++;
            }

            right++;

        }

        return minWindow==INT_MAX?"": s.substr(track.first,minWindow);
    }
};
