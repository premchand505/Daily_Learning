#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    // Main function called by the driver
    int minCost(vector<int>& height) {
        int n = height.size();
        int k;
        cin>>k;
       vector<int> dp(n,-1);
       
       dp[0] = 0;
       for(int i = 1 ; i<n ;i++){
           int mincost = INT_MAX;
        for(int j =1 ;j<=k ;j++){

            if(i-j>=0){
             int jumpcost = dp[i-j] + abs(height[i] - height[i-j]);
mincost = min(mincost , jumpcost);
        }
           
           dp[i] =mincost;
       }
       }
       
       
       
      
        return dp[n-1];
    }
};