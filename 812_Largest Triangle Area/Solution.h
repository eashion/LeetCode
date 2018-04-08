#刚开始还在思考怎么贪心，后来发现数据量很小以后果断数学公式解决了
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                for(int k = j+1; k < points.size(); k++){
                    double tmp = 0.5*(points[i][0]*points[j][1]+points[i][1]*points[k][0]+points[j][0]*points[k][1]
                                      -points[k][0]*points[j][1]-points[i][0]*points[k][1]-points[i][1]*points[j][0]);
                    tmp = abs(tmp);
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};
