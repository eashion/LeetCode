class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> itinerary;
        unordered_map<string,multiset<string>> graph;
        if( tickets.size() == 0 ){
            return itinerary;
        }
        for( int i = 0; i < tickets.size(); i++ ){
            graph[tickets[i].first].insert(tickets[i].second);
        }
        stack<string> dfs;
        dfs.push("JFK");
        while( dfs.empty() == false ){
            string cur = dfs.top();
            if( graph[cur].empty() == true ){
                itinerary.push_back(cur);
                dfs.pop();
            }
            else{
                dfs.push(*(graph[cur].begin()));
                graph[cur].erase(graph[cur].begin());
            }
        }
        reverse(itinerary.begin(),itinerary.end());
        return itinerary;
    }
};
