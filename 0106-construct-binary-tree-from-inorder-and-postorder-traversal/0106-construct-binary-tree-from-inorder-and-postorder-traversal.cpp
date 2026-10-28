/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1,
                     postIndex, mp);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd, int& postIndex,
                    unordered_map<int, int>& mp) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = mp[rootVal];

        // Build right subtree first
        root->right = build(inorder, postorder, rootIndex + 1,
                            inEnd, postIndex, mp);

        // Then build left subtree
        root->left = build(inorder, postorder, inStart,
                           rootIndex - 1, postIndex, mp);

        return root;
    }
};