class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
      vector<int> result;
      int top=0,bottom=mat.size()-1,left=0,right=mat[0].size()-1;
      while(1){
        if(left>right)break; else {
          for(int i=left;i<=right;i++) result.push_back(mat[top][i]);
          top++;
          }
        if(top>bottom)break; else {
          for(int i=top;i<=bottom;i++) result.push_back(mat[i][right]);
          right--;
          }
        if(right<left)break; else {
          for(int i=right;i>=left;i--) result.push_back(mat[bottom][i]);
          bottom--;
          }
        if(bottom<top)break; else {
          for(int i=bottom;i>=top;i--) result.push_back(mat[i][left]);
          left++;
          }
      }
      return result;
    }
};