#include "seal/seal.h"
#ifndef HHE_H
#define HHE_H
#include "HHE.h"
#endif

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
        SecretKey he_sk;                   // HE Decryption Key
        RelinKeys he_rk;
        GaloisKeys he_gk;

        shared_ptr<SEALContext> my_get_seal_context(uint64_t plain_mod = 65537, 
                                                uint64_t mod_degree = 16384, 
                                                int seclevel = 128) {
            if (seclevel != 128) throw runtime_error("Security Level not supported");
            seal::sec_level_type sec = seal::sec_level_type::tc128;
            
            seal::EncryptionParameters parms(seal::scheme_type::bfv);
            parms.set_poly_modulus_degree(mod_degree);

            if (mod_degree == 65536) {
                sec = seal::sec_level_type::none;
                parms.set_coeff_modulus(
                    {0xffffffffffc0001, 0xfffffffff840001, 0xfffffffff6a0001,
                    0xfffffffff5a0001, 0xfffffffff2a0001, 0xfffffffff240001,
                    0xffffffffefe0001, 0xffffffffeca0001, 0xffffffffe9e0001,
                    0xffffffffe7c0001, 0xffffffffe740001, 0xffffffffe520001,
                    0xffffffffe4c0001, 0xffffffffe440001, 0xffffffffe400001,
                    0xffffffffdda0001, 0xffffffffdd20001, 0xffffffffdbc0001,
                    0xffffffffdb60001, 0xffffffffd8a0001, 0xffffffffd840001,
                    0xffffffffd6e0001, 0xffffffffd680001, 0xffffffffd2a0001,
                    0xffffffffd000001, 0xffffffffcf00001, 0xffffffffcea0001,
                    0xffffffffcdc0001, 0xffffffffcc40001});  // 1740 bits
            } else {
                parms.set_coeff_modulus(seal::CoeffModulus::BFVDefault(mod_degree));
            }
 
            parms.set_plain_modulus(plain_mod);
            shared_ptr<SEALContext> context = make_shared<seal::SEALContext>(parms, true, sec);

            return context;
        }

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
    shared_ptr<SEALContext> context = my_get_seal_context(config::plain_mod, config::mod_degree, config::seclevel);

    tuple<PublicKey, SecretKey, RelinKeys> ret = HHE::keyGen();

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
