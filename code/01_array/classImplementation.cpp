#include <iostream>
using namespace std;

class Array
{
public:
    Array(int size = 0)
        : size_(size), cap_(10)
    {
        arr_ = new int[cap_];
    }

    ~Array()
    {
        delete[] arr_;
    }

public:
    void push_back(int val)
    {
        if (size_ == cap_)
        {
            expand(2 * cap_);
        }
        arr_[size_] = val;
        size_++;
    }

    void pop()
    {
        if (size_ != 0)
        {
            size_--;
        }
    }

    int find(int val)
    {
        for (int i = 0; i < size_; i++)
        {
            if (arr_[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    void insert(int pos, int val)
    {
        if (size_ == cap_)
        {
            expand(2 * cap_);
        }
        for (int i = size_; i >= pos; i++)
        {
            arr_[i] = arr_[i - 1];
        }
        arr_[pos] = val;
        size_++;
    }

    int erase(int pos)
    {
        if (size_ == 0)
        {
            throw "size is empty";
        }
        for (int i = pos; i < size_ - 1; i++)
        {
            arr_[i] = arr_[i + 1];
        }
        size_--;
    }
    void showInfo()
    {
        for (int i = 0; i < size_; i++)
        {
            cout << arr_[i] << " ";
        }
        cout << endl;
    }

    int &operator[](int index)
    {
        if (index < 0 || index > size_ - 1)
        {
            throw "valid index";
        }
        return arr_[index];
    }

private:
    void expand(int size)
    {
        int *p = new int[size];
        memcpy(p, arr_, size_ * sizeof(int));
        delete[] arr_;
        arr_ = p;
        cap_ = size;
    }

private:
    int *arr_;
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
    arr.showInfo();
}