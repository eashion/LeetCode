class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        int min = INT_MAX;
        for(int i = 0; i < list1.size(); i++){
            for(int j = 0; j < list2.size(); j++){
                if (list1[i]==list2[j]) {
                    if (i+j < min) {
                        res.clear();
                        min = i+j;
                        res.push_back(list1[i]);
                    } else if (i+j == min) {
                        res.push_back(list1[i]);
                    }
                }
            }
        }
        return res;
    }
};

public String[] findRestaurant(String[] list1, String[] list2) {
    Map<String, Integer> map = new HashMap<>();
    List<String> res = new LinkedList<>();
    int minSum = Integer.MAX_VALUE;
    for (int i=0;i<list1.length;i++) map.put(list1[i], i);
    for (int i=0;i<list2.length;i++) {
        Integer j = map.get(list2[i]);
        if (j != null && i + j <= minSum) {
            if (i + j < minSum) { res.clear(); minSum = i+j; }
            res.add(list2[i]);
        }
    }
    return res.toArray(new String[res.size()]);
}
