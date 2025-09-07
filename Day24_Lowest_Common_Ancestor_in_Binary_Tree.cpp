#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q)
        return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right)
        return root;  
    return left ? left : right;  
}

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        if (nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    return left ? left : findNode(root->right, val);
}

int main() {
    vector<int> nodes = {3, 5, 1, 6, 2, 0, 8, NULL, NULL, 7, 4};
    TreeNode* root = buildTree(nodes);

    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 4);

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) 
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}
