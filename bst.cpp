#include <iostream>
#include <limits.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int num) {
        if (node == nullptr) {
            return new Node(num);
        }
        if (num < node->data) {
            node->left = insert(node->left, num);
        }
        else if (num > node->data) {
            node->right = insert(node->right, num);
        }
        return node;
    }

    void inorderPrint(Node* node) const {
        if (node == nullptr) return;
        inorderPrint(node->left);
        cout << node->data << " ";
        inorderPrint(node->right);
    }

    Node* search(Node* node, int key) const {
        if (node == nullptr || node->data == key) {
            return node;
        }
        if (key < node->data) {
            return search(node->left, key);
        }
        else {
            return search(node->right, key);
        }
    }

    int countNodes(Node* node) const {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    Node* copy(Node* node) {
        if (node == nullptr) return nullptr;
        Node* newNode = new Node(node->data);
        newNode->left = copy(node->left);
        newNode->right = copy(node->right);
        return newNode;
    }

    void printLevel(Node* node, int level) const {
        if (node == nullptr) return;
        if (level == 1) {
            cout << node->data << " ";
        }
        else {
            printLevel(node->left, level - 1);
            printLevel(node->right, level - 1);
        }
    }

    bool isValidBST(Node* node, int min, int max) const {
        if (node == nullptr) return true;
        if (node->data <= min || node->data >= max) return false;
        return isValidBST(node->left, min, node->data) &&
            isValidBST(node->right, node->data, max);
    }

public:
    BST() : root(nullptr) {}

    BST(const BST& other) : root(nullptr) {
        root = copy(other.root);
    }

    ~BST() {
        destroy(root);
    }

    Node* getroot() {
        return root;
    }

    Node* findmin(Node* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }

    bool insert(int v) {
        if (search(v) != nullptr) return false; // Don't insert duplicates
        root = insert(root, v);
        return true;
    }

    void inorderPrint() const {
        inorderPrint(root);
        cout << endl;
    }

    int height(Node* node) const {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    void levelOrderPrint() const {
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            printLevel(root, i);
        }
        cout << endl;
    }

    Node* inordersuccessor(Node* inp) {
        Node* res = findmin(inp->right);
        cout << endl << "The inorder successor is: " << res->data << endl;
        return res;
    }

    Node* findmax(Node* inp) {
        while (inp && inp->right)
            inp = inp->right;
        return inp;
    }

    Node* inorderpredecessor(Node* inp) {
        Node* res = findmax(inp->left);
        cout << endl << "The inorder predecessor is: " << res->data << endl;
        return res;
    }

    Node* findlca(Node* root, int n1, int n2) {
        if (!root) return NULL;
        if (n1 < root->data && n2 < root->data)
            return findlca(root->left, n1, n2);
        if (n1 > root->data && n2 > root->data)
            return findlca(root->right, n1, n2);
        return root;
    }

    void ksmallest(Node* root, int& k, int& res) {
        if (root == NULL) return;
        ksmallest(root->left, k, res);
        k--;
        if (k == 0) {
            res = root->data;
            return;
        }
        ksmallest(root->right, k, res);
    }

    Node* search(int key) const {
        return search(root, key);
    }

    int countNodes() const {
        return countNodes(root);
    }

    bool isValidBST() const {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    int getcount(Node* root, int l, int h) {
        if (!root) return 0;
        else if (root->data <= h && root->data >= l)
            return 1 + getcount(root->left, l, h) + getcount(root->right, l, h);
        else if (root->data < l) {
            return getcount(root->left, l, h);
        }
        else if (root->data > h) {
            return getcount(root->right, l, h);
        }
        else {
            return 0;
        }
    }
};

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(20);

    cout << "In-order traversal: ";
    tree.inorderPrint();

    tree.inordersuccessor(tree.getroot());
    tree.inorderpredecessor(tree.getroot());

    int k = 2;
    int s = 0;
    tree.ksmallest(tree.getroot(), k, s);
    cout << "The k-th smallest value is: " << s << endl;

    Node* res = tree.findlca(tree.getroot(), 5, 20);
    cout << "The LCA is: " << res->data << endl;

    cout << "The height of the tree is: " << tree.height(tree.getroot()) << endl;

    cout << "Total count of nodes: " << tree.countNodes() << endl;

    cout << "Total count of nodes in range: " << tree.getcount(tree.getroot(), 5, 20) << endl;

    if (tree.isValidBST()) {
        cout << "The tree is a valid BST." << endl;
    }
    else {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
