#include "seal/seal.h"

using namespace std;
using namespace seal;

SEALContext get_context();

class HHE {
    public:
        int keyGen(int lambda);
};
