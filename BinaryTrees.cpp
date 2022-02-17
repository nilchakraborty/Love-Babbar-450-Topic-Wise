/*// level order traversal
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root == NULL) return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()) {
//             int size = q.size();
//             vector<int> level;
//             for(int i = 0;i<size;i++) {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 if(node->left != NULL) q.push(node->left);
//                 if(node->right != NULL) q.push(node->right);
//                 level.push_back(node->val);
//             }
//             ans.push_back(level);
//         }
//         return ans;
//     }
// };
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
void printCurrentLevel(node *root, int level);
int height(node *node);
node *newNode(int data);

void printLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}*/
/*// Reverse Level Order traversal
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
void printCurrentLevel(node *root, int level);
int height(node *node);
node *newNode(int data);

void reverseLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = h; i >= 1; i--)
        printCurrentLevel(root, i);
}
void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Level Order traversal of binary tree is \n";
    reverseLevelOrder(root);
    return 0;
}*/
/*// Vertical order traversal
#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector < vector < int >> findVertical(node * root) {
  map < int, map < int, multiset < int >>> nodes;
  queue < pair < node * , pair < int, int >>> todo;
  todo.push({root,{0, 0}});
  //initial vertical and level
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    node * temp = p.first;

    //x -> vertical , y->level
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(temp -> data); //inserting to multiset

    if (temp -> left) {
      todo.push({temp -> left,{x - 1,y + 1}});
    }
    if (temp -> right) {
      todo.push({temp -> right,{x + 1,y + 1}});
      }
  }
  vector < vector < int >> ans;
  for (auto p: nodes) {
    vector < int > col;
    for (auto q: p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(10);
  root -> left -> left -> right = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(3);
  root -> right -> left = newNode(9);
  root -> right -> right = newNode(10);

  vector < vector < int > > verticalTraversal;
  verticalTraversal = findVertical(root);

  cout << "The Vertical Traversal is : " << endl;
  for (auto vertical: verticalTraversal) {
    for (auto nodeVal: vertical) {
      cout << nodeVal << " ";
    }
    cout << endl;
  }
  return 0;
}*/
/*// Height of a tree
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
};
int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}
int main()
{
    node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Height of tree is " << maxDepth(root)-1;
    return 0;
}*/
/*// Diameter of a tree
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int data);
int max(int a, int b) { return (a > b) ? a : b; }
int height(struct node *node);
int diameter(struct node *tree)
{
    if (tree == NULL)
        return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
int height(struct node *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Diameter of the given binary tree is " << diameter(root);

    return 0;
}*/
/*// Mirror of a tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)
        malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
void mirror(struct Node *node)
{
    if (node == NULL)
        return;
    else
    {
        struct Node *temp;
        mirror(node->left);
        mirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
void inOrder(struct Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Inorder traversal of the constructed"
         << " tree is" << endl;
    inOrder(root);
    mirror(root);
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    inOrder(root);

    return 0;
}*/
/*// Inorder Traversal of a tree both using recursion and Iteration
// Preorder Traversal of a tree both using recursion and Iteration
// Postorder Traversal of a tree both using recursion and Iteration
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void printPreorder(struct Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}*/
/*// Left View of a tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(
        sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void leftViewUtil(struct Node *root,
                  int level, int *max_level)
{
    if (root == NULL)
        return;
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}
void leftView(struct Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}
int main()
{
    Node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);

    leftView(root);

    return 0;
}*/
/*// Right View of Tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(
        sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void rightViewUtil(struct Node *root,
                   int level, int *max_level)
{
    if (root == NULL)
        return;
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
int main()
{
    Node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);

    rightView(root);

    return 0;
}*/
/*// Top View of a tree
// class Solution
// {
//     public:
//     vector<int> topView(Node *root)
//     {
//         vector<int> ans;
//         if(root == NULL) return ans;
//         map<int,int> mpp;
//         queue<pair<Node*, int>> q;
//         q.push({root, 0});
//         while(!q.empty()) {
//             auto it = q.front();
//             q.pop();
//             Node* node = it.first;
//             int line = it.second;
//             if(mpp.find(line) == mpp.end()) mpp[line] = node->data;

//             if(node->left != NULL) {
//                 q.push({node->left, line-1});
//             }
//             if(node->right != NULL) {
//                 q.push({node->right, line + 1});
//             }

//         }

//         for(auto it : mpp) {
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int key)
{
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}
void fillMap(Node *root, int d, int l, map<int, pair<int, int>> &m)
{
    if (root == NULL)
        return;
    if (m.count(d) == 0)
    {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > 1)
    {
        m[d] = make_pair(root->data, l);
    }
    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}
void topView(struct Node *root)
{
    map<int, pair<int, int>> m;
    fillMap(root, 0, 0, m);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second.first << " ";
    }
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topView(root);
    return 0;
}*/
/*// Bottom View of a tree
// class Solution {
//   public:
//     vector <int> bottomView(Node *root) {
//         vector<int> ans;
//         if(root == NULL) return ans;
//         map<int,int> mpp;
//         queue<pair<Node*, int>> q;
//         q.push({root, 0});
//         while(!q.empty()) {
//             auto it = q.front();
//             q.pop();
//             Node* node = it.first;
//             int line = it.second;
//             mpp[line] = node->data;

//             if(node->left != NULL) {
//                 q.push({node->left, line-1});
//             }
//             if(node->right != NULL) {
//                 q.push({node->right, line + 1});
//             }

//         }

//         for(auto it : mpp) {
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };
#include <bits/stdc++.h>
#include <map>
using namespace std;
struct Node
{
    int data;
    int hd;
    Node * left, * right;
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};

void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
    if (root == NULL)
        return;
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root -> data, curr);
    }
    else
    {
        pair < int, int > p = m[hd];
        if (p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root -> data;
        }
    }
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m);
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}

void printBottomView(Node * root)
{
    map < int, pair < int, int > > m;

    printBottomViewUtil(root, 0, 0, m);
    map < int, pair < int, int > > ::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}

int main()
{
    Node * root = new Node(20);
    root -> left = new Node(8);
    root -> right = new Node(22);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(25);
    root -> left -> right -> left = new Node(10);
    root -> left -> right -> right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    printBottomView(root);
    return 0;
}*/
/*// Zig-Zag traversal of a binary tree
#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
void zizagtraversal(struct Node *root)
{
    if (!root)
        return;
    stack<struct Node *> currentlevel;
    stack<struct Node *> nextlevel;
    currentlevel.push(root);
    bool lefttoright = true;
    while (!currentlevel.empty())
    {
        struct Node *temp = currentlevel.top();
        currentlevel.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (lefttoright)
            {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty())
        {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}
struct Node *newNode(int data)
{
    struct Node *node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int main()
{
    // create tree
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";

    zizagtraversal(root);

    return 0;
}*/
/*// Check if a tree is balanced or not
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
int height(node *node);
bool isBalanced(node *root)
{
    int lh, rh;
    if (!root)
        return 1;
    lh = height(root->left);
    rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) &&
        isBalanced(root->right))
        return 1;
    return 0;
}
int max(int a, int b)
{
    return(a >= b) ? a : b;
}
int height(node *node)
{
    if (!node)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}*/
/*// Diagnol Traversal of a Binary tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void diagonalPrint(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp)
        {
            if (q.empty())
                return;
            cout << endl;
            q.push(NULL);
        }
        else
        {
            while (temp)
            {
                cout << temp->data << " ";
                if (temp->left)
                    q.push(temp->left);
                temp = temp->right;
            }
        }
    }
}
int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalPrint(root);
}*/
/*// Boundary traversal of a Binary tree
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
//function to print leaf nodes
void printLeaves(struct node *root)
{
    if (!root)
        return;
    printLeaves(root->left);
    if (!(root->left) && !(root->right))
        cout << root->data << " ";
    printLeaves(root->right);
}
void printBoundaryLeft(struct node *root)
{
    if (!root)
        return;
    if (root->left)
    {
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
}
void printBoundaryRight(struct node *root)
{
    if (!root)
        return;
    if (root->right)
    {
        printBoundaryLeft(root->right);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        printBoundaryLeft(root->left);
        cout << root->data << " ";
    }
}
void printBoundary(struct node *root)
{
    if (!root)
        return;
    cout << root->data;
    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
}
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printBoundary(root);

    return 0;
}*/
/*// Construct Binary Tree from String with Bracket Representation
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int element)
    {
        data = element;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
Node *constructTree(string s)
{
    Node *root = new Node(s[0] - '0');
    stack<Node *> stk;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(root);
        }
        else if (s[i] == ')')
        {
            root = stk.top();
            stk.pop();
        }
        else
        {
            if (root->left == NULL)
            {
                Node *left = new Node(s[i] - '0');
                root->left = left;
                root = root->left;
            }
            else if (root->right == NULL)
            {
                Node *right = new Node(s[i] - '0');
                root->right = right;
            }
        }
    }
    return root;
}
int main()
{
    string s = "4(2(3)(1))(6(5))";
    Node* root = constructTree(s);
    preOrder(root);

    return 0;
}*/
/*// Convert Binary tree into Doubly Linked List
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *bintree2listUtil(node *root, node **head, node **tail)
{
    if (root == NULL)
        return NULL;

    node *left = root->left;
    node *right = root->right;

    bintree2listUtil(root->left, head, tail);

    if (*head == NULL)
    {
        *head = root;
    }

    root->left = *tail;

    if (*tail != NULL)
    {
        (*tail)->right = root;
    }

    *tail = root;

    bintree2listUtil(root->right, head, tail);

    return root;
}
node *bintree2list(node *root)
{
    if (root == NULL)
        return root;

    node *head = NULL;
    node *tail = NULL;

    bintree2listUtil(root, &head, &tail);

    return head;
}
node *newNode(int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
void printList(node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}
int main()
{
    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    node *head = bintree2list(root);
    printList(head);

    return 0;
}*/
/*// Convert Binary tree into Sum tree
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
int toSumTree(node *Node)
{
    if (!Node)
        return 0;
    int old_val = Node->data;
    Node->data = toSumTree(Node->left) + toSumTree(Node->right);
    return Node->data + old_val;
}
void printInorder(node *Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout << " " << Node->data;
    printInorder(Node->right);
}
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
int main()
{
    node *root = NULL;
    int x;
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSumTree(root);
    cout << "Inorder Traversal of the resultant tree is: \n";
    printInorder(root);
    return 0;
}*/
/*// Construct Binary tree from Inorder and preorder traversal
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    char data;
    node *left, *right;
};
int search(char arr[], int start, int end, char value);
node *newNode(char data);
node *buildTree(char in[], char pre[], int inStart, int inEnd)
{
    static int preIndex = 0;
    if (inStart > inEnd)
        return NULL;
    node *tNode = newNode(pre[preIndex++]);
    if (inStart == inEnd)
        return tNode;
    int inIndex = search(in, inStart, inEnd, tNode->data);
    tNode->left = buildTree(in, pre, inStart, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}
int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}
node *newNode(char data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
void printInorder(node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    node *root = buildTree(in, pre, 0, len - 1);
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}*/
/*// Find minimum swaps required to convert a Binary tree into BST
#include <bits/stdc++.h>
using namespace std;
void inorder(int a[], std::vector<int> &v,
             int n, int index)
{
    if (index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}
int minSwaps(std::vector<int> &v)
{
    std::vector<pair<int, int>> t(v.size());
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        t[i].first = v[i], t[i].second = i;

    sort(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++)
    {
        if (i == t[i].second)
            continue;
        else
        {
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }

        if (i != t[i].second)
            --i;
        ans++;
    }
    return ans;
}
int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}*/
/*// Check if Binary tree is Sum tree or not
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int sum(struct node *root)
{
    if (!root)
        return 0;
    return sum(root->left) + root->data + sum(root->right);
}
int isSumTree(struct node *node)
{
    int ls, rs;
    if (!node || (!node->left && !node->right))
        return 1;
    ls = sum(node->left);
    rs = sum(node->right);
    if ((node->data == ls + rs) && isSumTree(node->left) && isSumTree(node->right))
        return 1;
    return 0;
}
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(
        sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
int main()
{
    struct node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";

    getchar();
    return 0;
}*/
/*// Check if all leaf nodes are at same level or not
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
bool checkUtil(struct Node *root, int level, int *leaflevel)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
    {
        if (*leaflevel == 0)
        {
            *leaflevel = level;
            return true;
        }
        return (level == *leaflevel);
    }
    return checkUtil(root->left, level + 1, leaflevel) &&
           checkUtil(root->right, level + 1, leaflevel);
}
bool check(struct Node *root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
}
int main()
{
    struct Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
    getchar();
    return 0;
}*/
/*// Check if a Binary Tree contains duplicate subtrees of size 2 or more [ IMP ]
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char key;
    Node *left, *right;
};
Node *newNode(char key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

unordered_set<string> subtrees;

// Function that returns true if
// tree contains a duplicate subtree
// of size 2 or more
bool dupSubUtil(Node *root)
{

    // To store subtrees
    set<string> subtrees;

    // Used to traverse tree
    queue<Node *> bfs;
    bfs.push(root);

    while (!bfs.empty())
    {
        Node *n = bfs.front();
        bfs.pop();

        // To store the left and the right
        // children of the current node
        char l = ' ', r = ' ';

        // If the node has a left child
        if (n->left != NULL)
        {
            l = n->left->key;

            // Push left node's data
            bfs.push(n->left);
        }

        // If the node has a right child
        if (n->right != NULL)
        {
            r = n->right->key;

            // Push right node's data
            bfs.push(n->right);
        }

        string subt;
        subt += n->key;
        subt += l;
        subt += r;

        if (l != ' ' || r != ' ')
        {

            // If this subtree count is greater than 0
            // that means duplicate exists
            if (!subtrees.insert(subt).second)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left = newNode('D');

    cout << (dupSubUtil(root) ? "Yes" : "No");

    return 0;
}*/
/*// Check if 2 trees are mirror or not
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
int areMirror(Node *a, Node *b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    return a->data == b->data &&
           areMirror(a->left, b->right) &&
           areMirror(a->right, b->left);
}
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int main()
{
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left = newNode(4);
    a->left->right = newNode(5);

    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);

    areMirror(a, b) ? cout << "Yes" : cout << "No";

    return 0;
}*/
/*// Sum of Nodes on the Longest path from root to leaf node
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *getNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void sumOfLongRootToLeafPath(Node *root, int sum,
                             int len, int &maxLen, int &maxSum)
{
    if (!root)
    {
        if (maxLen < len)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }
    sumOfLongRootToLeafPath(root->left, sum + root->data,
                            len + 1, maxLen, maxSum);
    sumOfLongRootToLeafPath(root->right, sum + root->data,
                            len + 1, maxLen, maxSum);
}
int sumOfLongRootToLeafPathUtil(Node *root)
{
    if (!root)
        return 0;
    int maxSum = INT_MIN, maxLen = 0;
    sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
    return maxSum;
}
int main()
{
    Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(5);
    root->left->left = getNode(7);
    root->left->right = getNode(1);
    root->right->left = getNode(2);
    root->right->right = getNode(3);
    root->left->right->left = getNode(6);

    cout << "Sum = "
         << sumOfLongRootToLeafPathUtil(root);

    return 0;
}*/
// Check if given graph is tree or not.  [ IMP ]
/*// Find Largest subtree sum in a tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
int findLargestSubtreeSumUtil(Node *root, int &ans)
{
    if (!root)
        return 0;
    int currSum = root->key +
                  findLargestSubtreeSumUtil(root->left, ans) +
                  findLargestSubtreeSumUtil(root->right, ans);
    ans = max(ans, currSum);
    return currSum;
}
int findLargestSubtreeSum(Node *root)
{
    if (!root)
        return 0;
    int ans = INT_MIN;
    findLargestSubtreeSumUtil(root, ans);
    return ans;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);

    cout << findLargestSubtreeSum(root);
    return 0;
}*/
/*// Maximum Sum of nodes in Binary tree such that no two are adjacent
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int sumOfGrandChildren(node *node);
int getMaxSum(node *node);
int getMaxSumUtil(node *node, map<struct node *, int> &mp);

int sumOfGrandChildren(node *node, map<struct node *, int> &mp)
{
    int sum = 0;
    if (node->left)
        sum += getMaxSumUtil(node->left->left, mp) +
               getMaxSumUtil(node->left->right, mp);
    if (node->right)
        sum += getMaxSumUtil(node->right->left, mp) +
               getMaxSumUtil(node->right->right, mp);
    return sum;
}
int getMaxSumUtil(node *node, map<struct node *, int> &mp)
{
    if (!node)
        return 0;
    if (mp.find(node) != mp.end())
        return mp[node];
    int incl = node->data + sumOfGrandChildren(node, mp);
    int excl = getMaxSumUtil(node->left, mp) +
               getMaxSumUtil(node->right, mp);
    mp[node] = max(incl, excl);
    return mp[node];
}
int getMaxSum(node *node)
{
    if (node == NULL)
        return 0;
    map<struct node *, int> mp;
    return getMaxSumUtil(node, mp);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);

    cout << getMaxSum(root) << endl;
    return 0;
}*/
/*// Print all "K" Sum paths in a Binary tree
#include <bits/stdc++.h>
using namespace std;
void printVector(const vector<int> &v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void printKPathUtil(Node *root, vector<int> &path, int k)
{
    if (!root)
        return;
    path.push_back(root->data);
    printKPathUtil(root->left, path, k);
    printKPathUtil(root->right, path, k);
    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--)
    {
        f += path[j];
        if (f == k)
            printVector(path, j);
    }
    path.pop_back();
}
void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printKPath(root, k);
    return 0;
}*/
/*// Find LCA in a Binary tree
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return (Node);
}
node *lca(node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
    return root;
}
int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    node *t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
    return 0;
}*/
/*// Find distance between 2 nodes in a Binary tree
#include <iostream>
using namespace std;
struct Node
{
    struct Node *left, *right;
    int key;
};
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
int findLevel(Node *root, int k, int level)
{
    if (!root)
        return -1;
    if (root->key == k)
        return level;

    int l = findLevel(root->left, k, level + 1);
    return (l != -1) ? l : findLevel(root->right, k, level + 1);
}
Node *findDistUtil(Node *root, int n1, int n2, int &d1,
                   int &d2, int &dist, int lvl)
{
    if (!root)
        return NULL;
    if (root->key == n1)
    {
        d1 = lvl;
        return root;
    }
    if (root->key == n2)
    {
        d2 = lvl;
        return root;
    }
    Node *left_lca = findDistUtil(root->left, n1, n2,
                                  d1, d2, dist, lvl + 1);
    Node *right_lca = findDistUtil(root->right, n1, n2,
                                   d1, d2, dist, lvl + 1);
    if (left_lca && right_lca)
    {
        dist = d1 + d2 - 2 * lvl;
        return root;
    }
    return (left_lca != NULL) ? left_lca : right_lca;
}
int findDistance(Node *root, int n1, int n2)
{
    int d1 = -1, d2 = -1, dist;
    Node *lca = findDistUtil(root, n1, n2, d1, d2,
                             dist, 1);
    if (d1 != -1 && d2 != -1)
        return dist;
    if (d1 != -1)
    {
        dist = findLevel(lca, n2, 0);
        return dist;
    }
    if (d2 != -1)
    {
        dist = findLevel(lca, n1, 0);
        return dist;
    }
    return -1;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}*/
/*// Kth Ancestor of node in a Binary tree
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
void generateArray(Node *root, int ancestors[])
{
    ancestors[root->data] = -1;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            ancestors[temp->left->data] = temp->data;
            q.push(temp->left);
        }

        if (temp->right)
        {
            ancestors[temp->right->data] = temp->data;
            q.push(temp->right);
        }
    }
}
int kthAncestor(Node *root, int n, int k, int node)
{
    int ancestors[n + 1] = {0};
    generateArray(root, ancestors);
    int count = 0;

    while (node != -1)
    {
        node = ancestors[node];
        count++;

        if (count == k)
            break;
    }
    return node;
}
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;
    cout << kthAncestor(root, 5, k, node);
    return 0;
}*/
/*// Find all Duplicate subtrees in a Binary tree [ IMP ]
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
string inorder(Node *node, unordered_map<string, int> &m)
{
    if (!node)
        return "";
    string str = "(";
    str += inorder(node->left, m);
    str += to_string(node->data);
    str += inorder(node->right, m);
    str += ")";
    if (m[str] == 1)
        cout << node->data << " ";
    m[str]++;
    return str;
}
void printAllDups(Node *root)
{
    unordered_map<string, int> m;
    inorder(root, m);
}
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
    Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    printAllDups(root);
    return 0;
}*/
/*// Tree Isomorphism Problem
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}
bool isIsomorphic(node *n1, node *n2)
{
    if (!n1 && !n2)
        return true;
    if (!n1 || !n2)
        return false;
    if (n1->data != n2->data)
        return false;
    return (isIsomorphic(n1->left, n2->left) &&
            isIsomorphic(n1->right, n2->right)) ||
           (isIsomorphic(n1->left, n2->right) &&
            isIsomorphic(n1->right, n2->left));
}
int main()
{
    struct node *n1 = newNode(1);
    n1->left = newNode(2);
    n1->right = newNode(3);
    n1->left->left = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);

    struct node *n2 = newNode(1);
    n2->left = newNode(3);
    n2->right = newNode(2);
    n2->right->left = newNode(4);
    n2->right->right = newNode(5);
    n2->left->right = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);

    if (isIsomorphic(n1, n2) == true)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}*/
/*// Flatten Binary Tree to LinkedList
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

class Solution
{
    node *prev = NULL;

public:
    void flatten(node *root)
    {
        node *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                node *pre = cur->left;
                while (pre->right)
                {
                    pre = pre->right;
                }
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right = newNode(5);
    root->right->right = newNode(6);
    root->right->right->left = newNode(7);

    Solution obj;

    obj.flatten(root);
    while (root->right != NULL)
    {
        cout << root->data << "->";
        root = root->right;
    }
    cout << root->data;
    return 0;
}*/
