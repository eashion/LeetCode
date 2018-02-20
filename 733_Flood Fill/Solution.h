class Solution {
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc]==newColor) {
            return image;
        }
        dfs(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc,int old, int newColor){
        image[sr][sc] = newColor;
        for(int i = 0; i < 4; i++){
            int nx = sr+dx[i];
            int ny = sc+dy[i];
            if (nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size() && image[nx][ny]==old) {
                dfs(image,nx,ny,old,newColor);
            }
        }
    }
};
