class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }

        for(auto it: mpp){
            if(it.second>1){
                return true;
            }
        }
        return false;
    }
};