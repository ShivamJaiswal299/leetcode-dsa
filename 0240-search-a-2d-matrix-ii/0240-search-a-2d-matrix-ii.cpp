class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
      int row = mat.size(),col=mat[0].size();
      int cIdx=col-1,rIdx=0;//as we will start from right corner
      while(rIdx<row && cIdx>=0){//stops when boundary hits
        if(mat[rIdx][cIdx]==x) return true;
        else if(mat[rIdx][cIdx]<x) rIdx++;//rowidx increasing as current row wont have the element
        else if(mat[rIdx][cIdx]>x) cIdx--;//columnidx increasing as currnt column wont have the element
      }
      return false;
    }
};