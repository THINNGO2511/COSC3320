#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// PSID: 2053907
// Submission ID: 5b6f7c1b-ab56-47be-894a-5f6537c7570e

int func(int n){
    if(n==1) return 1; 
    return 2*(n/2+1-func(n/2));
}

int main() {
    int n;//n is input number
    cin>>n;
    cout<<func(n);
    return 0;
}