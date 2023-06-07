long long merge(int low,int mid,int high,long long arr[]){
        
        vector<int>temp(high-low+1);
        long long ans = 0;
        
        int left = low;
        int right = mid+1,k=0;
        
        while(left<=mid && right<=high){
            if(arr[left] <= arr[right]){
                temp[k++] = (arr[left++]);
            }
            else{
                ans += mid-left+1;
                temp[k++] = (arr[right++]);
            }
        }
        
        while(left<=mid){
           temp[k++] = (arr[left++]);
        }
        while(right<=high){
            temp[k++] = (arr[right++]);
        }
        
        k=0;
        for(int i=low;i<=high;i++){
            arr[i] = temp[k++];
        }
        return ans;
    }
    long long mergeSort(int low,int high,long long arr[]){
        long long count = 0;
        
        if(low < high){
            int mid = (low+high)/2;
            count += mergeSort(low,mid,arr);
            count += mergeSort(mid+1,high,arr);
            
            count += merge(low,mid,high,arr);
        }
        
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        
        return mergeSort(0,N-1,arr);
    }
