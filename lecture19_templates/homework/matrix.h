template <class X> class matrix {
    X **mat;
public:
    matrix(int n, int m);
    matrix(X &x);
    void get(X &M);
    matrix operator + (matrix B);
    matrix operator = (matrix B);
    matrix operator - (matrix B);
    matrix operator * (matrix B);
    matrix operator / (matrix B);
    template <class I> matrix operator *= (I l);
    template <class I> matrix operator /= (I l);
};