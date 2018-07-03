Prefix Tree, 关键是树结构的设计，以及新建节点和插入函数的逻辑。https://blog.csdn.net/lisonglisonglisong/article/details/45584721
```
struct trie_node{
    int cnt;
    trie_node* children[26];
    trie_node(){}
    trie_node(int cnt){
        this->cnt = cnt;
    }
};
class Trie {
private:
    trie_node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = createTrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertTrieNode(root, word);
        return ;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchTrieChildren(root,word)>=1;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchTrieChildren(root, prefix)>=0;
    }
private:
    trie_node* createTrieNode(){
        trie_node* node = new trie_node(0);
        for(int i = 0; i < 26; i++){
            node->children[i] = NULL;
        }
        return node;
    }
    void insertTrieNode(trie_node* root, string str){
        int pos = 0;
        int len = str.length();
        trie_node* p = root;
        while(pos < len){
            int tmp = str[pos]-'a';
            if (p->children[tmp] == NULL) {
                p->children[tmp] = createTrieNode();
            }
            p = p->children[tmp];
            pos++;
        }
        p->cnt += 1;
        return ;
    }
    int searchTrieChildren(trie_node* root, string str){
        int pos = 0;
        int len = str.length();
        trie_node* p = root;
        while(pos < len){
            int tmp = str[pos]-'a';
            if (p->children[tmp] == NULL) {
                return -1;
            }
            p = p->children[tmp];
            pos++;
        }
        return p->cnt;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
```
