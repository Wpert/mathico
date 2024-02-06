#include "tpage.h"

using namespace vie;

TPageManager::TPageManager(sf::Font& buttonFont) : mainFont_(buttonFont) {}

void TPageManager::ClearEverything() {
    pageButtons_.ClearButtons();
    pageTextBoxes_.ClearTextboxes();
    pageSliders_.ClearSliders();
}

void TPageManager::MenuPage() {
    this->ClearEverything();
    currentPage_ = GuiPage::MENU_PAGE;
    // gui
    pageButtons_.AddButton(sf::Vector2f(10, 10), "Sierpinski triangle", ButtonAction::TO_SIERP_PAGE, mainFont_);
    pageButtons_.AddButton(sf::Vector2f(10, 45), "Fern", ButtonAction::TO_FERN_PAGE, mainFont_);
    pageButtons_.AddButton(sf::Vector2f(10, 80), "Polygons", ButtonAction::TO_POLYGON_PAGE, mainFont_);
    pageButtons_.AddButton(sf::Vector2f(10, 115), "Save image", ButtonAction::TO_FILE_PAGE, mainFont_);

    pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", ButtonAction::EXIT, mainFont_);
}

void TPageManager::SierpinskiPage() {
    this->ClearEverything();
    currentPage_ = GuiPage::SIERPINSKI;
    // gui
    pageButtons_.AddButton(sf::Vector2f(10, 10), "Draw Triangle", ButtonAction::DRAW_SIERP, mainFont_);
    // slider to choose N
    pageSliders_.AddSlider(sf::Vector2f({10, 200}), sf::Vector2f({210, 200}), 0, 10000, 25, mainFont_, Sliders::SIERPINSKI_DOTS);

    pageButtons_.AddButton(sf::Vector2f(10, 325), "Back to menu", ButtonAction::TO_MENU_PAGE, mainFont_);
    pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", ButtonAction::EXIT, mainFont_);
}

void TPageManager::FernPage() {
    this->ClearEverything();
    currentPage_ = GuiPage::FERN;

    pageButtons_.AddButton(sf::Vector2f(10, 10), "Draw Fern", ButtonAction::DRAW_FERN, mainFont_);

    pageSliders_.AddSlider(sf::Vector2f({10, 200}), sf::Vector2f({210, 200}), 0, 10000, 25, mainFont_, Sliders::FERN_DOTS);

    pageButtons_.AddButton(sf::Vector2f(10, 325), "Back to menu", ButtonAction::TO_MENU_PAGE, mainFont_);
    pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", ButtonAction::EXIT, mainFont_);
}

void TPageManager::PolygonPage() {
    this->ClearEverything();
    currentPage_ = GuiPage::POLYGON;

    pageTextBoxes_.AddName(sf::Vector2f(10, 10), "Enter X position:", mainFont_);
    pageTextBoxes_.AddName(sf::Vector2f(10, 80), "Enter Y position:", mainFont_);
    pageTextBoxes_.AddName(sf::Vector2f(10, 150), "Enter N:", mainFont_);

    pageTextBoxes_.AddTextbox(sf::Vector2f(10, 45), TextBoxes::SET_X, mainFont_);
    pageTextBoxes_.AddTextbox(sf::Vector2f(10, 115), TextBoxes::SET_Y, mainFont_);
    pageTextBoxes_.AddTextbox(sf::Vector2f(10, 185), TextBoxes::SET_N, mainFont_);

    pageButtons_.AddButton(sf::Vector2f(10, 220), "Draw Polygon", ButtonAction::DRAW_POLYGON, mainFont_);

    pageButtons_.AddButton(sf::Vector2f(10, 325), "Back to menu", ButtonAction::TO_MENU_PAGE, mainFont_);
    pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", ButtonAction::EXIT, mainFont_);
}

void TPageManager::FilePage() {
    this->ClearEverything();
    currentPage_ = GuiPage::SAVE;
    // gui
    pageButtons_.AddButton(sf::Vector2f(10, 80), "Save image", ButtonAction::SAVE_IMAGE, mainFont_);

    // textboxes
    pageTextBoxes_.AddTextbox(sf::Vector2f(10, 45), SET_FILENAME, mainFont_);

    pageTextBoxes_.AddName(sf::Vector2f(10, 10), "Filename of new image", mainFont_);

    pageButtons_.AddButton(sf::Vector2f(10, 325), "Back to menu", ButtonAction::TO_MENU_PAGE, mainFont_);
    pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", ButtonAction::EXIT, mainFont_);
}

void TPageManager::TakeInputs(sf::Event &e, sf::RenderWindow& window) {
    pageButtons_.TakeInput(e, window);
    pageTextBoxes_.TakeInput(e, window);
    pageSliders_.TakeInput(e, window);
}

void TPageManager::Render(sf::RenderWindow &window) {
    pageButtons_.Render(window);
    pageTextBoxes_.Render(window);
    pageSliders_.Render(window);
}
