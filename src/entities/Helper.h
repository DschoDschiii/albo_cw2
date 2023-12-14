#ifndef HELPER_H
#define HELPER_H


struct message{
    // time stamp
    // ciphertext
    // signature
};


namespace config
{
    // HE parameters
    uint64_t plain_mod = 65537;
    uint64_t mod_degree = 16384;
    int seclevel = 128;
}

#endif