class Vector {

public:

	Vector();
	Vector(int size);
	Vector(const Vector& other);
	~Vector();

	void set_size(int size);
	int get_size() const;
	void fill(int min, int max);
	void fill(int max);
	void print();
	
	int& operator [] (int index);
	const int& operator [] (int index) const;
	Vector& operator++(int index);

	void push_back(int el);

private:

	int size;
	int* arr;

};