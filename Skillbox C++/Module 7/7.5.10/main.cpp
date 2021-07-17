#include <iostream>

int main() {
    int heightOfTree, width;
    std::cout << "- - - Ёлочка - - -" << std::endl;
    do {
        std::cout << "Введите высоту ёлочки: ";
        std::cin >> heightOfTree;
    } while (heightOfTree <= 0);
    width = heightOfTree * 2 + 1;
    for (int y = 0, grid = 1; y < heightOfTree; y++, grid += 2) {
        for (int x = 0; x < width; x++) {
            if (x >= width / 2 - grid / 2 + 1 && x <= width / 2 + grid / 2 + 1)std::cout << "#";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
