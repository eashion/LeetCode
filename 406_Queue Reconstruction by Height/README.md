At first I thought it is a dfs problem, but dfs is not efficient enough. I found start from the smallest is a good idea. The problem is put
it in the right position in a new vector or swap in the initial vector. If turns out sort in decreasing order and greedyly swap from back is
 enough to solve this. Since we start from left, pp.second is exactly the position of pp.
 ```
 class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        for(int i = 0; i < people.size(); i++){
            checkValid(i, people);
        }
        return people;
    }
private:
    static bool cmp(pair<int,int> p1, pair<int,int> p2){
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }
    void checkValid(int pos, vector<pair<int,int>>& people){
        int tar = people[pos].second;
        if (tar == pos) 
            return ;
        pair<int, int> pp = people[pos];
        for(int i = pos-1; i >= tar; i--){
            swap(people[i], people[i+1]);
        }
        people[tar] = pp;
        return ;
    }
};
 ```
