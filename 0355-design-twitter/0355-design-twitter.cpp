class Twitter {
private:
    int time;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // C++ priority_queue is a max-heap by default.
        // We will store vectors inside: {time, tweetId, userId, index}
        // The heap will automatically sort by the first element (time) in descending order.
        priority_queue<vector<int>> pq;
        
        // Collect all users whose tweets should be in the feed
        vector<int> users;
        users.push_back(userId);
        for (int followeeId : following[userId]) {
            users.push_back(followeeId);
        }
        
        // Initialize the heap with the single most recent tweet from each user
        for (int u : users) {
            if (!tweets[u].empty()) {
                int index = tweets[u].size() - 1;
                pq.push({tweets[u][index].first, tweets[u][index].second, u, index});
            }
        }
        
        vector<int> res;
        // Extract up to the 10 most recent tweets
        while (!pq.empty() && res.size() < 10) {
            vector<int> top = pq.top();
            pq.pop();
            
            res.push_back(top[1]); // Add tweetId to result
            
            int u = top[2];
            int index = top[3];
            
            // If the user has older tweets, push the next one into the heap
            if (index > 0) {
                int nextIndex = index - 1;
                pq.push({tweets[u][nextIndex].first, tweets[u][nextIndex].second, u, nextIndex});
            }
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */