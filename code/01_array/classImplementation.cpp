#include <iostream>
using namespace std;


class Array
{
public:
	Array(int size = 10) : size_(0), cap_(size)
	{
		array = new int[cap_];
	}
	~Array()
	{
		delete[] array;
		array = nullptr;
	}
public:
	void push_back(int val)
	{
		if (size_ == cap_)
		{
			expand(2 * cap_);
		}
		array[size_++] = val;
	}

	void pop_back()
	{
		if (size_ == 0)
		{
			throw "empty array";
		}
		size_--;
	}

	void insert(int pos, int val)
	{
		if (pos<0 || pos>size_)
		{
			throw "valid pos";
		}
		if (size_ == cap_)
		{
			expand(2 * cap_);
		}
		for (int i = size_; i >= pos+1; i--)
		{
			array[i] = array[i - 1];
		}
		array[pos] = val;
		size_++;
	}
	void erase(int pos)
	{
		if (pos<0 || pos>=size_)
		{
			throw "valid pos";
		}
		for (int i = pos+1; i < size_; i++)
		{
			array[i-1] = array[i];
		}
		size_--;
	}

	void show()
	{
		for (int i = 0; i < size_; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}



private:
	void expand(int size)
	{
		int* p = new int[size];
		memcpy(p, array, size_ * sizeof(int));
		delete[] array;
		array = p;
		cap_ = size;
	}
private:
	int* array;
	int size_;
	int cap_;
};

int main()
{
	Array arr;
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(i);
	}

}