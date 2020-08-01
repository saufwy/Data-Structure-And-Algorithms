#include <iostream>
#include <string>

template <typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = nullptr;
        }
    };

    Node* _root;
    int _count;

public:
    BST() {
        _root = nullptr;
        _count = 0;
    }
    ~BST() {
    }

    int size() const {
        return _count;
    }

    bool empty() {
        return _count == 0;
    }

    void insert(Key key, Value value) {
        _root = _insert(_root, key, value);
    }

    bool contain(Key key) const {
        return _contain(_root, key);
    }

    Value* search(Key key) {
        return _search(_root, key);
    }

protected:
    Node* _insert(Node* node, Key key, Value value) {
        if (node == nullptr) {
            return new Node(key, value);
        }
        if (node->key == key) {
            node->value = value;
        } else if (node->key > key) {
            node->left = _insert(node->left, key, value);
        } else {
            node->right = _insert(node->right, key, value);
        }
        return node;
    }

    bool _contain(Node* node, Key key) const {
        if (node == nullptr) {
            return false;
        }

        if (node->key == key) {
            return true;
        } else if (node->key < key) {
            return _contain(node->right, key);
        } else { // node->key > key
            return _contain(node->left, key);
        }
    }

    Value* _search(Node* node, Key key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->key == key) {
            return &node->value;
        } else if (node->key < key) {
            return _search(node->right, key);
        } else {
            return _search(node->left, key);
        }
    }

};

int main() {
    BST<std::string,int> bst;
    bst.insert("1", 100);
    bst.insert("2", 101);
    bst.insert("3", 102);
    bst.insert("4", 103);
    bst.insert("5", 104);
    if (bst.contain("1")) {
        std::cout << *bst.search("5") << std::endl;
    }
    return 0;
}

