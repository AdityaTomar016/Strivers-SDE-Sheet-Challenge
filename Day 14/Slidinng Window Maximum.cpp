class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res;
        
        list<int>l;
        
        for(int i=0;i<n;i++){
            
            while(!l.empty() && l.front() == i-k){
                l.pop_front();
            }
            
            while(!l.empty() && nums[l.back()] < nums[i]){
                l.pop_back();
            }
            
            l.push_back(i);
            
            if(i >= k-1){
                res.push_back(nums[l.front()]);
            }
        }
        
        return res;
    }
};
