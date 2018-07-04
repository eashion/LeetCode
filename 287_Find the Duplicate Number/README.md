At first I want to use bit operation to save number information. But the flag number increases a lot with the increasing of n. While use string 
is enough and even more convinient. initialize n+1 lenth string with '0'. As a bonus, learned how to use bit operation to compare two unsigned 
integer. Use xor operation to find those bits that a and b are different. We only care about the first different digit. So we use >> operation 
to make sure that all the right digits are 1, and use diff ^= diff>>1 to find the first different digit. If a&diff is not 0x00, then a is larger.
```
    int BitCompare(uint32_t a, uint32_t b){
        uint32_t diff = a^b;
        if (!diff) {
            return 0;
        }
        
        myprint(diff);
        diff |= diff>>1;
        myprint(diff);
        diff |= diff>>2;
        myprint(diff);
        diff |= diff>>4;
        myprint(diff);
        diff |= diff>>8;
        myprint(diff);
        diff |= diff>>16;
        myprint(diff);
        diff ^= diff>>1;
        myprint(diff);
        
        return a&diff ? 1:-1;
    }
    void myprint(uint32_t num){
        cout<<num<<endl;
        while(num){
            cout<<num%2;
            num /= 2;
        }
        cout<<endl;
    }
```
