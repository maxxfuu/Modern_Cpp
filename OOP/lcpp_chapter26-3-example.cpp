#include <iostream>

class A {
public:
  virtual std::string_view getName() const { return "A"; }
};

class B : public A {
public:
  virtual std::string_view getName() const override final { return "B"; }
};

class C : public B {
public:
  virtual std::string_view getName() const { return "C"; }
};

int main() {
  C c{};
  c.getName();

  return 0;
}
