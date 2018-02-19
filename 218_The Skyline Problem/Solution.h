struct rightEnd{
	int pos;
    int right;
    int height;
    rightEnd(int pos,int right, int height){
    	this->pos = pos;
        this->right = right;
        this->height = height;
    }
    
    bool operator < (rightEnd a) const {
		if (this->right==a.right) {
			return this->height<a.height;
		}
		return this->right>a.right;
    }
};
struct heightLevel{
    int pos;
    int height;
    heightLevel(int pos, int height){
        this->pos = pos;
        this->height = height;
    }
    
    bool operator < (heightLevel a) const {
        return this->height<a.height;
    }
};
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<rightEnd,vector<rightEnd>> que;
        priority_queue<heightLevel,vector<heightLevel>> heightSta;
        vector<pair<int, int>> res;
        vector<bool> instack(buildings.size()+1, false);
		heightSta.push(heightLevel(buildings.size(),0));
		que.push(rightEnd(buildings.size(),INT_MAX,0));
		instack[buildings.size()] = true;
        int pos = 0;
        while (pos<buildings.size()) {
            rightEnd rightend = que.top();
            heightLevel heightlevel = heightSta.top();
            if (buildings[pos][0]<=rightend.right) {
                if (buildings[pos][2]>heightlevel.height) {
                	res.push_back(make_pair(buildings[pos][0],buildings[pos][2]));
                	heightSta.push(heightLevel(pos,buildings[pos][2]));
                	que.push(rightEnd(pos,buildings[pos][1],buildings[pos][2]));
                	instack[pos] = true;
                } else {
                	heightSta.push(heightLevel(pos,buildings[pos][2]));
                	que.push(rightEnd(pos,buildings[pos][1],buildings[pos][2]));
                	instack[pos] = true;
                }
            } else {
            	int nextHeight;
            	while (rightend.right<buildings[pos][0]) {
            		instack[rightend.pos] = false;
            		nextHeight = findNextHeight(instack,heightSta);
					if (rightend.height>nextHeight) {
                        res.push_back(make_pair(rightend.right,nextHeight));
                    }
            		que.pop();
            		instack[rightend.pos] = false;
            		rightend = que.top();
            	}
            	if (buildings[pos][2]>nextHeight) {
                	res.push_back(make_pair(buildings[pos][0],buildings[pos][2]));
                	heightSta.push(heightLevel(pos,buildings[pos][2]));
                	que.push(rightEnd(pos,buildings[pos][1],buildings[pos][2]));
                	instack[pos] = true;
                } else {
                	heightSta.push(heightLevel(pos,buildings[pos][2]));
                	que.push(rightEnd(pos,buildings[pos][1],buildings[pos][2]));
                	instack[pos] = true;
                }
            }
            pos++;
        }
		while (que.size() != 1) {
			rightEnd rightend = que.top();
			instack[rightend.pos] = false;
            int nextHeight = findNextHeight(instack,heightSta);
			if (rightend.height>nextHeight) {
				res.push_back(make_pair(rightend.right,nextHeight));
			}
            que.pop();
            instack[rightend.pos] = false;
		}
        for(int i = 1; i < res.size(); i++){
            if (res[i].first==res[i-1].first) {
                res.erase(res.begin()+(i-1));
                i--;
            }
        }
        return res;
    }
private:
	int findNextHeight(vector<bool> instack, priority_queue<heightLevel>& heightSta){
		while (!heightSta.empty()) {
			heightLevel cur = heightSta.top();
			if (heightSta.size()==1 || instack[cur.pos] == true) {
				return cur.height;
			}
			heightSta.pop();
		}
		return -1;
	}
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        if (buildings.size()==0) {
            return res;
        }
        res = devideAndConquer(buildings,0,buildings.size()-1);
        return res;
    }
private:
   	vector<pair<int, int>> devideAndConquer(vector<vector<int>> buildings, int left, int right){
   		vector<pair<int, int>> res;
   		if (left==right) {
   			res.push_back(make_pair(buildings[left][0],buildings[left][2]));
   			res.push_back(make_pair(buildings[left][1],0));
   			return res;
   		}
   		int mid = (left+right)/2;
   		vector<pair<int, int>> leftSet = devideAndConquer(buildings,left,mid);
   		vector<pair<int, int>> rightSet = devideAndConquer(buildings,mid+1,right);
   		combineSets(leftSet, rightSet, res);
   		return res;
   	}
   	void combineSets(vector<pair<int, int>> leftSet, vector<pair<int ,int>> rightSet, vector<pair<int, int>>& res){
   		int m = 0;
   		int n = 0;
   		int h1 = 0;
   		int h2 = 0;
   		while (m<leftSet.size() && n<rightSet.size()) {
   			int x = 0;
   			int h = 0;
   			if (leftSet[m].first < rightSet[n].first) {
   				x = leftSet[m].first;
   				h1 = leftSet[m].second;
   				h = max(h1, h2);
   				m++;
   			} else if (leftSet[m].first > rightSet[n].first) {
   				x = rightSet[n].first;
   				h2 = rightSet[n].second;
   				h = max(h1, h2);
   				n++;
   			} else {
   				x = leftSet[m].first;
   				h1 = leftSet[m].second;
   				h2 = rightSet[n].second;
   				h = max(h1, h2);
   				m++;
   				n++;
   			}
   			if (res.size()==0 || h!=res[res.size()-1].second) {
   				res.push_back(make_pair(x,h));
   			}
   		}
   		while (m < leftSet.size()) {
   			res.push_back(leftSet[m]);
   			m++;
   		}
   		while (n < rightSet.size()) {
   			res.push_back(rightSet[n]);
   			n++;
   		}
   	}
};
