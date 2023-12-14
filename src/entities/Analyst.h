#include "seal/seal.h"
#include "Helper.h"

using namespace std;
using namespace seal;

class Analyst{
    public:
        PublicKey he_pk;

        Analyst();
        void generate_HHE_keys();
        message send_m1();
        message send_m3();
        void receive_m4(message m4);
        void decrypt_HHE();
        void print_result();
    private:
        //--- Todo: from example read over 
        vector<int64_t> w{17, 31, 24, 17}; // dummy weights
        vector<int64_t> b{-5, -5, -5, -5}; // dummy biases
        Ciphertext w_c;                    // the encrypted weights
        Ciphertext b_c;                    // the encrypted biases
        SecretKey he_sk;                   // HE Decryption Key
        RelinKeys he_rk;
        GaloisKeys he_gk;

        void init();

        void print(string str){
            cout << "[Analyst] " << str << endl;
        }
};  

Analyst::Analyst() {
    print("Create Analyst");
};

void Analyst::generate_HHE_keys() {
    print("Generating HHE keys");
    // A generates their key
    // Run HHE.KeyGen -> (pkA, skA, evkA)
    //Use Encryption Parameters for the Analyst
    SEALContext context = get_context();
    tuple<PublicKey, SecretKey, RelinKeys> ret = HHE::keyGen(context);

    he_pk = get<0>(ret);
    he_sk = get<1>(ret);
    he_rk = get<2>(ret);
}

message Analyst::send_m1() {
    message ret;
    // m1 = (t1, Enc(pkCSP, evk), sigA(H(t1||evk))))
    return ret;
}

message Analyst::send_m3() {
    message ret;
    return ret;
}

void Analyst::receive_m4(message m4) {
    
    // decrypt result
    decrypt_HHE();
}

// 1. Decrypt results using the secret key sk and SEAL decrypt function
//--- "PASTA_SEAL::decrypt_result()" to decrypt it.
void Analyst::decrypt_HHE() {
    // sets res
}

void Analyst::print_result() {

}

// BatchEncoder analyst_he_benc(*context);
// Encryptor analyst_he_enc(*context, Analyst.he_pk);
// Evaluator analyst_he_eval(*context);
// bool use_bsgs = false;
// vector<int> gk_indices = add_gk_indices(use_bsgs, analyst_he_benc);
// keygen.create_galois_keys(gk_indices, Analyst.he_gk);
// print_line(__LINE__);
// // Decryptor analyst_he_dec(*context, Analyst.he_sk);
// print_line(__LINE__);
// cout << "Analyst encrypts his weights and biases" << endl;
// print_vec(Analyst.w, Analyst.w.size(), "Analyst.w");
// print_vec(Analyst.b, Analyst.b.size(), "Analyst.b");
// Analyst.w_c = encrypting(Analyst.w, Analyst.he_pk, analyst_he_benc, analyst_he_enc);
// Analyst.b_c = encrypting(Analyst.b, Analyst.he_pk, analyst_he_benc, analyst_he_enc);
// vector<int64_t> w_d = decrypting(Analyst.w_c, Analyst.he_sk, analyst_he_benc, *context, Analyst.w.size());
// vector<int64_t> b_d = decrypting(Analyst.b_c, Analyst.he_sk, analyst_he_benc, *context, Analyst.b.size());