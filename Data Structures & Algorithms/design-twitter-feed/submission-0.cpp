class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int timestamp;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;

        using heapItem = tuple<int, int, int, int>;
        priority_queue<heapItem> maxHeap;

        unordered_set<int> followees = follows[userId];
        followees.insert(userId);

        for(int followeeId : followees){
            auto it = tweets.find(followeeId);

            if(it!=tweets.end()&& !it->second.empty()){
                int lastIdx = it->second.size() - 1;
                auto& [time, tweetId] = it->second[lastIdx];
                maxHeap.push({time, tweetId, followeeId, lastIdx});
            }
        }

        while(!maxHeap.empty() && feed.size() < 10){
            auto [time, tweetId, followeeId, idx] = maxHeap.top();
            maxHeap.pop();
            feed.push_back(tweetId);
            if (idx > 0) {
                int nextIdx = idx - 1;
                auto& [nextTime, nextTweetId] = tweets[followeeId][nextIdx];
                maxHeap.push({nextTime, nextTweetId, followeeId, nextIdx});
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};
