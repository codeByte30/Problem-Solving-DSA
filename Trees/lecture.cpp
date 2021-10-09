#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class node {
public:
	int data;
	node*left, *right;
	node(int data) {
		this->data = data;
		left = right = NULL;
	}
};
node*createTree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}
	node*root = new node(d);
	root->left = createTree();
	root->right = createTree();
	return root;
}
void inorder(node*root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node*root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

void solve(node*root, int d, map<int, vector<int>>&m) {
	if (root == NULL) return;
	m[d].push_back(root->data);
	solve(root->left, d - 1, m);
	solve(root->right, d + 1, m);
}
void levelOrder(node*root) {
	queue<node*>q;
	q.push(root);
	while (!q.empty()) {
		node*f = q.front();
		q.pop();
		cout << f->data << " ";
		if (f->left) {
			q.push(f->left);
		}
		if (f->right) {
			q.push(f->right);
		}
	}
}
void levelOrderLevelWise(node*root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	vector<vector<int>>ans; // levelwise store
	vector<int>curr; // stores element in curr level
	while (!q.empty()) {
		node*f = q.front();
		q.pop();
		if (f == NULL) {
			// cout << endl;
			ans.push_back(curr);
			curr.clear();
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			// cout << f->data << " ";
			curr.push_back(f->data);
			if (f->left) {
				q.push(f->left);
			}
			if (f->right) {
				q.push(f->right);
			}
		}
	}
	for (auto x : ans) {
		for (auto ele : x) {
			cout << ele << " ";
		}
		cout << endl;
	}
}
void leftView(node*root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	vector<vector<int>>ans; // levelwise store
	vector<int>curr; // stores element in curr level
	while (!q.empty()) {
		node*f = q.front();
		q.pop();
		if (f == NULL) {
			// cout << endl;
			ans.push_back(curr);
			curr.clear();
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			// cout << f->data << " ";
			curr.push_back(f->data);
			if (f->left) {
				q.push(f->left);
			}
			if (f->right) {
				q.push(f->right);
			}
		}
	}
	for (auto x : ans) {
		cout << x.front() << " ";
	}
	cout << endl;
}
void rightView(node*root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	vector<vector<int>>ans; // levelwise store
	vector<int>curr; // stores element in curr level
	while (!q.empty()) {
		node*f = q.front();
		q.pop();
		if (f == NULL) {
			// cout << endl;
			ans.push_back(curr);
			curr.clear();
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			// cout << f->data << " ";
			curr.push_back(f->data);
			if (f->left) {
				q.push(f->left);
			}
			if (f->right) {
				q.push(f->right);
			}
		}
	}
	for (auto x : ans) {
		cout << x.back() << " ";
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node*root = NULL;
	root = createTree();
	// inorder(root);
	// cout << endl;
	// map<int, vector<int>>m;
	// solve(root, 0, m);
	// for (auto p : m) {
	// 	cout << p.first << " --> ";
	// 	for (int x : p.second) {
	// 		cout << x << ", ";
	// 	}
	// 	cout << endl;
	// }
	// levelOrder(root);
	levelOrderLevelWise(root);
	leftView(root);
	rightView(root);
	return 0;
}