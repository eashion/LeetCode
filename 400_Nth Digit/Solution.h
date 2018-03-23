#the basic idea is to find which number is this. and rember the left digit.
class Solution {
public:
    int findNthDigit(int n) {
        int num = 0;
        long cnt = 9;
        int pos = 0;
        for(int i = 0; true; i++){
            long tmp = cnt*(i+1);
            if (n>tmp) {
                n -= tmp;
            } else {
                pos = i;
                break;
            }
            num += cnt;
            cnt *= 10;
        }
        if (pos==0) {
            return n;
        }
        num += n/(pos+1);
        int left = n%(pos+1);
        if (left == 0) {
            return num%10;
        }
        num += 1;
        left = (pos+1)-left;
        while(num != 0){
            if (left==0) {
                return num%10;
            }
            num = num/10;
            left--;
        }
        return -1;
    }
};


class Solution 
{
    // date: 2016-09-18     location: Vista Del Lago III Apartments
public:
    int findNthDigit(int n) 
    {
        // step 1. calculate how many digits the number has.
        long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // step 2. calculate what the number is.
        int index = n % digits;
        if (index == 0)
            index = digits;
        long num = 1;
        for (int i = 1; i < digits; i ++)
            num *= 10;
        num += (index == digits) ? n / digits - 1 : n / digits;;

        // step 3. find out which digit in the number is we wanted.
        for (int i = index; i < digits; i ++)
            num /= 10;
        return num % 10;
    }
};
