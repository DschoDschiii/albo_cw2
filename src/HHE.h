#include "seal/seal.h"

using namespace std;
using namespace seal;

enum Function{add, mult};

//SEALContext get_context();
SEALContext get_context();

class HHE {
    public:
        static tuple<PublicKey, SecretKey, RelinKeys> keyGen(SEALContext context) {
            PublicKey pk;
            SecretKey sk;
            RelinKeys eval; //Todo check if it's actually RelinKey that I should use
            KeyGenerator keygen(context);
            sk = keygen.secret_key();
            keygen.create_public_key(pk);
            keygen.create_relin_keys(eval);
            return make_tuple(pk, sk, eval);
        }

        static tuple<Ciphertext, Ciphertext> enc() {
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
            return c_prime;
        }

        static Ciphertext eval(RelinKeys evk, Function f, vector<Ciphertext> c_primes) {
            // ret <- HE.Eval(evk, f, c_primes)
            Ciphertext ret;
            return ret;
        }

        static Plaintext dec(SecretKey sk, Ciphertext c_prime) {
            // ret <- HE.Dec(sk, c_prime)
            Plaintext p;
            return p;
        }
};
