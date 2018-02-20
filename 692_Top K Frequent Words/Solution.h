struct node{
    string word;
    int cnt;
    node(){}
    node(string word, int cnt){
        this->word = word;
        this->cnt = cnt;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<node> lis;
        vector<string> res;
        unordered_map<string, int> mm;
        lis.push_back(node("",INT_MAX));
        for(int i = 0; i < words.size(); i++){
            int pos = mm[words[i]];
            if (pos!=0) {
                lis[pos].cnt+=1;
                doswap(lis,pos,mm);
            } else {
                mm[words[i]] = lis.size();
                lis.push_back(node(words[i],1));
                doswap(lis,lis.size()-1,mm);
            }
        }
        for(int i = 1; i <= k; i++){
            res.push_back(lis[i].word);
        }
        return res;
    }
    void doswap(vector<node>& lis, int pos, unordered_map<string, int>& mm){
        if (pos==1) {
            return ;
        }
        while(pos>1){
            if (lis[pos].cnt<lis[pos-1].cnt) {
                return ;
            } else if (lis[pos].cnt==lis[pos-1].cnt) {
                if (lis[pos].word.compare(lis[pos-1].word)>0) {
                    return ;
                }
				mm[lis[pos].word] = pos-1;
				mm[lis[pos-1].word] = pos;
                swap(lis[pos], lis[pos-1]);
            } else {
				mm[lis[pos].word] = pos-1;
				mm[lis[pos-1].word] = pos;
                swap(lis[pos], lis[pos-1]);
            }
            pos--;
        }
		return ;
    }
};


class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        
        List<String> result = new LinkedList<>();
        Map<String, Integer> map = new HashMap<>();
        for(int i=0; i<words.length; i++)
        {
            if(map.containsKey(words[i]))
                map.put(words[i], map.get(words[i])+1);
            else
                map.put(words[i], 1);
        }
        
        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>(
                 (a,b) -> a.getValue()==b.getValue() ? b.getKey().compareTo(a.getKey()) : a.getValue()-b.getValue()
        );
        
        for(Map.Entry<String, Integer> entry: map.entrySet())
        {
            pq.offer(entry);
            if(pq.size()>k)
                pq.poll();
        }

        while(!pq.isEmpty())
            result.add(0, pq.poll().getKey());
        
        return result;
    }
}
