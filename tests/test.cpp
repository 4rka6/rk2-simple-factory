#include <iostream>
#include "../src/ConceptualExample.cpp"

int main() {
   using namecpace ConceptualExample;
   auto shape = ShapeFactory::getShape(ShapeFactory::ShapeKind::Circle);
   if (shape) {
      std::cout << "Test passed: Circle created" << std::endl;
      return 0
   } else {
      std::cout << "Test failed: Circle not created" << std::endl;
      return 1;
   }
}
