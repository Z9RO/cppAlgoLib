#include<memory>

template<typename K, typename V>
class searchTree{
private:
    struct Node
    {
        K key;
        V value;
        int n;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        Node(K k, V val): key(k), value(val), n(1), left(nullptr), right(nullptr){};
    };
    std::shared_ptr<Node> _root;
    V get(K k, std::shared_ptr<Node> root);
    int put(K k, V val, std::shared_ptr<Node> root);
    V getMin(std::shared_ptr<Node> root);
    V getMax(std::shared_ptr<Node> root);
public:
    searchTree(): _root(nullptr){};
    V getMin(){
        if(_root!=nullptr){
            return getMin(_root);
        }else{
            return 0;
        }
    }
    V getMax(){
        if(_root!=nullptr){
            return getMax(_root);
        }else{
            return 0;
        }
    }
    int getSize(){ return _root->n ; };
    V get(K k){
        if(_root!=nullptr){
            return get(k, _root);
        }else{
            return 0;
        }
    }
    void put(K k, V val){
        if(_root!=nullptr){
            put(k, val, _root);
        }else{
            _root = std::make_shared<Node>(k, val);
        }
    }
};

template<typename K, typename V>
V searchTree<K, V>::get(K k, std::shared_ptr<searchTree::Node> root){
    if(root->key == k){
        return root->value;
    }else if(root->key < k){
        return root->right != nullptr ? get(k, root->right) : -1;
    }else{
        return root->left != nullptr ? get(k, root->left) : -1 ;
    }
}

template<typename K, typename V>
int searchTree<K, V>::put(K k, V val, std::shared_ptr<searchTree::Node> root){
    if(root->key == k){
        root->value = val;
        return 0;
    }else if(root->key < k){
        if(root->right != nullptr){
            int count = put(k, val, root->right);
            root->n += count;
            return count;
        }else{
            root->right = std::make_shared<Node>(k, val);
            root->n ++;
            return 1;
        }
    }else{
        if(root->left != nullptr){
            int count = put(k, val, root->left);
            root->n += count;
            return count;
        }else{
            root->left = std::make_shared<Node>(k, val);
            root->n ++;
            return 1;
        }
    }
}

template<typename K, typename V>
V searchTree<K, V>::getMin(std::shared_ptr<searchTree::Node> root){
    return root->left != nullptr ? getMin(root->left) : root->value ;
}

template<typename K, typename V>
V searchTree<K, V>::getMax(std::shared_ptr<searchTree::Node> root){
    return root->right != nullptr ? getMax(root->right) : root->value ;
}