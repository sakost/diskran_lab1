//
// Created by sakost on 02.10.2020.
//

#ifndef LAB1_PAIR_H
#define LAB1_PAIR_H


namespace NPair {

    template<typename F, typename S>
    class TPair {
    public:
        TPair(F first, S second);

        bool operator<(const TPair &other);

        F First;
        S Second;
    };
}


#endif //LAB1_PAIR_H
