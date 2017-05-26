class Twitter {
typedef pair<int,int> PP;
vector<PP> twitterList;
unordered_map<int, unordered_set<int> > mm;
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        twitterList.push_back(PP(userId,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int cnt = 0;
        for( int i = twitterList.size()-1; i >= 0; i-- ){
            PP tmp = twitterList[i];
            if( tmp.first==userId || mm[userId].find(tmp.first)!=mm[userId].end() ){
                res.push_back(tmp.second);
                cnt++;
            }
            if( cnt == 10 ){
                break;
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if( followerId != followeeId ){
            mm[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        mm[followerId].erase(followeeId);
    }
};
