#ifndef ANTLR4CPP_FETCHER_OPERATION_H
#define ANTLR4CPP_FETCHER_OPERATION_H


class Operation {
    private:
        typedef enum {
            ldconst,
            add,
            sub,
            mul,
            rmem,
            wmem,
            call,
            cmp_eq,
            cmp_lt,
            cmp_le
        } Operation_Enum;
    public:
        Operation_Enum op;
};


#endif //ANTLR4CPP_FETCHER_OPERATION_H
