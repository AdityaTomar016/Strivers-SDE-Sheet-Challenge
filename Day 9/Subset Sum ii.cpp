class Solution {
public:
    void solve(int i,vector<int>nums,vector<vector<int>> &ans,vector<int>&ds){
        
        ans.push_back(ds);
        
        for(int idx=i;idx<nums.size();idx++){
            
            if(idx != i && nums[idx] == nums[idx-1]) continue;
            
            ds.push_back(nums[idx]);
            solve(idx+1,nums,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        sort(nums.begin(),nums.end());
        
        solve(0,nums,ans,ds);
        
        return ans;
    }
};
