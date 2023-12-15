#include "seal/seal.h"
#include "Helper.h"
#include "../../thirdparty/ciphers/pasta_3/seal/pasta_3_seal.h"

using namespace std;
using namespace seal;

enum Function{add, mult};

class HHE {
    private:
        static SEALContext get_context(uint64_t plain_mod, uint64_t mod_degree, int seclevel) {
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
            SEALContext context(parms);

            return context;
        }

    public:
        static tuple<PublicKey, SecretKey, RelinKeys> keyGen() {
            SEALContext context = HHE::get_context(config::plain_mod, config::mod_degree, config::seclevel);

            PublicKey pk;
            SecretKey sk;
            RelinKeys eval; //Todo check if it's actually RelinKey that I should use
            KeyGenerator keygen(context);
            sk = keygen.secret_key();
            keygen.create_public_key(pk);
            keygen.create_relin_keys(eval);
            return make_tuple(pk, sk, eval);
        }

        static tuple<Ciphertext, Ciphertext> enc(vector<uint64_t> secret_key, uint64_t modulus, vector<uint64_t> he_pk) {
            // return make_tuple(enc_key, ciphertext);
            // K <- SKE.Gen(1^lambda)
            // cK <- HE.Enc(pk, K)
            Ciphertext c_k;
            // c <- SKE.Enc(K, m)
            // message encrypted using shared secret key ???
            Ciphertext c;
            return make_tuple(c_k, c);
        }

        static Ciphertext decomp(RelinKeys evk, Ciphertext c, Ciphertext c_k) {
            // c_prime <- HE.Eval(evk, SKE.Dec, c_K, c)
            Ciphertext c_prime;

            // Notes: 
//            c_prime = pasta.HE_decrypt(ciphertext, true);

            return c_prime;
        }

        static Ciphertext eval(RelinKeys evk, Function f, vector<Ciphertext> c_primes) {
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

        static Plaintext dec(SecretKey sk, Ciphertext c_prime) {
            // ret <- HE.Dec(sk, c_prime)
            Plaintext p;
            return p;
        }
};
