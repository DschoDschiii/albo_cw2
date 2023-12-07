class HHE {
    public:
        int keyGen(int lambda);
};

int HHE::keyGen(int lambda) {
    (pk, sk, evk) = HE.KeyGen(lambda);
    return (pk, sk, evk);
}