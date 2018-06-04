```
class Solution {
public:
    bool validPalindrome(string s) {
        //s = "abcd";
        //s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
        int left = 0;
        int right = s.length()-1;
        int flag = 0;
        int s1 = -1;
        int s2 = -1;
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
            } else {
                if (flag == 1) {
                    if (s1!=-1 && s2!=-1) {
                        left = s1;
                        right = s2;
                        s1 = -1;
                        s2 = -1;
                        continue;
                    } else {
                        return false;
                    }
                } else {
                    int t1 = checkAlphanumeric(s[left+1]);
                    int t2 = checkAlphanumeric(s[right-1]);
                    if (t1==n2 && t2!=n1) {
                        left += 2;
                        right -= 1;
                        flag = 1;
                    } else if (t2==n1 && t1!=n2) {
                        right -= 2;
                        left += 1;
                        flag = 1;
                    } else if (t2==n1 && t1==n2) {
                        s1 = left+1;
                        s2 = right-2;
                        left += 2;
                        right -= 1;
                        flag = 1;
                    }else {
                        return false;
                    }
                }
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
