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
            node->_insert(node->right, key, value);
        }
        return node;
    }

};

int main() {
    BST<std::string,int> t;
    return 0;
}

