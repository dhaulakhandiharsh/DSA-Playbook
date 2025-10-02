class Twitter {
public:
    vector<pair<int,int>> recentTweets; // userId, tweedId
    map<int, set<int>> followed; // userId : people they follow

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        recentTweets.push_back(pair<int,int>(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        followed[userId].insert(userId); // make sure self is in there

        for (int i = recentTweets.size()-1; i >= 0; i--){
            if (ans.size() == 10){
                break;
            }
            if (followed[userId].contains(recentTweets[i].first)){
                ans.push_back(recentTweets[i].second);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followed[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followed[followerId].erase(followeeId);
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