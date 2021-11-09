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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildFromMiddle(vector<int>& nums, int low, int high){
        if (low > high)
            return nullptr;
        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildFromMiddle(nums, low, mid - 1);
        node->right = buildFromMiddle(nums, mid + 1, high);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildFromMiddle(nums, 0, nums.size()-1);
    }
};