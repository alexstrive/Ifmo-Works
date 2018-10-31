//
// Created by Alexey Novopashin on 28/05/2018.
//

#ifndef LABWORK5_VECTOR_H
#define LABWORK5_VECTOR_H


template<class T>
class Vector {
private:
    typedef T *Iterator;
    T *values;
    unsigned size;
    unsigned lastIndex = 0;

    /**
     * Метод, предназаченный для расширения
     * Существующего буфера значений
     * При каждом вызове буффер увеличивается в 2 раза
     */
    void expand() {
        auto newSize = size * 2;
        auto *newValues = new T[newSize];

        for (int i = 0; i < size; i++) {
            newValues[i] = values[i];
        }

        delete values;

        setSize(newSize);
        setValues(newValues);
    }

    void setValues(T *values) {
        Vector::values = values;
    }

    void setSize(unsigned int size) {
        Vector::size = size;
    }

    void expandIfOverflow() {
        if (lastIndex == size - 1) {
            expand();
        }
    }

public:
    explicit Vector(unsigned initialSize = 1) : size(initialSize) {
        values = new T[initialSize];
    }

    /**
     * Добавление в конец
     */
    void push(T value) {
        expandIfOverflow();
        values[lastIndex] = value;
        lastIndex += 1;
    }

    /**
     * Удаление с конца
     */
    void pop() {
        lastIndex -= 1;
    }

    /**
     * Добавление начального элемента
     */
    void unshift(T value) {
        expandIfOverflow();
        for (int i = size; i != -1; i--) {
            values[i + 1] = values[i];
        }
        values[0] = value;
        lastIndex += 1;
    }

    /**
     * Удаление начального элемента
     */
    void shift() {
        for (int i = 1; i < size; i++) {
            values[i - 1] = values[i];
        }
        lastIndex -= 1;
    }


    /**
     * Получение итератора на начало
     */
    Iterator begin() {
        return values;
    }

    /**
     * Получение итератора на конец
     */
    Iterator end() {
        return values + lastIndex;
    }

    /**
     * Получение по индексу
     * @param index интересущий индекс
     * @return Значение по индексу
     */
    T &operator[](unsigned int index) {
        return values[index];1
    }
};


#endif //LABWORK5_VECTOR_H
