#https://leetcode.com/problems/all-oone-data-structure/discuss/91400/All-in-O(1)-with-detailed-explantation
#上面解释的很清楚
#需要补充的一点为list back&end函数的区别：
#end() 函数返回一个指向当前vector末尾元素的下一位置的迭代器.要访问末尾元素,需要先将此迭代器减1。
#back() 函数返回当前vector最末一个元素的引用。
#另外需要注意，虽然list为双向链表，但是vs为了避免iterator越界，是不允许end--=first的
class AllOne {
private:
    struct Row
    {
        list<string> strs;
        int cnt;
		Row(const string &s, int x) {
			this->strs.push_front(s);
			this->cnt = x;
		}
    };
    //cnt in decresing order
    list<Row> matrix;
    //save the information of row and col
    unordered_map<string, pair<list<Row>::iterator, list<string>::iterator>> mm;
public:
    /** Initialize your data structure here. */
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(mm.find(key) != mm.end()){
            auto row = mm[key].first;
            auto col = mm[key].second;
            auto nextRow = row;
			if (row==matrix.begin()) {
				nextRow = matrix.end();
			} else {
				--nextRow;
			}
            // list is a Circular double linked list
            if (nextRow==matrix.end() || nextRow->cnt!=row->cnt+1) {
                auto newRow = matrix.emplace(row, key, row->cnt+1);
                mm[key] = make_pair(newRow, newRow->strs.begin());
            } else {
                nextRow->strs.push_front(key);
                mm[key] = make_pair(nextRow, nextRow->strs.begin());
            }
            row->strs.erase(col);
            if (row->strs.empty()) {
                matrix.erase(row);
            }
        } else {
            if (matrix.empty() || matrix.back().cnt!=1) {
                auto newRow = matrix.emplace(matrix.end(), key, 1);
                mm[key] = make_pair(newRow, newRow->strs.begin());
            } else {
                matrix.back().strs.push_front(key);
				mm[key] = make_pair(--matrix.end(), matrix.back().strs.begin());
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (mm.find(key) == mm.end()) {
            return ;
        } else {
            auto row = mm[key].first;
            auto col = mm[key].second;
			if (row->cnt == 1) {
                row->strs.erase(col);
                if (row->strs.empty()) matrix.erase(row);
                mm.erase(key);
                return;
            }
            auto nextRow = row;
			if (row==matrix.end()) {
				nextRow = matrix.begin();
			} else {
				++nextRow;
			}
            if (nextRow==matrix.end() || nextRow->cnt!=row->cnt-1) {
				auto newRow = matrix.emplace(nextRow, key, row->cnt-1);
                mm[key] = make_pair(newRow, newRow->strs.begin());
            } else {
                nextRow->strs.push_front(key);
                mm[key] = make_pair(nextRow, nextRow->strs.begin());
            }
            row->strs.erase(col);
            if (row->strs.empty()) {
                matrix.erase(row);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return matrix.empty() ? "":matrix.front().strs.front();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return matrix.empty() ? "":matrix.back().strs.front();
    }
};
