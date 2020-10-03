//
// Created by sakost on 02.10.2020.
//

#ifndef LAB1_SORT_H
#define LAB1_SORT_H

#include <cinttypes>
#include <limits>
#include <cassert>

#include "vector.h"
#include "pair.h"

namespace NSort{
    using TKey = std::uint64_t;
    using TValue = std::uint64_t;

    NPair::TPair<TKey, TValue> MaxElement(const NVector::TVector<NPair::TPair<TKey, TValue>> &vector){
        NPair::TPair<TKey, TValue> maxElement = vector[0];

        for (size_t i = 0; i < vector.Size(); ++i) {
            if(maxElement < vector[i]){
                maxElement = vector[i];
            }
        }
        return maxElement;
    }
    NPair::TPair<TKey, TValue> MinElement(const NVector::TVector<NPair::TPair<TKey, TValue>> &vector){
        NPair::TPair<TKey, TValue> minElement = vector[0];

        for (size_t i = 0; i < vector.Size(); ++i) {
            if(vector[i] < minElement){
                minElement = vector[i];
            }
        }
        return minElement;
    }

    void InsertionSort(NVector::TVector<NPair::TPair<TKey, TValue>> &vector){
        if(vector.Size() == 0){
            return;
        }
        for (long long i = 1; i < vector.Size(); ++i) {
            NPair::TPair<TKey, TValue > key = vector[i];
            long long j = i-1;

            while (j >= 0 && vector[j].First > key.First){
                vector[j+1] = vector[j];
                j--;
            }
            vector[j+1] = key;
        }
    }

    void BucketSort(NVector::TVector<NPair::TPair<TKey, TValue>> &vector){
        if(vector.Size() == 0){
            return;
        }
        
        NVector::TVector<NVector::TVector<NPair::TPair<TKey, TValue>>> buckets(vector.Size());


        const NPair::TPair<TKey, TValue> minElement = MinElement(vector);
        const NPair::TPair<TKey, TValue> maxElement = MaxElement(vector);
        const long double interval = (long double)(maxElement.First - minElement.First + 1) / vector.Size();

        for (size_t i = 0; i < vector.Size(); ++i) {
            TKey i1 = (TKey)((vector.At(i).First - minElement.First) / interval);
            if(i1 == vector.Size()){
                i1--;
            }
            NPair::TPair<TKey, TValue> element = vector.At(i);
            buckets.At(i1).PushBack(element);
        }

        for (size_t i = 0; i < vector.Size(); ++i) {
            InsertionSort(buckets.At(i));
        }

        size_t k = 0;
        for (size_t i = 0; i < buckets.Size(); ++i) {
            for (size_t j = 0; j < buckets.At(i).Size(); ++j) {
                vector.At(k++) = buckets.At(i).At(j);
            }
        }

        assert(k == vector.Size());
    }
}


#endif //LAB1_SORT_H
