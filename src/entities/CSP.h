#include "seal/seal.h"
#ifndef HHE_H
#define HHE_H
#include "HHE.h"
#endif

class CSP {
    public:
        CSP();

        void receive_m1(message m1);
        void receive_m2(message m2);
        void decompose_HHE();
        void receive_m3(message m3);
        void evaluate_HHE();
        message send_m4();
    
    private:
        std::vector<Ciphertext> c_prime; // the decomposed HE encrypted data of user's c_i
        Ciphertext c_res;                // the HE encrypted results that will be sent to the Analyst
        SecretKey he_sk;

        void print(string str){
            cout << "[CSP] " << str << endl;
        }
};

CSP::CSP() {
    print("Creating CSP");
};

void CSP::receive_m1(message m1) {

}

void CSP::receive_m2(message m2) {
    // make useful
    decompose_HHE();
}

// 1. Convert sym-enc data to homo-enc data
// 1.1 Use HE_decrypt() (from hasta_3_seal.cpp)
//      and the encrypted key
//      it returns HE-based ciphertext (SEAL cipher): std::vector<Ciphertext>
//      that can be further used for evalution by using SEAL and HE schemes like BFV and BGV.
//--- 3. Send the encrypted data to the server and apply the Decomp() 
//--- "PASTA_SEAL::HE_decrypt()" to convert symmetric ciphertexts to 
//--- homomorphic ciphertexts.
void CSP::decompose_HHE() {
    // sets c_prime
}

void CSP::receive_m3(message m3) {

    // do function
    evaluate_HHE();
}

// 1. Do evaluation function and return ciphertext results to Analyst
//--- 4. Apply the HE.Eval() to compute the result of addition or 
//--- multiplication over the homomorphic ciphertexts.
void CSP::evaluate_HHE() {
    // sets c_res
}

message CSP::send_m4() {
    message ret;
    return ret;
}

//--- Todo: rewrite myself!!!!
    // KeyGenerator csp_keygen(*context);
    // CSP.he_sk = csp_keygen.secret_key();
    // TEST::he_sk_test(Analyst.he_sk, CSP.he_sk); // throw an error if 2 keys are the same
    
    // cout << "Making a PASTA_SEAL Worker Object for the CSP based on the new CSP HE sk and the Analyst's HE pk" << endl;
    // PASTA_3_MODIFIED_1::PASTA_SEAL CSPWorker(context, Analyst.he_pk, CSP.he_sk, Analyst.he_rk, Analyst.he_gk);
    
    // cout << "CSP Decompose: Turning the user's SKE encrypted data c_i into HE encryped c_prime" << endl;
    // CSP.c_prime = CSPWorker.decomposition(User.c_i, User.c_k, config::USE_BATCH);
    
    // cout << "CSP Evaluate a linear transformation using c_prime, Analyst's encrypted weights and biases" << endl;
    // packed_enc_multiply(CSP.c_prime[0], Analyst.w_c, CSP.c_res, analyst_he_eval);
    // packed_enc_addition(CSP.c_res, Analyst.b_c, CSP.c_res, analyst_he_eval);
//---