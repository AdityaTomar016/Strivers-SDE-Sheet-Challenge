int NumsSmaller(int t,vector<int>r){
    int low=0,high=r.size()-1;
    
    while(low<=high){
        int mid = (low+high)/2;
        
        if(r[mid] <= t){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
int Solution::findMedian(vector<vector<int> > &arr) {
    int n = arr.size();
    int m = arr[0].size();
    int low = 1,high=0;
    
    for(int i=0;i<n;i++){
        high = max(high,arr[i][m-1]);
    }
    
    while(low <= high){
        int mid = (low+high)/2;
        
        int count=0;
        for(int i=0;i<n;i++){
            count += NumsSmaller(mid,arr[i]);
        }
        
        if(count <= (n*m)/2){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    
    return low;
}
