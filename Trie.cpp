/*// Construct a trie from scratch
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MAXN 100001
#define INF 1e18+1
struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}*/
/*//Implement Trie – 2 (Prefix Tree)
#include <bits/stdc++.h>

using namespace std;
struct Node {
  Node * links[26];
  int cntEndWith = 0;
  int cntPrefix = 0;

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }
  Node * get(char ch) {
    return links[ch - 'a'];
  }
  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
  void increaseEnd() {
    cntEndWith++;
  }
  void increasePrefix() {
    cntPrefix++;
  }
  void deleteEnd() {
    cntEndWith--;
  }
  void reducePrefix() {
    cntPrefix--;
  }
  int getEnd() {
    return cntEndWith;
  }
  int getPrefix() {
    return cntPrefix;
  }
};
class Trie {
  private:
    Node * root;

  public:
    // Initialize your data structure here.
    Trie() {
      root = new Node();
    }

  // Inserts a word into the trie.
  void insert(string word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node -> containsKey(word[i])) {
        node -> put(word[i], new Node());
      }
      node = node -> get(word[i]);
      node -> increasePrefix();
    }
    node -> increaseEnd();
  }

 int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }


  int countWordsStartingWith(string & word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
      } else {
        return 0;
      }
    }
    return node -> getPrefix();
  }

  void erase(string & word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
        node -> reducePrefix();
      } else {
        return;
      }
    }
    node -> deleteEnd();
  }
};

int main() {
  Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
  <<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  return 0;
}*/
/*// power set
#include<bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main()
{
	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}
}*/
/*// Find shortest unique prefix for every word in a given list
#include <bits/stdc++.h>
using namespace std;
#define MAX 256
#define MAX_WORD_LEN 500
struct trieNode
{
    struct trieNode *child[MAX];
    int freq;
};
struct trieNode *newTrieNode(void)
{
    struct trieNode *newNode = new trieNode;
    newNode->freq = 1;
    for (int i = 0; i < MAX; i++)
        newNode->child[i] = NULL;
    return newNode;
}

void insert(struct trieNode *root, string str)
{
    int len = str.length();
    struct trieNode *pCrawl = root;
    for (int level = 0; level < len; level++)
    {
        int index = str[level];
        if (!pCrawl->child[index])
            pCrawl->child[index] = newTrieNode();
        else
            (pCrawl->child[index]->freq)++;
        pCrawl = pCrawl->child[index];
    }
}
void findPrefixesUtil(struct trieNode *root, char prefix[], int ind)
{
    if (!root)
        return;
    if (root->freq == 1)
    {
        prefix[ind] = '\0';
        cout << prefix << " ";
        return;
    }
    for (int i = 0; i < MAX; i++)
    {
        if (root->child[i] != NULL)
        {
            prefix[ind] = i;
            findPrefixesUtil(root->child[i], prefix, ind + 1);
        }
    }
}
void findPrefixes(string arr[], int n)
{
    struct trieNode *root = newTrieNode();
    root->freq = 0;
    for (int i = 0; i < n; i++)
        insert(root, arr[i]);
    char prefix[MAX_WORD_LEN];
    findPrefixesUtil(root, prefix, 0);
}
int main()
{
    string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr) / sizeof(arr[0]);
    findPrefixes(arr, n);
    return 0;
}*/
/*// Word Break Problem | (Trie solution)
#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 26;
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}
bool wordBreak(string str, TrieNode *root)
{
    int size = str.size();
    if (size == 0)
        return true;
    for (int i = 0; i <= size; i++)
    {
        if (search(root, str.substr(0, i)) &&
            wordBreak(str.substr(i, size - i), root))
            return true;
    }
    return false;
}
int main()
{
    string dictionary[] = {"mobile", "samsung", "sam",
                           "sung", "ma\n", "mango",
                           "icecream", "and", "go", "i",
                           "like", "ice", "cream"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    struct TrieNode *root = getNode();
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);

    wordBreak("ilikesamsung", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("iiiiiiii", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmango", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmangok", root) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}*/
/*// Given a sequence of words, print all anagrams together
//string 1305
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

// structure for each word of duplicate array
class Word {
public:
	char* str; // to store word itself
	int index; // index of the word in the original array
};

// structure to represent duplicate array.
class DupArray {
public:
	Word* array; // Array of words
	int size; // Size of array
};

// Create a DupArray object that contains an array of Words
DupArray* createDupArray(char* str[], int size)
{
	// Allocate memory for dupArray and all members of it
	DupArray* dupArray = new DupArray();
	dupArray->size = size;
	dupArray->array = new Word[(dupArray->size * sizeof(Word))];

	// One by one copy words from the given wordArray to dupArray
	int i;
	for (i = 0; i < size; ++i) {
		dupArray->array[i].index = i;
		dupArray->array[i].str = new char[(strlen(str[i]) + 1)];
		strcpy(dupArray->array[i].str, str[i]);
	}

	return dupArray;
}

// Compare two characters. Used in qsort() for
// sorting an array of characters (Word)
int compChar(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}

// Compare two words. Used in qsort()
// for sorting an array of words
int compStr(const void* a, const void* b)
{
	Word* a1 = (Word*)a;
	Word* b1 = (Word*)b;
	return strcmp(a1->str, b1->str);
}

// Given a list of words in wordArr[],
void printAnagramsTogether(char* wordArr[], int size)
{
	// Step 1: Create a copy of all words present in given wordArr.
	// The copy will also have original indexes of words
	DupArray* dupArray = createDupArray(wordArr, size);

	// Step 2: Iterate through all words in dupArray and sort
	// individual words.
	int i;
	for (i = 0; i < size; ++i)
		qsort(dupArray->array[i].str,
			strlen(dupArray->array[i].str), sizeof(char), compChar);

	// Step 3: Now sort the array of words in dupArray
	qsort(dupArray->array, size, sizeof(dupArray->array[0]), compStr);

	// Step 4: Now all words in dupArray are together, but these
	// words are changed. Use the index member of word struct to
	// get the corresponding original word
	for (i = 0; i < size; ++i)
		cout << wordArr[dupArray->array[i].index] << " ";
}

// Driver program to test above functions
int main()
{
	char* wordArr[] = { "cat", "dog", "tac", "god", "act" };
	int size = sizeof(wordArr) / sizeof(wordArr[0]);
	printAnagramsTogether(wordArr, size);
	return 0;
}*/
/*// Implement a Phone Directory
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	// Each Trie Node contains a Map 'child'
	// where each alphabet points to a Trie
	// Node.
	// We can also use a fixed size array of
	// size 256.
	unordered_map<char,TrieNode*> child;

	// 'isLast' is true if the node represents
	// end of a contact
	bool isLast;

	// Default Constructor
	TrieNode()
	{
		// Initialize all the Trie nodes with NULL
		for (char i = 'a'; i <= 'z'; i++)
			child[i] = NULL;

		isLast = false;
	}
};

// Making root NULL for ease so that it doesn't
// have to be passed to all functions.
TrieNode *root = NULL;

// Insert a Contact into the Trie
void insert(string s)
{
	int len = s.length();

	// 'itr' is used to iterate the Trie Nodes
	TrieNode *itr = root;
	for (int i = 0; i < len; i++)
	{
		// Check if the s[i] is already present in
		// Trie
		TrieNode *nextNode = itr->child[s[i]];
		if (nextNode == NULL)
		{
			// If not found then create a new TrieNode
			nextNode = new TrieNode();

			// Insert into the Map
			itr->child[s[i]] = nextNode;
		}

		// Move the iterator('itr') ,to point to next
		// Trie Node
		itr = nextNode;

		// If its the last character of the string 's'
		// then mark 'isLast' as true
		if (i == len - 1)
			itr->isLast = true;
	}
}

// This function simply displays all dictionary words
// going through current node. String 'prefix'
// represents string corresponding to the path from
// root to curNode.
void displayContactsUtil(TrieNode *curNode, string prefix)
{
	// Check if the string 'prefix' ends at this Node
	// If yes then display the string found so far
	if (curNode->isLast)
		cout << prefix << endl;

	// Find all the adjacent Nodes to the current
	// Node and then call the function recursively
	// This is similar to performing DFS on a graph
	for (char i = 'a'; i <= 'z'; i++)
	{
		TrieNode *nextNode = curNode->child[i];
		if (nextNode != NULL)
			displayContactsUtil(nextNode, prefix + (char)i);
	}
}

// Display suggestions after every character enter by
// the user for a given query string 'str'
void displayContacts(string str)
{
	TrieNode *prevNode = root;

	string prefix = "";
	int len = str.length();

	// Display the contact List for string formed
	// after entering every character
	int i;
	for (i=0; i<len; i++)
	{
		// 'prefix' stores the string formed so far
		prefix += (char)str[i];

		// Get the last character entered
		char lastChar = prefix[i];

		// Find the Node corresponding to the last
		// character of 'prefix' which is pointed by
		// prevNode of the Trie
		TrieNode *curNode = prevNode->child[lastChar];

		// If nothing found, then break the loop as
		// no more prefixes are going to be present.
		if (curNode == NULL)
		{
			cout << "nNo Results Found for "" << prefix
				<< "" n";
			i++;
			break;
		}

		// If present in trie then display all
		// the contacts with given prefix.
		cout << "nSuggestions based on "" << prefix
			<< "" are n";
		displayContactsUtil(curNode, prefix);

		// Change prevNode for next prefix
		prevNode = curNode;
	}

	// Once search fails for a prefix, we print
	// "Not Results Found" for all remaining
	// characters of current query string "str".
	for (; i<len; i++)
	{
		prefix += (char)str[i];
		cout << "nNo Results Found for "" << prefix
			<< "" n";
	}
}

// Insert all the Contacts into the Trie
void insertIntoTrie(string contacts[],int n)
{
	// Initialize root Node
	root = new TrieNode();

	// Insert each contact into the trie
	for (int i = 0; i < n; i++)
		insert(contacts[i]);
}

// Driver program to test above functions
int main()
{
	// Contact list of the User
	string contacts[] = {"gforgeeks" , "geeksquiz"};

	// Size of the Contact List
	int n = sizeof(contacts)/sizeof(string);

	// Insert all the Contacts into Trie
	insertIntoTrie(contacts, n);

	string query = "gekk";

	// Note that the user will enter 'g' then 'e', so
	// first display all the strings with prefix as 'g'
	// and then all the strings with prefix as 'ge'
	displayContacts(query);

	return 0;
}*/
/*// Print unique rows in a given boolean matrix
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5
void findUniqueRows(int M[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            flag = 1;
            for (int k = 0; k <= COL; k++)
                if (M[i][k] != M[j][k])
                    flag = 0;
            if (flag == 1)
                break;
        }
        if (flag == 0)
        {
            for (int j = 0; j < COL; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
    }
}

int main()
{
    int M[ROW][COL] = {{0, 1, 0, 0, 1},
                       {1, 0, 1, 1, 0},
                       {0, 1, 0, 0, 1},
                       {1, 0, 1, 0, 0}};

    findUniqueRows(M);
    return 0;
}*/
