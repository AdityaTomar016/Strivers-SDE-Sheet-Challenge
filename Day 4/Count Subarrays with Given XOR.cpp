#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    unordered_map<int,int>mp;
    mp[0] = 1;

    int count=0;
    int xorr=0;

    for(int i=0;i<n;i++){
        xorr = xorr^arr[i];
        
        int req = xorr^x;

        
        count += mp[req];
        

        mp[xorr]++;
    }

    return count;
}
