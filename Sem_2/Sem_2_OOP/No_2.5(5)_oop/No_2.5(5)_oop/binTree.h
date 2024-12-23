template<class T>
class Node {

public:
	T data;
	Node* right;
	Node* left;
	int level;

	friend Node<T>* find_space(Node<T>* Root, T data) {

		Node<T>* p_cur = Root, * p_prev = Root;
		while (p_cur) {

			p_prev = p_cur;
			if (data < p_cur->data)
				p_cur = p_cur->left;
			else
				p_cur = p_cur->right;
		}
		return p_prev;
	}

	Node() = default;
	Node(T data = T(0), Node* right = nullptr, Node* left = nullptr) {
		this->data = data;
		this->right = right;
		this->left = left;
	}
};

template<class T>
class BinTree {

public:

	BinTree() = default;
	
	BinTree(const T& data) {
		add(data);
	};

	BinTree(const BinTree<T>& other) {
		copy_tree(Root, other.Root);
	}

	~BinTree() {
		del_tree(Root);
	}

	void copy_tree(Node<T>* Root1, Node<T>*& Root2) {

		if (Root1) {
			add(Root2, Root1->data);
			copy_tree(Root1->left, Root2);
			copy_tree(Root1->right, Root2);
		}
	}


	void add(const T& data) {

		Node<T>* new_Root = new Node<T>;
		new_Root->data = data;
		new_Root->left = nullptr;
		new_Root->right = nullptr;
		new_Root->level = 0;

		if (!Root) {
			Root = new_Root;
			new_Root->level = 1;
		}
		else {

			Node<T>* p_prev = find_space(Root, data); 
			
			if (data < p_prev->data)
				p_prev->left = new_Root;
			
			else
				p_prev->right = new_Root;

			new_Root->level = p_prev->level + 1;
		}
	}

	void del_tree(Node<T>*& Root) {
		if (Root) {
			del_tree(Root->left);
			del_tree(Root->right);
			delete Root;
			Root = nullptr;
		}
	}

	void del_el(const T& data) {

		if (Root->data == data) {
			del_tree(Root);
		}

		Node<T>* to_delete = find_el(Root, data);
		del_tree(to_delete);
	}

	Node<T> find_el(const T& data) {

		Node<T>* p_cur = Root, * p_prev = Root;

		if (p_cur->data == data) {
			return Root;
		}

		while (p_cur) {

			p_prev = p_cur;

			if (p_cur->data == data) {
				return p_prev;
			} 
			else if (data < p_cur->data) {
				p_cur = p_cur->left;
			}
			else {
				p_cur = p_cur->right;
			}
		}
	}

	void print_tree(Node<T>* Root) {

		if (Root) {
			print_tree(Root->left);
			std::cout << Root->data << " ";
			print_tree(Root->right);
		}
	}

	void print_tree_level() {
		print_tree_level(Root, 0);
	}

	int calc_level(int target) {
		return calc_level(Root, target, 1);
	}
	

private:


	void print_tree_level(Node<T>* Root, int level) {

		if (Root) {

			print_tree_level(Root->left, level + 1);

			for (int i = 0; i < level; i++) {
				std::cout << "      ";
			}
			std::cout << Root->data << std::endl;
			print_tree_level(Root->right, level + 1);
		}
	}

	int calc_level(Node<T>* Root, int level_target, int level_current = 1) {
		if (!Root)
			return 0;

		if (level_current == level_target)
			return 1;

		return calc_level(Root->left, level_target, level_current + 1) +
			calc_level(Root->right, level_target, level_current + 1);

	}

	Node<T>* Root = nullptr;
};