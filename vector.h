//
// Created by sakost on 17.09.2020.
//

#ifndef LAB1_VECTOR_H
#define LAB1_VECTOR_H

#include <cstdlib>

namespace NVector {
    template<typename T>
    class TVector {
    public:
        [[maybe_unused]] TVector();

        [[maybe_unused]] explicit TVector(size_t n);

        [[maybe_unused]] TVector(const TVector<T> &other);

        ~TVector();

        [[maybe_unused]] void Clear();

        [[maybe_unused]] void PushBack(T element);

        [[maybe_unused]] void PopBack();

        [[maybe_unused]] T Back() const;

        [[maybe_unused]] [[nodiscard]] size_t Size() const;

        [[maybe_unused]] T &operator[](size_t n);

        [[maybe_unused]] T &At(size_t n);

    private:
        T *Arr;
        size_t Capacity{}, Len{};
    };

} // namespace NVector

#endif //LAB1_VECTOR_H
