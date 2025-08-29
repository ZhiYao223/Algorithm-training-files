#include <iostream>
#include <vector>
#include <queue>
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == nullptr) return 0;
        que.push(root);
        int minDepth = 0;
        while (!que.empty()){
            int size = que.size();
            minDepth++;
            for (int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if (node != nullptr && node->left == nullptr && node->right == nullptr) return minDepth;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }    
        return minDepth;
    }
};