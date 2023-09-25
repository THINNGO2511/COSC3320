#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

// PSID: 2053907
// Submission ID: 621229d2-5317-4c54-aeef-5ca4147057aa 

using namespace std;

int calculatePoint(vector<int> arr1, vector<int> arr2){
    int index = 0, temp = 0, finalScore = 0;

    while(index < arr2.size()){
        while(temp < arr1.size() && arr2[index] > arr1[temp]){
            temp++;
        }

        finalScore+=temp;
        index++;
    }

    return finalScore;
}

void merge(vector<int> &robertInput, vector<int> &rachelInput,int left, int mid, int right, int &robertVal, int &rachelVal){
    int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;

    vector<int> leftRobert, rightRobert, leftRachel, rightRachel;

    for(int i = 0; i < subArrayOne; i++){
        leftRobert.push_back(robertInput[left+i]);
        leftRachel.push_back(rachelInput[left+i]);
    }

    for(int j = 0; j < subArrayTwo; j++){
        rightRobert.push_back(robertInput[mid + 1 + j]);
        rightRachel.push_back(rachelInput[mid + 1 + j]);
    }

    int iRobert = 0, iRachel = 0, jRobert = 0, jRachel = 0, mergeRobert = left, mergeRachel = left;

    robertVal += calculatePoint(leftRachel, rightRobert);
    // cout<<robertVal<<endl;
    rachelVal += calculatePoint(leftRobert, rightRachel);

    //merging robert

    while(iRobert < subArrayOne && jRobert < subArrayTwo){
        if(leftRobert[iRobert] <= rightRobert[jRobert]){
            robertInput[mergeRobert] = leftRobert[iRobert++];
        }
        else{
            robertInput[mergeRobert] = rightRobert[jRobert++];
        }
        mergeRobert++;
    }

    while(iRobert < subArrayOne){
        robertInput[mergeRobert++] = leftRobert[iRobert++];
    }

    while(jRobert < subArrayTwo){
        robertInput[mergeRobert++] = rightRobert[jRobert++];
    }

    //merging rachel

    while(iRachel < subArrayOne && jRachel < subArrayTwo){
        if(leftRachel[iRachel] <= rightRachel[jRachel]){
            rachelInput[mergeRachel] = leftRachel[iRachel++];
        }
        else{
            rachelInput[mergeRachel] = rightRachel[jRachel++];
        }
        mergeRachel++;
    }

    while(iRachel < subArrayOne){
        rachelInput[mergeRachel++] = leftRachel[iRachel++];
    }

    while(jRachel < subArrayTwo){
        rachelInput[mergeRachel++] = rightRachel[jRachel++];
    }
}



void mergeSort(vector<int> &robertInput, vector<int> &rachelInput, int begin, int end, int &robertVal, int &rachelVal){
    if(begin >= end) return;

    int mid = begin + (end - begin) / 2;

	mergeSort(robertInput, rachelInput, begin, mid, robertVal, rachelVal);
	mergeSort(robertInput, rachelInput, mid + 1, end, robertVal, rachelVal);
    merge(robertInput, rachelInput, begin, mid, end, robertVal, rachelVal);
}


int main() {
    vector<int>robertInput, rachelInput;
    int tempVal,robertVal = 0, rachelVal = 0;
    string robertTemp, rachelTemp;
    stringstream robT(robertTemp);
    stringstream racT(rachelTemp);

    //getting robert points
    getline(cin, robertTemp);
    robT<<robertTemp;

    while(robT >> tempVal) {
        robertInput.push_back(tempVal);
    }

    //getting rachel points
    getline(cin, rachelTemp);
    racT<<rachelTemp;

    while(racT >> tempVal){
        rachelInput.push_back(tempVal);
    }

    mergeSort(robertInput, rachelInput, 0, robertInput.size()-1, robertVal, rachelVal);
    cout<<robertVal<<" "<<rachelVal;

    return 0;
}