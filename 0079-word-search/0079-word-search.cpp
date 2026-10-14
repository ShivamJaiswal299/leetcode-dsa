class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      const int ROWS = board.size(), COLS = board[0].size();
      for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
          // Try every cell as the starting point
          if(helper(i,j,0,board,word)) return true;
        }
      }
      return false;
    }
    bool helper(int i,int j,int idx,vector<vector<char>>& board,string word){
      if(idx==word.size()) return true; // Base case: all letters matched, word is found

      // Return false if:
        // 1. we went outside the grid, or
        // 2. this cell's letter does not match the needed letter
      if( i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[idx])  return false;

      // mark this cell as visited
      char temp = board[i][j];
      board[i][j]='#';

  // try all 4 directions for the next letter
  // '||' stops as soon as one direction returns true
      bool found = helper(i-1,j,idx+1,board,word)||helper(i,j+1,idx+1,board,word)||helper(i+1,j,idx+1,board,word)||helper(i,j-1,idx+1,board,word);
      board[i][j]=temp;
      
      return found;
    }
};