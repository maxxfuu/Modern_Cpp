#include <iostream>

class A {
public: 
  virtual void print() {
    std::cout << "A" << std::endl;
  }
 
};

class B : public A {
public:
  void print() override {
    std::cout << "B" << std::endl;
  }
};


class X {
private:
  A o_A {};

public:
  virtual A* getObject() {
    return &o_A; 
  }
};

class Y: public X {
private:
  B o_B {};

public:
  B* getObject() { // of covariant type
    return &o_B;
  }
};

int main() {
  Y o_Y{};
  X& ref { o_Y }; 

  ref.getObject()->print();

  return 0; 
}

/*
Normally a virutal functions can be override by the most derived virtual
function if:
- the derived class has the same return type, function signature, and same
cv-qualifer (const-volatile qualifer)

Otherwise, the virutal function won't compile. However, if you do want to have
different return types so that we can have the flexibility to:
- invoke functions explicitly while having polymorphic behavior
and CV-qualifier short for return type is the same
*/
