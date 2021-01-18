﻿#include <csignal>
#include <iostream>

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
int scan
(RingList<T>& list, T data)
{
    int index;
    DoublyLinkedRingList<T>* Joja = list.first;
    if (Joja != nullptr)
    {
        for (int i = 0; i < list.size; ++i)
        {
            if (Joja->data == data)
            {
                std::cout << i << std::endl;
                return i;
            }
            Joja = Joja->next;
        }
    }
    return 0;
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

    int value = 22;
    std::cout << std::endl << " scan " << std::endl;
    scan(test_int, value);
    print(test_int);

    return 0;
}