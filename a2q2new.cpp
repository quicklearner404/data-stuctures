//#include <iostream>
//#include<vector>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
//};
//
//class BST {
//private:
//    TreeNode* root;
//    int size;
//
//   
//    TreeNode* insert(TreeNode* node, int val) {
//        if (!node) return new TreeNode(val);
//        if (val < node->val) node->left = insert(node->left, val);
//        else if (val > node->val) node->right = insert(node->right, val);
//        return node;
//    }
//
//    TreeNode* deleteNode(TreeNode* node, int val) {
//        if (!node) return nullptr;
//
//        if (val < node->val) {
//            node->left = deleteNode(node->left, val);
//        }
//        else if (val > node->val) {
//            node->right = deleteNode(node->right, val);
//        }
//        else {
//            // Case: Leaf node
//            if (!node->left && !node->right) {
//                delete node;
//                return nullptr;
//            }
//            // Case: One child
//            if (!node->left) {//only ri8
//                TreeNode* temp = node->right;
//                delete node;
//                return temp;
//            }
//            else if (!node->right) {//only left
//                TreeNode* temp = node->left;
//                delete node;
//                return temp;
//            }
//            // Case: Two children
//            TreeNode* minNode = findMin(node->right);
//            node->val = minNode->val;
//            node->right = deleteNode(node->right, minNode->val);
//        }
//        return node;
//    }
//
//    // Helper for inorders successor
//    TreeNode* findMin(TreeNode* node) {
//        while (node && node->left) node = node->left;
//        return node;
//    }
//
//    //kth smallest to help with median
//    bool findKthSmallest(TreeNode* node, int& k, int& result) {
//        if (!node) return false;
//        if (findKthSmallest(node->left, k, result)) return true;
//        if (--k == 0) {
//            result = node->val;
//            return true;
//        }
//        return findKthSmallest(node->right, k, result);
//    }
//
//    // Helper for in-order traversal
//    void inorder(TreeNode* node) {
//        if (!node) return;
//        inorder(node->left);
//        cout << node->val << " ";
//        inorder(node->right);
//    }
//    void inorder(TreeNode* node, vector<int>& values) {
//        if (!node) return;
//        inorder(node->left, values);
//        values.push_back(node->val);
//        inorder(node->right, values);
//    }
//
//    // Helper to merge two sorted vectors
//    vector<int> mergeVectors(const vector<int>& v1, const vector<int>& v2) {
//        vector<int> merged;
//        int i = 0, j = 0;
//        while (i < v1.size() && j < v2.size()) {
//            if (v1[i] < v2[j]) merged.push_back(v1[i++]);
//            else merged.push_back(v2[j++]);
//        }
//        while (i < v1.size()) merged.push_back(v1[i++]);
//        while (j < v2.size()) merged.push_back(v2[j++]);
//        return merged;
//    }
//
//public:
//    BST() : root(nullptr), size(0) {}
//
//    void insert(int val) {
//        root = insert(root, val);
//        size++;
//    }
//
//    void deleteNode(int val) {
//        if (search(val)) {
//            root = deleteNode(root, val);
//            size--;
//        }
//        else {
//            cout << "Value " << val << " not found in the tree." << endl;
//        }
//    }
//
//    bool search(int val) {
//        TreeNode* current = root;
//        while (current) {
//            if (current->val == val) return true;
//            current = (val < current->val) ? current->left : current->right;
//        }
//        return false;
//    }
//
//    float find_median() {
//        if (size == 0) {
//            cout << "Tree is empty." << endl;
//            return 0;
//        }
//        int mid1, mid2 = 0;
//        if (size % 2 == 1) {  // Odd number of nodes
//             mid1 =  mid2= (size + 1) / 2 ;
//        }
//        else {  // Even number of nodes
//             mid1 = (size + 1) / 2, mid2 = (size + 2) / 2;
//           // int mid1 = (size + 1) / 2, mid2 = (size + 2) / 2;
//        }
//
//       
//        int val1, val2;
//        findKthSmallest(root, mid1, val1);
//        findKthSmallest(root, mid2, val2);
//        return (val1 + val2) / 2.0;
//    }
//
//    int getSize() const { return size; }
//
//   
//    void printInOrder() {
//        inorder(root);
//        cout << endl;
//    }
//    // Merge two BSTs and return the merged tree
//    BST mergeWith(BST& other) {
//        vector<int> values1, values2;
//
//        // Get in-order values of both trees
//        inorder(this->root, values1);
//        inorder(other.root, values2);
//
//        // Merge the two sorted lists of values
//        vector<int> mergedValues = mergeVectors(values1, values2);
//
//        // Insert merged values into a new BST
//        BST mergedTree;
//        for (int val : mergedValues) {
//            mergedTree.insert(val);
//        }
//
//        return mergedTree;
//    }
//
//};
//
//int main() {
//    BST tree1, tree2;
//
//    //fill tree 1
//    tree1.insert(10);
//    tree1.insert(5);
//    tree1.insert(15);
//    tree1.insert(3);
//    tree1.insert(7);
//    tree1.insert(6);
//
//    // tree2
//    tree2.insert(6);
//    tree2.insert(20);
//    tree2.insert(4);
//
//    
//    cout << "Original in-order traversal of tree1: ";
//    tree1.printInOrder();
//
//    
//    cout << "Original in-order traversal of tree2: ";
//    tree2.printInOrder();
//
//   //deletion
//    cout << "Deleting node with value 65 from tree1" << endl;
//    tree1.deleteNode(65);
//    cout << "In-order traversal of tree1 after deletion: ";
//    tree1.printInOrder();
//
//   //size and median of tree1
//    cout << "Size of tree1: " << tree1.getSize() << endl;
//    cout << "Median of tree1: " << tree1.find_median() << endl;
//    //merging tree1 n 2
//    BST mergedTree = tree1.mergeWith(tree2);
//    cout << "In-order traversal of merged tree: ";
//    mergedTree.printInOrder();
//
//    return 0;
//}
