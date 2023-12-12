#include "seal/seal.h"

using namespace std;
using namespace seal;

#ifndef UTIL_H
#define UTIL_H
SEALContext get_context();
#endif

class HHE {
    public:
        int keyGen(int lambda);
};
