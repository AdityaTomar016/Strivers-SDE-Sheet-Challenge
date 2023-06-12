int minCoins(int coins[], int M, int V) 
	{ 
	    sort(coins,coins+M);
	    
	    int i=M-1, count = 0;
	    
	    while(i>=0){
	        if(V < coins[i]){
	            i--;
	        }
	        else{
	            count += V/coins[i];
	            V -= (V/coins[i]) * coins[i];
	            i--;
	        }
	        
	        if(V == 0){
	            return count;
	        }
	       // if(i <= 0 && V > 0){
	       //     return -1;
	       // }
	    }
	    return -1;
	} 
