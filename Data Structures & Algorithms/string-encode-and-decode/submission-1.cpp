class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for(string s: strs){
            encodedString+=to_string(s.size())+"#"+s;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        int right = 0;
        while(right<s.size()){
            int left = right;
            while(s[right]!='#') right++;
            int len = stoi(s.substr(left, right-left));
            string str = s.substr(right+1, len);
            decodedStrings.push_back(str);
            right = len+right+1;
        }
        return decodedStrings;
    }
};
