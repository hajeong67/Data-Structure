#include <iostream>
using namespace std;
#define MAX_QUEUE_SIZE 100
class BinaryNode {
	int data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) {}
	~BinaryNode() {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }
};
class CircularQueue {
	int front;
	int rear;
	BinaryNode* data[MAX_QUEUE_SIZE];
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return(rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(BinaryNode* n) {
		if (isFull()) cout << "error: 큐가 포화상태입니다" << endl;
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}
	BinaryNode* dequeue() {
		if (isEmpty()) cout << "error: 큐가 공백상태입니다" << endl;
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};

class BinaryTree
{
protected: // Binary Search Tree class에 상속해 주는 멤버 변수입니다.
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) {}
	~BinaryTree() {}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }
	int getCount() { return isEmpty() ? 0 : getCount(root); };
	void inorder() {
		cout << "inorder: ";
		inorder(root);
	}
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft())
			+ getCount(node->getRight());
	}

	void levelorder();
	void inorder(BinaryNode* node);
};

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) {}
	~BinSrchTree(void) {}

	BinaryNode* search(int key);
	BinaryNode* search(BinaryNode* n, int key);
	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);

	void remove(int key);
	void remove(BinaryNode* parent, BinaryNode* node);
};

void BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << " [" << node->getData() << "] ";
		if (node->getRight() != NULL) inorder(node->getRight());
	}
}
void BinaryTree::levelorder() {
	cout << endl << "levelorder: ";
	if (!isEmpty()) {
		CircularQueue q;
		q.enqueue(root);
		while (!q.isEmpty()) {
			BinaryNode* n = q.dequeue();
			if (n != NULL) {
				cout << " [" << n->getData() << "] ";
				q.enqueue(n->getLeft());
				q.enqueue(n->getRight());
			}
		}
	}
	cout << endl;
}
BinaryNode* BinSrchTree::search(int key) {
	BinaryNode* node = search(root, key);
	if (node != NULL) { //key 값을 가진 노드를 찾으면 해당 노드의 데이터와 메모리 주소를 출력, 해당 노드를 반환하고
		cout << "키값은 " << node->getData() << " 노드는 " << node << endl;
		return node;
	}
	else { //만약 key 값을 가진 노드를 찾지 못하면 NULL을 반환
		cout << "failed. " << endl;
		return node;
	}
}
BinaryNode* BinSrchTree::search(BinaryNode* n, int key) {
	if (n == nullptr || n->data == key) {
		return n;
	}
	else if (key < n->data) {
		return search(n->left, key);
	}
	else {
		return search(n->right, key);
	}
}

void BinSrchTree::insert(BinaryNode* n) {
	if (n == NULL) return;
	if (isEmpty()) root = n;
	else insert(root, n);
}

void BinSrchTree::insert(BinaryNode* r, BinaryNode* n) {
	if (n->getData() == r->getData()) return;
	else if (n->getData() < r->getData()) {
		if (r->getLeft() == NULL) r->setLeft(n);
		else insert(r->getLeft(), n);
	}
	else {
		if (r->getRight() == NULL) r->setRight(n);
		else insert(r->getRight(), n);
	}
}

void BinSrchTree::remove(int key) {
	if (isEmpty()) return;

	BinaryNode* parent = NULL;
	BinaryNode* node = root;

	while (node != NULL && node->getData() != key) {
		parent = node;
		node = (key < node->getData()) ? node->getLeft() : node->getRight();
	}
	if (node == NULL) {
		cout << "Error: key is not in the tree!" << endl;
		return;
	}
	else remove(parent, node);
}

void BinSrchTree::remove(BinaryNode* parent, BinaryNode* node) {
	if (node->isLeaf()) {
		if (parent == NULL) root = NULL;
		else {
			if (parent->getLeft() == node)
				parent->setLeft(NULL);
			else
				parent->setRight(NULL);
		}
	}

	else if (node->getLeft() == NULL || node->getRight() == NULL) {
		BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
		if (node == root)
			root = child;
		else {
			if (parent->getLeft() == node)
				parent->setLeft(child);
			else
				parent->setRight(child);
		}
	}

	else {
		BinaryNode* succp = node;
		BinaryNode* succ = node->getRight();
		BinaryNode* succp2 = node;
		BinaryNode* succ2 = node->getLeft();
		int leftmost, rightmost;

		while (succ->getLeft() != NULL) {
			succp = succ;
			succ = succ->getLeft();
		}

		while (succ2->getRight() != NULL) {
			succp2 = succ2;
			succ2 = succ2->getRight();
		}

		leftmost = succ->getData() - node->getData();
		rightmost = node->getData() - succ2->getData();
		if (leftmost < rightmost) {
			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());

			node->setData(succ->getData());
			node = succ;
		}
		else if (leftmost > rightmost) {
			if (succp2->getRight() == succ2)
				succp2->setRight(succ2->getLeft());
			else
				succp2->setLeft(succ2->getLeft());

			node->setData(succ2->getData());
			node = succ2;
		}
	}
	delete node;
}
int BinSrchTree::getHeight(BinaryNode* n) {
	if (n == nullptr) {
		return -1; // 노드가 없는 경우 높이는 -1
	}
	else {
		int left_height = getHeight(n->left); // 왼쪽 서브트리의 높이 계산
		int right_height = getHeight(n->right); // 오른쪽 서브트리의 높이 계산
		return 1 + std::max(left_height, right_height); // 높은 값에 1을 더하여 현재 노드의 높이를 계산
	}
}

int main()
{
	BinSrchTree tree;
	int temp_in = 0;
	int num_of_nodes = 10;
	int arr[10];
	arr[0] = 35;
	arr[1] = 18;
	arr[2] = 7;
	arr[3] = 26;
	arr[4] = 12;
	arr[5] = 3;
	arr[6] = 68;
	arr[7] = 22;
	arr[8] = 30;
	arr[9] = 99;

	cout << "삽입 연산을 수행하여 이진탐색트리를 만듭니다." << endl;
	cout << "[삽입연산] : ";
	for (int i = 0; i < num_of_nodes; i++) {
		tree.insert(new BinaryNode(arr[i]));
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	tree.inorder();
	tree.levelorder();

	cout << endl << "BST 정보 출력" << endl;
	cout << "노드 개수: " << tree.getCount() << endl;

	cout << endl << "26을 찾습니다. " << endl;
	tree.search(26);
	cout << endl << "25를 찾습니다. " << endl;
	tree.search(25);

	cout << endl << "Original BST 정보 출력" << endl;
	tree.levelorder();
	cout << "3 삭제" << endl;
	tree.remove(3);
	tree.levelorder();
	cout << "삭제 후 BST 정보 출력" << endl;
	cout << "노드 개수: " << tree.getCount() << endl;

	return 0;
}