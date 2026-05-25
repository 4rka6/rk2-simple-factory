#ifndef CONCRETE_PRODUCT_B_H
#define CONCRETE_PRODUCT_B_H

#include "Product.h"
#include <string>

class ConcreteProductB : public Product {
public:
    std::string operation() const override {
        return "Result of ConcreteProductB";
    }
};

#endif
