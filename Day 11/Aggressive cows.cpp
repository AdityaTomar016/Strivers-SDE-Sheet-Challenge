bool possible(int dist,vector<int>arr,int cows){
    int currdis = arr[0],count=0;

    for(int i=1;i<arr.size();i++){
        if(arr[i] - currdis >= dist){
            count++;
            currdis = arr[i];
        }
    }
    if(count >= cows) return true;
    return false;
}
void solve(){
    
   int n;
   cin>>n;

   vector<int>arr(n);

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   int cows;
   cin>>cows;

    sort(arr.begin(),arr.end());
    
   int low = 1;
   int high = arr[n-1]-arr[0];


   while(low <= high){
    int mid = (low+high)/2;

    if(possible(mid,arr,cows)){
        low = mid+1;
    }
    else{
        high = mid-1;
    }
   }

   cout<<high;

}
