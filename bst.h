#include <iostream>

using namespace std;

/*
    Rooted binary tree
    Definitions
      - Empty
      - Root node with left and right subtrees
        - single key (x)
        - all nodes in left subtree have keys < x
        - all nodes in right subtree have keys > x

    TODO
        - delete
        - find min
        - find max
        - successor
*/

template <class T>
struct tree
{
    T item;
    tree *parent;
    tree *left;
    tree *right;

    tree() { }
    tree(const T& item) : item(item), parent(NULL), left(NULL), right(NULL) { }
    tree(const tree<T>& other) = delete;
};

template <class T>
tree<T> * remove_item(tree<T> * tree, const T& t)
{
    if (tree == NULL) return tree;

    if (t < tree->item)
    {
        tree->left = remove_item(tree->left, t);
    }
    else if (t > tree->item)
    {
        tree->right = remove_item(tree->right, t);
    }
    else
    {
        if (tree->left == NULL)
        {
            auto temp = tree->right;
            delete tree;
            return temp;
        }
        else if(tree->right == NULL)
        {
            auto temp = tree->left;
            delete tree;
            return temp;
        }

        auto temp = minimum(tree->right);
        tree->item = temp->item;
        tree->right = remove_item(tree->right, temp->item);
    }

    return tree;
}

template <class T>
const tree<T> * const insert(tree<T> ** tree, const T& t, ::tree<T> * const parent = NULL)
{
    ::tree<T> *temp;

    if (*tree == NULL)
    {
        temp = new ::tree<T>();
        temp->item = t;
        temp->parent = parent;
        *tree = temp;
        return *tree;
    }
    else if (t < (*tree)->item) insert(&((*tree)->left), t, *tree);
    else insert(&((*tree)->right), t, *tree);

    return *tree;
}

template <class T>
const tree<T> * const minimum(const tree<T> * const tree)
{
    if (tree == NULL) return tree;

    auto temp = &tree;
    while ((*temp)->left != NULL)
    {
        temp = &(*temp)->left;
    }

    return *temp;
}

template <class T>
const tree<T> * const maximum(const tree<T> * const tree)
{
    if (tree == NULL) return tree;

    auto temp = &tree;
    while ((*temp)->right != NULL)
    {
        temp = &(*temp)->right;
    }

    return *temp;
}

template <class T>
void print(const tree<T>& tree, const int& level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "-";
    }

    cout << " " << tree.item << endl;
}

template <class T>
const tree<T> * const search_tree(const tree<T> * const tree, const T& t)
{
    if (tree == NULL) return tree;

    if (tree->item == t) return tree;

    auto target = t < tree->item ? &tree->left : &tree->right;

    return search_tree(*target, t);
}

template <class T, typename VisitFn>
const tree<T> * const traverse(const tree<T> * const tree, VisitFn&& visit, const int& level = 0)
{
    if (tree == NULL) return tree;

    int next_level = level + 1;
    traverse(tree->left, visit, next_level);
    visit(*tree, level);
    traverse(tree->right, visit, next_level);

    return tree;
}