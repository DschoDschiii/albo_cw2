#include "seal/seal.h"
#include "../thirdparty/ciphers/pasta_3/seal/pasta_3_seal.h"

using namespace std;
using namespace seal;

enum Function{add, mult};

class HHE {
    private: 
        shared_ptr<SEALContext> context_ptr;
        inline shared_ptr<SEALContext> get_seal_context(uint64_t plain_mod, 
                                                uint64_t mod_degree, 
                                                int seclevel);

    public:
        // HHE(vector<uint64_t> secret_key)
        //     : context_ptr(get_seal_context()) {}
        // // HHE(std::vector<uint64_t> secret_key, uint64_t lambda = 16384):
        // //     context(get_context(lambda)),
        // //     pasta(PASTA_3::PASTA_SEAL(secret_key, context))
        // // {}

        tuple<PublicKey, SecretKey, RelinKeys> keyGen() {
            PublicKey pk;
            SecretKey sk;
            RelinKeys eval; //Todo check if it's actually RelinKey that I should use
            KeyGenerator keygen(*context_ptr);
            sk = keygen.secret_key();
            keygen.create_public_key(pk);
            keygen.create_relin_keys(eval);
            return make_tuple(pk, sk, eval);
        }

        tuple<Ciphertext, Ciphertext> enc() {
            // K <- SKE.Gen(1^lambda)
            // cK <- HE.Enc(pk, K)
            Ciphertext c_k;
            // c <- SKE.Enc(K, m)
            // message encrypted using shared secret key ???
            Ciphertext c;
            return make_tuple(c_k, c);
        }

        Ciphertext decomp(RelinKeys evk, Ciphertext c, Ciphertext c_k) {
            // c_prime <- HE.Eval(evk, SKE.Dec, c_K, c)
            Ciphertext c_prime;

            // Notes: 
//            c_prime = pasta.HE_decrypt(ciphertext, true);

            return c_prime;
        }

        Ciphertext eval(RelinKeys evk, Function f, vector<Ciphertext> c_primes) {
            // ret <- HE.Eval(evk, f, c_primes)
            Ciphertext ret;
            
            if(f == Function::add) {
                cout << "Performing addition" << endl;
            } else if(f == Function::mult) {
                cout << "Performing multiplication" << endl;
            } else {
                cout << "Error! Calling invalid Evaluation-Function!" << endl;
            }

            return ret;
        }

        Plaintext dec(SecretKey sk, Ciphertext c_prime) {
            // ret <- HE.Dec(sk, c_prime)
            Plaintext p;
            return p;
        }
};
