There are two key points. length and height. We start from the top left and top right. For shorter height, it's max depends on the most right
one. So after calculate that, we can move to the next. So we can solve this by O(n).
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        //height = {1,2,1,0,1,2,1};
        //height = {1,2,4,3};
        int res = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            if (height[left] < height[right]) {
                res = max(res, (right-left)*height[left]);
                left++;
            } else {
                res = max(res, (right-left)*height[right]);
                right--;
            }
        }
        return res;
    }
};
```
