class Solution {
public:
    void solver(vector<vector<int>>& matrix,vector<pair<int,int>> vp){
        int m =matrix.size(),n=matrix[0].size();
        for(auto it: vp){
            for(int x=0;x<n;x++){
                matrix[it.first][x]=0;
            }
             for(int y=0;y<m;y++){
                matrix[y][it.second]=0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m =matrix.size(),n=matrix[0].size();
        vector<pair<int,int>> vp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    vp.push_back({i,j});
                }
            }
        }
        solver(matrix,vp);
    }
};