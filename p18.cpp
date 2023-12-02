#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// PSID: 2053907
// Submission ID: d2d184c2-d0cf-4d72-b47f-bdfbe1ce43ae 

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

TreeNode* deserialize(istringstream& in) {
    char val;
    in >> val;

    if (in.peek() == '}'){
        in >> val;
        return nullptr;
    }

    int num;
    in >> num;
    
    TreeNode* root = new TreeNode(num);
    root->left = deserialize(in);
    root->right = deserialize(in);

    in >> val;
    return root;
}

TreeNode* process_string(string input){
    istringstream iss(input);
    return deserialize(iss);
}


void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    string input;
    getline(cin, input);
    TreeNode* root = process_string(input);
    inorderTraversal(root);
    cout << endl;
    return 0;
}