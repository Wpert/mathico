#ifndef SAVE_PAGE_HPP
#define SAVE_PAGE_HPP

#include "sierpinski_page.hpp"

namespace vie {

class SavePage : public PageManager {
private:
    Logic* p_logic_;

    void saveImage() {}

    class SaveImageButton : public Button {
        SavePage* p_obj_;
        Logic* p_logic_;
    public:
        SaveImageButton(sf::Vector2f position, sf::Vector2f size, std::string text,
            const sf::Font &buttonFont, SavePage* objPtr, Logic* logic)
            : Button(position, size, text, buttonFont), p_obj_(objPtr), p_logic_(logic)
        {
            std::cout << "SaveImageButton has constructed" << std::endl;
        }

        ~SaveImageButton() {
            std::cout << "SaveImageButton has destructed" << std::endl;
        }
        bool CallFunc() const override {
            std::string path(__FILE__);
            std::cout << __FILE__ << std::endl;
            path = path.substr(0, path.rfind("new_gui/")); // ../folder/gui
            path = path.substr(0, path.rfind('/') + 1); // ../folder/

            std::string filename = p_obj_->textboxes_[0].GetString();
            p_logic_->editableImage_.saveToFile(path + "pictures/" + filename);
            return false;
        }
    };

public:
    SavePage(const sf::Font& font, Logic* p_logic) : PageManager(), p_logic_(p_logic) {
        sf::Vector2f position({10, 10});
        sf::Vector2f buttonSize(200, 30);

        textboxes_.AddUnit(new TextBox({10, 10}, buttonSize, font, "Enter filename"));

        buttons_.AddUnit(new SaveImageButton({10, 80}, buttonSize, "Save image", font, this, p_logic_));
        buttons_.AddUnit(new SelectPageButton({10, 200}, buttonSize, "Back to menu", font, p_logic_, page_type::main));

        // sliders_.AddUnit(new vie::Slider({10, 45}, {210, 45}, 0, 10000, 25, font));
    }

    void RenderUnits(sf::RenderWindow& window) {
        if (!isMainWindowActive_)
            return; 
        buttons_.Render(window);
        textboxes_.Render(window);
        sliders_.Render(window);
        window.draw(area_);
        window.draw(p_logic_->renderingSprite_);
    }
};

}

#endif