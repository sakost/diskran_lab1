#include <iostream>
#include <algorithm>

#include "vector.h"
#include "pair.h"
#include "sort.h"


using TData = NPair::TPair<NSort::TKey, NSort::TValue>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    NVector::TVector<TData> vector;

    NSort::TKey key;
    NSort::TValue value;
    while(std::cin >> key >> value){
        vector.PushBack(NPair::TPair<NSort::TKey, NSort::TValue>(key, value));
    }

    NSort::BucketSort(vector);

    for (int i = 0; i < vector.Size(); ++i) {
        std::cout << vector[i].First << ' ' << vector[i].Second << std::endl;
    }

    return 0;
}
