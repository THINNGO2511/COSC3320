#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode(int value) : val(value) , left(nullptr) , right(nullptr) {}
};

//insert tree
TreeNode* insert(TreeNode* root, int value){
    if(!root){
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

//function to find LCA(least common ancestor)
TreeNode* findLCA(TreeNode* root, int value1, int value2){
    if(!root){
        return NULL;
    }

    if(root->val > value1 && root->val > value2){
        return findLCA(root->left, value1, value2);
    }
    else if(root->val < value1 && root->val < value2){
        return findLCA(root->right, value1, value2);
    }else{
        return root;
    }
}

//function to find distance from LCA to node
int findDistance(TreeNode* root, int node_val){
    if(!root){
        return 0;
    }

    if(node_val == root->val){
        return 0;
    }

    else if(node_val > root->val){
        return 1 + findDistance(root->right, node_val);
    }

    else{
        return 1 + findDistance(root->left, node_val);
    }
}


int calculateDistance(TreeNode* root, int first_node, int second_node){
    TreeNode* LCA = findLCA(root, first_node, second_node);
    int distance1 = findDistance(LCA, first_node);
    int distance2 = findDistance(LCA, second_node);
    return distance1+distance2;
}

int main(){

    vector<int> values;
    int value;
    string temp;

    getline(cin,temp);
    stringstream ss(temp);

    while (ss >> value) {
        values.push_back(value);
    }

    TreeNode* root = nullptr;
    for (int val : values) {
        root = insert(root, val);
    }

    int node1, node2;
    cin >> node1 >> node2;

    int distance = calculateDistance(root,node1, node2);
    cout<<distance<<endl;

    return 0;
}