class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        int map[202];
        memset(map,0,sizeof(map));
        if (nums.size()==0) {
            return res;
        }
        for( int i = 0; i < nums.size()-1; i++ ){
            if (map[nums[i]+100]==1) {
                continue;
            }
            cur.push_back(nums[i]);
            devide(i,1,nums,cur,res);
            map[nums[i]+100] = 1;
            cur.pop_back();
        }
        return res;
    }
    void devide(int pos,int len,vector<int> nums,vector<int>& cur,vector<vector<int>>& res){
        if (len>=2) {
            vector<int> tmp;
            tmp.insert(tmp.end(),cur.begin(),cur.end());
            res.push_back(tmp);
        }
        int map[202];
        memset(map,0,sizeof(map));
        for(int i = pos+1; i < nums.size(); i++ ){
            if (map[nums[i]+100]==1) {
                continue;
            }
            if (nums[i]>=nums[pos]){
                cur.push_back(nums[i]);
                devide(i,len+1,nums,cur,res);
                map[nums[i]+100] = 1;
                cur.pop_back();
            }
        }
        return ;
    }
};

public class Solution {

     public List<List<Integer>> findSubsequences(int[] nums) {
         Set<List<Integer>> res= new HashSet<List<Integer>>();
         List<Integer> holder = new ArrayList<Integer>();
         findSequence(res, holder, 0, nums);
         List result = new ArrayList(res);
         return result;
     }

    public void findSequence(Set<List<Integer>> res, List<Integer> holder, int index, int[] nums) {
        if (holder.size() >= 2) {
            res.add(new ArrayList(holder));
        }
        for (int i = index; i < nums.length; i++) {
            if(holder.size() == 0 || holder.get(holder.size() - 1) <= nums[i]) {
                holder.add(nums[i]);
                findSequence(res, holder, i + 1, nums);
                holder.remove(holder.size() - 1);
            }
        }
    }
}
