class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int product = 1, zeroCounter = 0;
        bool foundZero = false;
        for(int i = 0 ; i<nums.size(); i++){
            if(nums[i]==0){
                foundZero = true;
                zeroCounter++;
                continue;
            }
            product*=nums[i];
        }

        for(int i = 0; i<nums.size(); i++){
            if(foundZero){
                if(zeroCounter>1) ans[i] = 0;
                else ans[i] = (nums[i]==0) ? product : 0;
            }
            else ans[i] = product / nums[i];
        }
        return ans;
    }
};
