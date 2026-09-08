class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      //check leetcode 162 - find peak in vector
      //binary search on rows , inside linear traversal to find max, then check max is peak or not , if not  we move in the other direction.
      int m = mat.size(), n = mat[0].size();
      int low = 0, midrow, high=m-1;
      while(low<=high){
        int midrow = low + (high-low)/2;
        //finding max element idx.
        int maxidx = max_element(mat[midrow].begin(),mat[midrow].end())-mat[midrow].begin();
        int maxele = mat[midrow][maxidx];
        // checking its peak or not.
        if(( midrow-1<0 || (mat[midrow-1][maxidx]<maxele))  &&  ( midrow+1>=m || (mat[midrow+1][maxidx]<maxele))) return {midrow,maxidx};//expand the window to understand the condition imposed.
        else if(midrow-1>=0 && mat[midrow-1][maxidx]>maxele) high = midrow-1;//boundary checks are important
        else if(midrow+1<m && mat[midrow+1][maxidx]>maxele) low = midrow+1;//boundary checks are important
      }
    return {-1,-1};
    }
};