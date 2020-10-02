//
// Created by sakost on 17.09.2020.
//

#include "vector.h"

#include <exception>

namespace NVector {
    template<typename T>
    TVector<T>::TVector(size_t n) {
        Capacity = 2 * n;
        Len = n;
        Arr = malloc(sizeof(T) * Capacity);
    }

    template<typename T>
    TVector<T>::TVector() : TVector(1) {}

    template<typename T>
    size_t TVector<T>::Size() const {
        return Len;
    }

    template<typename T>
    TVector<T>::~TVector() {
        free(Arr);
    }

    template<typename T>
    void TVector<T>::PushBack(T element) {
        if (Len++ == Capacity) {
            Capacity = 2 * Capacity;
            Arr = realloc(Arr, sizeof(T) * Capacity);
        }
        Arr[Len - 1] = element;
    }

    template<typename T>
    void TVector<T>::PopBack() {
        Len--;
    }

    template<typename T>
    T TVector<T>::Back() const {
        return Arr[Len - 1];
    }

    template<typename T>
    T &TVector<T>::operator[](size_t n) {
        return Arr[n];
    }

    template<typename T>
    T &TVector<T>::At(size_t n) {
        if (n < 0 || n >= Len) {
            throw std::exception();
        }
        return (*this)[n];
    }



    template<typename T>
    TVector<T>::TVector(const TVector<T> &other) {
        Capacity = other.Capacity;
        Arr = realloc(Arr, sizeof(T) * Capacity);
        for (size_t i(0); i < other.Capacity; i++) {
            Arr[i] = other[i];
        }
    }


    template<typename T>
    void TVector<T>::Clear() {
        delete this;
        this = new TVector<T>();
    }

} // namespace NVector

