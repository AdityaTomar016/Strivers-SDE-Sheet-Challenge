double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp());
        double total=0;
        
        for(int i=0;i<n;i++){
            if(arr[i].weight <= W){
                total += arr[i].value;
                W -= arr[i].weight;
            }
            else{
                total += W*((double)arr[i].value/(double)arr[i].weight);
                break;
            }
        }
        return total;
    }
