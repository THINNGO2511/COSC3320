#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Helper function to reconstruct post-order traversal
vector<int> reconstructPostOrder(int n, vector<int>& preOrder, vector<int>& inOrder,
                                  int preStart, int inStart, unordered_map<int, int>& inOrderMap) {
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

int main() {
    int n;
    cin >> n;

    vector<int> preOrder(n);
    vector<int> inOrder(n);

    for (int i = 0; i < n; i++) {
        cin >> preOrder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
    }

    // Create a map to store indices of elements in the in-order traversal
    unordered_map<int, int> inOrderMap;
    for (int i = 0; i < n; i++) {
        inOrderMap[inOrder[i]] = i;
    }

    // Reconstruct post-order traversal
    vector<int> postOrder = reconstructPostOrder(n, preOrder, inOrder, 0, 0, inOrderMap);

    // Output
    for (int i = 0; i < n; i++) {
        cout << postOrder[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
