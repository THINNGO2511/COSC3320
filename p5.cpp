#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

// PSID: 2053907
// Submission ID: 38c0d94e-1794-4dca-a23a-66c563550422 

vector<int> reconstructPostOrder(int n, vector<int>& preOrder, vector<int>& inOrder, int preStart, int inStart, unordered_map<int, int>& inOrderMap) {
    if (n == 0) {
        return {};
    }

    int root = preOrder[preStart];
    int rootIndex = inOrderMap[root];
    int leftSize = rootIndex - inStart;
    int rightSize = n - leftSize - 1;

    vector<int> leftPostOrder = reconstructPostOrder(leftSize, preOrder, inOrder, preStart + 1, inStart, inOrderMap);
    vector<int> rightPostOrder = reconstructPostOrder(rightSize, preOrder, inOrder, preStart + leftSize + 1, rootIndex + 1, inOrderMap);

    vector<int> postOrder;
    postOrder.insert(postOrder.end(), leftPostOrder.begin(), leftPostOrder.end());
    postOrder.insert(postOrder.end(), rightPostOrder.begin(), rightPostOrder.end());
    postOrder.push_back(root);

    return postOrder;
}

int main(){
    int size;
    cin >> size;

    vector<int> preOrderVect(size), inOrderVect(size);


    for(int i = 0; i < size; i++){
        cin >> preOrderVect[i];
    }

    for(int i = 0; i < size; i++){
        cin >> inOrderVect[i];
    }

    //map to store index for inOrderVect, so value/index format
    unordered_map<int, int > inOrderMap;
    for(int i = 0; i < size; i++){
        inOrderMap[inOrderVect[i]] = i;
    }

    vector<int> postOrder = reconstructPostOrder(size, preOrderVect, inOrderVect, 0,0, inOrderMap);

    for(int i = 0; i <size; i++){
        cout<<postOrder[i]<<" ";
    }

    return 0;
}