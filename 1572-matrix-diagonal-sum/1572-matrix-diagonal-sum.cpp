class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int i = 0,j = 0;
        while(i<mat.size() && j<mat[0].size()){
            sum+=mat[i][j];
            mat[i][j]=0;
            i++;j++;
        }
        
        i=0,j=mat[0].size()-1;
        while(i<mat.size() && j>=0){
            sum+=mat[i][j];
            mat[i][j]=0;
            i++;j--;
        }
        
        return sum;
    }
};