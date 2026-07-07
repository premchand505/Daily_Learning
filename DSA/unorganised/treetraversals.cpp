// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <climits>

// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
    
//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

// // 1. Preorder Traversal (Root -> Left -> Right)
// void preorder(Node* node) {
//     if (node == nullptr) return;
//     cout << node->data << " ";
//     preorder(node->left);
//     preorder(node->right);
// }

// // 2. Inorder Traversal (Left -> Root -> Right)
// void inorder(Node* node) {
//     if (node == nullptr) return;
//     inorder(node->left);
//     cout << node->data << " ";
//     inorder(node->right);
// }

// // 3. Postorder Traversal (Left -> Right -> Root)
// void postorder(Node* node) {
//     if (node == nullptr) return;
//     postorder(node->left);
//     postorder(node->right);
//     cout << node->data << " ";
// }

// // 4. Level Order Traversal (BFS) - Print level by level
// void levelorder(Node* node) {
//     if (node == nullptr) return;
    
//     queue<Node*> q;
//     q.push(node);
    
//     while (!q.empty()) {
//         int size = q.size();
//         for (int i = 0; i < size; i++) {
//             Node* curr = q.front();
//             q.pop();
//             cout << curr->data << " ";
            
//             if (curr->left) q.push(curr->left);
//             if (curr->right) q.push(curr->right);
//         }
//         cout << endl;  // New line after each level
//     }
// }

// // 5. Level Order Traversal returning 2D vector
// vector<vector<int>> levelOrderTraversal(Node* root) {
//     vector<vector<int>> ans;
//     if (!root) return ans;
    
//     queue<Node*> q;
//     q.push(root);
    
//     while (!q.empty()) {
//         int size = q.size();
//         vector<int> level;
//         for (int i = 0; i < size; i++) {
//             Node* node = q.front();
//             q.pop();
//             level.push_back(node->data);
//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//         ans.push_back(level);
//     }
//     return ans;
// }

// // 6. Maximum Depth (Height) of Binary Tree
// int maxDepth(Node* node) {
//     if (!node) return 0;
//     int left = maxDepth(node->left);
//     int right = maxDepth(node->right);
//     return 1 + max(left, right);
// }

// // 7. Check if Binary Tree is Height-Balanced
// int checkBalanced(Node* node) {
//     if (!node) return 0;
    
//     int left = checkBalanced(node->left);
//     if (left == -1) return -1;
    
//     int right = checkBalanced(node->right);
//     if (right == -1) return -1;
    
//     if (abs(left - right) > 1) return -1;
    
//     return 1 + max(left, right);
// }
// bool isBalanced(Node* root) {
//     return checkBalanced(root) != -1;
// }

// // 8. Diameter of Binary Tree (longest path between any two nodes)
// int diameterOfBinaryTree(Node* root, int& diameter) {
//     if (!root) return 0;
    
//     int left = diameterOfBinaryTree(root->left, diameter);
//     int right = diameterOfBinaryTree(root->right, diameter);
    
//     diameter = max(diameter, left + right);
    
//     return 1 + max(left, right);
// }
// int diameterOfBinaryTree(Node* root) {
//     int diameter = 0;
//     diameterOfBinaryTree(root, diameter);
//     return diameter;
// }

// // 9. Maximum Path Sum (node values can be negative)
// int maxPathSumUtil(Node* node, int& best) {
//     if (!node) return 0;
    
//     int left = maxPathSumUtil(node->left, best);
//     int right = maxPathSumUtil(node->right, best);
    
//     left = max(left, 0);
//     right = max(right, 0);
    
//     best = max(best, node->data + left + right);
    
//     return node->data + max(left, right);
// }
// int maxPathSum(Node* root) {
//     int best = INT_MIN;
//     maxPathSumUtil(root, best);
//     return best;
// }

// // 10. Check if two trees are identical
// bool areIdentical(Node* p, Node* q) {
//     if (!p && !q) return true;
//     if (!p || !q) return false;
//     return (p->data == q->data) &&
//            areIdentical(p->left, q->left) &&
//            areIdentical(p->right, q->right);
// }

// // 11. Minimum Depth of Binary Tree
// int minDepth(Node* node) {
//     if (!node) return 0;
//     if (!node->left) return 1 + minDepth(node->right);
//     if (!node->right) return 1 + minDepth(node->left);
//     return 1 + min(minDepth(node->left), minDepth(node->right));
// }

// // 12. Zigzag Level Order Traversal
// vector<vector<int>> zigzagLevelOrder(Node* root) {
//     vector<vector<int>> ans;
//     if (!root) return ans;
    
//     queue<Node*> q;
//     q.push(root);
//     bool leftToRight = true;
    
//     while (!q.empty()) {
//         int size = q.size();
//         vector<int> level(size);
        
//         for (int i = 0; i < size; i++) {
//             Node* node = q.front();
//             q.pop();
            
//             int index = leftToRight ? i : (size - 1 - i);
//             level[index] = node->data;
            
//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//         ans.push_back(level);
//         leftToRight = !leftToRight;
//     }
//     return ans;
// }

// // 13. Check if Binary Tree is Symmetric (Mirror of itself)
// bool isSymmetricHelper(Node* left, Node* right) {
//     if (!left && !right) return true;
//     if (!left || !right) return false;
//     return (left->data == right->data) &&
//            isSymmetricHelper(left->left, right->right) &&
//            isSymmetricHelper(left->right, right->left);
// }
// bool isSymmetric(Node* root) {
//     return !root || isSymmetricHelper(root->left, root->right);
// }

// // 14. Root to Node Path
// bool rootToNodePath(Node* root, vector<int>& result, int target) {
//     if (!root) return false;
    
//     result.push_back(root->data);
    
//     if (root->data == target) return true;
    
//     if (rootToNodePath(root->left, result, target) ||
//         rootToNodePath(root->right, result, target)) {
//         return true;
//     }
    
//     result.pop_back();
//     return false;
// }

// int main() {
//     // Example tree construction
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
    
//     cout << "Preorder: ";
//     preorder(root);
//     cout << endl;
    
//     cout << "Level Order:\n";
//     levelorder(root);
    
//     cout << "Max Depth: " << maxDepth(root) << endl;
//     cout << "Is Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;
    
//     return 0;
// }