#include <iostream>
#include <vector>
#include <chrono>

#include "seal/seal.h"
#include "entities/Analyst.h"
#include "entities/CSP.h"
#include "entities/User.h"

using namespace std;
using namespace seal;

// Generate the keys and shared variables here, so you can pass them 
// to any entity you want based on the protocol flow 
// Call each entity based on the protocol flow here
int main() {
    cout << "Running SD protocol with one Analyst, one User and one CSP" << endl;

    // --- Create Entities ---
    Analyst a;
    User u(0);
    CSP csp;
    
    // --- Setup Entities ---
    a.generate_HHE_keys();
    u.generate_SKE_key();

    // A send m1 to CSP
    message m1 = a.send_m1();
    csp.receive_m1(m1);

    u.encrypt_data();
    u.encrypt_HE_symmetric_key(a.he_pk);
    // 'Send' encrypted data and key to the server
    message m2 = u.send_m2();
    csp.receive_m2(m2);

    // ANALYST: Request evaluation function
    message m3 = a.send_m3();
    csp.receive_m3(m3);

    message m4 = csp.send_m4();
    a.receive_m4(m4);

    a.print_result();

    cout << "The program works!" << endl;
    return 0;
}