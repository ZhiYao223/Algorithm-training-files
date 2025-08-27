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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()){
            int size = que.size();
            vector<int> path = {NULL};
            for (int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                path.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(path);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};