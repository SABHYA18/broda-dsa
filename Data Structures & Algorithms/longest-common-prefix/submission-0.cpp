class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string ans = "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string second = strs[strs.size()-1];
        int i = 0;

        while(i<first.size() && i<second.size() && first[i] == second[i]){
            i++;
        }

        return first.substr(0,i);

    }
};