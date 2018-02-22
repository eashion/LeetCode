public int[] exclusiveTime(int n, List<String> logs) {
    int[] res = new int[n];
    Stack<Integer> stack = new Stack<>();
    int prevTime = 0;
    for (String log : logs) {
        String[] parts = log.split(":");
        if (!stack.isEmpty()) res[stack.peek()] +=  Integer.parseInt(parts[2]) - prevTime; 
        prevTime = Integer.parseInt(parts[2]);
        if (parts[1].equals("start")) stack.push(Integer.parseInt(parts[0]));
        else {
            res[stack.pop()]++;
            prevTime++;
        }
    }
    return res;
}

struct functions{
    int no;
    int statime;
    int intervaltime;
    functions(){}
    functions(int no, int statime, int intervaltime){
        this->no = no;
        this->statime = statime;
        this->intervaltime = intervaltime;
    }
};
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n,0);
        stack<functions> sta;
        vector<vector<string>> lis(logs.size(), vector<string>(3));
        for(int i = 0; i < logs.size(); i++){
            lis[i] = mysplit(logs[i]);
        }
        for(int i = 0; i < logs.size(); i++){
            if (lis[i][1]==string("start")) {
                sta.push(functions(stoi(lis[i][0]), stoi(lis[i][2]), 0));
            } else {
                functions ff = sta.top();
				int time = stoi(lis[i][2])-ff.statime+1;
                sta.pop();
				res[ff.no] += time-ff.intervaltime;
                if (!sta.empty()) {
                    functions pre = sta.top();
					sta.pop();
					pre.intervaltime += time;
					sta.push(pre);
                }
            }
        }
        return res;
    }
private:
    vector<string> mysplit(string s){
        vector<string> lis;
        int sta = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i]==':') {
                lis.push_back(s.substr(sta,i-sta));
                sta = i+1;
            }
        }
        lis.push_back(s.substr(sta,s.size()-sta));
        return lis;
    }
};
