#include "../new_gui/button/button.hpp"
#include <cassert>

std::string getTestPath() {
    std::string path(__FILE__);
    std::cout << __FILE__ << std::endl;
    path = path.substr(0, path.rfind("/test/") + 1);
    return path;
}

bool ContainsTest(vie::Button* btn) {
    sf::Vector2i mousePosition;
    for (size_t i = 0; i < 50; ++i) {
        mousePosition.x = std::rand() % 100;
        mousePosition.y = std::rand() % 100;
        if (btn->Contains(mousePosition)) {
            btn->CallFunc();
            if (mousePosition.x < 10 || mousePosition.x >= 10 + 200)
                return false;
            if (mousePosition.y < 10 || mousePosition.y >= 10 + 30)
                return false;
        }
    }
    return true;
}

class TestButton : public vie::Button {
public:
    TestButton(
        sf::Vector2f position, sf::Vector2f size,
        std::string text, const sf::Font &buttonFont
        )
        : Button(position, size, text, buttonFont)
    {
        std::cout << "TestButton has constructed" << std::endl;
    }

    ~TestButton() {
        std::cout << "TestButton has destructed" << std::endl;
    }

    bool CallFunc() const override {
        std::cout << "TestButton has been called" << std::endl;
        return false;
    }
};

int main() {
    std::string dirPath = getTestPath();
    sf::Font basicFont;
    std::cout << "Dir path: " <<  dirPath << std::endl;
    basicFont.loadFromFile(dirPath + "resources/calibri.ttf");
    TestButton btn({10, 10}, {200, 30}, "text", basicFont);

    assert(ContainsTest(&btn));
    std::cout << 1 << std::endl;
    return 0;
}
