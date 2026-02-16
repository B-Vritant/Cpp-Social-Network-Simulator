#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <cctype>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

string lowercase(string username)
{
    for (int i = 0; i < username.size(); i++)
    {
        username[i] = tolower(username[i]);
    }
    return username;
}

class Node
{
public:
    string username;
    time_t timestamp;
    string content;
    Node *left;
    Node *right;
    int height;
    Node(string usernm, time_t ts, string c)
    {
        username = usernm;
        timestamp = ts;
        content = c;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLtree
{
public:
    Node *root;
    void delete_tree(Node *root)
    {
        if (root != nullptr)
        {
            delete_tree(root->left);
            delete_tree(root->right);
            delete root;
        }
    }
    AVLtree() { root = nullptr; }
    ~AVLtree() { delete_tree(root); }

    int get_height(Node *n)
    {
        if (n == nullptr)
            return 0;
        return n->height;
    }

    void update_height(Node *n)
    {
        if (n == nullptr)
            return;
        n->height = 1 + max(get_height(n->left), get_height(n->right));
    }

    int balance(Node *n)
    {
        if (n == nullptr)
            return 0;
        return get_height(n->left) - get_height(n->right);
    }

    void print_inorder(vector<string> &v, Node *root)
    {
        if (root == nullptr)
            return;
        print_inorder(v, root->left);
        bool exists = false;
        for (auto name : v)
        {
            if (name == root->username)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
            v.push_back(root->username);
        print_inorder(v, root->right);
    }

    Node *rotate_Right(Node *root)
    {
        if (!root || !(root->left))
            return root;
        Node *child = root->left;
        Node *rightchild = child->right;
        child->right = root;
        root->left = rightchild;
        update_height(root);
        update_height(child);
        return child;
    }

    Node *rotate_Left(Node *root)
    {
        if (!root || !(root->right))
            return root;
        Node *child = root->right;
        Node *leftchild = child->left;
        child->left = root;
        root->right = leftchild;
        update_height(root);
        update_height(child);
        return child;
    }

    Node *add_Friend_Helper(Node *root, string username)
    {
        if (!root)
            return new Node(username, 0, "");
        if (username < root->username)
            root->left = add_Friend_Helper(root->left, username);
        else if (username > root->username)
            root->right = add_Friend_Helper(root->right, username);
        else
            return root;

        update_height(root);
        int bal = balance(root);

        if (bal > 1 && username < root->left->username)
            return rotate_Right(root);
        if (bal < -1 && username > root->right->username)
            return rotate_Left(root);
        if (bal > 1 && username > root->left->username)
        {
            root->left = rotate_Left(root->left);
            return rotate_Right(root);
        }
        if (bal < -1 && username < root->right->username)
        {
            root->right = rotate_Right(root->right);
            return rotate_Left(root);
        }
        return root;
    }

    Node *helper_add(Node *root, string usernm, string content, time_t nowtime)
    {
        if (root == nullptr)
        {
            return new Node(usernm, nowtime, content);
        }
        if (root->timestamp > nowtime)
        {
            root->left = helper_add(root->left, usernm, content, nowtime);
        }
        else if (root->timestamp < nowtime)
        {
            root->right = helper_add(root->right, usernm, content, nowtime);
        }
        else
        {
            if (usernm < root->username)
                root->left = helper_add(root->left, usernm, content, nowtime);
            else if (usernm > root->username)
                root->right = helper_add(root->right, usernm, content, nowtime);
            else
                return root;
        }
        update_height(root);
        int bal = balance(root);
        if (bal > 1 && nowtime < root->left->timestamp)
            return rotate_Right(root);
        if (bal < -1 && nowtime > root->right->timestamp)
            return rotate_Left(root);
        if (bal > 1 && nowtime > root->left->timestamp)
        {
            root->left = rotate_Left(root->left);
            return rotate_Right(root);
        }
        if (bal < -1 && nowtime < root->right->timestamp)
        {
            root->right = rotate_Right(root->right);
            return rotate_Left(root);
        }
        return root;
    }

    void add(string username, string content)
    {
        root = helper_add(root, username, content, time(0));
    }

    Node *get_root() { return root; }
};

// Todo: Graph class coming in next commit
int main()
{
    cout << "AVL Tree implementation ready. More features coming soon..." << endl;
    return 0;
}