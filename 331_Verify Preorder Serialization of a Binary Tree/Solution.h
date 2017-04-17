class Solution {
public:
    bool isValidSerialization(string preorder) {
        if( preorder == "" ){
            return true;
        }
        preorder += ",";
        int capacity = 1;
        for( int i = 0; i < preorder.length(); i++ ){
            if( preorder[i] != ',' ){
                continue;
            }
            capacity -= 1;
            if( capacity < 0 ){
                return false;
            }
            if( preorder[i-1] != '#' ){
                capacity += 2;
            }
        }
        return capacity==0;
    }
};
