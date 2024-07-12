class Twitter {
public:
    map<int, vector<pair<int, int>>> userTweets;
    map<int, set<int>> userFollowers;
    int counter = 0;

    Twitter() { }

    void postTweet(int userId, int tweetId) {
        auto p = make_pair(counter, tweetId);
        counter++;
        userTweets[userId].push_back(p);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> tweets;
        auto followers = userFollowers[userId];
        followers.insert(userId);  // Include the user themselves
        
        for (auto it : followers) {
            for (auto f : userTweets[it]) {
                tweets.push(f);
            }
        }

        int count = 0;
        vector<int> ans;
        while (count < 10 && !tweets.empty()) {
            auto t = tweets.top();
            tweets.pop();
            ans.push_back(t.second);
            count++;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {  // Users can't follow themselves
            userFollowers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (userFollowers[followerId].count(followeeId)) {
            userFollowers[followerId].erase(followeeId);
        }
    }
};
