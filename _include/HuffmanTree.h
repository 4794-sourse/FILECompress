#pragma once

#include <iostream>
#include <assert.h>
#include <queue>
#include <vector>

template <typename T>
struct HuffmanTreeNode {
	HuffmanTreeNode(const T &data)
		: _weight(data)
		, pLeft(NULL)
		, pRight(NULL)
		, pParent(NULL)
	{}

	T 		_weight;
	HuffmanTreeNode *pLeft;
	HuffmanTreeNode *pRight;
	HuffmanTreeNode *pParent;
};

template <typename T>
struct greater {
	bool operator()(const T &left, const T &right) {
		return left->_weight > right->_weight;
	}
};


template <typename T>
class HuffmanTree {
public:
	HuffmanTree(const T *weight, int size, const T &invalid) : pRoot(NULL) , _invalid(invalid) {
		assert(NULL != weight && size >= 0);
		_Create(weight, size);
	}

	~HuffmanTree() { _Destroy(pRoot); }

	HuffmanTreeNode<T> * GetRoot() { return pRoot; }

	void LevelTraverse();

private:
	void _Destroy(HuffmanTreeNode<T> * &pRoot);

	void _Create(const T *weight, int size);

private:
	HuffmanTreeNode<T>	*pRoot; // 哈夫曼树的头节点
	T					_invalid; // CodeInfo类型，初始化一个默认值，该字符的出现频次为0。
};

template <typename T>
void HuffmanTree<T>::LevelTraverse() {
	std::queue<HuffmanTreeNode<T> *> q;
	if (NULL != pRoot)
		q.push(pRoot);

	while (!q.empty()) {
		HuffmanTreeNode<T> *pCur = q.front();
		q.pop();
		std::cout << pCur->_weight << " ";

		if (NULL != pCur->pLeft)
			q.push(pCur->pLeft);
		if (NULL != pCur->pRight)
			q.push(pCur->pRight);
	}

	std::cout << std::endl;
}

template <typename T>
void HuffmanTree<T>::_Destroy(HuffmanTreeNode<T> * &pRoot) {
	if (NULL != pRoot) {
		_Destroy(pRoot->pLeft);
		_Destroy(pRoot->pRight);
		delete pRoot;
		pRoot = NULL;
	}
}

template <typename T>
void HuffmanTree<T>::_Create(const T *weight, int size) {
	if (0 == size) { 
		return;
	} else if (1 == size) {
		if (*weight != _invalid) // 该字符出现的频次不为0，就建立一个节点
			pRoot = new HuffmanTreeNode<T>(*weight);
	} else {
		std::priority_queue<HuffmanTreeNode<T> *, std::vector<HuffmanTreeNode<T>* >, greater<HuffmanTreeNode<T>*> > heap;

		for (int i = 0; i < size; ++i) {
			if (weight[i] != _invalid) {
				HuffmanTreeNode<T> *tmp = new HuffmanTreeNode<T>(weight[i]);
				heap.push(tmp);
			}
		}

		HuffmanTreeNode<T> *pLeft, *pRight;
		while (heap.size() >= 2) {
			pLeft = heap.top();
			heap.pop();
			pRight = heap.top();
			heap.pop();

			HuffmanTreeNode<T> *pParent = new HuffmanTreeNode<T>(pLeft->_weight + pRight->_weight);
			pParent->pLeft = pLeft;
			pParent->pRight = pRight;
			pLeft->pParent = pParent;
			pRight->pParent = pParent;

			heap.push(pParent);
		}
		if (!heap.empty())
			pRoot = heap.top();
	}
}