class Solution {
    
private:
struct atom{
    string var;
    int cnt;
    atom(){
        cnt = 0;
    }
    bool operator<(const atom& rhs) const { return var < rhs.var; }
};
public:
    string countOfAtoms(string formula) {
        stack<atom> sta;
        vector<atom> vec;
        bool flag = false;
        for(int i = 0; i < formula.length(); i++){
            if(formula[i]=='('){
                atom inSta;
                inSta.var = "(";
                sta.push(inSta);
                continue;
            }
            if(formula[i]==')'){
                i++;
                int cnt = getCnt(i,formula);
                while(1){
                    atom outSta = sta.top();
                    sta.pop();
                    if(outSta.var=="("){
                        break;
                    }
                    outSta.cnt *= cnt;
                    vec.push_back(outSta);
                }
                for(int x = 0; x < vec.size(); x++){
                    sta.push(vec[x]);
                }
                vec.clear();
                continue;
            }
            atom tmp;
            tmp.var = getAtom(i,formula);
            int cnt = getCnt(i,formula);
            cnt = cnt==0?1:cnt;
            tmp.cnt = cnt;
            sta.push(tmp);
        }
        while(!sta.empty()){
            vec.push_back(sta.top());
            sta.pop();
        }
        sort(vec.begin(),vec.end());
        string res = "";
        for(int i = 0; i < vec.size(); i++){
            res += vec[i].var;
            int tmp = vec[i].cnt;
            while(i+1<vec.size() && vec[i+1].var==vec[i].var){
                i++;
                tmp += vec[i].cnt;
            }
            if(tmp!=1){
                res += to_string(tmp);
            }
        }
        return res;
    }

private:
    int getCnt(int &i,string formula){
        int cnt = 0;
        for(;i<formula.length();i++){
            int tmp = formula[i]-'0';
            if(tmp>=0 && tmp<=9){
                cnt = cnt*10+tmp;
            } else {
                i--;
                return cnt;
            }
        }
        return cnt;
    }
    string getAtom(int &i,string formula){
        string atom = "";
        int tmp = -1;
        atom += formula[i++];
        for(; i < formula.length(); i++){
            tmp = formula[i]-'a';
            if(tmp>=0 && tmp<=25){
                atom += formula[i];
            } else {
                break;
            }
        }
        return atom;
    }
};
class Solution {
public:
    string countOfAtoms(string formula) {
        string output;
        const int n = formula.size();
        int i = 0;
        map<string, int> counts = parseFormula(formula, i);
        for (pair<string, int> p : counts) {
            output += p.first;
            if (p.second > 1) output += to_string(p.second);
        }
        return output;
    }

private:
    map<string, int> parseFormula(string& s, int& i) {
        map<string, int> counts;
        const int n = s.size();
        while (i < n && s[i] != ')') {
            map<string, int> cnts = parseUnit(s, i);
            merge(counts, cnts, 1);
        }
        return counts;
    }

    map<string, int> parseUnit(string& s, int& i) {
        map<string, int> counts;
        const int n = s.size();
        if (s[i] == '(') {
            map<string, int> cnts = parseFormula(s, ++i); // ++i for '('
            int digits = parseDigits(s, ++i); // ++i for ')'
            merge(counts, cnts, digits);
        }
        else {
            int i0 = i++; // first letter
            while (i < n && islower(s[i])) { i++; }
            string atom = s.substr(i0, i - i0);
            int digits = parseDigits(s, i);
            counts[atom] += digits;
        }
        return counts;
    }

    int parseDigits(string& s, int& i) {
        int i1 = i;
        while (i < s.size() && isdigit(s[i])) { i++; }
        int digits = i == i1 ? 1 : stoi(s.substr(i1, i - i1));
        return digits;
    }

    void merge(map<string, int>& counts, map<string, int>& cnts, int times) {
        for (pair<string, int> p : cnts) counts[p.first] += p.second * times;
    }
};
