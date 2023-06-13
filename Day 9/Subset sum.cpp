void solve(int i,int sum,vector<int>arr,int n,vector<int>&ans){
        if(i == n){
            ans.push_back(sum);
            return;
        }
        solve(i+1,sum+arr[i],arr,n,ans);
        solve(i+1,sum,arr,n,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        
        solve(0,0,arr,N,ans);
        return ans;
    }
