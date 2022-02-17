/*//Write a Program to reverse the Linked List.(Iterative)
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }
    void reverse()
    {
        Node *current = head;
        Node *prev = NULL, *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
int main()
{
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    cout << "Given linked list\n";
    ll.print();
    ll.reverse();
    cout << "\nReversed LInked list \n";
    ll.print();
    return 0;
}*/
/*//Write a Program to reverse the Linked List.(Recursive)
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
struct LinkedList
{
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
int main()
{
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    cout << "Given linked list\n";
    ll.print();
    ll.head = ll.reverse(ll.head);
    cout << "\nReversed LInked list \n";
    ll.print();
    return 0;
}*/
/*//Reverse a Linked List in group of Given Size.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *reverse(Node *head, int k)
{
    if (!head)
        return NULL;
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
        head->next = reverse(next, k);
    return prev;
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    Node *head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given linked list \n";
    printList(head);
    head = reverse(head, 3);

    cout << "\nReversed Linked list \n";
    printList(head);

    return 0;
}*/
/*//Write a program to Detect loop in a linked list.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    int flag;
};
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->flag = 0;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
bool detectLoop(struct Node *h)
{
    while (h != NULL)
    {
        if (h->flag == 1)
            return true;
        h->flag = 1;
        h = h->next;
    }
    return false;
}
int main()
{
    struct Node *head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}*/
/*//Find the starting point of the loop.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *next;
};
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
Node *detectAndRemoveloop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != fast)
        return NULL;
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
int main()
{
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = head->next->next;
    Node *res = detectAndRemoveloop(head);
    if (res == NULL)
        cout << "Loop doesnt exist";
    else
        cout << "Loop starting node is " << res->key;
    return 0;
}*/
/*//Remove Duplicates in a sorted Linked List.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void removeDuplicates(Node *head)
{
    Node *current = head;
    Node *next_next;
    if (current == NULL)
        return;
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
int main()
{
    Node *head = NULL;
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    cout << "Linked list before duplicate removal ";
    printList(head);
    removeDuplicates(head);
    cout << "\nLinked list after duplicate removal ";
    printList(head);

    return 0;
}*/
/*//Remove Duplicates in a Un-sorted Linked List.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void removeDuplicates(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next = newNode(11);
    start->next->next->next->next->next->next = newNode(10);

    printf("Linked list before removing duplicates ");
    printList(start);

    removeDuplicates(start);

    printf("\nLinked list after removing duplicates ");
    printList(start);

    return 0;
}*/
/*// Write a Program to Move the last element to Front in a Linked List.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void moveToFront(Node **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;
    Node *secLast = NULL;
    Node *last = *head_ref;
    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    Node *start = NULL;
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout << "Linked list before moving last to front\n";
    printList(start);

    moveToFront(&start);

    cout << "\nLinked list after removing last to front\n";
    printList(start);

    return 0;
}*/
/*// Add “1” to a number represented as a Linked List.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node *addOneUtil(Node *head)
{
    Node *res = head;
    Node *temp, *prev = NULL;
    int carry = 1, sum;
    while (head != NULL)
    {
        sum = carry + head->data;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    return res;
}
Node *addOne(Node *head)
{
    head = reverse(head);
    head = addOneUtil(head);
    return reverse(head);
}
void print(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << endl;
}
int main()
{
    Node *head = newNode(1);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);
    cout << "List is ";
    print(head);
    head = addOne(head);
    cout << "\nResultant list is ";
    print(head);
    return 0;
}*/
/*// Add two numbers represented by linked lists.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
struct Node *addTwoList(struct Node *first, struct Node *second)
{
    struct Node *res = NULL;
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;
    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = newNode(sum);
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    return res;
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int main()
{
    struct Node *res = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    cout << "First List is ";
    printList(first);
    push(&second, 4);
    push(&second, 8);
    cout << "Second List is ";
    printList(second);

    res = addTwoList(first, second);
    cout << "Resultant list is ";
    printList(res);
    return 0;
}*/
/*// Intersection of two Sorted Linked List.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void push(Node **head_ref, int new_data);
Node *sortedIntersect(Node *a, Node *b)
{
    Node dummy;
    Node *tail = &dummy;
    dummy.next = NULL;
    while (a != NULL && b != NULL)
    {
        if (a->data == b->data)
        {
            push((&tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return (dummy.next);
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    Node *a = NULL;
    Node *b = NULL;
    Node *intersect = NULL;
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);
    intersect = sortedIntersect(a, b);

    cout << "Linked list containing common items of a & b \n";
    printList(intersect);
}*/
/*// Intersection Point of two Linked Lists.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
int getCount(Node *head);
int _getIntesectionNode(int d, Node *head1, Node *head2);
int getIntesectionNode(Node *head1, Node *head2)
{
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
    if (c1 > c2)
    {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else
    {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}
int _getIntesectionNode(int d, Node *head1, Node *head2)
{
    Node *current1 = head1;
    Node *current2 = head2;
    for (int i = 0; i < d; i++)
    {
        if (current1 == NULL)
        {
            return -1;
        }
        current1 = current1->next;
    }
    while (current1 != NULL && current2 != NULL)
    {
        if (current1 == current2)
            return current1->data;
        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}
int getCount(Node *head)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}
int main()
{
    Node *newNode;

    Node *head1 = new Node();
    head1->data = 10;

    Node *head2 = new Node();
    head2->data = 3;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    cout << "The node of intersection is "
         << getIntesectionNode(head1, head2);
}*/
/*// Merge Sort For Linked lists.[Very Important]
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *SortedMerge(Node *a, Node *b);
void FrontBackSplit(Node *source,
                    Node **frontRef, Node **backRef);
void MergeSort(Node **headRef)
{
    Node *head = *headRef;
    Node *a;
    Node *b;
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a, b);
}
Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
void FrontBackSplit(Node *source,
                    Node **frontRef, Node **backRef)
{
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main()
{
    Node *res = NULL;
    Node *a = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
    MergeSort(&a);

    cout << "Sorted Linked List is: \n";
    printList(a);

    return 0;
}*/
/*// Quicksort for Linked Lists.[Very Important]
#include <cstdio>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
struct Node *getTail(struct Node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
struct Node *partition(struct Node *head, struct Node *end,
                       struct Node **newHead,
                       struct Node **newEnd)
{
    struct Node *pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            struct Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL)
        (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}
struct Node *quickSortRecur(struct Node *head,
                            struct Node *end)
{
    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;
    struct Node *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {
        struct Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}
void quickSort(struct Node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
int main()
{
    struct Node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    cout << "Linked List before sorting \n";
    printList(a);

    quickSort(&a);

    cout << "Linked List after sorting \n";
    printList(a);

    return 0;
}*/
/*// Find the middle Element of a linked list.
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

class NodeOperation
{
public:
    void pushNode(class Node **head_ref, int data_val)
    {
        class Node *new_node = new Node();
        new_node->data = data_val;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    void printNode(class Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }

    void printMiddle(class Node *head)
    {
        struct Node *slow_ptr = head;
        struct Node *fast_ptr = head;

        if (head != NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            cout << "The middle element is [" << slow_ptr->data << "]" << endl;
        }
    }
};
int main()
{
    class Node *head = NULL;
    class NodeOperation *temp = new NodeOperation();
    for (int i = 5; i > 0; i--)
    {
        temp->pushNode(&head, i);
        temp->printNode(head);
        temp->printMiddle(head);
    }
    return 0;
}*/
/*// Check if a linked list is a circular linked list.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
bool isCircular(struct Node *head)
{
    if (head == NULL)
        return true;
    struct Node *node = head->next;
    while (node != NULL && node != head)
        node = node->next;
    return (node == head);
}
Node *newNode(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main()
{
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    head->next->next->next->next = head;

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}*/
/*// Split a Circular linked list into two halves.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;
    if (head == NULL)
        return;
    while (fast_ptr->next != head && fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;
    *head1_ref = head;
    if (head->next != head)
        *head2_ref = slow_ptr->next;
    fast_ptr->next = slow_ptr->next;
    slow_ptr->next = head;
}
void push(Node **head_ref, int data)
{
    Node *ptr1 = new Node();
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}
void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        cout << endl;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}
int main()
{
    int list_size, i;

    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;

    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    cout << "Original Circular Linked List";
    printList(head);

    splitList(head, &head1, &head2);

    cout << "\nFirst Circular Linked List";
    printList(head1);

    cout << "\nSecond Circular Linked List";
    printList(head2);
    return 0;
}*/
/*/ Write a Program to check whether the Singly Linked list is a palindrome or not.
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node(int d)
    {
        data = d;
    }
    Node *ptr;
};
bool isPalin(Node *head)
{
    Node *slow = head;
    stack<int> s;
    while (slow != NULL)
    {
        s.push(slow->data);
        slow = slow->ptr;
    }
    while (head != NULL)
    {
        int i = s.top();
        s.pop();
        if (head->data != i)
        {
            return false;
        }
        head = head->ptr;
    }
    return true;
}
int main()
{
    Node one = Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);

    five.ptr = NULL;
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = &four;
    four.ptr = &five;
    Node *temp = &one;

    int result = isPalin(&one);

    if (result == 1)
        cout << "isPalindrome is true\n";
    else
        cout << "isPalindrome is true\n";

    return 0;
}*/
/*// Deletion from a Circular Linked List.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void push(Node **head_ref, int data)
{
    Node *ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *head_ref;
    if (*head_ref != NULL)
    {
        Node *temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}
void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    cout << endl;
}
void deleteNode(Node **head, int key)
{

    if (*head == NULL)
        return;

    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *last = *head, *d;

    if ((*head)->data == key)
    {
        while (last->next != *head)
            last = last->next;

        last->next = (*head)->next;
        free(*head);
        *head = last->next;
    }

    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }
    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else
        cout << "no such keyfound";
}
int main()
{
    Node *head = NULL;
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);

    cout << "List Before Deletion: ";
    printList(head);

    deleteNode(&head, 7);

    cout << "List After Deletion: ";
    printList(head);

    return 0;
}*/
/*// Reverse a Doubly Linked list.
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void reverse(Node **head_ref)
{
    Node *temp = NULL;
    Node *current = *head_ref;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        *head_ref = temp->prev;
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    Node *head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    cout << "Original Linked list" << endl;
    printList(head);

    reverse(&head);

    cout << "\nReversed Linked list" << endl;
    printList(head);

    return 0;
}*/
/*// Find pairs with a given sum in a DLL.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

void pairSum(struct Node *head, int x)
{
    struct Node *first = head;
    struct Node *second = head;
    while (second->next != NULL)
        second = second->next;

    bool found = false;

    while (first != second && second->next != first)
    {
        if ((first->data + second->data) == x)
        {
            found = true;
            cout << "(" << first->data << ", "
                 << second->data << ")" << endl;

            first = first->next;
            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
    if (found == false)
        cout << "No pair found";
}
void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;

    pairSum(head, x);

    return 0;
}*/
/*// Count triplets in a sorted DLL whose sum is equal to given value “X”.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next, *prev;
};
int countTriplets(struct Node *head, int x)
{
    struct Node *ptr1, *ptr2, *ptr3;
    int count = 0;

    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)
                if ((ptr1->data + ptr2->data + ptr3->data) == x)
                    count++;
    return count;
}
void insert(struct Node **head, int data)
{
    struct Node *temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;

    if ((*head) == NULL)
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

    int x = 17;

    cout << "Count = "
         << countTriplets(head, x);
    return 0;
}*/
/*// Sort a “k”sorted Doubly Linked list.[Very IMP]
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *sortAKSortedDLL(struct Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    for (Node *i = head->next; i != NULL; i = i->next)
    {
        Node *j = i;
        while (j->prev != NULL && j->data < j->prev->data)
        {
            Node *temp = j->prev->prev;
            Node *temp2 = j->prev;
            Node *temp3 = j->next;
            j->prev->next = temp3;
            j->prev->prev = j;
            j->prev = temp;
            j->next = temp2;
            if (temp != NULL)
                temp->next = j;
            if (temp3 != NULL)
                temp3->prev = temp2;
        }
        if (j->prev == NULL)
            head = j;
    }
    return head;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
void printList(struct Node *head)
{
    if (head == NULL)
        cout << "Doubly Linked list empty";

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    struct Node *head = NULL;

    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);

    int k = 2;

    cout << "Original Doubly linked list:\n";
    printList(head);
    head = sortAKSortedDLL(head, k);
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);

    return 0;
}*/
/*// Rotate DoublyLinked list by N nodes.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
};
void rotate(struct Node **head_ref, int N)
{
    if (N == 0)
        return;
    struct Node *current = *head_ref;
    int count = 1;
    while (count < N && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;
    struct Node *NthNode = current;
    while (current->next != NULL)
        current = current->next;
    current->next = *head_ref;
    (*head_ref)->prev = current;
    *head_ref = NthNode->next;
    (*head_ref)->prev = NULL;
    NthNode->next = NULL;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}
void printList(struct Node *node)
{
    while (node->next != NULL)
    {
        cout << node->data << " "
             << "<=>"
             << " ";
        node = node->next;
    }
    cout << node->data;
}

int main(void)
{
    struct Node *head = NULL;

    push(&head, 'e');
    push(&head, 'd');
    push(&head, 'c');
    push(&head, 'b');
    push(&head, 'a');

    int N = 2;

    cout << "Given linked list \n";
    printList(head);
    rotate(&head, N);

    cout << "\nRotated Linked list \n";
    printList(head);

    return 0;
}*/
/*// Rotate a Doubly Linked list in group of Given Size.[Very IMP]
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
};
Node *getNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}
void push(Node **head_ref, Node *new_node)
{
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
Node *revListInGroupOfGivenSize(Node *head, int k)
{
    Node *current = head;
    Node *next = NULL;
    Node *newHead = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        push(&newHead, current);
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = revListInGroupOfGivenSize(next, k);
        head->next->prev = head;
    }
    return newHead;
}
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));

    int k = 2;

    cout << "Original list: ";
    printList(head);

    head = revListInGroupOfGivenSize(head, k);

    cout << "\nModified list: ";
    printList(head);

    return 0;
}*/
// Can we reverse a linked list in less than O(n) ?
// Why Quicksort is preferred for. Arrays and Merge Sort for LinkedLists ?
// Flatten a Linked List(JAVA)
/*// Sort a LL of 0's, 1's and 2's
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
void sortList(Node *head)
{
    int count[3] = {0, 0, 0};
    Node *ptr = head;
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (count[i] == 0)
        {
            ++i;
        }
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main(void)
{
    Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);

    cout << "Linked List Before Sorting\n";
    printList(head);
    sortList(head);
    cout << "Linked LIst after Sorting\n";
    printList(head);
    return 0;
}*/
/*// Clone a linked list with next and random pointer
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}
Node *clone(Node *start)
{
    Node *curr = start, *temp;
    while (curr)
    {
        temp = curr->next;

        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = start;
    while (curr)
    {
        if (curr->next)
            curr->next->random = 
            curr->random ? curr->random->next : curr->random;
        curr = curr->next ? curr->next->next : curr->next;
    }
    Node *original = start, *copy = start->next;
    temp = copy;
    while (original && copy)
    {
        original->next =
            original->next ? original->next->next : original->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}
int main()
{
    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);
    start->random = start->next->next;

    start->next->random = start;

    start->next->next->random =start->next->next->next->next;

    start->next->next->next->random =start->next->next->next->next;

    start->next->next->next->next->random =start->next;

    cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    Node *cloned_list = clone(start);
    print(cloned_list);

    return 0;
}*/
/*// Merge K sorted Linked list
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}
Node *mergeKLists(Node *arr[], int last)
{
    while (last != 0)
    {
        int i = 0, j = last;
        while (i < j)
        {
            arr[i] = SortedMerge(arr[i], arr[j]);
            i++, j--;
            if (i >= j)
                last = j;
        }
    }
    return arr[0];
}
Node *newNode(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main()
{
    int k = 3;
    int n = 4;
    Node *arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
    Node *head = mergeKLists(arr, k - 1);

    printList(head);

    return 0;
}*/
/*// Multiply 2 no. represented by LL
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
long long multiplyTwoLists(Node *first, Node *second)
{
    long long N = 1000000007;
    long long num1 = 0, num2 = 0;
    while (first || second)
    {
        if (first)
        {
            num1 = ((num1)*10) % N + first->data;
            first = first->next;
        }
        if (second)
        {
            num2 = ((num2)*10) % N + second->data;
            second = second->next;
        }
    }
    return ((num1 % N) * (num2 % N)) % N;
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        if (node->next)
            cout << "->";
        node = node->next;
    }
    cout << "\n";
}
int main()
{
    struct Node *first = NULL;
    struct Node *second = NULL;

    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    printf("First List is: ");
    printList(first);

    push(&second, 4);
    push(&second, 8);
    printf("Second List is: ");
    printList(second);

    cout << "Result is: ";
    cout << multiplyTwoLists(first, second);

    return 0;
}*/
/*// Delete nodes which have a greater value on right side
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void reverseList(struct Node **headref);
void _delLesserNodes(struct Node *head);

void delLesserNodes(struct Node **head_ref)
{
    reverseList(head_ref);
    _delLesserNodes(*head_ref);
    reverseList(head_ref);
}
void _delLesserNodes(struct Node *head)
{
    struct Node *current = head;
    struct Node *maxnode = head;
    struct Node *temp;

    while (current != NULL &&
           current->next != NULL)
    {
        if (current->next->data < maxnode->data)
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else
        {
            current = current->next;
            maxnode = current;
        }
    }
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void reverseList(struct Node **headref)
{
    struct Node *current = *headref;
    struct Node *prev = NULL;
    struct Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headref = prev;
}
void printList(struct Node *head)
{
    while (head != NULL)
    {
        cout << " " << head->data;
        head = head->next;
    }
    cout << "\n";
}
int main()
{
    struct Node *head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);

    cout << "Given Linked List \n";
    printList(head);

    delLesserNodes(&head);

    cout << "Modified Linked List \n";
    printList(head);

    return 0;
}*/
/*// Segregate even and odd nodes in a Linked List
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

void segregateEvenOdd(Node **head_ref)
{
    Node *end = *head_ref;
    Node *prev = NULL;
    Node *curr = *head_ref;
    while (end->next != NULL)
        end = end->next;
    Node *new_end = end;

    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
    if (curr->data % 2 == 0)
    {
        *head_ref = curr;
        while (curr != end)
        {
            if ((curr->data) % 2 == 0)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                new_end->next = curr;
                new_end = curr;
                curr = prev->next;
            }
        }
    }
    else
        prev = curr;
    if (new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    Node *head = NULL;

    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 4);
    push(&head, 1);
    push(&head, 0);

    cout << "Original Linked list ";
    printList(head);

    segregateEvenOdd(&head);

    cout << "\nModified Linked list ";
    printList(head);

    return 0;
}*/
/*// Program for n’th node from the end of a Linked List
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void printNthFromLast(struct Node *head, int n)
{
    int len = 0, i;
    struct Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (len < n)
        return;
    temp = head;
    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;
    cout << temp->data;
    return;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main()
{
    struct Node *head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);

    printNthFromLast(head, 4);
    return 0;
}*/
/*// Find the first non-repeating character from a stream of characters
#include <iostream>
#define MAX_CHAR 256
using namespace std;

// A linked list node
struct node
{
    char a;
    struct node *next, *prev;
};

// A utility function to append a character x at the end
// of DLL. Note that the function may change head and tail
// pointers, that is why pointers to these pointers are
// passed.
void appendNode(struct node **head_ref,
                struct node **tail_ref, char x)
{
    struct node *temp = new node;
    temp->a = x;
    temp->prev = temp->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = *tail_ref = temp;
        return;
    }
    (*tail_ref)->next = temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
}

// A utility function to remove a node 'temp' fromt DLL.
// Note that the function may change head and tail pointers,
// that is why pointers to these pointers are passed.
void removeNode(struct node **head_ref,
                struct node **tail_ref, struct node *temp)
{
    if (*head_ref == NULL)
        return;

    if (*head_ref == temp)
        *head_ref = (*head_ref)->next;
    if (*tail_ref == temp)
        *tail_ref = (*tail_ref)->prev;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete (temp);
}

void findFirstNonRepeating()
{
    // inDLL[x] contains pointer to
    // a DLL node if x is present
    // in DLL. If x is not present, then inDLL[x] is NULL
    struct node *inDLL[MAX_CHAR];

    // repeated[x] is true if x is repeated two or more
    // times. If x is not seen so far or x is seen only
    // once. then repeated[x] is false
    bool repeated[MAX_CHAR];

    // Initialize the above two arrays
    struct node *head = NULL, *tail = NULL;
    for (int i = 0; i < MAX_CHAR; i++)
    {
        inDLL[i] = NULL;
        repeated[i] = false;
    }

    // Let us consider following stream and see the process
    char stream[] = "geeksforgeeksandgeeksquizfor";
    for (int i = 0; stream[i]; i++)
    {
        char x = stream[i];
        cout << "Reading " << x << " from stream \n";

        // We process this character only if it has not
        // occurred or occurred only once. repeated[x] is
        // true if x is repeated twice or more.s
        if (!repeated[x])
        {
            // If the character is not in DLL, then add this
            // at the end of DLL.
            if (inDLL[x] == NULL)
            {
                appendNode(&head, &tail, stream[i]);
                inDLL[x] = tail;
            }
            else // Otherwise remove this character from DLL
            {
                removeNode(&head, &tail, inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] = true; // Also mark it as repeated
            }
        }

        // Print the current first non-repeating character
        // from stream
        if (head != NULL)
            cout << "First non-repeating character so far "
                    "is "
                 << head->a << endl;
    }
}

int main()
{
    findFirstNonRepeating();
    return 0;
}*/
