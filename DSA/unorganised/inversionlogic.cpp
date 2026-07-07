#include<bits/stdc++.h>
using namespace std;

// ist either evens place on left and odd placed on left
//we have to return minimum swaps we get in each path n dtka emin of those

//we take tow ds to track the even and odd indices 

// first path we iterate and place all evens on left 
//second path w take all odfs and place on left

// we donot need to perform swaps we justneed to count the swaps that can happen 

//mathematical intution  the swap required to swap from A to B using corresponding elemts swap is  abs(a-b);


//for each path calculation we iterate till its nums size and calculate aboslute difference between the position i.e  even_index(i) -i

int minswaps(vector<int>& nums){

vector<int> even_index;
vector<int>odd_index;

for(int i =0 ;i<nums.size();i++){
    if(nums[i] % 2 == 0){
        even_index.push_back(i);
    }else{
        odd_index.push_back(i);
    }
}

long long evensleft =0;
for(int i =0;i<even_index.size();i++){
    evensleft += abs(even_index[i] - i);
}

long long oddsleft =0;
for(int i =0;i<odd_index.size();i++){
    oddsleft += abs(odd_index[i] - i);
}

return  min(evensleft,oddsleft);


 }


 int main(){
    vector<int> nums = {1,2,3,4,5};
    int  res = minswaps(nums);
cout<<res;
return 0;
}