// Chapter 26 - Modern C++


#include <iostream>
#include <string>

class Person {
  private:
    std::string name_; 

  public:
    Person(std::string name) : name_{name} {};
    ~Person() {};

    // getter function 
    std::string getName() {
      return name_;
    }
};

class Student : public Person {
  private:
    int semester_;

  public:
    Student(const std::string& name, int semester) : Person{name}, semester_{semester} {};
    ~Student() {};

    int getSemester() const { return semester_;}
};

int main() {

  Person person{"John Doe"};
  std::cout << person.getName() << std::endl;

  Student student{"Max Fu", 2};
  std::cout << student.getName() << std::endl;
  std::cout << student.getSemester() << std::endl;
  std::cout << "hi";

  return 0;
}

