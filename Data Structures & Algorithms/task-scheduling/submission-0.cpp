class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size()==0) return 0;
        priority_queue<int> maxHeap;
        unordered_map<char, int> mpp;
        queue<pair<int, int>> q;
        int time = 0, remaining_count = 0;
        for(auto c: tasks){
            mpp[c]++;
        }

        for(auto it: mpp){
            maxHeap.push(it.second);
        }

        while(!maxHeap.empty() || !q.empty()){
            time++;

            if(maxHeap.empty()){
                time = q.front().second;
            }else {
                int cnt = maxHeap.top()-1;
                maxHeap.pop();
                if(cnt>0){
                    q.push({cnt, time+n});
                }
            }

            if(!q.empty() && q.front().second==time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
