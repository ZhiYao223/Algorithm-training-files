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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
private:
    bool compare(TreeNode* left, TreeNode* right){
        if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right != nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        // 排除存在空节点的情况
        else if (left->val != right->val) return false;
        // 剩下的就是左右节点都存在，且数值相同的情况
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left );
        bool isSame = outside && inside;
        return isSame;
    }
};