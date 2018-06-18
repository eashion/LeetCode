A subproblem of maximum rectangle. Use stack to record the last height which is greater than the current one. Calculate the area when it is
 goding to pop out. Pop out the height when the current one is smaller than it.
 ```
 class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //heights = {10,1,10};
        int res = 0;
        vector<int> insta;
        insta.push_back(0);
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++){
            while(insta.size()>0 && heights[i]<=heights[insta.back()]){
                int h = heights[insta.back()];
                insta.pop_back();
                int pos = insta.size()>0?insta.back():-1;
                int range = i-pos-1;
                res = max(res, range*h);
            }
            insta.push_back(i);
        }
        return res;
    }
};
 ```
