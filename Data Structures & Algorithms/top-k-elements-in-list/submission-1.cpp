class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        priority_queue<pair<int, int>, vector<pair<int, int>>,          greater<pair<int, int>>> minHeap;
        vector<int> ans;
        for(int i: nums){
            mpp[i]++;
        }

        for(auto it: mpp){
            int first = it.first;
            int second = it.second;
            minHeap.push({second,first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
            
        }

        while(!minHeap.empty()){
            pair<int, int> top = minHeap.top();
            ans.push_back(top.second);   
            minHeap.pop();
        }

        return ans;
    }
};
