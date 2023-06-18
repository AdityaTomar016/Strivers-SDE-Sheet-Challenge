class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int>dx = {0,1,0,-1};
        vector<int>dy = {1,0,-1,0};
        
        queue<pair<int,int>>q;
        int time=0,ct=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j] > 0) ct++;
                
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            time++;
            
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                ct--;
                
                for(int it=0;it<4;it++){
                    int row = x + dx[it];
                    int col = y + dy[it];
                    
                    if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1){
                        q.push({row,col});
                        grid[row][col] = 2;
                    }
                }
            }
        }
        
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j] == 1){
        //             return -1;
        //         }
        //     }
        // }
        
        if(ct == 0) return max(0,time-1);
        return -1;
    }
};
