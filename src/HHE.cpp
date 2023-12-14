#include "HHE.h"

using namespace std;
using namespace seal;

inline shared_ptr<SEALContext> HHE::get_seal_context(uint64_t plain_mod = 65537, 
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