/*// Fina a value in a BST
#include <iostream>
using namespace std;

class BST
{
	int data;
	BST *left, *right;

public:
	BST();
	BST(int);
	BST* Insert(BST*, int);
	void Inorder(BST*);
};
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}
BST* BST ::Insert(BST* root, int value)
{
	if (!root)
	{
		return new BST(value);
	}
	if (value > root->data)
	{
		root->right = Insert(root->right, value);
	}
	else
	{
		root->left = Insert(root->left, value);
	}
	return root;
}
void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);
	return 0;
}*/
/*// Deletion of a node in a BST
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key;
        inorder(root->right);
    }
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
struct node *deleteNode(struct node *root, int key)
{
    if (!root)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    return 0;
}*/
/*// Find min and max value in a BST
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return (newNode(data));
    else
    {
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }
}
int minValue(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return (current->data);
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);

    cout << "\n Minimum value in BST is " << minValue(root);
    getchar();
    return 0;
}*/
/*// Find inorder successor and inorder predecessor in a BST
#include <iostream>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
};
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (!root)
        return;
    if (root->key == key)
    {
        if (!root->left)
        {
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }
        if (!root->right)
        {
            Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            pre = tmp;
        }
        return;
    }
    if (root->key > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
Node *insert(Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    int key = 65;
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    Node *pre = NULL, *suc = NULL;

    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
        cout << "Predecessor is " << pre->key << endl;
    else
        cout << "No Predecessor";

    if (suc != NULL)
        cout << "Successor is " << suc->key;
    else
        cout << "No Successor";
    return 0;
}*/
/*// Check if a tree is a BST or not
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int isBSTUtil(node *node, int min, int max);
int isBST(node *node)
{
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}
int isBSTUtil(node *node, int min, int max)
{
    if (node == NULL)
        return 1;
    if (node->data < min || node->data > max)
        return 0;
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}
int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}*/
/*// Populate Inorder successor of all nodes
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node *next;
};
void populateNext(node *p)
{
    static node *next = NULL;
    if (p)
    {
        populateNext(p->next);
        p->next = next;
        next = p;
        populateNext(p->left);
    }
}
node *newnode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    Node->next = NULL;

    return (Node);
}
int main()
{
    node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(12);
    root->left->left = newnode(3);
    populateNext(root);
    node *ptr = root->left->left;
    while (ptr)
    {
        cout << "Next of " << ptr->data << " is " <<
        (ptr->next ? ptr->next->data : -1) << endl;
        ptr = ptr->next;
    }

    return 0;
}*/
/*// Find LCA  of 2 nodes in a BST
same as BT problem*/
/*// Construct BST from preorder traversal
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *newNode(int data)
{
    node *temp = new node();

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
node *constructTreeUtil(int pre[], int *preIndex, int low,
                        int high, int size)
{
    if (*preIndex >= size || low > high)
        return NULL;
    node *root = newNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;
    if (low == high)
        return root;
    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;
    root->left = constructTreeUtil(pre, preIndex, *preIndex, i - 1, size);
    root->right = constructTreeUtil(pre, preIndex, i, high, size);
    return root;
}
node *constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, 0, size - 1, size);
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
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    node *root = constructTree(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}*/
/*// Convert Binary tree into BST
BT 1086*/
/*// Convert a normal BST into a Balanced BST
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
void storeBSTNodes(Node *root, vector<Node *> &nodes)
{
    if (root == NULL)
        return;
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}
Node *buildTreeUtil(vector<Node *> &nodes, int start,
                    int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = nodes[mid];
    root->left = buildTreeUtil(nodes, start, mid - 1);
    root->right = buildTreeUtil(nodes, mid + 1, end);

    return root;
}
Node *buildTree(Node *root)
{
    vector<Node *> nodes;
    storeBSTNodes(root, nodes);
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n - 1);
}
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void preOrder(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
int main()
{

    Node *root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);

    root = buildTree(root);

    printf("Preorder traversal of balanced "
           "BST is : \n");
    preOrder(root);
    return 0;
}*/
/*// Merge two BST [ V.V.V>IMP ]
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
int *merge(int arr1[], int tarr2[], int m, int n);
void storeInorder(node *node, int inorder[], int *index_ptr);
node *sortedArrayToBST(int arr[], int start, int end);
node *mergeTrees(node *root1, node *root2, int m, int n)
{
    int *arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, &i);
    int *arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, &j);
    int *mergedArr = merge(arr1, arr2, m, n);
    return sortedArrayToBST(mergedArr, 0, m + n - 1);
}
node *newNode(int data)
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
int *merge(int arr1[], int arr2[], int m, int n)
{
    int *mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }

    return mergedArr;
}
void storeInorder(node *node, int inorder[], int *index_ptr)
{
    if (node == NULL)
        return;
    storeInorder(node->left, inorder, index_ptr);

    inorder[*index_ptr] = node->data;
    (*index_ptr)++;
    storeInorder(node->right, inorder, index_ptr);
}
node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    node *root = newNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}
int main()
{
    node *root1 = newNode(100);
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
    node *root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);

    node *mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);
    return 0;
}*/
/*// Find Kth largest element in a BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void kthLargestUtil(Node *root, int k, int &c)
{
    if (!root || c >= k)
        return;
    kthLargestUtil(root->right, k, c);
    c++;
    if (c == k)
    {
        cout << "K'th largest element is" << root->key << endl;
        return;
    }
    kthLargestUtil(root->left, k, c);
}
void kthLargest(Node *root, int k)
{
    int c = 0;
    kthLargestUtil(root, k, c);
}
Node *insert(Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int c = 0;
    for (int k = 1; k <= 7; k++)
        kthLargest(root, k);

    return 0;
}*/
/*// Find Kth smallest element in a BST
#include <iostream>
using namespace std;
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
Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}
Node *kthSmallest(Node *root, int &k)
{
    // base case
    if (root == NULL)
        return NULL;
    Node *left = kthSmallest(root->left, k);
    if (left != NULL)
        return left;
    k--;
    if (k == 0)
        return root;
    return kthSmallest(root->right, k);
}
void printKthSmallest(Node *root, int k)
{
    int count = 0;
    Node *res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->data;
}
int main()
{
    Node *root = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};

    for (int x : keys)
        root = insert(root, x);

    int k = 3;
    printKthSmallest(root, k);
    return 0;
}*/
/*// Count pairs from 2 BST whose sum is equal to given value "X"
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *getNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
}
int countPairs(Node *root1, Node *root2, int x)
{
    if (root1 == NULL || root2 == NULL)
        return 0;
    stack<Node *> st1, st2;
    Node *top1, *top2;

    int count = 0;
    while (1)
    {
        while (root1 != NULL)
        {
            st1.push(root1);
            root1 = root1->left;
        }
        while (root2 != NULL)
        {
            st2.push(root2);
            root2 = root2->right;
        }
        if (st1.empty() || st2.empty())
            break;

        top1 = st1.top();
        top2 = st2.top();
        if ((top1->data + top2->data) == x)
        {
            count++;
            st1.pop();
            st2.pop();
            root1 = top1->right;
            root2 = top2->left;
        }
        else if ((top1->data + top2->data) < x)
        {
            st1.pop();
            root1 = top1->right;
        }
        else
        {
            st2.pop();
            root2 = top2->left;
        }
    }
    return count;
}
int main()
{ 
    root1->left = getNode(3);  
    root1->right = getNode(7);   
    root1->left->left = getNode(2);
    root1->left->right = getNode(4);
    root1->right->left = getNode(6);
    root1->right->right = getNode(8);

    root2->left = getNode(6);        
    root2->right = getNode(15);      
    root2->left->left = getNode(3); 
    root2->left->right = getNode(8); 
    root2->right->left = getNode(11);
    root2->right->right = getNode(18);

    int x = 16;
    cout << "Pairs = "
         << countPairs(root1, root2, x);

    return 0;
}*/
/*// Find the median of BST in O(n) time and O(1) space
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}
int counNodes(struct Node *root)
{
    struct Node *current, *pre;

    // Initialise count of nodes as 0
    int count = 0;

    if (root == NULL)
        return count;

    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // Count node if its left is NULL
            count++;

            // Move to its right
            current = current->right;
        }
        else
        {
            pre = current->left;

            while (pre->right != NULL &&
                   pre->right != current)
                pre = pre->right;
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;

                // Increment count if the current
                // node is to be visited
                count++;
                current = current->right;
            } 
        }    
    }        

    return count;
}

int findMedian(struct Node *root)
{
    if (root == NULL)
        return 0;

    int count = counNodes(root);
    int currCount = 0;
    struct Node *current = root, *pre, *prev;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // count current node
            currCount++;

            // check if current node is the median
            // Odd case
            if (count % 2 != 0 && currCount == (count + 1) / 2)
                return prev->data;

            // Even case
            else if (count % 2 == 0 && currCount == (count / 2) + 1)
                return (prev->data + current->data) / 2;

            // Update prev for even no. of nodes
            prev = current;

            //Move to the right
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;

                prev = pre;

                // Count current node
                currCount++;

                // Check if the current node is the median
                if (count % 2 != 0 && currCount == (count + 1) / 2)
                    return current->data;

                else if (count % 2 == 0 && currCount == (count / 2) + 1)
                    return (prev->data + current->data) / 2;

                // update prev node for the case of even
                // no. of nodes
                prev = current;
                current = current->right;

            }
        }   
    }     
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "\nMedian of BST is "
         << findMedian(root);
    return 0;
}*/
/*// Count BST ndoes that lie in a given range
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}
int getCount(node *root, int low, int high)
{
    if (!root)
        return 0;
    if (root->data == high && root->data == low)
        return 1;
    if (root->data <= high && root->data >= low)
        return 1 + getCount(root->left, low, high) +
               getCount(root->right, low, high);
    else if (root->data < low)
        return getCount(root->right, low, high);
    else
        return getCount(root->left, low, high);
}
int main()
{
    node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(50);
    root->left->left = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    int l = 5;
    int h = 45;
    cout << "Count of nodes between [" << l << ", " << h
         << "] is " << getCount(root, l, h);
    return 0;
}*/
/*// Replace every element with the least greater element on its right
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
Node *insert(Node *node, int data, Node *&succ)
{
    if (node == NULL)
        return node = newNode(data);
    if (data < node->data)
    {
        succ = node;
        node->left = insert(node->left, data, succ);
    }
    else if (data > node->data)
        node->right = insert(node->right, data, succ);
    return node;
}
void replace(int arr[], int n)
{
    Node *root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *succ = NULL;
        root = insert(root, arr[i], succ);
        if (succ)
            arr[i] = succ->data;
        else
            arr[i] = -1;
    }
}
int main()
{
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92,
                 43, 3, 91, 93, 25, 80, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    replace(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}*/
/*// Given "n" appointments, find the conflicting appointments
#include <bits/stdc++.h>
using namespace std;
struct Interval
{
    int low, high;
};
struct ITNode
{
    Interval *i;
    int max;
    ITNode *left, *right;
};
ITNode *newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
};
ITNode *insert(ITNode *root, Interval i)
{
    if (root == NULL)
        return newNode(i);
    int l = root->i->low;
    if (i.low < l)
        root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);
    if (root->max < i.high)
        root->max = i.high;

    return root;
}
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low < i2.high && i2.low < i1.high)
        return true;
    return false;
}
Interval *overlapSearch(ITNode *root, Interval i)
{
    if (root == NULL)
        return NULL;
    if (doOVerlap(*(root->i), i))
        return root->i;
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
    return overlapSearch(root->right, i);
}
void printConflicting(Interval appt[], int n)
{
    ITNode *root = NULL;
    root = insert(root, appt[0]);
    for (int i = 1; i < n; i++)
    {
        Interval *res = overlapSearch(root, appt[i]);
        if (res != NULL)
            cout << "[" << appt[i].low << "," << appt[i].high
                 << "] Conflicts with [" << res->low << ","
                 << res->high << "]\n";
        root = insert(root, appt[i]);
    }
}
int main()
{
    Interval appt[] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(appt) / sizeof(appt[0]);
    cout << "Following are conflicting intervals\n";
    printConflicting(appt, n);
    return 0;
}*/
/*// Check preorder is valid or not
#include <bits/stdc++.h>
using namespace std;
bool canRepresentBST(int pre[], int n)
{
    stack<int> s;
    int root = INT_MIN;
    for (int i=0; i<n; i++)
    {
        if (pre[i] < root)
            return false;
        while (!s.empty() && s.top()<pre[i])
        {
            root = s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}

int main()
{
    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1) / sizeof(pre1[0]);
    canRepresentBST(pre1, n) ? cout << "true\n" : cout << "false\n";

    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2) / sizeof(pre2[0]);
    canRepresentBST(pre2, n) ? cout << "true\n" : cout << "false\n";
    return 0;
}*/
/*// Check whether BST contains Dead end
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}
void storeNodes(Node *root, unordered_set<int> &all_nodes,
                unordered_set<int> &leaf_nodes)
{
    if (!root)
        return;
    all_nodes.insert(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        leaf_nodes.insert(root->data);
        return;
    }
    storeNodes(root->left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}
bool isDeadEnd(Node *root)
{
    if (!root)
        return false;
    unordered_set<int> all_nodes, leaf_nodes;
    all_nodes.insert(0);
    storeNodes(root, all_nodes, leaf_nodes);
    for (auto i = leaf_nodes.begin(); i != leaf_nodes.end(); i++)
    {
        int x = (*i);
        if (all_nodes.find(x + 1) != all_nodes.end() &&
            all_nodes.find(x - 1) != all_nodes.end())
            return true;
    }
    return false;
}
int main()
{
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    if (isDeadEnd(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}*/
/*// Largest BST in a Binary Tree [ V.V.V.V.V IMP ]
// class NodeValue {
// public:
//     int maxNode, minNode, maxSize;
    
//     NodeValue(int minNode, int maxNode, int maxSize) {
//         this->maxNode = maxNode;
//         this->minNode = minNode;
//         this->maxSize = maxSize;
//     }
// };

// class Solution {
// private:
//     NodeValue largestBSTSubtreeHelper(TreeNode* root) {
//         // An empty tree is a BST of size 0.
//         if (!root) {
//             return NodeValue(INT_MAX, INT_MIN, 0);
//         }
        
//         // Get values from left and right subtree of current tree.
//         auto left = largestBSTSubtreeHelper(root->left);
//         auto right = largestBSTSubtreeHelper(root->right);
        
//         // Current node is greater than max in left AND smaller than min in right, it is a BST.
//         if (left.maxNode < root->val && root->val < right.minNode) {
//             // It is a BST.
//             return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
//                             left.maxSize + right.maxSize + 1);
//         }
        
//         // Otherwise, return [-inf, inf] so that parent can't be valid BST
//         return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
//     }
//     public:
//     int largestBSTSubtree(TreeNode* root) {
//         return largestBSTSubtreeHelper(root).maxSize;
//     }
// };
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
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return (node);
}
struct Info
{
    int sz;     // Size of subtree
    int max;    // Min value in subtree
    int min;    // Max value in subtree
    int ans;    // Size of largest BST which is subtree of current node
    bool isBST; // If subtree is BST
};
Info largestBSTBT(Node *root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};
    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);
    Info ret;
    ret.sz = (1 + l.sz + r.sz);
    if (l.isBST && r.isBST && l.max < root->data &&
        r.min > root->data)
    {
        ret.min = min(l.min, min(r.min, root->data));
        ret.max = max(r.max, max(l.max, root->data));
        ret.ans = ret.sz;
        ret.isBST = true;

        return ret;
    }
    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;

    return ret;
}
int main()
{
    struct Node *root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);
    printf(" Size of the largest BST is %d\n",
           largestBSTBT(root).ans);
    return 0;
}*/
/*// Flatten BST to sorted list.
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void print(node *parent)
{
    node *curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}
void inorder(node *curr, node *&prev)
{
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}
node *flatten(node *parent)
{
    node *dummy = new node(-1);
    node *prev = dummy;
    inorder(parent, prev);

    prev->left = NULL;
    prev->right = NULL;
    node *ret = dummy->right;
    delete dummy;
    return ret;
}
int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
    print(flatten(root));

    return 0;
}*/
