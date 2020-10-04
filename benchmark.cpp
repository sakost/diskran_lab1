//
// Created by sakost on 03.10.2020.
//


#include "pair.h"
#include "vector.h"
#include "sort.h"

#include <iostream>
#include <cstdint>
#include <chrono>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    NVector::TVector<NPair::TPair<NSort::TKey , NSort::TValue>> v;
    NPair::TPair<NSort::TKey , NSort::TValue> pair;


    auto start = std::chrono::steady_clock::now();
    NSort::TKey key;
    NSort::TValue value;
    while (std::cin >> key >> value) {
        pair.First = key;
        pair.Second = value;
        v.PushBack(pair);
    }
    auto finish = std::chrono::steady_clock::now();
    auto dur = finish - start;
    std::cerr << "input " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    NSort::BucketSort(v);
    finish = std::chrono::steady_clock::now();
    dur = finish - start;
    std::cerr << "custom bucket sort " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" << std::endl;

    std::shuffle(v.Begin(), v.End());

    start = std::chrono::steady_clock::now();
    std::stable_sort(v.Begin(), v.End());
    finish = std::chrono::steady_clock::now();

    dur = finish - start;
    std::cerr << "stable sort from std " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < v.Size(); i++) {
        std::cout << v[i].First << ' ' << v[i].Second << '\n';
    }
    finish = std::chrono::steady_clock::now();
    dur = finish - start;
    std::cerr << "output " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" << std::endl;

    return 0;
}
