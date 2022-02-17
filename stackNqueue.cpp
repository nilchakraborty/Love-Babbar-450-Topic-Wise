/*// Implement Stack from Scratch
#include <bits/stdc++.h>
#define n 100
using namespace std;
class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "No element in stack" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;
    return 0;
}*/
/*// Implement Queue from Scratch
#include <bits/stdc++.h>
using namespace std;
#define n 20
class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void enqueue(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;

        if (front == -1)
        {
            front++;
        }
    }
    void dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in queue" << endl;
            return;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in queue" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.peek() << endl;
    q.dequeue();

    cout << q.empty() << endl;
    return 0;
}*/
/*// Implement 2 stack in an array
#include <bits/stdc++.h>
using namespace std;
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = n / 2 + 1;
        top2 = n / 2;
    }
    void push1(int x)
    {
        if (top1 > 0)
        {
            top1--;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack Overflow"
                 << " By element :" << x << endl;
            return;
        }
    }
    void push2(int x)
    {
        if (top2 < size - 1)
        {
            top2++;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack Overflow"
                 << " By element :" << x << endl;
            return;
        }
    }
    int pop1()
    {
        if (top1 <= size / 2)
        {
            int x = arr[top1];
            top1++;
            return x;
        }
        cout << "Stack underflow";
        exit(1);
    }
    int pop2()
    {
        if (top2 >= size / 2 + 1)
        {
            int x = arr[top2];
            top2--;
            return x;
        }
        cout << "STack Underflow";
        exit(1);
    }
};

int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << " : " << ts.pop1()
         << endl;
    ts.push2(40);
    cout << "Popped element from stack2 is "
         << ": " << ts.pop2()
         << endl;
    return 0;
}*/
/*// find the middle element of a stack
#include <bits/stdc++.h>
using namespace std;
class DLLNode
{
public:
    DLLNode *prev;
    int data;
    DLLNode *next;
};
class myStack
{
public:
    DLLNode *head;
    DLLNode *mid;
    int count;
};
myStack *createMyStack()
{
    myStack *ms = new myStack();
    ms->count = 0;
    return ms;
};
void push(myStack *ms, int new_data)
{
    DLLNode *new_DLLNode = new DLLNode();
    new_DLLNode->data = new_data;
    new_DLLNode->prev = NULL;
    new_DLLNode->next = ms->head;
    ms->count += 1;

    if (ms->count == 1)
    {
        ms->mid = new_DLLNode;
    }
    else
    {
        ms->head->prev = new_DLLNode;

        if (!(ms->count & 1))
            ms->mid = ms->mid->prev;
    }
    ms->head = new_DLLNode;
}
int pop(myStack *ms)
{
    if (ms->count == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    DLLNode *head = ms->head;
    int item = head->data;
    ms->head = head->next;
    if (ms->head != NULL)
        ms->head->prev = NULL;

    ms->count -= 1;
    if ((ms->count) & 1)
        ms->mid = ms->mid->next;

    free(head);

    return item;
}
int findMiddle(myStack *ms)
{
    if (ms->count == 0)
    {
        cout << "Stack is empty now\n";
        return -1;
    }

    return ms->mid->data;
}
int deletemiddle(myStack *ms)
{
    int temp = ms->mid->data;
    ms->mid->prev->next = ms->mid->next;
    ms->mid->next->prev = ms->mid->prev->next;

    delete ms->mid;
    ms->mid = ms->mid->next;
    return temp;
}
int main()
{
    myStack *ms = createMyStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);

    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    cout << "Deleted Middle Element is " << deletemiddle(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    return 0;
}*/
/*// Implement "N" stacks in an Array
#include <bits/stdc++.h>
using namespace std;
class kStacks
{
    int *arr;
    int *top;
    int *next;
    int n, k;
    int free;

public:
    kStacks(int k, int n);
    bool isFull() { return (free == -1); }
    void push(int item, int sn);
    int pop(int sn);
    bool isEmpty(int sn) { return (top[sn] == -1); }
};
kStacks::kStacks(int k1, int n1)
{
    k = k1, n = n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];
    for (int i = 0; i < k; i++)
        top[i] = -1;
    free = 0;
    for (int i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = -1;
}
void kStacks::push(int item, int sn)
{
    if (isFull())
    {
        cout << "\nStack Overflow\n";
        return;
    }

    int i = free;
    free = next[i];
    next[i] = top[sn];
    top[sn] = i;
    arr[i] = item;
}
int kStacks::pop(int sn)
{
    if (isEmpty(sn))
    {
        cout << "\nStack Underflow\n";
        return INT_MAX;
    }
    int i = top[sn];
    top[sn] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}
int main()
{
    int k = 3, n = 10;
    kStacks ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}*/
/*// Check the expression has valid or Balanced parenthesis or not.
string 416*/
/*// Reverse a String using Stack
#include <bits/stdc++.h>
using namespace std;
void reverse(string s)
{
    stack<string> stc;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            stc.push(temp);
            temp = "";
        }
        else
        {
            temp = temp + s[i];
        }
    }
    stc.push(temp);
    while (!stc.empty())
    {
        temp = stc.top();
        cout << temp << " ";
        stc.pop();
    }
    cout << endl;
}

int main()
{
    string s = "I Love To Code";
    reverse(s);
    return 0;
}*/
/*// Design a Stack that supports getMin() in O(1) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;
struct MyStack
{
    stack<int> s;
    int minEle;
    void getMin()
    {
        if (s.empty())
            cout << "Stack is empty\n";
        else
            cout << "Minimum Element in the stack is: "
                 << minEle << "\n";
    }
    void peek()
    {
        if (s.empty())
        {
            cout << "Stack is empty ";
            return;
        }

        int t = s.top();
        cout << "Top Most Element is: ";
        (t < minEle) ? cout << minEle : cout << t;
    }
    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();
        if (t < minEle)
        {
            cout << minEle << "\n";
            minEle = 2 * minEle - t;
        }
        else
            cout << t << "\n";
    }
    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            cout << "Number Inserted: " << x << "\n";
            return;
        }
        if (x < minEle)
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else
            s.push(x);

        cout << "Number Inserted: " << x << "\n";
    }
};
int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();

    return 0;
}*/
/*// Find the next Greater element
#include <bits/stdc++.h>
using namespace std;
void printNGE(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && s.top() < arr[i])
        {
            cout << s.top() << "--> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while (s.empty() == false)
    {
        cout << s.top() << "--> " << -1 << endl;
        s.pop();
    }
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}*/
/*// The celebrity Problem
#include <bits/stdc++.h>
#include <list>
using namespace std;
#define N 8
bool MATRIX[N][N] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0},
                     {0, 0, 1, 0}};

bool knows(int a, int b)
{
    return MATRIX[a][b];
}
int findCelebrity(int n)
{
    int indegree[n] = {0}, outdegree[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = knows(i, j);
            outdegree[i] += x;
            indegree[j] += x;
        }
    }
    for (int i = 0; i < n; i++)
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;
    return -1;
}
int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
    return 0;
}*/
// Arithmetic Expression evaluation
/*// Evaluation of Postfix expression
#include <iostream>
#include <string.h>
using namespace std;
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};
struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	if (!stack) return NULL;
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	if (!stack->array) return NULL;
	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

int evaluatePostfix(char* exp)
{
	struct Stack* stack = createStack(strlen(exp));
	int i;
	if (!stack) return -1;
	for (i = 0; exp[i]; ++i)
	{
		if (isdigit(exp[i]))
			push(stack, exp[i] - '0');
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i])
			{
			case '+': push(stack, val2 + val1); break;
			case '-': push(stack, val2 - val1); break;
			case '*': push(stack, val2 * val1); break;
			case '/': push(stack, val2/val1); break;
			}
		}
	}
	return pop(stack);
}
int main()
{
	char exp[] = "231*+9-";
	cout<<"postfix evaluation: "<< evaluatePostfix(exp);
	return 0;
}*/
// Implement a method to insert an element at its bottom without using any other data structure.
/*// Reverse a stack using recursion
#include <bits/stdc++.h>
using namespace std;
stack<char> st;
string ns;
char insert_at_bottom(char x)
{
    if (st.size() == 0)
        st.push(x);
    else
    {
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
        st.push(a);
    }
}
char reverse()
{
    if (st.size() > 0)
    {
        char x = st.top();
        st.pop();
        reverse();
        insert_at_bottom(x);
    }
}
int main()
{
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');

    cout << "Original Stack" << endl;

    cout << "1"
         << " "
         << "2"
         << " "
         << "3"
         << " "
         << "4"
         << endl;

    reverse();
    cout << "Reversed Stack"
         << endl;

    while (!st.empty())
    {
        char p = st.top();
        st.pop();
        ns += p;
    }

    cout << ns[3] << " " << ns[2] << " "
         << ns[1] << " " << ns[0] << endl;
    return 0;
}*/
/*// Sort a Stack using recursion
#include <iostream>
using namespace std;
struct stack
{
    int data;
    struct stack *next;
};
void initStack(struct stack **s) { *s = NULL; }
int isEmpty(struct stack *s)
{
    if (s == NULL)
        return 1;
    return 0;
}
void push(struct stack **s, int x)
{
    struct stack *p = (struct stack *)malloc(sizeof(*p));

    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    p->data = x;
    p->next = *s;
    *s = p;
}
int pop(struct stack **s)
{
    int x;
    struct stack *temp;

    x = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    free(temp);

    return x;
}
int top(struct stack *s) { return (s->data); }
void sortedInsert(struct stack **s, int x)
{
    if (isEmpty(*s) or x > top(*s))
    {
        push(s, x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s, temp);
}
void sortStack(struct stack **s)
{
    if (!isEmpty(*s))
    {
        int x = pop(s);
        sortStack(s);
        sortedInsert(s, x);
    }
}
void printStack(struct stack *s)
{
    while (s)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << "\n";
}
int main(void)
{
    struct stack *top;

    initStack(&top);
    push(&top, 30);
    push(&top, -5);
    push(&top, 18);
    push(&top, 14);
    push(&top, -3);

    cout << "Stack elements before sorting:\n";
    printStack(top);

    sortStack(&top);
    cout << "\n";

    cout << "Stack elements after sorting:\n";
    printStack(top);

    return 0;
}*/
/*// Merge Overlapping Intervals
array 403*/
/*// Largest rectangular Area in Histogram
#include <bits/stdc++.h>
using namespace std;
int getMaxArea(int hist[], int n)
{
    stack<int> s;
    int max_area = 0;
    int tp;
    int area_with_top;
    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}

int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist) / sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}*/
/*// Length of the Longest Valid Substring
#include <bits/stdc++.h>
using namespace std;
int findMaxLen(string str)
{
    int n = str.length();
    stack<int> s;
    s.push(-1);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            s.push(i);
        else
        {
            if (!s.empty())
            {
                s.pop();
            }
            if (!s.empty())
                result = max(result, i - s.top());
            else
                s.push(i);
        }
    }
    return result;
}
int main()
{
    string str = "((()()";
    cout << findMaxLen(str) << endl;

    str = "()(()))))";
    cout << findMaxLen(str) << endl;
    return 0;
}*/
/*// Expression contains redundant bracket or not
#include <bits/stdc++.h>
using namespace std;
bool checkRedundancy(string &str)
{
    stack<char> st;
    for (auto &ch : str)
    {
        if (ch == ')')
        {
            char top = st.top();
            st.pop();
            bool flag = true;

            while (!st.empty() and top != '(')
            {
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;
                top = st.top();
                st.pop();
            }
            if (flag == true)
                return true;
        }

        else
            st.push(ch);
    }
    return false;
}
void findRedundant(string &str)
{
    bool ans = checkRedundancy(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main()
{
    string str = "((a+b))";
    findRedundant(str);

    str = "(a+b)/c)";
    findRedundant(str);

    str = "(a+b*(c-d))";
    findRedundant(str);
    return 0;
}*/
/*// Implement Stack using Queue
#include <bits/stdc++.h>
using namespace std;
class Stack
{
    queue<int> q1, q2;
    int curr_size;

public:
    Stack()
    {
        curr_size = 0;
    }
    void push(int x)
    {
        curr_size++;
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;
    }
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }
    int size()
    {
        return curr_size;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size()
         << endl;
    return 0;
}*/
/*// Implement Stack using Deque
#include <bits/stdc++.h>
using namespace std;

struct DQueNode
{
    int value;
    DQueNode *next;
    DQueNode *prev;
};

class Deque
{
private:
    DQueNode *head;
    DQueNode *tail;

public:
    Deque()
    {
        head = tail = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    int size()
    {
        if (!isEmpty())
        {
            DQueNode *temp = head;
            int len = 0;
            while (temp != NULL)
            {
                len++;
                temp = temp->next;
            }
            return len;
        }
        return 0;
    }
    void insert_first(int element)
    {
        DQueNode *temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }
    void insert_last(int element)
    {
        DQueNode *temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }
    void remove_first()
    {
        if (!isEmpty())
        {
            DQueNode *temp = head;
            head = head->next;
            if (head)
                head->prev = NULL;
            delete temp;
            if (head == NULL)
                tail = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }
    void remove_last()
    {
        if (!isEmpty())
        {
            DQueNode *temp = tail;
            tail = tail->prev;
            if (tail)
                tail->next = NULL;
            delete temp;
            if (tail == NULL)
                head = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }
    void display()
    {
        if (!isEmpty())
        {
            DQueNode *temp = head;
            while (temp != NULL)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "List is Empty" << endl;
    }
};
class Stack : public Deque
{
public:
    void push(int element)
    {
        insert_last(element);
    }
    void pop()
    {
        remove_last();
    }
};
class Queue : public Deque
{
public:
    void enqueue(int element)
    {
        insert_last(element);
    }
    void dequeue()
    {
        remove_first();
    }
};
int main()
{
    Stack stk;

    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();

    stk.pop();
    cout << "Stack: ";
    stk.display();

    Queue que;

    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();

    que.dequeue();
    cout << "Queue: ";
    que.display();

    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}*/
/*// Stack Permutations (Check if an array is stack permutation of other)
#include <bits/stdc++.h>
using namespace std;
bool checkStackPermutation(int ip[], int op[], int n)
{
    queue<int> input;
    for (int i = 0; i < n; i++)
        input.push(ip[i]);

    queue<int> output;
    for (int i = 0; i < n; i++)
        output.push(op[i]);

    stack<int> tempStack;
    while (!input.empty())
    {
        int ele = input.front();
        input.pop();
        if (ele == output.front())
        {
            output.pop();
            while (!tempStack.empty())
            {
                if (tempStack.top() == output.front())
                {
                    tempStack.pop();
                    output.pop();
                }
                else
                    break;
            }
        }
        else
            tempStack.push(ele);
    }
    return (input.empty() && tempStack.empty());
}
int main()
{
    int input[] = {1, 2, 3};
    int output[] = {2, 1, 3};
    int n = 3;
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}*/
/*// Implement Queue using Stack
#include <bits/stdc++.h>
using namespace std;
struct Queue
{
    stack<int> s1, s2;
    void enQueue(int x)
    {
        s1.push(x);
    }
    int deQueue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Q is empty";
            exit(0);
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
};
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    return 0;
}*/
/*// Implement "n" queue in an array
#include <iostream>
#include <climits>
using namespace std;
class kQueues
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n, k;
    int free;

public:
    kQueues(int k, int n);
    bool isFull() { return (free == -1); }
    void enqueue(int item, int qn);
    int dequeue(int qn);
    bool isEmpty(int qn) { return (front[qn] == -1); }
};
kQueues::kQueues(int k1, int n1)
{
    k = k1, n = n1;
    arr = new int[n];
    front = new int[k];
    rear = new int[k];
    next = new int[n];
    for (int i = 0; i < k; i++)
        front[i] = -1;
    free = 0;
    for (int i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = -1;
}
void kQueues::enqueue(int item, int qn)
{
    if (isFull())
    {
        cout << "\nQueue Overflow\n";
        return;
    }
    int i = free;
    free = next[i];

    if (isEmpty(qn))
        front[qn] = i;
    else
        next[rear[qn]] = i;

    next[i] = -1;
    rear[qn] = i;
    arr[i] = item;
}
int kQueues::dequeue(int qn)
{
    if (isEmpty(qn))
    {
        cout << "\nQueue Underflow\n";
        return INT_MAX;
    }
    int i = front[qn];
    next[i] = free;
    free = i;
    return arr[i];
}
int main()
{
    int k = 3, n = 10;
    kQueues ks(k, n);
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);

    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;
    return 0;
}*/
/*// Implement a Circular queue
#include <iostream>
#define SIZE 5
using namespace std;

class Queue
{
private:
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    void enQueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full";
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << endl
                 << "Inserted " << element << endl;
        }
    }
    int deQueue()
    {
        int element;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return (-1);
        }
        else
        {
            element = items[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % SIZE;
            }
            return (element);
        }
    }

    void display()
    {
        int i;
        if (isEmpty())
        {
            cout << endl
                 << "Empty Queue" << endl;
        }
        else
        {
            cout << "Front -> " << front;
            cout << endl
                 << "Items -> ";
            for (i = front; i != rear; i = (i + 1) % SIZE)
                cout << items[i];
            cout << items[i];
            cout << endl
                 << "Rear -> " << rear;
        }
    }
};

int main()
{
    Queue q;

    q.deQueue();

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);

    q.display();

    int elem = q.deQueue();

    if (elem != -1)
        cout << endl
             << "Deleted Element is " << elem;

    q.display();

    q.enQueue(7);

    q.display();

    q.enQueue(8);

    return 0;
}*/
/*// LRU Cache Implementationa
#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
    list<int> dq;
    unordered_map<int, list<int>::iterator> max;
    int csize;

public:
    LRUCache(int);
    void refer(int);
    void display();
};
LRUCache::LRUCache(int n)
{
    csize = n;
}
void LRUCache::refer(int x)
{
    if (max.find(x) == max.end())
    {
        if (dq.size() == csize)
        {
            int last = dq.back();
            dq.pop_back();
            max.erase(last);
        }
    }
    else
        dq.erase(max[x]);
    dq.push_front(x);
    max[x] = dq.begin();
}
void LRUCache::display()
{
    for (auto it = dq.begin(); it != dq.end(); it++)
        cout << (*it) << " ";
    cout << endl;
}
int main()
{
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
    return 0;
}*/
/*// Reverse a Queue using recursion
#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
void printQueue(queue<lld> Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
void reverseQueue(queue<lld> &q)
{
    if (q.empty())
        return;
    lld data = q.front();
    q.pop();
    reverseQueue(q);
    q.push(data);
}
int main()
{
    queue<lld> Queue;
    Queue.push(56);
    Queue.push(27);
    Queue.push(30);
    Queue.push(45);
    Queue.push(85);
    Queue.push(92);
    Queue.push(58);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
    reverseQueue(Queue);
    printQueue(Queue);
    return 0;
}*/
/*// Reverse the first “K” elements of a queue
#include <bits/stdc++.h>
using namespace std;
void reverseQueueFirstKElements(
    int k, queue<int> &Queue)
{
    if (Queue.empty() == true || k > Queue.size())
        return;
    if (k <= 0)
        return;
    stack<int> Stack;
    for (int i = 0; i < k; i++)
    {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }
    for (int i = 0; i < Queue.size() - k; i++)
    {
        Queue.push(Queue.front());
        Queue.pop();
    }
}
void Print(queue<int> &Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
int main()
{
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);

    int k = 5;
    reverseQueueFirstKElements(k, Queue);
    Print(Queue);
}*/
/*// Interleave the first half of the queue with second half
#include <bits/stdc++.h>
using namespace std;
void interLeaveQueue(queue<int> &q)
{
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;
    stack<int> s;
    int halfSize = q.size() / 2;
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}*/
/*// Find the first circular tour that visits all Petrol Pumps
#include <bits/stdc++.h>
using namespace std;
class petrolPump
{
public:
    int petrol;
    int distance;
};
int printTour(petrolPump arr[], int n)
{
    int start = 0;
    int end = 1;
    int curr_petrol = arr[start].petrol - arr[start].distance;
    while (end != start || curr_petrol < 0)
    {
        while (curr_petrol < 0 && start != end)
        {
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1) % n;
            if (start == 0)
                return -1;
        }
        curr_petrol += arr[end].petrol - arr[end].distance;
        end = (end + 1) % n;
    }
    return start;
}
int main()
{
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
 
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);
 
    (start == -1)? cout<<"No solution": cout<<"Start = "<<start;
    return 0;
}*/
/*// Minimum time required to rot all oranges
#include <bits/stdc++.h>
using namespace std;
const int R = 3;
const int C = 5;
bool issafe(int i, int j)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}

int rotOranges(int v[R][C])
{
    bool changed = false;
    int no = 2;
    while (true)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (v[i][j] == no)
                {
                    if (issafe(i + 1, j) && v[i + 1][j] == 1)
                    {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j + 1) && v[i][j + 1] == 1)
                    {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i - 1, j) && v[i - 1][j] == 1)
                    {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j - 1) && v[i][j - 1] == 1)
                    {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }
        if (!changed)
            break;
        changed = false;
        no++;
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (v[i][j] == 1)
                return -1;
        }
    }
    return no - 2;
}
int main()
{
    int v[R][C] = {{2, 1, 0, 2, 1},
                   {1, 0, 1, 2, 1},
                   {1, 0, 0, 2, 1}};

    cout << "Max time incurred: " << rotOranges(v);
    return 0;
}*/
/*// Distance of nearest cell having 1 in a binary matrix
#include <bits/stdc++.h>
#define N 3
#define M 4
using namespace std;
void printDistance(int mat[N][M])
{
    int ans[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans[i][j] = INT_MAX;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
                for (int l = 0; l < M; l++)
                {
                    if (mat[k][l] == 1)
                        ans[i][j] = min(ans[i][j], abs(i - k) + abs(j - l));
                }
        }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int mat[N][M] =
    {
        0, 0, 0, 1,
        0, 0, 1, 1,
        0, 1, 1, 0
    };
    printDistance(mat);
    return 0;
}*/
/*// First negative integer in every window of size “k”
#include <bits/stdc++.h>
using namespace std;
void printFirstNegativeInteger(int arr[], int n, int k)
{
    bool flag;
    for (int i = 0; i < (n - k + 1); i++)
    {
        flag = false;
        for (int j = 0; j < k; j++)
        {
            if (arr[i + j] < 0)
            {
                cout << arr[i + j] << " ";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "0"
                 << " ";
    }
}
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, n, k);
    return 0;
}*/
/*// Check if all levels of two trees are anagrams or not.
BinaryTress 1324*/
/*// Sum of minimum and maximum elements of all subarrays of size “k”.
#include <bits/stdc++.h>
using namespace std;
int SumOfKsubArray(int arr[], int n, int k)
{
    int sum = 0;
    deque<int> S(k), G(k);
    int i = 0;
    for (i = 0; i < k; i++)
    {
        while ((!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back();
        while ((!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back();
        G.push_back(i);
        S.push_back(i);
    }
    for (; i < n; i++)
    {
        sum += arr[S.front()] + arr[G.front()];

        while (!S.empty() && S.front() <= i - k)
            S.pop_front();
        while (!G.empty() && G.front() <= i - k)
            G.pop_front();

        while ((!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back();

        while ((!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back();

        G.push_back(i);
        S.push_back(i);
    }
    sum += arr[S.front()] + arr[G.front()];
    return sum;
}
int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, n, k);
    return 0;
}*/
/*// Minimum sum of squares of character counts in a given string after removing “k” characters.
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
int minStringValue(string str, int k)
{
    int l = str.length();
 
    if (k >= l)
        return 0;
    int frequency[MAX_CHAR] = { 0 };
    for (int i = 0; i < l; i++)
        frequency[str[i] - 'a']++;

    priority_queue<int> q;
    for (int i = 0; i < MAX_CHAR; i++)
        q.push(frequency[i]);

    while (k--)
    {
        int temp = q.top();
        q.pop();
        temp = temp - 1;
        q.push(temp);
    }

    int result = 0;
    while (!q.empty())
    {
        int temp = q.top();
        result += temp * temp;
        q.pop();
    }
    return result;
}

int main()
{
    string str = "abbccc"; // Input 1
    int k = 2;
    cout << minStringValue(str, k) << endl;

    str = "aaab"; // Input 2
    k = 2;
    cout << minStringValue(str, k);
    return 0;
}*/
/*// Queue based approach or first non-repeating character in a stream.
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
void firstnonrepeating(char str[])
{
    queue<char> q;
    int charCount[MAX_CHAR] = {0};
    for (int i = 0; str[i]; i++)
    {
        q.push(str[i]);
        charCount[str[i] - 'a']++;
        while (!q.empty())
        {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty())
            cout << -1 << " ";
    }
    cout << endl;
}
int main()
{
    char str[] = "aabc";
    firstnonrepeating(str);
    return 0;
}*/
/*// Next Smaller Element
#include <bits/stdc++.h>
using namespace std;
void printNSE(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && s.top() > arr[i])
        {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while (s.empty() == false)
    {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}*/
