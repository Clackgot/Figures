#include <iostream>
#include <set>
#include <vector>
#include <time.h>

using namespace std;


template<class Type>
class MultSet
{
private:
	multiset<Type> _mset;

public:

	MultSet(unsigned int size)
	{
		srand((unsigned int)time(0));
		if (size > 0 && size < 500)
		{
			for (size_t i = 0; i < size; i++)
			{
				_mset.insert((rand() % 1000) / (Type)100);
			}
		}
		else
		{
			_mset = multiset<Type>();
		}
		
	}

	void print()
	{
		for (auto it : _mset)
		{
			printf("[%.1f]", it);
		}
		cout << endl;
	}

	void addFirst()
	{
		_mset.insert(*_mset.begin());
	}

	void removeGreaterThenAver()
	{
		Type aver = 0;

		for (auto it : _mset)
		{
			aver += it;
		}
		aver /= _mset.size();
		cout << "Среднее значение -> " << aver << endl;
		

		vector<Type> vec;

		for (auto &it : _mset)
		{
			if (it > aver)
			{
				cout << "Удалено значение -> " << it << endl;
				//ts.erase(it);
				vec.push_back(it);
			}
		}

		for (auto it : vec)
		{
			_mset.erase(it);
		}
	}

	void multipleMaxVal()
	{
		auto iter = --_mset.end();
		multiset<Type> tt;
		cout << "Максимальный элемент: " << *iter << endl;
		for (auto & it : _mset)
		{
			tt.insert(it *    (*iter)    );
		}
		
		_mset = tt;
	}

};


int main()
{
	setlocale(LC_ALL, "");
	auto tt = MultSet<float>(10);
	tt.print();
	tt.addFirst();
	tt.print();
	tt.removeGreaterThenAver();
	tt.print();
	tt.multipleMaxVal();
	tt.print();
}
