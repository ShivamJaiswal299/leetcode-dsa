class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      //soln of time complexity m*n and space constant O(1)
        bool zerocol=false,zerorow=false;
        for(int i=0;i<matrix.size();i++) if(matrix[i][0]==0) zerocol=true;
        for(int j=0;j<matrix[0].size();j++) if(matrix[0][j]==0) zerorow=true;
        for(int i=0;i<matrix.size();i++)for(int j=0;j<matrix[0].size();j++){
          if(matrix[i][j]==0){
            matrix[i][0]=0;
            matrix[0][j]=0;
          }
        }
        for(int i=matrix.size()-1;i>0;i--)for(int j=matrix[0].size()-1;j>0;j--){
          if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
        }
        if(zerocol) for(int i=0;i<matrix.size();i++) matrix[i][0] = 0; 
        if(zerorow) for(int j=0;j<matrix[0].size();j++) matrix[0][j] = 0; 
    }
};