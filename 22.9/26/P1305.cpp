#include <iostream>
using namespace std;
struct node
{
    char c;
    node* left = NULL;
    node* right = NULL;
};

void add_left(node* p, char x)
{
    p->left = new node;
    p->left->c = x;
}

void add_right(node* p, char x)
{
    p->right = new node;
    p->right->c = x;
}

node* find(char target, node* root)
{
    if (root->c == target) return root;
    if (root->left)  return find(target, root->left);
    if (root->right) return find(target, root->right);
}

void __find(char target, node* vis, node*& f)
{
    if (target == vis->c)   { f = vis;return;               }
    if (vis->left )         { __find(target, vis->left,f);  }
    if (vis->right)         { __find(target, vis->right,f); }
}

void print(node* root)
{
    cout << root->c;
    if (root->left) print(root->left);
    if (root->right) print(root->right);
}
int main() {
    int a;
    cin >> a;
    node* root = new node;
    string s;
    cin >> s;
    root->c = s[0];
    if (s[1] != '*') add_left(root, s[1]);
    if (s[2] != '*') add_right(root, s[2]);
    for (int i = 0;i < a - 1;i++)
    {
        cin >> s;

        node* find = nullptr;
        __find(s[0], root, find);
        //cout << find->c << " ";

        if (s[1] != '*') add_left(find, s[1]);
        if (s[2] != '*') add_right(find, s[2]);
    }
    print(root);

    return 0;
}


/*
6
abc
bdi
cj*
d**
i**
j**



 */
