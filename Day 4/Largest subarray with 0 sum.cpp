
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int maxi=0;
        
        unordered_map<int,int>mp;
        
        int curr_sum=0;
        
        for(int i=0;i<n;i++){
            curr_sum += A[i];
            
            if(A[i] == 0 && maxi == 0) maxi = 1;
            
            if(curr_sum == 0){
                maxi = i+1;
            }
            else{
                if(mp.find(curr_sum) != mp.end()){
                    maxi = max(maxi, i-mp[curr_sum]);
                }
                else{
                    mp[curr_sum] = i;
                }
            }
        }
        
        return maxi;
    }
};
