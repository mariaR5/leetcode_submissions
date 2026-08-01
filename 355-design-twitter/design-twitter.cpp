class Twitter {
public:
    int timeStamp;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;
    
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        timeStamp++;
        tweets[userId].push_back({timeStamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;

        if (!tweets[userId].empty()) {
            int index = tweets[userId].size() - 1;
            pq.push({
                tweets[userId][index].first, // timestamp
                tweets[userId][index].second, // tweetId
                userId,
                index, 
            });
        }

        if (!follows[userId].empty()) {
            for (auto followeeId : follows[userId]) {
                if (!tweets[followeeId].empty()) {
                    int index = tweets[followeeId].size()-1;
                    pq.push({
                        tweets[followeeId][index].first, // timestamp
                        tweets[followeeId][index].second, // tweetId
                        followeeId,
                        index, 
                    });
                }
            }
        }

        vector<int> recents;

        while (!pq.empty() && recents.size() < 10) {
            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int index = cur[3];

            recents.push_back(tweetId);

            if (index > 0) {
                index--;
                pq.push({
                    tweets[user][index].first, // timestamp
                    tweets[user][index].second, // tweetId
                    user,
                    index, 
                });
            }
        }

        return recents;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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