class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      const int ROWS = board.size(), COLS = board[0].size();
      for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
          if(helper(i,j,0,board,word)) return true;
        }
      }
      return false;
    }
    bool helper(int i,int j,int idx,vector<vector<char>>& board,string word){
      if(idx==word.size()) return true;
      if( i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[idx])  return false;
      char temp = board[i][j];
      board[i][j]='#';

      bool found = helper(i-1,j,idx+1,board,word)||helper(i,j+1,idx+1,board,word)||helper(i+1,j,idx+1,board,word)||helper(i,j-1,idx+1,board,word);
      board[i][j]=temp;
      
      return found;
    }
};