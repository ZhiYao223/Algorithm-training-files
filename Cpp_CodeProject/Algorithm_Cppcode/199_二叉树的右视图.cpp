#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* left, TreeNode* right):val(val),left(left),right(right){}
    TreeNode():val(0),left(nullptr),right(nullptr){}
}TreeNode, *PTreeNode;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()){
            int size = que.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (i == (size-1)){
                    result.push_back(node->val);
                }  
            }            
        }
        return result;
    }
};