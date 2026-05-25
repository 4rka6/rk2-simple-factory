#include <iostream>
#include <memory>
#include "../src/Factory.h"

int main() {
    bool allPassed = true;
    
    auto productA = Factory::createProduct("A");
    if (productA && productA->operation() == "Result of ConcreteProductA") {
        std::cout << "[PASS] Product A created" << std::endl;
    } else {
        std::cout << "[FAIL] Product A not created" << std::endl;
        allPassed = false;
    }
    
    auto productB = Factory::createProduct("B");
    if (productB && productB->operation() == "Result of ConcreteProductB") {
        std::cout << "[PASS] Product B created" << std::endl;
    } else {
        std::cout << "[FAIL] Product B not created" << std::endl;
        allPassed = false;
    }
    
    auto unknown = Factory::createProduct("C");
    if (unknown == nullptr) {
        std::cout << "[PASS] Unknown type returns nullptr" << std::endl;
    } else {
        std::cout << "[FAIL] Unknown type should return nullptr" << std::endl;
        allPassed = false;
    }
    
    return allPassed ? 0 : 1;
}
