public class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int result = Integer.MIN_VALUE;
        
        for (int house : houses) {
            int index = Arrays.binarySearch(heaters, house);
            if (index < 0) {
        	index = -(index + 1);
            }
            int dist1 = index - 1 >= 0 ? house - heaters[index - 1] : Integer.MAX_VALUE;
            int dist2 = index < heaters.length ? heaters[index] - house : Integer.MAX_VALUE;
        
            result = Math.max(result, Math.min(dist1, dist2));
        }
        
        return result;
    }
}

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int res = 0;
        int p1 = -1;
        int p2 = 0;
        int left = INT_MIN;
        int right = INT_MAX;
        for(int i = 0; i < houses.size(); i++){
            while(p2<heaters.size() && heaters[p2]<houses[i]){
                p2++;
            }
            p1 = p2-1;
            left = p1==-1? INT_MIN:heaters[p1];
            right = p2==heaters.size()? INT_MAX:heaters[p2];
            if (left==INT_MIN) {
                res = max(res,right-houses[i]);
            } else if (right==INT_MAX) {
                res = max(res,houses[i]-left);
            } else {
                res = max(res,min(houses[i]-left,right-houses[i]));
            }
        }
        return res;
    }
};
