//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//class BST {
//private:
//    Node* root;
//
//    Node* insert(Node* node, int num) {
//        if (node == nullptr) {
//            return new Node(num);
//        }
//        if (num < node->data) {
//            node->left = insert(node->left, num);
//        }
//        else if (num > node->data) {
//            node->right = insert(node->right, num);
//        }
//        return node;
//    }
//
//    // Recursive function for inorder traversal (LVR)
//    void inorderPrint(Node* node) const {
//        if (node == nullptr) return;
//        inorderPrint(node->left);
//        cout << node->data << " ";
//        inorderPrint(node->right);
//    }
//
//    // Recursive function to search for a node by key
//    Node* search(Node* node, int key) const {
//        if (node == nullptr || node->data == key) {
//            return node;
//        }
//        if (key < node->data) {
//            return search(node->left, key);
//        }
//        else {
//            return search(node->right, key);
//        }
//    }
//
//    // Recursive function to count the total nodes in the BST
//    int countNodes(Node* node) const {
//        if (node == nullptr) return 0;
//        return 1 + countNodes(node->left) + countNodes(node->right);
//    }
//
//    // Recursive function to count the leaf nodes (nodes with no children)
//    int leafCount(Node* node) const {
//        if (node == nullptr) return 0;
//        if (node->left == nullptr && node->right == nullptr) return 1;
//        return leafCount(node->left) + leafCount(node->right);
//    }
//
//    // Recursive function to destroy all nodes (Post-order LRV traversal)
//    void destroy(Node* node) {
//        if (node != nullptr) {
//            destroy(node->left);
//            destroy(node->right);
//            delete node;
//        }
//    }
//
//    // Recursive function to deep copy the tree
//    Node* copy(Node* node) {
//        if (node == nullptr) return nullptr;
//        Node* newNode = new Node(node->data);
//        newNode->left = copy(node->left);
//        newNode->right = copy(node->right);
//        return newNode;
//    }
//
//    // Recursive function to print level by level
//    void printLevel(Node* node, int level) const {
//        if (node == nullptr) return;
//        if (level == 1) {
//            cout << node->data << " ";
//        }
//        else {
//            printLevel(node->left, level - 1);
//            printLevel(node->right, level - 1);
//        }
//    }
//
//    // Helper function to calculate the height of the tree
//    int height(Node* node) const {
//        if (node == nullptr) return 0;
//        return 1 + max(height(node->left), height(node->right));
//    }
//
//public:
//    // Constructor to initialize the root
//    BST() : root(nullptr) {}
//
//    // Copy constructor
//    BST(const BST& other) : root(nullptr) {
//        root = copy(other.root);
//    }
//
//    // Destructor to free memory
//    ~BST() {
//        destroy(root);
//    }
//
//    // Insert function
//    bool insert(int v) {
//        if (search(v) != nullptr) return false; // Don't insert duplicates
//        root = insert(root, v);
//        return true;
//    }
//
//    // Inorder print (LVR)
//    void inorderPrint() const {
//        inorderPrint(root);
//        cout << endl;
//    }
//
//    // Level-order print using recursion
//    void levelOrderPrint() const {
//        int h = height(root);
//        for (int i = 1; i <= h; i++) {
//            printLevel(root, i);
//        }
//        cout << endl;
//    }
//
//    // Search function
//    Node* search(int key) const {
//        return search(root, key);
//    }
//
//    // Function to count total nodes
//    int countNodes() const {
//        return countNodes(root);
//    }
//
//    // Function to count leaf nodes
//    int leafCount() const {
//        return leafCount(root);
//    }
//};
//
//int main() {
//    BST tree;
//    tree.insert(10);
//    tree.insert(5);
//    tree.insert(15);
//    tree.insert(3);
//    tree.insert(7);
//    tree.insert(20);
//
//    cout << "In-order traversal: ";
//    tree.inorderPrint();
//
//    cout << "Level-order traversal: ";
//    tree.levelOrderPrint();
//
//    cout << "Total nodes: " << tree.countNodes() << endl;
//    cout << "Leaf nodes: " << tree.leafCount() << endl;
//
//    Node* searchNode = tree.search(7);
//    if (searchNode) {
//        cout << "Node 7 found!" << endl;
//    }
//    else {
//        cout << "Node 7 not found!" << endl;
//    }
//
//    return 0;
//}
