class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            int j = i+1;
            while(j<nums.size()){
                if(nums[i]==target-nums[j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};
