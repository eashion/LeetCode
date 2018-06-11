This problem is difficult for me. It's similar to skyline. But in this problem we just need to calculate the area without overlap. Basically
at the end the graph is constructed with rectangles. We can calculate the space saperately.
```
(a + b) % p = (a % p + b % p) % p
(a - b) % p = (a % p - b % p) % p
(a * b) % p = (a % p * b % p) % p
a ^ b % p = ((a % p)^b) % p
struct Node{
    int a,b;
    Node(){}
    Node(int a, int b){
        this->a = a;
        this->b = b;
    }
};
class Solution {
int mod = pow(10, 9)+7;
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int res = 0;
        //rectangles = {{0,0,1000000000,1000000000}};
        vector<int> X;
        vector<int> Y;
        for(int i = 0; i < rectangles.size(); i++){
            X.push_back(rectangles[i][0]);
            X.push_back(rectangles[i][2]);
            Y.push_back(rectangles[i][1]);
            Y.push_back(rectangles[i][3]);
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        deleteRepeat(X);
        deleteRepeat(Y);
        vector<vector<bool>> visit(X.size(), vector<bool>(Y.size(), false));
        for(int i = 0; i < rectangles.size(); i++){
            int x1 = lower_bound(X.begin(), X.end(), rectangles[i][0])-X.begin();
            int x2 = lower_bound(X.begin(), X.end(), rectangles[i][2])-X.begin();
            int y1 = lower_bound(Y.begin(), Y.end(), rectangles[i][1])-Y.begin();
            int y2 = lower_bound(Y.begin(), Y.end(), rectangles[i][3])-Y.begin();
            //cout<<"x:"<<x1<<" "<<x2<<endl;
            //cout<<"y:"<<y1<<" "<<y2<<endl;
            for(int u = x1; u < x2; u++){
                for(int v = y1; v < y2; v++){
                    visit[u][v] = true;
                }
            }
        }
        for(int i = 0; i < X.size(); i++){
            for(int j = 0; j < Y.size(); j++){
                if (visit[i][j] == true) {
                    res = (res + (long long)(X[i + 1] - X[i]) * (Y[j + 1] - Y[j])) % mod;
                }
            }
        }
        return res;
    }
private:
    void deleteRepeat(vector<int>& lis){
        for(auto iter = lis.begin()+1; iter < lis.end(); ){
            //cout<<*iter<<" ";
            if (*iter ==  *(iter-1)){
                iter = lis.erase(iter);
            } else {
                iter++;
            }
        }
        //cout<<endl;
        return ;
    }
};
```
