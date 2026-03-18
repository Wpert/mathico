#pragma once

#include <spdlog/spdlog.h>

#include "../logic.hpp"

namespace vie {

class SavePage : public PageManager {
private:
    Logic* p_logic_;

    void saveImage() {}

    class SaveImageButton : public Button {
        SavePage* p_obj_;
        Logic* p_logic_;
    public:
        SaveImageButton(
            sf::Vector2f position,
            sf::Vector2f size,
            std::string text,
            const sf::Font &buttonFont,
            SavePage* objPtr,
            Logic* logic
        ) : Button(position, size, text, buttonFont),
            p_obj_(objPtr),
            p_logic_(logic)
        {
            spdlog::debug("SaveImageButton has constructed");
        }

        ~SaveImageButton() {
            spdlog::debug("SaveImageButton has destructed");
        }

        bool CallFunc() const override {
            std::string path(__FILE__);
            spdlog::debug("path to save_page.hpp: {}", path);

            path = path.substr(0, path.rfind("new_gui/")); // ../folder/gui
            path = path.substr(0, path.rfind('/') + 1); // ../folder/

            std::string filename = p_obj_->textboxes_[0].GetString();
            std::string fullImagePath = path + "../../../pictures/" + filename;

            bool isSavedImage = p_logic_->editableImage_.saveToFile(fullImagePath);
            if (!isSavedImage) {
                spdlog::error("Couldn't save image to file: {}", fullImagePath);
            }
            else {
                spdlog::info("Saved image to this file: {}", fullImagePath);
            }

            return false;
        }
    };

public:
    SavePage(const sf::Font& font, Logic* p_logic);
    ~SavePage() = default;

    void RenderUnits(sf::RenderWindow& window) override;
};

}
