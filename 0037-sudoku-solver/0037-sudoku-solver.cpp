class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
      helper(0,0,board);
    }
    bool helper(int i, int j, vector<vector<char>> &board) {
        if (i == 9) return true; // all cells done -> solved

        // next cell
        int ni = (j == 8) ? i + 1 : i;
        int nj = (j == 8) ? 0 : j + 1;

        // already filled , move ahead
        if (board[i][j] != '.') return helper(ni, nj, board);

        for (int num = 1; num <= 9; num++) {
            if (rowvalid(i,j,num,board) && colvalid(i,j,num,board) && gridvalid(i,j,num,board)) {   // your checks, later
                board[i][j] = '0' + num;                      // place
                if (helper(ni, nj, board)) return true;       // solved, keep digit
                board[i][j] = '.';                            // failed, undo
            }
        }
        return false;   // no number worked here so go back and change earlier cell
    }
    bool rowvalid(int i,int j, int num, vector<vector<char>> &board){
      for(int j=0;j<9;j++){
        if(board[i][j]=='0'+num) return false;
      }
      return true;
    }
    bool colvalid(int i,int j, int num, vector<vector<char>> &board){
      for(int i=0;i<9;i++){
        if(board[i][j]=='0'+num) return false;
      }
      return true;

    }
    bool gridvalid(int i,int j, int num, vector<vector<char>> &board){
      //logic- find the top left corner of this grid then traverse the 3x3 grid
      int r = i - i%3;
      int c = j - j%3;
      for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
          if(board[i][j]=='0'+num) return false;
        }
      }
      return true;
    }
};