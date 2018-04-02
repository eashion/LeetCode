class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int res = 0;
        if (envelopes.size()==0) {
            return res;
        }
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> opt(envelopes.size(), 1);
        for(int i = 0; i < envelopes.size(); i++){
            //cout<<envelopes[i].first<<" "<<envelopes[i].second<<endl;
            for(int k = 0; k < i; k++){
                if (envelopes[i].first>envelopes[k].first && envelopes[i].second>envelopes[k].second) {
                    opt[i] = max(opt[i], opt[k]+1);
                }
            }
            //cout<<"opt"<<opt[i]<<endl;
            res = max(res, opt[i]);
        }
        return res;
    }
private:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        if (a.first!=b.first )
            return a.first<b.first;
        return a.second<b.second;
    }
};
