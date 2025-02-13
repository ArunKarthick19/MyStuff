#include "childAnimal.h"

int main() {
    const int SIZE = 10;
    Mammal* zoo[SIZE] = { nullptr }; // Array of Mammal pointers
    int choice;
    int count = 0;

    while (true) {
        std::cout << "Select the animal to send to Zoo: \n";
        std::cout << "(1) Dog \n(2) Cat \n(3) Lion \n(4) Move all animals \n(5) Quit\n";
        std::cin >> choice;

        if (choice == 5) {
            break; // Exit loop
        } else if (choice >= 1 && choice <= 3 && count < SIZE) {
            std::string name;
            std::cout << "Enter name: ";
            std::cin >> name;

            COLOR color = White; // Default color, could add input for color
            if (choice == 1) {
                zoo[count++] = new Dog(name, color, "Owner");
            } else if (choice == 2) {
                zoo[count++] = new Cat(name, color);
            } else if (choice == 3) {
                zoo[count++] = new Lion(name, color);
            }
        } else if (choice == 4) {
            for (int i = 0; i < count; ++i) {
                zoo[i]->speak();
                zoo[i]->move();
                zoo[i]->eat();
            }
        } else {
            std::cout << "Invalid choice or zoo full!" << std::endl;
        }
    }

    // Clean up
    for (int i = 0; i < count; ++i) {
        delete zoo[i];
    }

    std::cout << "Program exiting…" << std::endl;
    return 0;
}
