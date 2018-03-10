class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        stack<int> sta;
        for(int i = 0; i < ops.size(); i++){
            if (ops[i]=="C") {
                sta.pop();
            } else if (ops[i]=="D") {
                int last = sta.top();
                sta.push(last*2);
            } else if (ops[i]=="+"){
                int n1 = sta.top();
                sta.pop();
                int n2 = sta.top();
                sta.pop();
                sta.push(n2);
                sta.push(n1);
                sta.push(n1+n2);
            } else {
                sta.push(stoi(ops[i]));
            }
        }
        while(!sta.empty()){
            res += sta.top();
            sta.pop();
        }
        return res;
    }
};
