class Solution {
public:
    
    bool isSafe(int row,int col,vector<string> &board,int n){
        int x = row;
        int y = col;
        
        while(x >= 0 && y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x--;
            y--;
        }
        
        x = row;
        y = col;
        
        while(x >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x--;
        }
        
        x = row;
        
        while(x >= 0 && y < n){
            if(board[x][y] == 'Q'){
                return false;
            }
            x--;
            y++;
        }
        
        return true;
    }
    void solve(int row,vector<string> &board,vector<vector<string>> &ans, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(row+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        
        solve(0,board,ans,n);
        return ans;
    }
};
