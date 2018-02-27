#do it recursively
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(mystoi(s));
        }
        NestedInteger res = NestedInteger();
        s = s.substr(1, s.length()-2);
        cout<<s<<endl;
        int pos = 0;
        int sta = 0;
        while(findNext(pos, s)){
            string cur = s.substr(sta, pos-sta);
            res.add(deserialize(cur));
            pos += 1;
            sta = pos;
        }
        return res;
    }
    int mystoi(string num){
        int base = 1;
        int res;
        if (num[0] == '-') {
            base = -1;
            res = stoi(num.substr(1));
        } else {
            res = stoi(num);
        }
        return res*base;
    }
    bool findNext(int &pos, string s){
        if (pos>=s.length()) {
            return false;
        }
        int cnt = 0;
        while(pos<s.length()){
            if (s[pos]=='[') {
                cnt++;
            }
            if (s[pos]==']') {
                cnt--;
            }
            if (s[pos]==',' && cnt==0) {
                return true;
            }
            pos++;
        }
        return true;
    }
};
