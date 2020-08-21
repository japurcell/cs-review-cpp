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

    ~tree()
    {
        delete left;
        delete right;
    }
};

template <class T>
const tree<T> * const insert(tree<T> * const tree, const T& t)
{
    if (tree == NULL || t == tree->item) return tree;

    auto target = t < tree->item ? &tree->left : &tree->right;

    if (*target == NULL)
    {
        *target = new ::tree<T>();
        (*target)->item = t;
        (*target)->parent = tree;
        return tree;
    }
    else return insert(*target, t);
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