int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>arr;
        
        for(int i=0;i<n;i++){
            arr.push_back({end[i],start[i]});
        }
        
        sort(arr.begin(),arr.end());
        
        int last=-1,count=0;
        
        for(int i=0;i<n;i++){
            if(last == -1){
                count++;
                last = arr[i].first;
            }
            else if(last < arr[i].second){
                count++;
                last = arr[i].first;
            }
            else continue;
        }
        
        return count;
    }
