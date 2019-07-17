class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> tmpBoard(board);
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                int count = 0;
                count+=isLive(board, i, j-1);
                count+=isLive(board, i, j+1);
                count+=isLive(board, i-1, j-1);
                count+=isLive(board, i-1, j);
                count+=isLive(board, i-1, j+1);
                count+=isLive(board, i+1, j-1);
                count+=isLive(board, i+1, j);
                count+=isLive(board, i+1, j+1);
                
                if(board[i][j] == 1) {
                    if(count<2 || count>3) {
                        tmpBoard[i][j] = 0;
                        continue;
                    }
                    tmpBoard[i][j] = 1;
                    continue;
                }
                if(count == 3) {
                    tmpBoard[i][j] = 1;
                    continue;
                }
                tmpBoard[i][j] = 0;
            }
        }
        board = tmpBoard;
    }
    
    int isLive(vector<vector<int>>& board, int i, int j) {
        if(i>=0&&i<board.size()) {
            if(j>=0 && j<board[i].size()) {
                if(board[i][j]==1) {
                    return 1;
                }
            }
        }
        return 0;
    }
};