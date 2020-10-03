//
// Created by sakost on 02.10.2020.
//

#ifndef LAB1_PAIR_H
#define LAB1_PAIR_H


namespace NPair {

    template<typename F, typename S>
    class TPair {
    public:
        TPair(){
            First = 0;
            Second = 0;
        }

        TPair(F first, S second){
            this->First = first;
            this->Second = second;
        }

        TPair(const TPair &other){
            First = other.First;
            Second = other.Second;
        }

        ~TPair()= default;

        bool operator<(const TPair &other) const{
            if(First == other.First){
                return Second < other.Second;
            }
            return First < other.First;
        }

        TPair &operator=(const TPair &other) {
            First = other.First;
            Second = other.Second;
            return *this;
        }


        F First;
        S Second;
    };
}


#endif //LAB1_PAIR_H
