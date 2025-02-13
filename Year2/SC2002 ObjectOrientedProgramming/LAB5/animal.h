#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

enum COLOR { Green, Blue, White, Black, Brown };

// Function to convert COLOR enum to string
std::string colorToString(COLOR color) {
    switch (color) {
        case Green: return "Green";
        case Blue: return "Blue";
        case White: return "White";
        case Black: return "Black";
        case Brown: return "Brown";
        default: return "Unknown";
    }
}

class Animal {
public:
    Animal() : _name("unknown"), _color(Green) {
        std::cout << "constructing Animal object " << _name << std::endl;
    }
    Animal(std::string name, COLOR color) : _name(name), _color(color) {
        std::cout << "Constructing Animal object " << _name << std::endl;
        std::cout << "Name: " << _name << "  Color: " << colorToString(_color) << std::endl;
    }
    virtual ~Animal() {
        std::cout << "destructing Animal object " << _name << std::endl;
    }
    virtual void speak() const {
        std::cout << "Animal speaks " << std::endl;
    }
    virtual void eat() const {
        std::cout << "Animal eats " << std::endl;
    }
    virtual void move() const = 0; // pure virtual function

private:
    std::string _name;
    COLOR _color;
};

class Mammal : public Animal {
public:
    Mammal() : Animal() {
        std::cout << "Constructing Mammal object " << std::endl;
    }
    Mammal(std::string name, COLOR color) : Animal(name, color) {
        std::cout << "Constructing Mammal object " << std::endl;
    }
    ~Mammal() {
        std::cout << "Destructing Mammal object " << std::endl;
    }
    void eat() const override {
        std::cout << "Mammal eats!" << std::endl;
    }
    void move() const override {
        std::cout << "Mammal moves!" << std::endl;
    }
};

#endif // ANIMAL_H
