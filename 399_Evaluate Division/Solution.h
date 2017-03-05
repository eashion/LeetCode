class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int cnt = 1;
        int size = equations.size();
        vector<double> res;
        unordered_map<string,int> mm;
        double cost[2*size+1][2*size+1];
        for( int i = 1; i < 2*size+1; i++ ){
            for( int j = 1; j < 2*size+1; j++ ){
                cost[i][j] = -1.0;
            }
            cost[i][i] = 1;
        }
        for( int index = 0; index < size; index++ ){
            string t1 = equations[index].first;
            string t2 = equations[index].second;
            if( mm[t1] == 0 ){
                mm[t1] = cnt++;
            }
            if( mm[t2] == 0 ){
                mm[t2] = cnt++;
            }
            int p1 = mm[t1];
            int p2 = mm[t2];
            cost[p1][p2] = values[index];
            cost[p2][p1] = 1/values[index];
        }
        for( int k = 1; k < cnt; k++ ){
            for( int i = 1; i < cnt; i++ ){
                for( int j = 1; j < cnt; j++ ){
                    if( cost[i][k]!=-1.0 && cost[k][j]!=-1.0 ){
                        cost[i][j] = cost[i][k]*cost[k][j];
                    }
                }
            }
        }
        for( int index = 0; index < queries.size(); index++ ){
            int p1 = mm[queries[index].first];
            int p2 = mm[queries[index].second];
            if( p1==0 || p2==0 ){
                res.push_back(-1.0);
                continue;
            }
            if( cost[p1][p2] != -1.0 ){
                res.push_back(cost[p1][p2]);
            }
            else{
                res.push_back(-1.0);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        unordered_map<string,Node*> mm;
        for( int i = 0; i < equations.size(); i++ ){
            string s1 = equations[i].first;
            string s2 = equations[i].second;
            if( mm[s1]==NULL && mm[s2]==NULL ){
                mm[s1] = new Node();
                mm[s1]->value = values[i];
                mm[s2] = new Node();
                mm[s2]->value = 1;
                mm[s2]->parent = mm[s1];
            }
            else if( mm[s1]==NULL ){
                mm[s1] = new Node();
                mm[s1]->parent = findParent(mm[s2]);
                mm[s1]->value = mm[s2]->value*values[i];
            }
            else if( mm[s2]==NULL ){
                mm[s2] = new Node();
                mm[s2]->parent = findParent(mm[s1]);
                mm[s2]->value = mm[s1]->value/values[i];
            }
            else{
                unionParent(mm[s1],mm[s2],values[i],mm);
            }
        }
        for( int i = 0; i < queries.size(); i++ ){
            string s1 = queries[i].first;
            string s2 = queries[i].second;
            if( mm[s1]==NULL || mm[s2]==NULL || findParent(mm[s1])!=findParent(mm[s2]) ){
                res.push_back(-1.0);
            }
            else{
                res.push_back(mm[s1]->value/mm[s2]->value);
            }
        }
        return res;
    }
private:
    struct Node{
        Node* parent;
        double value = 1.0;
        Node(){
            parent = this;
        }
    };
private:
    Node* findParent(Node* x){
        if( x->parent == x ){
            return x;
        }
        return x->parent = findParent(x->parent);
    }
private:
    void unionParent(Node* x,Node* y,double value,unordered_map<string,Node*>& mm){
        Node* p1 = findParent(x);
        Node* p2 = findParent(y);
        double ratio = y->value*value/x->value;
        for( auto i = mm.begin(); i != mm.end(); i++ ){
            if( findParent(i->second) == p1 ){
                i->second->value *= ratio;
            }
        }
        p1->parent = p2;
    }
};
