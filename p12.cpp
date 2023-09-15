#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//PSID: 2053907
//Submission ID: 532d32b1-38d6-4a31-96b9-243b3e8dd6e1

//function to check if vector is in order
// bool inorderCheck(vector<int> values){
//     for(int i=0; i<values.size()-1; i++){
//         if(values[i]+1!=values[i+1]){
//             return false;
//         }
//     }
//     return true;
// }

//recursive function to check if k-size subset is in order
bool divideConquer(vector<int>&  values, int k){
    // //getting vector size
    // int s = values.size();

    // // //if size of vector is not divisible to k, it's wrong
    // if(s%k!=0){
    //     return false;
    // }

    //check if vector size is 0, which means if it is, then it's divisible by k
    if(values.size()==0){
        return true;
    }

    // //sort the array
    // sort(values.begin(), values.end());
    // //check when vector reaches size k, is it in order
    // if(values.size() == k){
    //     return inorderCheck(values);
    // }

    //check if k-consecutive numbers exist, then if they exist, take them out
    int base_index = values[0];
    values.erase(values.begin());
    for (int i = 1; i < k; i++) {
        auto remove = find(values.begin(), values.end(), ++base_index);
        if (remove == values.end()) {
            return false;
        }
        values.erase(remove);
    }

    return divideConquer(values, k);    
}


int main(){

    vector<int> values;
    int value, k;
    string temp;

    getline(cin,temp);
    stringstream ss(temp);

    while (ss >> value) {
        values.push_back(value);
    }

    sort(values.begin(), values.end());

    cin>>k;

    bool ans = divideConquer(values, k);
    // if(ans){
    //     cout<<"true"<<endl;
    // }else{
    //     cout<<"false"<<endl;
    // }
    cout<<(ans ? "true" : "false") <<endl;
    return 0;
}