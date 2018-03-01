class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size()<b.size()) {
            swap(a,b);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res = "";
        int pos = 0;
        bool flag = false;
        while(pos < b.size()){
            if (a[pos]=='0' && b[pos]=='0') {
                if (flag) {
                    res += '1';
                } else {
                    res += '0';
                }
                flag = false;
            } else if (a[pos]=='1' && b[pos]=='1') {
                if (flag) {
                    res += '1';
                } else {
                    res += '0';
                }
                flag = true;
            } else {
                if (flag) {
                    res += '0';
                } else {
                    res += '1';
                }
            }
            pos++;
        }
        while (pos < a.size()) {
            if (flag) {
                if (a[pos]=='1') {
                    res += '0';
                    flag = true;
                } else {
                    res += '1';
                    flag = false;
                }
            } else {
                res += a[pos];
            }
            pos++;
        }
        if (flag) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
