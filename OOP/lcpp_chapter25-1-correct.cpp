#include <iostream>
#include <string>

class Animal {
private:
  std::string type_;

protected:
  int height_;
  double weight_; 

public:
  Animal(int height, double weight, std::string type = "none") 
    : height_{height}, weight_{weight}, type_{type}{}
  ~Animal() {}
  
  virtual void displayStats() {
    std::cout << "Animal: " << type_ << std::endl; 
    std::cout << "height: " << height_ << " weight: " << weight_ << std::endl;
  }
};

class Dog : public Animal {
private:
  std::string sound_;

public:
  Dog(int height, double weight, std::string sound)
    : Animal{height, weight, "DOG"}, sound_{sound} {}

  void displaySound() {
    std::cout << "Dog Sound: " << sound_ << std::endl;
  }

  void displayStats() override{
    std::cout << "Power Level: " << height_ * weight_ << std::endl; 
  }
}; 

int main() {
  // Animal animal{172, 69};
  // animal.displayStats();
  
  // Virtual Function - No More Object Slicing 
  // By Pointer 
  Dog myDog{20, 50.0, "GRAH"};
  Animal* a1 = &myDog; 
  a1->displayStats();
  
  // By Reference
  Dog myDawg{200, 500.0, "GRAH"};
  Animal& a2 = myDawg; 
  a2.displayStats();

  return 0;
}

/*
In the example above, by defining a virtual function, we allow the compiler to enable dynamic binding.
To actually dynamically bind we need to provide a function within the derived class with the same name as the function 
defined in the base class. 

Then to actually invoke the function assuming the type is of baseClass with a derived objecct assigned to it. We need to make sure the type if of pointer or reference.
*/
