bool isSafe(int c,int node,vector<int>& col,bool graph[101][101], int n){
        for(int k=0;k<n;k++){
            if(k != node && graph[k][node] == 1 && col[k] == c){
                return false;
            }
        }
        return true;
    }
    bool solve(int i,vector<int>&col,bool graph[101][101], int m, int n){
        if(i == n){
            return true;
        }
        
        for(int j=1;j<=m;j++){
            if(isSafe(j,i,col,graph,n)){
                col[i] = j;
                if(solve(i+1,col,graph,m,n)) return true;
                col[i] = 0;
            }
        }
        
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>col(n,0);
        return solve(0,col,graph,m,n);
    }
