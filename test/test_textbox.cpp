#include "../new_gui/textbox/textbox.hpp"
#include <cassert>

std::string getTestPath() {
    std::string path(__FILE__);
    std::cout << __FILE__ << std::endl;
    path = path.substr(0, path.rfind("/test/") + 1);
    return path;
}

bool ContainsTest(vie::TextBox* tbox) {
    sf::Vector2i mousePosition;
    for (size_t i = 0; i < 50; ++i) {
        mousePosition.x = std::rand() % 100;
        mousePosition.y = std::rand() % 100;
        std::cout << "___ i = " << i << std::endl;
        std::cout << "x: " << mousePosition.x << std::endl;
        std::cout << "y: " << mousePosition.y << std::endl;
        if (tbox->Contains(mousePosition)) {
            if (mousePosition.x < 10 || mousePosition.x > 10 + 200) {
                std::cout << "WTF X?" << std::endl;
                return false;
            }
            if (mousePosition.y < 45 || mousePosition.y > 45 + 30) {
                std::cout << "WTF Y?" << std::endl;
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::string dirPath = getTestPath();
    sf::Font basicFont;
    std::cout << "Dir path: " <<  dirPath << std::endl;
    basicFont.loadFromFile(dirPath + "resources/calibri.ttf");

    sf::Event e;
    sf::RenderWindow window;
    vie::TextBox tbox({10, 10}, {200, 30}, basicFont, "desc text");

    for (size_t i = 0; i < 100; ++i) {
        tbox.update(e, window);
    }

    assert(ContainsTest(&tbox));

    return 0;
}