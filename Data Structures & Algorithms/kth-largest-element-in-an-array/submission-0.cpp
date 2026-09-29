class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        priority_queue<int> maxHeap;

        for(int i: nums){
            maxHeap.push(i);
        }
        int ans = 0;
        while(k>1){
            maxHeap.pop();
            k--;
        }
        ans = maxHeap.top();
        return ans;
    }
};
