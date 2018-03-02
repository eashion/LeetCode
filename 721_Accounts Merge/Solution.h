#At first I didn't understand the problem. I built a bad model. This is a union find problem, find and union action is needed. Since the 
relationship between email address can be complicated. One another thing, the first string, name cannot not be used as the key, since there
can be multiple user with same name. But the first email address can be used as the root node.
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        map<string, string> parent;
        map<string, string> owner;
        map<string, set<string>> unions;
        for (int i = 0; i < accounts.size(); i++) {
        	for (int j = 1; j < accounts[i].size(); j++) {
        		parent[accounts[i][j]] = accounts[i][j];
        		owner[accounts[i][j]] = accounts[i][0];
        	}
        }
        for (int i = 0; i < accounts.size(); i++) {
        	string p = find(accounts[i][1], parent);
        	for (int j = 2; j < accounts[i].size(); j++) {
        		parent[find(accounts[i][j], parent)] = p;
        	}
        }
        for (int i = 0; i < accounts.size(); i++) {
        	for (int j = 1; j < accounts[i].size(); j++) {
        		unions[find(accounts[i][j], parent)].insert(accounts[i][j]);
        	}
        }
        for (pair<string, set<string>> p : unions) {
        	vector<string> emails(p.second.begin(), p.second.end());
        	emails.insert(emails.begin(), owner[p.first]);
        	res.push_back(emails);
        }
        return res;
    }
private:
	string find(string cur, map<string, string> &parent){
		if (cur==parent[cur]) {
			return cur;
		}
		return parent[cur] = find(parent[cur], parent);
	}
};
