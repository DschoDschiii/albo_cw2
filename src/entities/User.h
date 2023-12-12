#include "seal/seal.h"

class User {
    public:
        User(uint64_t id){
            cout << "[User#" << id << "] Creating user" << endl;
        };
    private:
        //--- Todo: from example read over
        vector<uint64_t> ssk; // the secret symmetric keys
        vector<uint64_t> x_i{0, 1, 2, 3};
        vector<uint64_t> c_i;        // symmetric encrypted x_i
        std::vector<Ciphertext> c_k; // the HE encrypted symmetric keys
};