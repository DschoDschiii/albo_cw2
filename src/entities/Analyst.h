#include "seal/seal.h"
#include "Helper.h"

using namespace std;
using namespace seal;

class Analyst{
    public:
        PublicKey he_pk;

        Analyst(int64_t test);
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
    // A generates their key
    // Run HHE.KeyGen -> (pkA, skA, evkA)
    //Use Encryption Parameters for the Analyst
    KeyGenerator keygen(context);
    SecretKey he_sk = keygen.secret_key();      //HE Decryption Key
    
//--- Todo: rewrite myself!!!!
    // keygen.create_public_key(Analyst.he_pk);
    // keygen.create_relin_keys(Analyst.he_rk);
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
//---

    cout << endl;
}

void Analyst::generate_HHE_keys() {
    // should return (pkA, skA, evkA)
}

message Analyst::send_m1() {
    message ret;
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