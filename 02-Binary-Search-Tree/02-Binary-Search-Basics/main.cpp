#include <iostream>
#include <string>

template <typename Key, typename Value>
class BST {
public:
    BST() {
        root = nullptr;
        count = 0;
    }
    ~BST() {
    }

    int size() const {
        return count;
    }

    bool empty() {
        return count == 0;
    }

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

    Node* root;
    int count;
};

int main() {
    BST<std::string,int> t;
    return 0;
}

