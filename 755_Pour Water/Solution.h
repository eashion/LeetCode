class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while(V--){
            bool left = false;
            bool right = false;
            checkLeft(K,heights,left);
            if (!left) {
                checkRight(K,heights,right);
            }
            if (!left && !right) {
                heights[K]++;
            }
        }
        return heights;
    }
private:
    void checkLeft(int K,vector<int>& heights,bool& left){
        int flag = heights[K];
        for(int i = K-1; i >= 0; i--){
            if (heights[i]<flag) {
                checkLeft(i,heights,left);
                if (!left) {
                    heights[i]++;
                    left = true;
                    return ;
                }
            } else if (heights[i]>flag) {
                return ;
            }
        }
        return ;
    }
    void checkRight(int K,vector<int>& heights,bool& right){
        int flag = heights[K];
        for(int i = K+1; i < heights.size(); i++){
            if (heights[i]<flag) {
                checkRight(i,heights,right);
                if (!right) {
                    heights[i]++;
                    right = true;
                    return ;
                }
            } else if (heights[i]>flag) {
                return ;
            }
        }
        return ;
    }
};
