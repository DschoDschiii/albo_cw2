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
        HHE hhe; // HHE instance
        SecretKey he_sk;                   // HE Decryption Key
        RelinKeys he_rk;
        GaloisKeys he_gk;

        void print(string str){
            cout << "[Analyst] " << str << endl;
        }
};  

Analyst::Analyst() {
    print("Create Analyst");
    vector<uint64_t> secret_key;
    //hhe = HHE(secret_key);
};

void Analyst::generate_HHE_keys() {
    print("Generating HHE keys");
    // A generates their key
    // Run HHE.KeyGen -> (pkA, skA, evkA)
    //Use Encryption Parameters for the Analyst
    tuple<PublicKey, SecretKey, RelinKeys> ret = hhe.keyGen();

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
    // vector<int64_t> decrypted_res = decrypting(CSP.c_res, Analyst.he_sk, analyst_he_benc, *context, Analyst.w.size());
}

void Analyst::print_result() {
    // print_vec(decrypted_res, decrypted_res.size(), "decrypted result");
}

// BatchEncoder analyst_he_benc(*context);
// Encryptor analyst_he_enc(*context, Analyst.he_pk);
// Evaluator analyst_he_eval(*context);
// bool use_bsgs = false;
// vector<int> gk_indices = add_gk_indices(use_bsgs, analyst_he_benc);
// keygen.create_galois_keys(gk_indices, Analyst.he_gk);
