map string to vector<string>
```
struct MyFile{
    string name;
    string content;
    MyFile(){}
    MyFile(string name, string content){
        this->name = name;
        this->content = content;
    }
};
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, int> content2pos;
        vector<vector<string>> res;
        for(int i = 0; i < paths.size(); i++){
            string cur = paths[i];
            string path = parsePath(cur);
            while(cur.length() != 0){
                MyFile file = parseFile(cur);
                if (content2pos.find(file.content) == content2pos.end()) {
                    content2pos[file.content] = res.size();
                    vector<string> newlis;
                    newlis.push_back(path+"/"+file.name);
                    res.push_back(newlis);
                } else {
                    res[content2pos[file.content]].push_back(path+"/"+file.name);
                }
            }
        }
        for(auto iter = res.begin(); iter != res.end(); ){
            if (iter->size() > 1) {
                iter++;
            } else {
                iter = res.erase(iter);
            }
        }
        return res;
    }
private:
    string parsePath(string& cur){
        int pos = -1;
        string res = "";
        for(int i = 0; i < cur.length(); i++){
            if (cur[i] == ' ') {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            res = cur.substr(0, pos);
            cur = cur.substr(pos+1);
            //cout<<"path: "<<res<<endl;
            //cout<<"cur: "<<cur<<endl;
        }
        return res;
    }
    MyFile parseFile(string& cur){
        int left = -1;
        int right = -1;
        for(int i = 0; i < cur.length(); i++){
            if (cur[i]=='(') {
                left = i;
            } else if (cur[i]==')') {
                right = i;
                break;
            }
        }
        MyFile file;
        file.name = cur.substr(0, left);
        file.content = cur.substr(left+1, right-left-1);
        if (right+1 == cur.length()) {
            cur = "";
        } else {
            cur = cur.substr(right+2);
        }
        //cout<<"name: "<<file.name<<endl;
        //cout<<"content: "<<file.content<<endl;
        //cout<<"cur: "<<cur<<endl;
        return file;
    }
};
```
