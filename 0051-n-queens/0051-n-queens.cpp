class Solution {
public:
  vector<vector<string>> ans;
  vector<vector<string>> solveNQueens(int n) {
      //making board ready with .....{dot} format.
      vector<string> board;
      string s(n,'.');
      for(int i=0;i<n;i++) board.push_back(s);
      helper(0,n,board);
      return ans;
    }
  void helper(int row,int n,vector<string> &board){
    //if row checking goes out of bound while all previous queens are at correct pos then add in ans.
    if(row==n){
      ans.push_back(board);
      return;
      }
//we will check for each coln of the given row , if its safe to put there then we put the queen there and call recursion for the next row to put the queen.
    for(int col=0;col<n;col++){
      if(isSafe(row,col,board,n)){//isSafe return valid position or not.
        board[row][col]='Q';//adding the queen.
        helper(row+1,n,board);
        board[row][col]='.';//IMP- we also have to remove this queen to try other positions as board is a reference variable i.e. we didnt get its copy but itself.
      }
    }
  }
  bool isSafe(int row, int col,vector <string> &board,int n){
    // we only need to check the up-left, up and up-right as in other direction no queens are there to attack.
    int temprow=row,tempcol=col;
    //upleft
    while(row>=0 && col>=0){
      if(board[row][col]=='Q') return false;
      row--;
      col--; 
    }
    //up
    row=temprow,col=tempcol;
    while(row>=0){
      if(board[row][col]=='Q') return false;
      row--;
    }
    //upright
    row=temprow,col=tempcol;
    while(row>=0 && col<n){
      if(board[row][col]=='Q') return false;
      row--;
      col++; 
    }
    return true;
  }
};