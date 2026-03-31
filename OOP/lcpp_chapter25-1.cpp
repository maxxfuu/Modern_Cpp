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
  
  void displayStats() {
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

  void displayStats() {
    std::cout << "Power Level: " << height_ * weight_; 
  }
}; 

int main() {
  // Animal animal{172, 69};
  // animal.displayStats();
  
  // Object Slicing 
  Dog myDog{20, 50.0, "GRAH"};
  Animal a1 = myDog; 

  a1.displayStats();

  return 0;
}
