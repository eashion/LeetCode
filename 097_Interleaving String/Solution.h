struct node{
    int x,y;
    node(int x,int y){
        this->x = x;
        this->y = y;
    }
    bool operator==(const node &p) const {
        return p.y == y && p.x == x;
    }
};
namespace std {
    template <>
    struct hash<node> {
        size_t operator () (const node &f) const {
            return (std::hash<int>()(f.x) << 1) ^ std::hash<int>()(f.y);
        }
    };
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != (s1.length()+s2.length())) {            
            return false;
        }
        queue<node> que;
        unordered_set<node> visit;
        que.push(node(0,0));
        while(!que.empty()){
            node cur = que.front();
            que.pop();
            if (cur.x==s1.length() && cur.y==s2.length()) {
                return true;
            }
            if (visit.find(cur) != visit.end()) {
                continue;
            }
            visit.insert(cur);
            if (cur.x<s1.length()) {
                if (s1[cur.x]==s3[cur.x+cur.y]) {
                    que.push(node(cur.x+1,cur.y));
                }
            }
            if (cur.y<s2.length()) {
                if (s2[cur.y]==s3[cur.x+cur.y]) {
                    que.push(node(cur.x,cur.y+1));
                }
            }
        }
        return false;
    }
};

 bool isInterleave(string s1, string s2, string s3) {
    
    if(s3.length() != s1.length() + s2.length())
        return false;
    
    bool table[s1.length()+1][s2.length()+1];
    
    for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++){
            if(i==0 && j==0)
                table[i][j] = true;
            else if(i == 0)
                table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
        }
        
    return table[s1.length()][s2.length()];
}
