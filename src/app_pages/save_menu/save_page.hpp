#pragma once

#include <spdlog/spdlog.h>

#include "../logic.hpp"

namespace vie
{

class SavePage : public PageManager
{
  private:
    Logic *m_ptr_logic;

    class SaveImageButton : public Button
    {
        SavePage *m_ptr_obj;
        Logic *m_ptr_logic;

      public:
        SaveImageButton(sf::Vector2f position, sf::Vector2f size, const std::string &text, const sf::Font &buttonFont,
                        SavePage *objPtr, Logic *logic)
            : Button(position, size, text, buttonFont), m_ptr_obj(objPtr), m_ptr_logic(logic)
        {
            spdlog::debug("SaveImageButton has constructed");
        }

        ~SaveImageButton() override
        {
            spdlog::debug("SaveImageButton has destructed");
        }

        bool callFunc() const override
        {
            std::string path(__FILE__);
            spdlog::debug("path to save_page.hpp: {}", path);

            path = path.substr(0, path.rfind("new_gui/")); // ../folder/gui
            path = path.substr(0, path.rfind('/') + 1);    // ../folder/

            std::string filename = m_ptr_obj->textboxes_[0].GetString();
            std::string fullImagePath = path + "../../../pictures/" + filename;

            bool isSavedImage = m_ptr_logic->editableImage_.saveToFile(fullImagePath);
            if (!isSavedImage)
            {
                spdlog::error("Couldn't save image to file: {}", fullImagePath);
            }
            else
            {
                spdlog::info("Saved image to this file: {}", fullImagePath);
            }

            return false;
        }
    };

  public:
    SavePage() = delete;
    SavePage(const sf::Font &font, Logic *p_logic);
    SavePage(const SavePage &) = default;
    SavePage(SavePage &&) = default;
    ~SavePage() override = default;

    SavePage &operator=(const SavePage &) = default;
    SavePage &operator=(SavePage &&) = default;

    void renderUnits(sf::RenderWindow &window) override;
};

} // namespace vie
