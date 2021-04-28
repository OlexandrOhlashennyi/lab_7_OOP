#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class arr {
private:
	vector<T> v;
	unsigned size;
public:
	arr() { };
	arr(unsigned s) { 
		size = s;
		for (int i = 0; i < s; i++) {
			v.push_back({});
		}
	};
	~arr() { }
	void add(T elem) { v.push_back(elem);  size++; }
	T& operator[](int i) {
		if (i >= size)
			return v[size - 1];
		if(i < 0)
			return v[0];
		return v[i];
	}
	friend ostream& operator << (ostream& os, arr<T>& a) {
		if (a.size == NULL)
			return os;
		os << "[ ";
		for (auto it = a.v.begin(); it != a.v.end()-1; it++)
			os << *it << ", ";
		os << *(a.v.end()-1) << " ]";
		return os;
	}

	friend istream& operator >> (istream& is, arr<T>& a) {
		T elem;
		for (int i = 0; i < a.size; i++) {
			is >> elem;
			a.v[i] = elem;
		}
		return is;
	}

	unsigned search(T elem) {
		int i;
		for (i = 0; i != size; i++) {
			if (v[i] == elem)
				break;
		}
		if (i == size)
			return -1;
		return i;
	}
};

int main() {
	arr<string> a(5);
	cin >> a;
	cout << a << endl;
	cout << a.search("aq");

	return 0;
}