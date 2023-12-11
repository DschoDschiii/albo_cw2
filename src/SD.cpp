#include <iostream>
#include <vector>
#include "SD.h"
#include "Analyst.h"
#include "User.h"
#include "seal/seal.h"
#include "../thirdparty/ciphers/pasta_3/seal/pasta_3_seal.h"
#include "../thirdparty/ciphers/common_Zp/SEAL_Cipher.h"

using namespace std;

std::vector<uint64_t> secret_key = {0x07a30, 0x0cfe2, 0x03bbb, 0x06ab7, 0x0de0b, 0x0c36c, 0x01c39, 0x019e0,
      0x0e09c, 0x04441, 0x0c560, 0x00fd4, 0x0c611, 0x0a3fd, 0x0d408, 0x01b17,
      0x0fa02, 0x054ea, 0x0afeb, 0x0193b, 0x0b6fa, 0x09e80, 0x0e253, 0x03f49,
      0x0c8a5, 0x0c6a4, 0x0badf, 0x0bcfc, 0x0ecbd, 0x06ccd, 0x04f10, 0x0f1d6,
      0x07da9, 0x079bd, 0x08e84, 0x0b774, 0x07435, 0x09206, 0x086d4, 0x070d4,
      0x04383, 0x05d65, 0x0b015, 0x058fe, 0x0f0d1, 0x0c700, 0x0dc40, 0x02cea,
      0x096db, 0x06c84, 0x008ef, 0x02abc, 0x03fdf, 0x0ddaf, 0x028c7, 0x0ded4,
      0x0bb88, 0x020cd, 0x075c3, 0x0caf7, 0x0a8ff, 0x0eadd, 0x01c02, 0x083b1,
      0x0a439, 0x0e2db, 0x09baa, 0x02c09, 0x0b5ba, 0x0c7f5, 0x0161c, 0x0e94d,
      0x0bf6f, 0x070f1, 0x0f574, 0x0784b, 0x08cdb, 0x08529, 0x027c9, 0x010bc,
      0x079ca, 0x01ff1, 0x0219a, 0x00130, 0x0ff77, 0x012fb, 0x03ca6, 0x0d27d,
      0x05747, 0x0fa91, 0x00766, 0x04f27, 0x00254, 0x06e8d, 0x0e071, 0x0804e,
      0x08b0e, 0x08e59, 0x04cd8, 0x0485f, 0x0bde0, 0x03082, 0x01225, 0x01b5f,
      0x0a83e, 0x0794a, 0x05104, 0x09c19, 0x0fdcf, 0x036fe, 0x01e41, 0x00038,
      0x086e8, 0x07046, 0x02c07, 0x04953, 0x07869, 0x0e9c1, 0x0af86, 0x0503a,
      0x00f31, 0x0535c, 0x0c2cb, 0x073b9, 0x028e3, 0x03c2b, 0x0cb90, 0x00c33,
      0x08fe7, 0x068d3, 0x09a8c, 0x008e0, 0x09fe8, 0x0f107, 0x038ec, 0x0b014,
      0x007eb, 0x06335, 0x0afcc, 0x0d55c, 0x0a816, 0x0fa07, 0x05864, 0x0dc8f,
      0x07720, 0x0deef, 0x095db, 0x07cbe, 0x0834e, 0x09adc, 0x0bab8, 0x0f8f7,
      0x0b21a, 0x0ca98, 0x01a6c, 0x07e4a, 0x04545, 0x078a7, 0x0ba53, 0x00040,
      0x09bc5, 0x0bc7a, 0x0401c, 0x00c30, 0x00000, 0x0318d, 0x02e95, 0x065ed,
      0x03749, 0x090b3, 0x01e23, 0x0be04, 0x0b612, 0x08c0c, 0x06ea3, 0x08489,
      0x0a52c, 0x0aded, 0x0fd13, 0x0bd31, 0x0c225, 0x032f5, 0x06aac, 0x0a504,
      0x0d07e, 0x0bb32, 0x08174, 0x0bd8b, 0x03454, 0x04075, 0x06803, 0x03df5,
      0x091a0, 0x0d481, 0x09f04, 0x05c54, 0x0d54f, 0x00344, 0x09ffc, 0x00262,
      0x01fbf, 0x0461c, 0x01985, 0x05896, 0x0fedf, 0x097ce, 0x0b38d, 0x0492f,
      0x03764, 0x041ad, 0x02849, 0x0f927, 0x09268, 0x0bafd, 0x05727, 0x033bc,
      0x03249, 0x08921, 0x022da, 0x0b2dc, 0x0e42d, 0x055fa, 0x0a654, 0x073f0,
      0x08df1, 0x08149, 0x00d1b, 0x0ac47, 0x0f304, 0x03634, 0x0168b, 0x00c59,
      0x09f7d, 0x0596c, 0x0d164, 0x0dc49, 0x038ff, 0x0a495, 0x07d5a, 0x02d4,
      0x06c6c, 0x0ea76, 0x09af5, 0x0bea6, 0x08eea, 0x0fbb6, 0x09e45, 0x0e9db,
      0x0d106, 0x0e7fd, 0x04ddf, 0x08bb8, 0x0a3a4, 0x03bcd, 0x036d9, 0x05acf};

void CSP(int inputs){ } 
void Client(int inputs){ } 
void Analyst(int inputs){ } 

// Generate the keys and shared variables here, so you can pass them 
// to any entity you want based on the protocol flow 
// Call each entity based on the protocol flow here
int main() {
    Analyst a;
    User u1(1);
    User u2(2);

    //--- test
    //std::shared_ptr<seal::SEALContext> con = SEALZpCipher::create_context(65536, 65536, 128);
    //PASTA_3::PASTA_SEAL test(secret_key, con);
    //cout << test.get_cipher_name() << endl;
    //---

    // --- SETUP ---
    // A generates their key
    // Run HHE.KeyGen -> (pkA, skA, evkA)

    // Users generate their symmetric keys
    // SKE.KeyGen -> Ki

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