```
class Solution {
public:
    bool isPalindrome(string s) {
        //s = "race a car";
        //s = "0P";
        //s = " apG0i4maAs::sA0m4i0Gp0";
        int left = 0;
        int right = s.length()-1;
        while(left < right){
            int n1 = checkAlphanumeric(s[left]);
            int n2 = checkAlphanumeric(s[right]);
            //cout<<"left: "<<s[left]<<" "<<n1<<endl;
            //cout<<"right: "<<s[right]<<" "<<n2<<endl;
            if (n1 == -1) {
                left++;
                continue;
            }
            if (n2 == -1) {
                right--;
                continue;
            }
            if (n1 == n2) {
                left++;
                right--;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
private:
    int checkAlphanumeric(char tmp){
        if (tmp>='0' && tmp<='9') {
            return tmp-'0';
        }
        if (tmp>='A' && tmp<='Z') {
            return 10+tmp-'A';
        }
        if (tmp>='a' && tmp<='z') {
            return 10+tmp-'a';
        }
        return -1;
    }
};
```
