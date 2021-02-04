#include <csignal>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct DoublyLinkedRingList
{
    DoublyLinkedRingList<T>* previous;
    DoublyLinkedRingList<T>* next;
    T data;
};

template<typename T>
struct RingList
{
    DoublyLinkedRingList<T>* first;
    int size;
};

template<typename T>
void constructor(RingList<T>& list)
{
    list.first = nullptr;
    list.size = 0;
}

template<typename T>
int size(RingList<T>& list)
{
    return list.size;
}

template<typename T>
void push_forth(RingList<T>& list, T data)
{
    DoublyLinkedRingList<T>* Joja = new DoublyLinkedRingList<T>;
    Joja->data = data;
    if (list.first == nullptr)
    {
        list.first = Joja;
        Joja->next = Joja;
        Joja->previous = Joja;
    }
    else
    {
        list.first->previous->next = Joja;
        Joja->previous = list.first->previous;
        list.first->previous = Joja;
        Joja->next = list.first;
        list.first = Joja;
    }
    list.size++;
}

template<typename T>
void pushBack(RingList<T>& list, T data)
{
    DoublyLinkedRingList<T>* Joja = new DoublyLinkedRingList<T>;
    Joja->data = data;
    if (list.first == nullptr)
    {
        list.first = Joja;
        Joja->next = Joja;
        Joja->previous = Joja;
    }
    else
    {
        list.first->previous->next = Joja;
        Joja->previous = list.first->previous;
        list.first->previous = Joja;
        Joja->next = list.first;
    }
    list.size++;
}

template <typename T>
void incert
(RingList<T>& list, T data, int index)
{
    DoublyLinkedRingList<T>* Joja = new DoublyLinkedRingList<T>;
    Joja->next = list.first;
    Joja->data = data;
    for (int i = 0; i < index; ++i)
    {
        Joja->next = Joja->next->next;
    }
    Joja->previous = Joja->next->previous;
    Joja->next->previous = Joja;
    Joja->previous->next = Joja;
    list.size++;
}

template <typename T>
void incertPointer
(RingList<T>& list, T data, DoublyLinkedRingList<T>* a)
{
    DoublyLinkedRingList<T>* Joja = new DoublyLinkedRingList<T>;
    Joja->data = data;
    Joja->next = a->next;
    Joja->previous = a;
    Joja->next->previous = Joja;
    Joja->previous->next = Joja;
    list.size++;
}

template<typename T>
T popFirst(RingList<T>& list)
{
    T data;
    if (list.first != nullptr)
    {
        DoublyLinkedRingList<T>* a = list.first;
        list.first->previous->next = list.first->next;
        list.first = list.first->next;
        list.first->previous = a->previous;
        data = a->data;
        delete a;
        list.size--;
    }
    return data;
}

template<typename T>
T popEnd(RingList<T>& list)
{
    T data;
    if (list.first != nullptr)
    {
        DoublyLinkedRingList<T>* a = list.first->previous;
        list.first->previous = list.first->previous->previous;
        list.first->previous->next = list.first;
        data = a->data;
        delete a;
        list.size--;
    }
    return data;
}

template <typename T>
T exstract
(RingList<T>& list, int index)
{
    T data;
    DoublyLinkedRingList<T>* Joja = list.first;
    for (int i = 0; i < index; ++i)
    {
        Joja = Joja->next;
    }
    if (Joja != nullptr)
    {
        Joja->next->previous = Joja->previous;
        Joja->previous->next = Joja->next;
        data = Joja->data;
        delete Joja;
        list.size--;
    }
    return data;
}

template <typename T>
T exstractPointer
(RingList<T>& list, DoublyLinkedRingList<T>* a)
{
    T data;
    DoublyLinkedRingList<T>* Joja = list.first;
    if (a == list.first)
    {
        a = list.first->next;
    }
    if (a != nullptr)
    {
        Joja = a;
        Joja->next->previous = Joja->previous;
        Joja->previous->next = Joja->next;
        data = Joja->data;
        delete Joja;
        list.size--;
    }
    return data;
}

template <typename T>
T GetByIndex
(RingList<T>& list, int index)
{
    T data;
    DoublyLinkedRingList<T>* Joja = list.first;
    if (Joja != nullptr)
    {
        for (int i = 0; i < index; ++i)
        {
            Joja = Joja->next;
        }
        data = Joja->data;
        std::cout << data << std::endl;
    }
    return data;
}

template <typename T>
int scan(RingList<T>& list, T data) {
    int index = 0;
    DoublyLinkedRingList<T>* gg = list.first;
    while (gg->data != data)
    {
        gg = gg->next;
        ++index;
        if (gg == list.first)
        {
            cout << "No element " << endl;
            return -1;
        }
    }
    return index;
}

template <typename T>
void print(RingList<T>& list)
{
    DoublyLinkedRingList<T>* a = list.first;
    for (int i = 0; i < list.size; ++i)
    {
        std::cout << a->data << ' ';
        a = a->next;
    }
}

template<typename T>
void destructor(RingList<T>& list)
{
    for (int i = 1; i < list.size; i++)
    {
        list.first = list.first->next;
        delete list.first->previous;
    }
    delete list.first;
    list.first = nullptr;
    list.size = 0;
    std::cout << "List clear" << std::endl;
}

class Human
{
public:
    string name;
    int age;
};

std::ostream&
operator<<(std::ostream& out, Human& obj)
{
    out << obj.age << " " << obj.name;
    return out;
}

int
main()
{
    RingList<int> test_int;
    constructor(test_int);

    std::cout << " push forth" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        push_forth(test_int, i);
    }
    print(test_int);

    std::cout << std::endl << " pushBack" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        pushBack(test_int, i);
    }
    print(test_int);

    int index = 4;
    std::cout << std::endl << " incert" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        incert(test_int, i, index);
    }
    print(test_int);

    std::cout << std::endl << " incert Pointer" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        incertPointer(test_int, i + 20, test_int.first->next->next);
    }
    print(test_int);

    std::cout << std::endl << " pop first" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        popFirst(test_int);
    }
    print(test_int);

    std::cout << std::endl << " pop end" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        popEnd(test_int);
    }
    print(test_int);

    std::cout << std::endl << " exstract " << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        exstract(test_int, index);
    }
    print(test_int);

    std::cout << std::endl << " exstract Pointer" << std::endl;
    for (int i = 0; i < 2; ++i)
    {
        exstractPointer(test_int, test_int.first);
    }
    print(test_int);

    std::cout << std::endl << " Get by index " << std::endl;
    GetByIndex(test_int, 2);
    print(test_int);

    int value = 2;
    std::cout << std::endl << " scan " << std::endl;
    std::cout << scan(test_int, value) << std::endl;
    print(test_int);

    std::cout << std::endl;
    destructor(test_int);


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

    RingList<Human> test_Human;
    constructor(test_Human);
    cout << endl << "------------------------------------------" << endl;
    pushBack(test_Human, firstMan);
    push_forth(test_Human, secondMan);
    pushBack(test_Human, thirdMan);
    print(test_Human);

    cout << endl << "------------------------------------------" << endl;
    popFirst(test_Human);
    popEnd(test_Human);
    print(test_Human);

    cout << endl << "------------------------------------------" << endl;
    destructor(test_Human);
    return 0;
}
