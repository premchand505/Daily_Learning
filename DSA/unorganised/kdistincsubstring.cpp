#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

//intution generally if we ned strictly k the eliminate atmost k from atmost k-1
//so we start iterating from k to string length
//so use two loops

//one loop to acess the start of substring and another loop to calcl last of the substring
//take a set if at ith level cal all substring possible using j
//if s[j[] doesny exists already increae the unique count  if unique count > k we strop and if and break from second loop and in first
//loop if unique count is zero add it to set
using namespace std;
int countExactlyK(string& s,int k ){
unordered_set<string> set;


    for (int i =0;i<s.size();i++){
        unordered_map<char,int> check;
        int uniquecount =0;

        for(int j =i ;j< s.size();j++){

            if(check[s[j]]==0){
                uniquecount++;
            }

            check[s[j]]++;

            if(uniquecount> k) break;

            if(uniquecount == k){
                set.insert(s.substr(i,j-i+1));
            }
        }
    }

}



int main(){
    int k =3;
    string s ="abcbaa";
    int res = countExactlyK(s,k);
    cout<<res;
    return 0;
}