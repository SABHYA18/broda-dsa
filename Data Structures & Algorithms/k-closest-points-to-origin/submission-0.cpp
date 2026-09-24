class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, vector<int>>> maxHeap;


        for(auto& point: points){

            int x = point[0];
            int y = point[1];

            int dist = x*x + y*y;

            maxHeap.push({dist, point});

            while(maxHeap.size()>k){
                maxHeap.pop();
            }

        }
        vector<vector<int>> res;

        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }


        return res;
    }
};
