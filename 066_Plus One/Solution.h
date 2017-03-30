class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int plus = 1;
        for( int i = digits.size()-1; i >= 0; i-- ){
            int sum = digits[i]+plus;
            res.insert(res.begin(),sum%10);
            plus = sum/10;
        }
        if( plus != 0 ){
            res.insert(res.begin(),plus);
        }
        return res;
    }
};
