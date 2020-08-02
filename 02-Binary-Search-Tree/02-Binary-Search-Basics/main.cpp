#include <iostream>
#include <string>
#include <queue>

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
        _destroy(_root);
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

    void pre_order() const {
        _pre_order(_root);
    }

    void in_order() const {
        _in_order(_root);
    }

    void post_order() const {
        _post_order(_root);
    }

    void level_order() const {
        std::queue<Node*> queue;
        queue.push(_root);
        while (!queue.empty()) {
            Node* node = queue.front();
            queue.pop();
            std::cout << node->key << std::endl;
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
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

    void _pre_order(Node* node) const {
        if (node != nullptr) {
            std::cout << node->key << std::endl;
            _pre_order(node->left);
            _pre_order(node->right);
        }
    }

    void _in_order(Node* node) const {
        if (node != nullptr) {
            _in_order(node->left);
            std::cout << node->key << std::endl;
            _in_order(node->right);
        }
    }

    void _post_order(Node* node) const {
        if (node != nullptr) {
            _post_order(node->left);
            _post_order(node->right);
            std::cout << node->key << std::endl;
        }
    }

    void _destroy(Node* &node) {
        if (node != nullptr) {
            _destroy(node->left);
            _destroy(node->right);
            delete node; node = nullptr;
            _count--;
        }
    }
};

int main() {
    BST<int,int> bst;
    bst.insert(28, 1);
    bst.insert(16, 1);
    bst.insert(30, 1);
    bst.insert(13, 1);
    bst.insert(22, 1);
    bst.insert(29, 1);
    bst.insert(42, 1);

    std::cout <<  "preorder" << std::endl;
    bst.pre_order();
    std::cout <<  "inorder" << std::endl;
    bst.in_order();
    std::cout <<  "postorder" << std::endl;
    bst.post_order();
    std::cout <<  "levelorder" << std::endl;
    bst.level_order();
    return 0;
}

