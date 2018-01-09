class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        if (machines.size()==1) {
            return 0;
        }
        int mid;
        int sum = 0;
        int plus = 0;
        int maxOne = -1;
        for(int i = 0; i < machines.size(); i++){
            sum += machines[i];
            maxOne = max(maxOne,machines[i]);
        }
        if ((sum%machines.size()) != 0) {
            return -1;
        }
        mid = sum/machines.size();
        for(int i = 0; i < machines.size(); i++){
            if (checkAdjacent(i,mid,machines)) {
                cout<<i<<endl;
                plus += machines[i]-mid;
            }
        }
        cout<<"res"<<maxOne-mid<<endl;
        cout<<"plus"<<plus<<endl;
        return maxOne-mid+plus;
    }
private:
    bool checkAdjacent(int i,int mid,vector<int> machines){
        if (i==0 && machines[i+1]>=machines[i] && machines[i]>mid) {
            return true;
        }
        if (i==machines.size()-1 && machines[i-1]>=machines[i] && machines[i]>mid) {
            return true;
        }
        if (machines[i]>=mid && machines[i-1]>=machines[i] && machines[i+1]>=machines[i]) {
            return true;
        }
        return false;
    }
};

public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size();
        vector<int> sum(len + 1, 0);
        for (int i = 0; i < len; ++i)
            sum[i + 1] = sum[i] + machines[i];

        if (sum[len] % len) return -1;

        int avg = sum[len] / len;
        int res = 0;
        for (int i = 0; i < len; ++i)
        {
            int l = i * avg - sum[i];
            int r = (len - i - 1) * avg - (sum[len] - sum[i] - machines[i]);

            if (l > 0 && r > 0)
                res = std::max(res, std::abs(l) + std::abs(r));
            else
                res = std::max(res, std::max(std::abs(l), std::abs(r)));
        }
        return res;
    }
};
