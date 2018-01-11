class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        if (s.length()==0) {
            return res;
        }
        unordered_map<char, int> mm;
        for(int i = 0; i < s.length(); i++){
            char tmp = s[i];
            mm[tmp] += 1;
        }
        vector<PAIR> vec(mm.begin(),mm.end());
        sort(vec.begin(),vec.end(),cmp_by_value);
        for(int i = 0; i < vec.size(); i++){
            string tmp (vec[i].second,vec[i].first);
            cout<<"str:"<<tmp<<endl;
            res += tmp;
        }
        return res;
    }
private:
typedef pair<char, int> PAIR;  
  
static bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {  
  return lhs.second > rhs.second;  
}
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};
string frequencySort(string s) {
    unordered_map<char, int> freqOfChar;
    for(char c : s) {
        freqOfChar[c] ++;
    }

    map<int, string> dupStr;
    for(auto v : freqOfChar) {
        char c = v.first;
        int n = v.second;
        dupStr[n] += string(n, c);
    }

    string res;
    for(auto rit = dupStr.rbegin(); rit != dupStr.rend(); ++rit) {
        res += rit->second;
    }
    return res;
}
