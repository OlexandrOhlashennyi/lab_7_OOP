/*
-	формування вхідних даних заданого розміру;
-	збереження вхідних даних у файлі із заданою назвою,
з використанням перевантаженої операції виведення >>
для об’єктів розробленого класу;
-	зчитування вхідних даних із заданого файлу у об’єкти
розробленого класу з використанням перевантаженої операції
введення <<;
-	виведення результатів на екран або у файл.

На основі контейнера vector побудувати одновимірні масиви
цілих чисел та символьних рядків. Виконати операції введення
елементів у масив, послідовний пошук заданого елемента у
масиві і виведення його номера, виведення масиву на екран.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

	friend ofstream& operator << (ofstream& ofs, arr<T>& a) {
		if (a.size == NULL)
			return ofs;
		ofs << "[ ";
		for (auto it = a.v.begin(); it != a.v.end() - 1; it++)
			ofs << *it << ", ";
		ofs << *(a.v.end() - 1) << " ]";
		return ofs;
	}

	friend istream& operator >> (istream& is, arr<T>& a) {
		T elem;
		for (int i = 0; i < a.size; i++) {
			is >> elem;
			a.v[i] = elem;
		}
		return is;
	}

	friend ifstream& operator >> (ifstream& ifs, arr<T>& a) {
		T elem;
		for (int i = 0; i < a.size; i++) {
			ifs >> elem;
			a.v[i] = elem;
		}
		return ifs;
	}

	int search(T elem) {
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

template<class T>
void to_file(string fname, arr<T> a) {
	fstream file(fname, fstream::out | fstream::trunc);
	file << a;
	file.close();
}

template<class T>
void from_file(string fname, arr<T>& a) {
	fstream file(fname);
	file >> a;
	file.close();
}

int main() {
	arr<string> string_array(5);
	from_file("F:\\2_семестр\\лабораторні\\ООП\\лаб7\\in.txt", string_array);
	to_file("F:\\2_семестр\\лабораторні\\ООП\\лаб7\\out.txt", string_array);
	cout << string_array;

	int size;
	cout << "\n\n" << "input size of array: ";
	cin >> size;
	arr<int> int_array(size);
	cin >> int_array;
	cout << int_array;
	int elem, index;
	cout << "\n\nenter element to search: ";
	cin >> elem;
	index = int_array.search(elem);
	if (index == -1)
		cout << "not here" << endl;
	else
		cout << "element index: " << index << "\tand the value: " << int_array[index] << endl;
	return 0;
}