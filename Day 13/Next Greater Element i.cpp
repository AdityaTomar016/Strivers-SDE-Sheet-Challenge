class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=i;
        }
        
        stack<int>st;
        vector<int>res(nums1.size());
        
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }    
            
            int ans;
            
            if(st.empty()){
                ans = -1;
            }
            else{
                ans = st.top();
            }
            
            st.push(nums2[i]);
            
            
            if(mp.find(nums2[i]) != mp.end()){
                res[mp[nums2[i]]] = ans;
            }
        }
        
        return res;
    }
};
