#首先如何确定这是一道动态规划的问题？
#optimal subproblem and overlapping problem
#类似于取或者不取，转或者不转会对后面产生影响。
#当i-1达到满足条件的最小次数的转换后，可以通过i-1得到i需要的最小转换次数
#每一个i都需要判断是否转换，决策树的节点数2^n,存在overlapping problem
#转换关系：
#在合理状态上纠结了许久，首先转与不转都应该初始化为N，最大值
#如果A[i]>A[i-1] && B[i]>B[i-1]:正常顺序能够满足
#则能够更新opt[i][0]=opt[i-1][0];opt[i-1]=opt[i-1][1]+1
#如果A[i]>B[i-1] && B[i]>A[i-1]:前一个转了之后也能够满足
#则能够更新opt[i][0]=min(opt[i][0],opt[i-1][1]);//此时opt[i][0]中已经包含能否满足正常顺序的信息
#opt[i][1]=min(opt[i][1],opt[i-1][0]+1);//opt[i][1]已经包含正常顺序的信息，如果正常顺序不满足，opt[i][1]=N，不影响更新
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        //A = {0,7,8,10,10,11,12,13,19,18};
        //B = {4,4,5,7,11,14,15,16,17,20};
        vector<vector<int>> opt(A.size(), vector<int>(2, 0));
        opt[0][0] = 0;
        opt[0][1] = 1;
        for(int i = 1; i < A.size(); i++){
            opt[i][0] = A.size();
            opt[i][1] = A.size();
            if (A[i]>A[i-1] && B[i]>B[i-1]) {
                opt[i][0] = opt[i-1][0];
                opt[i][1] = opt[i-1][1]+1;
            }
            if (A[i]>B[i-1] && B[i]>A[i-1]) {
                opt[i][0] = min(opt[i][0], opt[i-1][1]);
                opt[i][1] = min(opt[i-1][0]+1, opt[i][1]);
            }
        }
        for(int i = 0; i < A.size(); i++){
            cout<<opt[i][0]<<' ';
        }
        cout<<endl;
        for(int i = 0; i < A.size(); i++){
            cout<<opt[i][1]<<' ';
        }
        cout<<endl;
        return min(opt[A.size()-1][0], opt[A.size()-1][1]);
    }
};
