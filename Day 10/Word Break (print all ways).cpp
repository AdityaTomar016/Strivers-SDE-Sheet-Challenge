#include <bits/stdc++.h> 

void solve(int i,string &ds,vector<string>&ans,string s,unordered_map<string,int>mp){
    if(i == s.size()){
        ans.push_back(ds);
        return;
    }

    for(int id=i;id<s.size();id++){
        string str = s.substr(i,id-i+1);
        if(mp.find(str) != mp.end()){
            int n = ds.size();
            ds += str + " ";
            solve(id+1,ds,ans,s,mp);
            ds.erase(n);
        }

        
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<string,int>mp;

    for(auto it: dictionary){
        mp[it]++;
    }

    vector<string>ans;
    string ds="";


    solve(0,ds,ans,s,mp);
    return ans;

}
