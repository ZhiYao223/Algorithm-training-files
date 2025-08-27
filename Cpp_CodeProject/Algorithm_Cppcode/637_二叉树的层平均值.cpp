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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        int sum = 0; // 每层总和
        while(!que.empty()){
            int size = que.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            result.push_back(sum / size);
        }
        return result;
    }
};