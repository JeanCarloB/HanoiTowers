//
// Created by jeanc on 15/09/2022.
//

#ifndef EXAMENI_RUNTIMEEXCEPTION_H
#define EXAMENI_RUNTIMEEXCEPTION_H

#include "Libreria.h"

class RuntimeException {
private:
    string errorMsg;

public:
    RuntimeException(const string& err) { errorMsg = err;}
    string getMessage() const { return errorMsg; }
};

class StackEmpty : public RuntimeException { public:
    StackEmpty(const string& err) : RuntimeException(err) {}

};

#endif //EXAMENI_RUNTIMEEXCEPTION_H
