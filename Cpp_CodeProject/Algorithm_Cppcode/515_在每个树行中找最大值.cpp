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

typedef struct Node{
    int val;
    vector<Node*> children;
    Node(){}
    Node(int _val):val(_val){}
    Node(int _val, vector<Node*> _children):val(_val),children(_children){}
}Node, PNode;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            int maxValue = que.front()->val; // 让最大值初始化为每层第一个元素
            for (int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                maxValue = maxValue >= node->val? maxValue : node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);  
            }
            result.push_back(maxValue);
        }      
        return result;
    }
};