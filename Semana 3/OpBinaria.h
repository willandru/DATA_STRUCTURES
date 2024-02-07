template <class T>
class OpBinaria{

    protected:
    T op1;
    T op2;
    char op;

    public:
    OpBinaria( T a, T b, char c);
    T EvaluarOperacion();
    
};