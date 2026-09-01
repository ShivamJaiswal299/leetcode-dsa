class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
      int row = mat.size(),col=mat[0].size();
      int low=0,mid,high=row-1;
      while(low<=high){
        mid = low + (high-low)/2;
        if(mat[mid][col-1]==x) return true;
        else if(mat[mid][col-1]>x) high = mid -1;
        else if(mat[mid][col-1]<x) low = mid +1;
      }
      int targetrow = low;
      if(targetrow>=row) return false; //checking wheather targetrow doesnt go out of range,also checking only upper bound as it only increases.
      //now finding further in the row.
      low=0,mid,high=col-1;
      while(low<=high){
        mid = low + (high-low)/2;
        if(mat[targetrow][mid]==x) return true;
        else if(mat[targetrow][mid]>x) high = mid -1;
        else if(mat[targetrow][mid]<x) low = mid +1;
      }
    return false;
    }
};