#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right):val(val),left(left),right(right){}
}TreeNode, *PTreeNode;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()){
             TreeNode* node = st.top();
            if (node != nullptr){
                st.pop();
                if (node->right != nullptr) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left != nullptr) st.push(node->left);
            }else{
                st.pop();
                result.push_back(st.top()->val);
                st.pop();
            }
        }
        return result;
    }
};