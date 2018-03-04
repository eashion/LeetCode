class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool flag = true;
        int bit = 0;
        for(int i = 0; i < data.size(); i++){
            if (bit==0) {
                int base = 128;
                while(base!=0 && data[i]/base==1){
                    bit += 1;
                    data[i] %= base;
                    base /= 2;
                }
                if (bit==1) {
                    flag = false;
                    break;
                } else if (bit>4) {
                    flag = false;
                    break;
                } else if (bit!=0) {
                    bit -= 1;
                }
            } else {
                if ((data[i]/128)==1 && (data[i]%128/64)==0) {
                    bit--;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (bit != 0) {
            flag = false;
        }
        return flag;
    }
};

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto c : data) {
            if (count == 0) {
                if ((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 3) == 0b11110) count = 3;
                else if ((c >> 7)) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};
