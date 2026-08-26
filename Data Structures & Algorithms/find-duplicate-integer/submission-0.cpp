class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, secondSlow = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }

        while(true){
            slow = nums[slow];
            secondSlow = nums[secondSlow];
            if(slow==secondSlow) {
                break;
            }
        }
        return slow;
    }
};
