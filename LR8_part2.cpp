#include <iostream>
#include <string>

using namespace std;

template<typename T, unsigned int S>
struct List
{
	T* nodes[S];
	int size;
};

template<typename T, unsigned int S>
void constuctor(List<T, S>& list)
{
	list.size = 0;
	for (int i = 0; i < S; i++)
	{
		list.nodes[i] = nullptr;
	}
}

template<typename T, unsigned int S>
int addEnd(List<T, S>& list, T data)
{
	if (list.size < S)
	{
		T* newNode = new T{ data };
		list.nodes[list.size] = newNode;
		list.size++;
		return 0;
	}
	else
	{
		return 0;
	}
}

template<typename T, unsigned int S>
int addIndex(List<T, S>& list, T data, int index)
{
	if (list.size < S)
	{
		T* newNode = new T{ data };
		for (int i = list.size; i > index; i--)
		{
			list.nodes[i] = list.nodes[i - 1];
		}
		list.nodes[index] = newNode;
		list.size++;
		return 0;
	}
	else
	{
		return 0;
	}
}

template<typename T, unsigned int S>
T popForth(List<T, S>& list)
{
	if (list.size != 0)
	{
		T data = *list.nodes[0];
		for (unsigned int i = 0; i < list.size - 1; i++)
		{
			list.nodes[i] = list.nodes[i + 1];
		}
		list.nodes[list.size - 1] = nullptr;
		list.size--;
		return data;
	}
	else
	{
		cout << "list clear!" << endl;
		retorn 1;
	}
}

template<typename T, unsigned int S>
T
popBack(List<T, S>& list)
{
	if (list.size != 0)
	{
		T data = *list.nodes[list.size - 1];
		list.nodes[list.size - 1] = nullptr;
		list.size--;
		return data;
	}
	else
	{
		cout << "list clear!" << endl;
		retorn 1;
	}
}

template<typename T, unsigned int S>
T
popIndex(List<T, S>& list, unsigned int index)
{
	if (index > list.size)
	{
		cout << "Index too big!" << endl;
		return 1;
	}
	else
	{
		T data = *list.nodes[index];
		for (unsigned int i = index; i < list.size - 1; i++)
		{
			list.nodes[i] = list.nodes[i + 1];
		}
		list.nodes[list.size - 1] = nullptr;
		list.size--;
		return data;
	}
}

template<typename T, unsigned int S>
T
ExtractionIndex(List<T, S>& list, unsigned int index)
{
	return *list.nodes[index];
}

template<typename T, unsigned int S>
unsigned int
findPos(List<T, S>& list, T data)
{
	for (unsigned int i = 0; i < list.size; ++i)
	{
		if (*list.nodes[i] == data)
		{
			return i;
		}
	}
	return list.size;
}

template<typename T, unsigned int S>
void print(List<T, S>& list)
{
	for (int i = 0; i < list.size; i++)
	{
		cout << *list.nodes[i] << ", ";
	}
}

template<typename T, unsigned int S>
unsigned long int
size(List<T, S>& list)
{
	return list.size;
}

template<typename T, unsigned int S>
void
destructor(List<T, S>& list)
{
	list.size = 0;
	for (int i = 0; i < S; i++)
	{
		list.nodes[i] = 0;
	}
}

class Human
{
public:
	string name;
	int age;

};

std::ostream&
operator<<(std::ostream& out, Human obj)
{
	out << obj.age << " " << obj.name;
	return out;
}

bool
operator==(Human& a, Human& b)
{
	return a.age == b.age;
}

int main()
{
	List<int, 10> Joja;
	constuctor(Joja);
	addEnd(Joja, 2);
	addEnd(Joja, 3);
	addEnd(Joja, 4);
	addEnd(Joja, 5);
	addEnd(Joja, 6);
	addEnd(Joja, 7);
	addEnd(Joja, 8);
	print(Joja);
	popForth(Joja);
	cout << endl;
	print(Joja);
	popBack(Joja);
	cout << endl;
	print(Joja);
	popIndex(Joja, 3);
	cout << endl;
	print(Joja);
	cout << endl << "Size -- " << size(Joja);
	cout << endl << "What in 1st element -- " << ExtractionIndex(Joja, 0);
	cout << endl << "What pos element 4 --  " << findPos(Joja, 4);
	destructor(Joja);

	cout << endl;
	cout << endl;
	cout << endl;

	Human firstMan, secondMan, thirdMan;
	firstMan.age = 20;
	firstMan.name = "Pora";
	secondMan.age = 30;
	secondMan.name = "Gora";
	thirdMan.age = 40;
	thirdMan.name = "Vora";

	List<Human, 10> People;
	constuctor(People);
	print(People);
	addEnd(People, firstMan);
	addEnd(People, secondMan);
	addEnd(People, thirdMan);
	print(People);
	cout << endl;
	std::cout << "Pos 3 man in massiv -- " << findPos(People, thirdMan) << std::endl;
	destructor(People);
	print(People);
	return 0;
}
