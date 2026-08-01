class Twitter {
public:
    int tweetId;
    int timeStamp;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;
    
    Twitter() {
        tweetId = 0;
        timeStamp = 0;
    }

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        >  buildHeap(int userId) {
        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > recents;

        for (auto tweet: tweets[userId]) {
            recents.push({tweet.first, tweet.second});
            while (recents.size() > 10) recents.pop();
        }

        for (int following: follows[userId]) {
            for (auto tweet: tweets[following]) {
                recents.push({tweet.first, tweet.second});
                while (recents.size() > 10) recents.pop();
            }
        }

        return recents;
    }
    
    void postTweet(int userId, int tweetId) {
        timeStamp++;
        tweets[userId].push_back({timeStamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > recents = buildHeap(userId);

        vector<int> recentTweets;

        while(!recents.empty()) {
            recentTweets.push_back(recents.top().second);
            recents.pop();
        }

        reverse(recentTweets.begin(), recentTweets.end());
        return recentTweets;
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