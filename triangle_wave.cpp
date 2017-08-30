#include <iostream>
#include <array>
#include <string>

using namespace std;

class triangle_wave {
public:
	triangle_wave() : m_height(0), m_frequency(0) {}
	~triangle_wave() {}

	friend istream & operator >> (istream &is, triangle_wave &rhs);
	friend ostream & operator << (ostream &os, const triangle_wave &rhs);

private:
	size_t m_height;
	size_t m_frequency;
};

istream & operator >> (istream &is, triangle_wave &rhs) {
	is >> rhs.m_height >> rhs.m_frequency;

	return is;
}

ostream & operator << (ostream &os, const triangle_wave &rhs) {
	const static array<string, 9> slices = {
		string(1, '1'),
		string(2, '2'),
		string(3, '3'),
		string(4, '4'),
		string(5, '5'),
		string(6, '6'),
		string(7, '7'),
		string(8, '8'),
		string(9, '9'),
	};

	for (size_t j = 0; j < rhs.m_frequency; ++j) {
		for (size_t i = 0; i < rhs.m_height; ++i) os << slices[i] << endl;
		for (size_t i = rhs.m_height - 2; i >= 0 && i < slices.size(); --i) os << slices[i] <<endl;
		if (j != rhs.m_frequency - 1) os << endl;
	}

	return os;
}

int main() {
	size_t set_count = 0;
	cin >> set_count;

	while (set_count--) {
		triangle_wave w;
		cin >> w;
		cout << w;
		if (set_count > 0) cout << endl;
	}
}