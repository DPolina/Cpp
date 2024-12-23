class Complex {

public:

	Complex();
	Complex(int r, int fi);
	Complex(const Complex& other);
	~Complex() = default;

	friend std::ostream& operator<<(ostream& s, const Complex& c) {

		cout << c.r << "(cos" << c.fi << " + isin" << c.fi << ") " << endl;

		return s;
	}

	friend std::istream& operator>>(istream& s, Complex& c) {

		cin >> c.r >> c.fi;

		return s;
	}

	Complex operator + (const Complex& other);
	Complex operator - (const Complex& other);
	Complex operator * (const Complex& other);
	Complex operator / (const Complex& other);
	//c = a + b
	
	Complex sqrt();
	Complex pow(double k);

private:

	double r;
	double fi;
};