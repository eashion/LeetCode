class Solution {
public:
    string removeKdigits(string num, int k) {
    	if (num.length()==k) {
    		return "0";
    	}
        while(k-- && num.length()!=0){
        	doRemove(num);
        }
        return num==""?"0":num;
    }
private:
	void doRemove(string &num){
		bool flag = false;
		int pos = 0;
		while(pos<num.length()-1){
			if (num[pos]>num[pos+1]) {
				num.erase(pos,1);
				flag = true;
				break;
			}
			pos++;
		}
		if (flag==false) {
			num.erase(pos, 1);
		}
		pos = 0;
		while(num[pos]=='0'){
			num.erase(pos,1);
		}
		return ;
	}
};




class Solution {
public:
    string removeKdigits(string num, int k) {
    	if (num.length()==k) {
    		return "0";
    	}
    	stack<char> sta;
    	for(int i = 0; i < num.length(); i++){
    		while(!sta.empty() && k){
    			char cur = sta.top();
    			if (cur>num[i]) {
    				sta.pop();
    				k--;
    			} else {
                    break;
                }
    		}
    		sta.push(num[i]);
    	}
        while(k--){
            sta.pop();
        }
    	string res = "";
    	while(!sta.empty()){
    		res += sta.top();
    		sta.pop();
    	}
        reverse(res.begin(), res.end());
    	while(res.length()>0 && res[0]=='0'){
    		res.erase(0,1);
    	}
        return res==""?"0":res;
    }
};
