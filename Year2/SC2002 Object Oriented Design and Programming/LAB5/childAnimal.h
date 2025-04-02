#ifndef CHILDANIMAL_H
#define CHILDANIMAL_H

#include "animal.h"

class Dog : public Mammal {
public:
    std::string owner;
    Dog() : Mammal() {
        std::cout << "Constructing Dog object " << std::endl;
    }
    Dog(std::string name, COLOR color, std::string own) : Mammal(name, color), owner(own) {
        std::cout << "Constructing Dog object " << std::endl;
        std::cout << "Owner: " << owner << std::endl;
    }
    ~Dog() {
        std::cout << "Destructing Dog object " << std::endl;
    }
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
    void eat() const override {
        std::cout << "Dog bites!" << std::endl;
    }
    void move() const override {
        std::cout << "Dog runs!" << std::endl;
    }
};

class Cat : public Mammal {
public:
    Cat() : Mammal() {
        std::cout << "Constructing Cat object " << std::endl;
    }
    Cat(std::string name, COLOR color) : Mammal(name, color) {
        std::cout << "Constructing Cat object " << std::endl;
    }
    ~Cat() {
        std::cout << "Destructing Cat object " << std::endl;
    }
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
    void eat() const override {
        std::cout << "Cat slurps!" << std::endl;
    }
    void move() const override {
        std::cout << "Cat sneaks!" << std::endl;
    }
};

class Lion : public Mammal {
public:
    Lion() : Mammal() {
        std::cout << "Constructing Lion object " << std::endl;
    }
    Lion(std::string name, COLOR color) : Mammal(name, color) {
        std::cout << "Constructing Lion object " << std::endl;
    }
    ~Lion() {
        std::cout << "Destructing Lion object " << std::endl;
    }
    void speak() const override {
        std::cout << "Roar!" << std::endl;
    }
    void eat() const override {
        std::cout << "Lion gulps!" << std::endl;
    }
    void move() const override {
        std::cout << "Lion stalks!" << std::endl;
    }
};

#endif // CHILDANIMAL_H
