class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp;
        if(s.size()<t.size() || s.size()>t.size()) return false; 
        for(char c: s){
            mpp[c]++;
        }

        for(char c: t){
            if(mpp.find(c)!=mpp.end()){
                mpp[c]--;
                if(mpp[c]==0) mpp.erase(c);
            }
        }

        if(mpp.empty()) return true;
        return false;
        
    }
};
