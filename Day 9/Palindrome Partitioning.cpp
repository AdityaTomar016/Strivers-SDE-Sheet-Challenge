class Solution {
public:
    
    bool ispal(string s,int j,int i){
        while(i<=j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        
        return true;
    }
    void solve(int i,string s,vector<string>&ds,vector<vector<string>>&ans){
        
        if(i == s.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int j=i;j<s.size();j++){
            if(ispal(s,j,i)){
                ds.push_back(s.substr(i,j-i+1));
                solve(j+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        
        solve(0,s,ds,ans);
        
        return ans;
    }
};
