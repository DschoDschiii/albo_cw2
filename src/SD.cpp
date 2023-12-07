#include <iostream>
#include "Analyst.h"
#include "User.h"

using namespace std;

int main() {
    Analyst a;
    User u1(1);
    User u2(2);

    //--- test
    PASTA_SEAL test;
    cout << test.get_cipher_name() << endl;
    //---

    // A generates their key
    // Run HHE.KeyGen -> (pkA, skA, evkA)

    // Users generate their symmetric keys
    // SKE.KeyGen -> Ki

    // A send m1 to CSP
    // m1 = (t1, Enc(pkCSP, evk), sigA(H(t1||evk))))

    cout << "The program works!" << endl;
    return 0;
}