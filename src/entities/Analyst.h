#include "seal/seal.h"

using namespace std;
using namespace seal;

class Analyst{
    public:
        Analyst(int64_t test);

    private:
        //--- Todo: from example read over 
        vector<int64_t> w{17, 31, 24, 17}; // dummy weights
        vector<int64_t> b{-5, -5, -5, -5}; // dummy biases
        Ciphertext w_c;                    // the encrypted weights
        Ciphertext b_c;                    // the encrypted biases
        PublicKey he_pk;
        SecretKey he_sk;
        RelinKeys he_rk;
        GaloisKeys he_gk;

        void init();

        void print(string str){
            cout << "[Analyst] " << str << endl;
        }
};  

Analyst::Analyst(int64_t test) {
    print("Create Analyst");
    init();
};

void Analyst::init() {
    print("--- Analyst::init ---");
    print("create HE parameters and HE context");

    SEALContext context = get_context();

    cout << endl;
}
