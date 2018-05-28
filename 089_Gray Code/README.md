Test the quality of XOR. Or just list which bits change in order.
```
class Solution {
public:
    vector<int> grayCode(int n) {
        /*cout<<"3^1: "<<(3^1)<<endl;
        cout<<"3^(3^1): "<<(3^(3^1))<<endl;
        cout<<"1^(3^1): "<<(1^(3^1))<<endl;
        */
        vector<int> base;
        for(int i = 0; i < n; i++){
            base.push_back(pow(2,i));
            cout<<base[i]<<endl;
        }
        vector<int> res;
        res.push_back(0);
        map<int, int> mm;
        mm[0] = 1;
        while(true){
            int cur = res[res.size()-1];
            bool flag = false;
            for(int i = 0; i < base.size(); i++){
                int next = cur^base[i];
                if (mm.find(next) == mm.end()) {
                    //cout<<"next: "<<next<<endl;
                    flag = true;
                    res.push_back(next);
                    mm[next] = 1;
                    break;
                }
            }
            if (flag == false) {
                break;
            }
        }
        return res;
    }
};
```
