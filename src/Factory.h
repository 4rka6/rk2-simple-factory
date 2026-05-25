#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include <string>
#include "Product.h"
#include "ConcreteProductA.h"
#include "ConcreteProductB.h"

class Factory {
public:
    static std::shared_ptr<Product> createProduct(const std::string& type) {
        if (type == "A") {
            return std::make_shared<ConcreteProductA>();
        } else if (type == "B") {
            return std::make_shared<ConcreteProductB>();
        }
        return nullptr;
    }
};

#endif
