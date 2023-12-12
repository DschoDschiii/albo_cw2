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
    
    private:
        void init();

        void print(string str){
            cout << "[CSP] " << str << endl;
        }
};

void CSP::init() {
    print("--- CSP::init ---");

//--- Todo: rewrite myself!!!!
    // cout << "---- CSP ----" << endl;
    // print_line(__LINE__);
    // cout << "CSP creates a new HE secret key from the context" << endl;
    // KeyGenerator csp_keygen(*context);
    // CSP.he_sk = csp_keygen.secret_key();
    // TEST::he_sk_test(Analyst.he_sk, CSP.he_sk); // throw an error if 2 keys are the same
    // print_line(__LINE__);
    // cout << "Making a PASTA_SEAL Worker Object for the CSP based on the new CSP HE sk and the Analyst's HE pk" << endl;
    // PASTA_3_MODIFIED_1::PASTA_SEAL CSPWorker(context, Analyst.he_pk, CSP.he_sk, Analyst.he_rk, Analyst.he_gk);
    // print_line(__LINE__);
    // cout << "CSP Decompose: Turning the user's SKE encrypted data c_i into HE encryped c_prime" << endl;
    // CSP.c_prime = CSPWorker.decomposition(User.c_i, User.c_k, config::USE_BATCH);
    // cout << "CSP.c_prime.size = " << CSP.c_prime.size() << endl;
    // // cout << "CSP.prime[0].size = " << CSP.c_prime[0].size() << endl;
    // // for debugging
    // // vector<int64_t> dec_c_prime = decrypting(CSP.c_prime[0], Analyst.he_sk, analyst_he_benc, *context, Analyst.w.size());
    // // print_vec(dec_c_prime, dec_c_prime.size(), "decrypted c_prime");
    // print_line(__LINE__);
    // cout << "CSP Evaluate a linear transformation using c_prime, Analyst's encrypted weights and biases" << endl;
    // packed_enc_multiply(CSP.c_prime[0], Analyst.w_c, CSP.c_res, analyst_he_eval);
    // packed_enc_addition(CSP.c_res, Analyst.b_c, CSP.c_res, analyst_he_eval);

    // cout << endl;
    // print_line(__LINE__);
    // cout << "---- Analyst ----" << endl;
    // cout << "Analyst decrypts the result" << endl;
    // vector<int64_t> decrypted_res = decrypting(CSP.c_res, Analyst.he_sk, analyst_he_benc, *context, Analyst.w.size());
    // print_vec(decrypted_res, decrypted_res.size(), "decrypted result");
//---
    cout << endl;
}