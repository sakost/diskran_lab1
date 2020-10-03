#pragma once

#include <stdexcept>
#include <cstring>


namespace NVector {
    const int DEFAULT_CAPACITY_MULTIPLIER = 2;

    template<typename T>
    class TVector {
    public:
        TVector(): Len(0) {
            Capacity = DEFAULT_CAPACITY_MULTIPLIER;
            Arr = new T[Capacity];
        }

        explicit TVector(size_t newSize, const T &defaultValue = T()) : TVector() {
            Len = newSize;
            if(Len == 0){
                Capacity = DEFAULT_CAPACITY_MULTIPLIER;
            } else {
                Capacity = newSize * DEFAULT_CAPACITY_MULTIPLIER;
            }
            delete []Arr;
            Arr = new T[Capacity];

            for (size_t i = 0; i < Len; ++i) {
                Arr[i] = defaultValue;
            }
        }

        [[nodiscard]] size_t Size() const {
            return Len;
        }

        [[nodiscard]] bool Empty() const {
            return Size() == 0;
        }

        [[maybe_unused]] T *Begin() const {
            return Arr;
        }

        [[maybe_unused]] T *End() const {
            if (Arr) {
                return Arr + Len;
            }
            return nullptr;
        }


        TVector(const TVector &other) : TVector(other.Size()) {
            if (other.Arr) {
                std::memcpy(Arr, other.Arr, sizeof(T) * Len);
            }
        }

        TVector &operator=(const TVector &other) {
            Clear();

            this->Len = other.Len;
            this->Capacity = other.Capacity;

            Arr = new T[this->Capacity];

            std::memcpy(Arr, other.Arr, sizeof(T) * Len);

            return *this;
        }

        ~TVector() {
            Clear();
        }

        void Clear(){
            delete[] Arr;

            Capacity = 0;
            Len = 0;
            Arr = nullptr;
        }

        [[maybe_unused]] void PushBack(T &element) {
            if (Len++ == Capacity) {
                Capacity = DEFAULT_CAPACITY_MULTIPLIER * Capacity;
                T *newArr = new T[Capacity];
                std::memcpy(newArr, Arr, (Capacity / DEFAULT_CAPACITY_MULTIPLIER) * sizeof(T));
                delete []Arr;
                Arr = newArr;
            }
            Arr[Len - 1] = element;
        }

        void PushBack(const T &&element){
            if (Len++ == Capacity) {
                Capacity = DEFAULT_CAPACITY_MULTIPLIER * Capacity;
                T *newArr = new T[Capacity];
                std::memcpy(newArr, Arr, (Capacity / DEFAULT_CAPACITY_MULTIPLIER) * sizeof(T));
                delete []Arr;
                Arr = newArr;
            }
            Arr[Len - 1] = element;
        }

        const T &At(size_t index) const {
//            if (index < 0 || index >= Len) {
//                throw std::out_of_range("Index is out of range");
//            }
            return Arr[index];
        }

        T &At(size_t index) {
            const T &elem = const_cast<const TVector *>(this)->At(index);
            return const_cast<T &>(elem);
        }

        const T &operator[](size_t index) const {
            return At(index);
        }

        T &operator[](size_t index) {
            return At(index);
        }

    private:
        size_t Len{};
        size_t Capacity{};
        T *Arr;
    };
}
