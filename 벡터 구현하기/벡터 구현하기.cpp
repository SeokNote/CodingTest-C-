#include <vector>
#include <iostream>
template <typename T>
//typedef int T;
class Myvector
{
public:
	Myvector()
	{

	}

	Myvector(size_t _size)
	{
		m_begin = new T[_size]();
		m_capacity = _size;
		m_size = _size;
	}
	~Myvector()
	{
		delete[] m_begin;
	}

	T& operator[] (size_t _index)
	{
		return m_begin[_index];
	}

	size_t size()
	{
		return m_size;
	}

	size_t capacity()
	{
		return m_capacity;
	}

	void resize(size_t _Size) // size와capacity 재설정.
	{
		reserve(_Size);
		m_size = _Size;
	}

	void reserve(size_t _Size) //새로 공간을 할당. size는 그대로 capacity만 재설정
	{
		T* CopyArr = m_begin;
		m_begin = new T[_Size]();
		m_capacity = _Size;
		for (size_t i = 0; i < m_size; i++)
		{
			m_begin[i] = CopyArr[i];
		}
		delete[] CopyArr;

	}

	void clear() // 사이즈만 0으로
	{
		m_size = 0;
	}

	void push_back(const T& _Value)
	{
		if (m_size + 1 > m_capacity)
		{
			reserve(m_capacity * 2);
		}
		m_begin[m_size + 1] = _Value;
		m_size++;
	}

	class iterator
	{
		friend Myvector;
	public:
		iterator& operator++()
		{
			++iter;
			return *this;
		}
		T& operator*()
		{
			return *iter;
		}
		bool operator != (const iterator& _iter)
		{
			return _iter.iter != iter;
		}

		bool operator == (const iterator& _iter)
		{
			return _iter.iter == iter;
		}
	private:
		iterator(T* _Index)
			: iter(_Index)
		{

		}
		T* iter = nullptr;

	};
	iterator begin()
	{
		return iterator(m_begin);
	}
	iterator end()
	{
		return iterator(&m_begin[m_size]);
	}
private:
	T* m_begin = nullptr;
	size_t m_capacity = 0;
	size_t m_size = 0;
};

int main()
{
	std::vector<long> v;
	std::vector<long>::iterator iter;
	iter = v.begin();
	v.resize(10);
	v.reserve(10);
	//int& Num = v[3];
	v.clear();
	v.push_back(1.1);
	int c = 0;
	v.clear();
	int a = 0;
	Myvector<int> myv(10);
	Myvector<int>::iterator StartIter = myv.begin();
	Myvector<int>::iterator EndIter = myv.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		std::cout << *StartIter << std::endl;
	}
	int b = myv[4];
	myv.clear();
	myv.reserve(20);
	myv.capacity();

	return 0;
}

//메모리의 영역과 동적할당.
