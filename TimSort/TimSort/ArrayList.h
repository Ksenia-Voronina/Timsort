#pragma once
#include <iostream>

using namespace std;

template <typename T>
class ArrayList
{
private:
    int size;
    int capacity;
    double* data;

    bool CheckIndex(int _index); //проверка на корректность позиции (индекса) в списке

public:

    ArrayList()
    {
        size = 0;
        capacity = 0;
        data = nullptr;
    }

    ArrayList(int size); //конструктор класса

    ~ArrayList(); //деструктор класса

    int Get(int _index); //возвращает элемент массива по определенному индексу

    int Size(); //возвращает размер массива

    void Resize(int new_size); //изменение размера массива

    void AddEnd(T _data); //добавление в конец массива

    void AddBegin(T _data, int _index);

    void Add(T _data, int _index); //добавление элемента в массив

    void Set(T _data, int _index); //изменение элемента по индексу

    void Clear(); //очистка списка

    void Remove(int _index); //удаление элемента из массива

    void Print();

};

template <typename T>
ArrayList<T>::ArrayList(int size)
{
    size = size;
    capacity = size;
    if (size != 0)
        data = new T[size];
    else
        data = 0;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    if (size > 0)
        delete[] data;
}

template <typename T>
int ArrayList<T>::Get(int _index) {
    if (CheckIndex(_index)) {
        cout << "Ќекорректный индекс" << endl;
        return -1;
    }
    //cout << data[_index] << "\n\n";
    return data[_index];
}

template <typename T>
int ArrayList<T>::Size() {
    return size;
}

template <typename T>
bool ArrayList<T>::CheckIndex(int _index) {
    return ((_index < 0) || (_index > size));
}

template <typename T>
void ArrayList<T>::Resize(int new_size) {
    if (new_size > capacity)
    {
        int new_capacity = max(new_size, size * 2);
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    size = new_size;
}

template <typename T>
void ArrayList<T>::Clear() {
    size = 0;
    int new_size = 2;
    T* data = new T[new_size];

    delete[] data;
}

template <typename T>
void ArrayList<T>::AddBegin(T _data, int _index) {
    for (int i = size - 1; i >= 0; i--) {
        if (i >= _index) {
            data[i + 1] = data[i];
        }
    }
    data[_index] = _data;
    size++;
}

template <typename T>
void ArrayList<T>::AddEnd(T _data) {
    Resize(size + 1);
    data[size - 1] = _data;
}

template <typename T>
void ArrayList<T>::Add(T _data, int _index) {
    if (CheckIndex(_index)) {
        cout << "Ќекорректный индекс" << endl;
        return;
    }

    for (int i = size - 1; i >= 0; i--) {
        if (i >= _index) {
            data[i + 1] = data[i];
        }
    }
    data[_index] = _data;
    size++;


}

template <typename T>
void ArrayList<T>::Set(T _data, int _index) {
    data[_index] = _data;
}

template <typename T>
void ArrayList<T>::Remove(int _index) {
    if (CheckIndex(_index)) {
        cout << "Ќекорректный индекс" << endl;
        return;
    }

    for (int i = _index + 1; i < size; i++) {
        data[i - 1] = data[i];
    }

    data[size--] = 0;
}

template <typename T>
void ArrayList<T>::Print() {
    cout << "ћассив List: ";

    if (size == 0) {
        cout << "пустой((" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
        cout << data[i] << " ";

    cout << endl;
}