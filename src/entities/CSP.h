#include "seal/seal.h"

class CSP {
    public:
        // public key
        //--- Todo: from example read over 
        std::vector<Ciphertext> c_prime; // the decomposed HE encrypted data of user's c_i
        Ciphertext c_res;                // the HE encrypted results that will be sent to the Analyst
        SecretKey he_sk;

        CSP(uint64_t test) {
            cout << "[CSP] Creating CSP" << endl;
        };
};