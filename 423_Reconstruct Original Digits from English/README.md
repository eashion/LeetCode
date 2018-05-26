Find special character from numbers.
```
class Solution {
public:
    string originalDigits(string s) {
        //s = "sevensixfourfour";
        map<char, int> mm;
        for(int i = 0; i < s.length(); i++){
            mm[s[i]]++;
        }
        vector<int> res(10, 0);
        int cnt;
        if (mm.find('z')!=mm.end() && mm['z']!=0) {
            cnt = mm['z'];
            mm['z'] -= cnt;
            mm['e'] -= cnt;
            mm['r'] -= cnt;
            mm['o'] -= cnt;
            res[0] = cnt;
        }
        if (mm.find('x')!=mm.end() && mm['x']!=0) {
            cnt = mm['x'];
            mm['s'] -= cnt;
            mm['i'] -= cnt;
            mm['x'] -= cnt;
            res[6] = cnt;
        }
        if (mm.find('s')!=mm.end() && mm['s']!=0) {
            cnt = mm['s'];
            mm['s'] -= cnt;
            mm['e'] -= 2*cnt;
            mm['v'] -= cnt;
            mm['n'] -= cnt;
            res[7] = cnt;
        }
        if (mm.find('v')!=mm.end() && mm['v']!=0) {
            cnt = mm['v'];
            mm['f'] -= cnt;
            mm['i'] -= cnt;
            mm['v'] -= cnt;
            mm['e'] -= cnt;
            res[5] = cnt;
        }
        if (mm.find('f')!=mm.end() && mm['f']!=0) {
            cnt = mm['f'];
            mm['f'] -= cnt;
            mm['o'] -= cnt;
            mm['u'] -= cnt;
            mm['r'] -= cnt;
            res[4] = cnt;
        }
        if (mm.find('r')!=mm.end() && mm['r']!=0) {
            cnt = mm['r'];
            mm['t'] -= cnt;
            mm['h'] -= cnt;
            mm['r'] -= cnt;
            mm['e'] -= 2*cnt;
            res[3] = cnt;
        }
        if (mm.find('h')!=mm.end() && mm['h']!=0) {
            cnt = mm['h'];
            mm['e'] -= cnt;
            mm['i'] -= cnt;
            mm['g'] -= cnt;
            mm['h'] -= cnt;
            mm['t'] -= cnt;
            res[8] = cnt;
        }
        if (mm.find('t')!=mm.end() && mm['t']!=0) {
            cnt = mm['t'];
            mm['t'] -= cnt;
            mm['w'] -= cnt;
            mm['o'] -= cnt;
            res[2] = cnt;
        }
        if (mm.find('o')!=mm.end() && mm['o']!=0) {
            cnt = mm['o'];
            mm['o'] -= cnt;
            mm['n'] -= cnt;
            mm['e'] -= cnt;
            res[1] = cnt;
        }
        if (mm.find('i')!=mm.end() && mm['i']!=0) {
            cnt = mm['i'];
            mm['n'] -= 2*cnt;
            mm['i'] -= cnt;
            mm['e'] -= cnt;
            res[9] = cnt;
        }
        string record = "";
        for(int i = 0; i < 10; i++){
            string tmp(res[i],char('0'+i));
            record += tmp;
        }
        return record;
    }
};
```
