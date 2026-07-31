class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> mpp;

        for(string s: strs){
            vector<int> count(26,0);
            for(char c: s){
                count[c-'a']++;
            }
            mpp[count].push_back(s);
        }
        vector<vector<string>> groupedAnagrams;
        for(auto it: mpp){
            groupedAnagrams.push_back(it.second);
        }

    return groupedAnagrams;

    }
};
