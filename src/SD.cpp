#include <iostream>
#include <vector>
#include <chrono>

#include "seal/seal.h"

#include "HHE.h"

#include "./entities/Entities.h"

using namespace std;
using namespace seal;


// Generate the keys and shared variables here, so you can pass them 
// to any entity you want based on the protocol flow 
// Call each entity based on the protocol flow here
int main() {
    cout << "Running SD protocol with one Analyst, one User and one CSP" << endl;

    Analyst a(0);
    User u(0);
    CSP csp(0);
    
    // --- SETUP ---


    // A send m1 to CSP
    // m1 = (t1, Enc(pkCSP, evk), sigA(H(t1||evk))))
    //
    // generate a shared symmetric key sk_evk 
    // encrypt the evk using a symmetric key encryption algorithm like AES 
    //  EncapsulatedEvk = SYM.Enc(sk_evk, evk); 
    // Encrypt the symmetric key using PKI 
    //  EncapSymKey = PKE.Enc(pkCSP, sk_evk); 
    // Send both EncapsulatedEvk, and EncapSymKey to CSP


    // USER
    // 1. Use PASTA (a symmetric cipher) to encrypt user's data.
    // 1.1 Get the symmetric key from the testvectors.h
    // 1.2 Encrypt user data using the symm-key and PASTA cipher (from pasta_3_plain.cpp)
    // nevermindPASTA_3::PASTA SymmEncryptor(secret_key, mod);

    // 2. Encrypt the symm-key itself
    // 2.1 Get the Analyst public key 'pk'
    // 2.2 Use HE.Enc() to encrypt
    // ((one of them or both) available in seal.cpp)
    //--- 2. Use BFV schemes to encrypt the symmetric key with 
    //--- "PASTA_SEAL::encrypt_key()".

    // 3. 'Send' encrypted data and key to the server


    // SERVER
    // 1. Convert sym-enc data to homo-enc data
    // 1.1 Use HE_decrypt() (from hasta_3_seal.cpp)
    //      and the encrypted key
    //      it returns HE-based ciphertext (SEAL cipher): std::vector<Ciphertext>
    //      that can be further used for evalution by using SEAL and HE schemes like BFV and BGV.
    //--- 3. Send the encrypted data to the server and apply the Decomp() 
    //--- "PASTA_SEAL::HE_decrypt()" to convert symmetric ciphertexts to 
    //--- homomorphic ciphertexts.


    // ANALYST
    // 1. Request evaluation function

    // SERVER
    // 1. Do evaluation function and return ciphertext results to Analyst
    //--- 4. Apply the HE.Eval() to compute the result of addition or 
    //--- multiplication over the homomorphic ciphertexts.

    // ANALYST
    // 1. Decrypt results using the secret key sk and SEAL decrypt function
    //--- 5. Send the result back to the analyst and use 
    //--- "PASTA_SEAL::decrypt_result()" to decrypt it.

    cout << "The program works!" << endl;
    return 0;
}