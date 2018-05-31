```
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //p1 = {1,1};
        //p2 = {0,1};
        //p3 = {1,2};
        // = {0,0};
        if (check(p1,p2,p3,p4) && check(p2,p1,p3,p4) && check(p3,p1,p2,p4)) {
            return true;
        } else {
            return false;
        }
    }
private:
    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        int dis2, dis3, dis4;
        dis2 = pow(p2[0]-p1[0], 2)+pow(p2[1]-p1[1], 2);
        dis3 = pow(p3[0]-p1[0], 2)+pow(p3[1]-p1[1], 2);
        dis4 = pow(p4[0]-p1[0], 2)+pow(p4[1]-p1[1], 2);
        //cout<<dis2<<endl;
        //cout<<dis3<<endl;
        //cout<<dis4<<endl;
        if (dis2==0 || dis3==0 || dis4==0) {
            return false;
        }
        if ((dis2==dis3+dis4&&dis3==dis4) || (dis3==dis2+dis4 && dis2==dis4) || (dis4==dis2+dis3 && dis2==dis3)) {
            return true;
        }
        return false;
    }
};class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //p1 = {1,1};
        //p2 = {0,1};
        //p3 = {1,2};
        // = {0,0};
        if (check(p1,p2,p3,p4) && check(p2,p1,p3,p4) && check(p3,p1,p2,p4)) {
            return true;
        } else {
            return false;
        }
    }
private:
    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        int dis2, dis3, dis4;
        dis2 = pow(p2[0]-p1[0], 2)+pow(p2[1]-p1[1], 2);
        dis3 = pow(p3[0]-p1[0], 2)+pow(p3[1]-p1[1], 2);
        dis4 = pow(p4[0]-p1[0], 2)+pow(p4[1]-p1[1], 2);
        //cout<<dis2<<endl;
        //cout<<dis3<<endl;
        //cout<<dis4<<endl;
        if (dis2==0 || dis3==0 || dis4==0) {
            return false;
        }
        if ((dis2==dis3+dis4&&dis3==dis4) || (dis3==dis2+dis4 && dis2==dis4) || (dis4==dis2+dis3 && dis2==dis3)) {
            return true;
        }
        return false;
    }
};
```
