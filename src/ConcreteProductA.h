#ifndef CONCRETE_PRODUCT_A_H
#define CONCRETE_PRODUCT_A_H

#include "Product.h"
#include <string>

class ConcreteProductA : public Product {
public:
    std::string operation() const override {
        return "Result of ConcreteProductA";
    }
};

#endif
