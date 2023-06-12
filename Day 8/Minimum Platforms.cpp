int findPlatform(int arr[], int dep[], int n)
    {
    
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int maxPlat=0;
    	int currPlat=0;
    	
    	int i=0,j=0;
    	
    	while(i<n && j<n){
    	    
    	    if(dep[j] >= arr[i]){
    	        currPlat++;
    	        i++;
    	    }
    	    else{
    	        currPlat--;
    	        j++;
    	    }
    	    
    	    maxPlat = max(maxPlat, currPlat);
    	}
    	
    	return maxPlat;
    }
