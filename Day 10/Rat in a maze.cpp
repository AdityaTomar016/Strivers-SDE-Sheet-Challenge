void solve(int i,int j,string s,vector<string>&ans,vector<vector<int>> &m, int n){
        if(i == n-1 && j == n-1){
            ans.push_back(s);
            return;
        }
        
        if(i<0 || j<0 || i>=n || j>=n || m[i][j] != 1){
            return;
        }
        int temp = m[i][j];
        m[i][j] = 2;
        
        solve(i+1,j,s+"D",ans,m,n);
        solve(i,j+1,s+"R",ans,m,n);
        solve(i-1,j,s+"U",ans,m,n);
        solve(i,j-1,s+"L",ans,m,n);
        
        
        m[i][j] = temp;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s="";
        vector<string>ans;
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return {};
        solve(0,0,s,ans,m,n);
        return ans;
    }
