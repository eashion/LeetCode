class Solution {
private:
struct mutation {
    string gene;
    int cnt;
    bool operator < (const mutation& a) const{
        return this->cnt > a.cnt;
    }
};
public:
    int minMutation(string start, string end, vector<string>& bank) {
        priority_queue<mutation> queue;
        map<string,int> curMinimum;
        mutation sta;
        sta.gene = start;
        if (find(bank.begin(),bank.end(),end)==bank.end()) {
            return -1;
        }
        sta.cnt = 0;
        int res = -1;
        queue.push(sta);
        for(int i = 0; i < bank.size(); i++ ){
            curMinimum[bank[i]] = INT_MAX;
        }
        while(!queue.empty()){
            mutation cur = queue.top();
            queue.pop();
            if(cur.gene==end){
                res = cur.cnt;
                break;
            }
            if (curMinimum[cur.gene]<cur.cnt) {
                continue;
            }
            for(int i = 0; i < bank.size(); i++){
                int cnt = getCnt(cur.gene,bank[i]);
                if (cnt!=1) {
                    continue;
                }
                mutation tmp;
                tmp.gene = bank[i];
                tmp.cnt = cur.cnt+cnt;
                if (tmp.cnt<curMinimum[tmp.gene]) {
                    curMinimum[tmp.gene] = tmp.cnt;
                    queue.push(tmp);
                }
            }
        }
        return res;
    }
    int getCnt(string s1,string s2){
        int cnt = 0;
        for(int i = 0; i < s1.length(); i++ ){
            if (s1[i]!=s2[i]) {
                cnt++;
                if (cnt==2) {
                    return cnt;
                }
            }
        }
        return cnt;
    }
};


class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end)) return -1;
        unordered_set<string> bset, eset, *set1, *set2;
        bset.insert(start), eset.insert(end);
        int step = 0, n = start.size();
        while (!bset.empty() and !eset.empty()) {
            if (bset.size() <= eset.size())
                set1 = &bset, set2 = &eset;
            else set2 = &bset, set1 = &eset;
            unordered_set<string> tmp;
            step ++;
            for (auto itr = set1->begin(); itr != set1->end(); ++itr) {
                for (int i = 0; i < n; ++i) {
                    string dna = *itr;
                    for (auto g : string("ATGC")) {
                        dna[i] = g;
                        if (set2->count(dna)) return step;
                        if (dict.count(dna)) {
                            tmp.insert(dna);
                            dict.erase(dna);
                        }
                    }
                }
            }
            *set1 = tmp;
        }
        return -1;
    }
};
