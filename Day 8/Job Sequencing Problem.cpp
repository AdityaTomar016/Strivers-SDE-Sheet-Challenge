
class comp{
  public:
  bool operator()(Job a, Job b){
      return a.profit > b.profit;
  }
};
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp());
        
        vector<int>ded(n,-1);
        int total = 0,count=0;
        
        for(int i=0;i<n;i++){
            int profit = arr[i].profit;
            int deadline = arr[i].dead;
            int id = arr[i].id;
            
            int t = deadline;
            while(t--){
                if(ded[t] == -1){
                    ded[t] = id;
                    total += profit;
                    count++;
                    break;
                }
            }
        }
        
        return {count,total};
    } 
};
