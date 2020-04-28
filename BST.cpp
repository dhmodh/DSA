#include<iostream>
#include<queue>
#define NL cout<<endl;
using namespace std;

class BST;
class node
{
  private:
	int data;
	node *left, *right;
  public:
	  node(int d = 0, node * l = 0, node * r = 0)
	{
		data = d;
		left = l;
		right = r;
	}
	friend class BST;
};

class BST
{
  private:
	node * root;
	int level;
  public:
	  BST()
	{
		level = 1;
		root = 0;
	}
	int getlevel()
	{
		return level;
	}
	node *getroot()
	{
		return root;
	}
	void insert(int);
	void print(node *, int);
	void preorder(node *);
	void postorder(node *);
	void inorder(node *);
	void levelorder();
	void search(int);
	void del(int);
};

void BST::insert(int d)
{
	if (!root)
		root = new node(d);
	else
	{
		node *tmp = root;
		node *prev;
		int st = 0;
		while (tmp != 0)
		{
			prev = tmp;
			if (tmp->data > d)
			{
				tmp = tmp->left;
				st = 0;
			}
			else
			{
				tmp = tmp->right;
				st = 1;
			}
			level++;
		}
		if (!st)
			prev->left = new node(d);
		else
			prev->right = new node(d);
	}
}

void BST::print(node * r, int l)
{
	if (!r)
		return;
	l += 5;
	print(r->right, l);
	for (int i = 5; i <= l; i += 5)
		cout << "    ";
	cout << r->data << endl;
	print(r->left, l);
}

void BST::preorder(node * r)
{
	if (!r)
		return;
	cout << r->data << " ";
	preorder(r->left);
	preorder(r->right);
}

void BST::inorder(node * r)
{
	if (!r)
		return;
	inorder(r->left);
	cout << r->data << " ";
	inorder(r->right);
}

void BST::postorder(node * r)
{
	if (!r)
		return;
	postorder(r->left);
	postorder(r->right);
	cout << r->data << " ";
}

void BST::levelorder()
{
	queue < node * >Q;
	node *cur;
	Q.push(root);
	while (!Q.empty())
	{
		cur = Q.front();
		cout << cur->data << " ";
		if (cur->left)
			Q.push(cur->left);
		if (cur->right)
			Q.push(cur->right);
		Q.pop();
	}
}

void BST::search(int d)
{
	if (!root)
		cout << "Tree dose not exsist\n";
	else
	{
		int n = 1;
		node *cur = root;
		while (cur != 0 && cur->data != d)
		{
			if (cur->data > d)
				cur = cur->left;
			else
				cur = cur->right;
			n++;
		}
		if (!cur)
			cout << "Data not found in tree";
		else
			cout << d << " found at depth = " << n;
	NL}
}

void BST::del(int d)
{
	if(!root)
	cout<<"Tree does not exsist\n";
	else
	{
		node *cur=root;
		node *prev, *cur1=0;
		while(cur && cur->data!=d)
		{
			prev=cur;
			if(cur->data>d)
			cur=cur->left;
			else
			cur=cur->right;
		}
		if(cur->left)
		{
			prev->left=cur->right;
			cur1=cur->right;
		}
		if(cur->right)
		{
			prev->right=cur->left;
			cur1=cur->left;
		}
		while(cur1)
		{
			prev=cur1;
			cur1=cur1->left;
		}
		prev->left=cur->left;
		delete cur;
	}
}

int main()
{
	BST b;
	int n, ch;
	cout <<
		"1.Insert node in tree\n2.Print tree\n3.In order traversal\n4.In order traversal\n5.Post order traversal\n6.Level order traversal\n7.Seach element\n8.Delete element\n9.Exit\n";
	do
	{
		cout << "Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter number to insert : ";
			cin >> n;
			b.insert(n);
			break;
		case 2:
			cout << "Trees is look like :\n";
			b.print(b.getroot(), 0);
			break;
		case 3:
			cout << "Pre order traversal : ";
			b.preorder(b.getroot());
			NL break;
		case 4:
			cout << "In order traversal : ";
			b.inorder(b.getroot());
			NL break;
		case 5:
			cout << "Post order traversal : ";
			b.postorder(b.getroot());
			NL break;
		case 6:
			cout << "Level order traversal : ";
			b.levelorder();
			NL break;
		case 7:
			cout << "Enter number to search : ";
			cin >> n;
			b.search(n);
			break;
		case 8:
			cout << "Enter number to delete : ";
			cin >> n;
			b.del(n);
			break;
		case 9:
			exit(0);
		default:
			cout << "Invalid choice\n";
			break;
		}
	}
	while (true);
	return 0;
}
