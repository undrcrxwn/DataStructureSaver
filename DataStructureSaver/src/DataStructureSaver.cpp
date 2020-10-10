#include "pch.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "StructManager.h"

class User {
public:
    uint32_t id;
    std::string name;
    float size[3];
    int* ptr; // Pointers can only be restored
              // within a single session

    void Display()
    {
        std::cout << std::setw(7) << "ID: " << id << std::endl;
        std::cout << std::setw(7) << "Name: " << name << std::endl;
        std::cout << std::setw(7) << "Size: ";
        for (float x : size)
            std::cout << x << " ";
        std::cout << std::endl;
        std::cout << std::setw(7) << "Ptr: " << ptr << std::endl;
        std::cout << std::setw(7) << "Val: " << *ptr << std::endl << std::endl;
    }
};

int main() {
    StructManager sm("user.dat");
    std::cout << std::setw(7) << "Path: " << sm.GetPath() << std::endl << std::endl;

    // Saving
    User user = { 2892, "Joe", { 0.3f, 0.1f, 1.1f }, new int(1337) };
    user.Display();
    sm.Save(user);

    // Reading
    User cur_user;
    sm.Read(&cur_user);
    cur_user.Display();

    // Undefind behavior
    sm.SetPath("old.dat");
    User old_user;
    sm.Read(&old_user);
    old_user.Display();

    return 0;
}