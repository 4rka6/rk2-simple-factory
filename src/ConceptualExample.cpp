#include <iostream>
#include <memory>
#include <string>
namespace ConceptualExample {
   class IShape { public: virtual ~IShape() {} virtual std::string draw() = 0; };
   class Circle : public IShape { public: std::string draw() override { return "Circle"; } };
   class ShapeFactory {
   public:
      enum class ShapeKind { Circle };
   static std::shared_ptr<IShape> getShape(ShapeKind kind) {
      if (kind == ShapeKind::Circle) return std::make_shared<Circle>();
      return nullptr;
   }
};
}
