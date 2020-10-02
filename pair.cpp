//
// Created by sakost on 02.10.2020.
//

#include "pair.h"

namespace NPair {
    template<typename F, typename S>
    TPair<F, S>::TPair(F first, S second) {
        this->First = first;
        this->Second = second;
    }

    template<typename F, typename S>
    bool TPair<F, S>::operator<(const TPair &other) {
        if(First == other.First){
            return Second < other.Second;
        }
        return First < other.First;
    }


}

