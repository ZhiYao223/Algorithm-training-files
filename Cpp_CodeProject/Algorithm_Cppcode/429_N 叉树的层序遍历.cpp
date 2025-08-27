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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()){
            int size = que.size();
            vector<int> path;
            for (int i = 0; i < size; i++){
                Node* node = que.front();
                que.pop();
                path.push_back(node->val);
                for (int j = 0; j < node->children.size(); j++){
                    if (node->children[j] != nullptr)
                        que.push(node->children[j]);
                }              
            }
            result.push_back(path);
        }    
        return result;
    }
};