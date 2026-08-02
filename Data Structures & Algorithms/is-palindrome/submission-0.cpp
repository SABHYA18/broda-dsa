class Solution {
public:
    bool isPalindrome(string s) {
        string strs = "";
        for(char c: s){
            if(c==' ') continue;
            if(isalnum(c)) strs+=tolower(c);
        }

    int left = 0, right = strs.size()-1;

        while(left<=right){
            if(strs[left]==strs[right]){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
};