#ifndef EFFECTO_TPAGE_H
#define EFFECTO_TPAGE_H

#include "textboxes/textbox.h"
#include "buttons/tbuttons.h"
#include "slider/slider.h"

namespace vie {
enum TextBoxes {
    GET_FILENAME,
    SET_FILENAME,
    SET_X,
    SET_Y,
    SET_N
};

namespace GuiPage {
    enum {
        MENU_PAGE,
        SIERPINSKI,
        FERN,
        POLYGON,
        SAVE
    };
}

namespace ButtonAction {
    enum {
        TO_SIERP_PAGE,
        DRAW_SIERP,
        DRAW_FERN,
        DRAW_POLYGON,
        LOAD_IMAGE,
        SAVE_IMAGE,
        TO_MENU_PAGE,
        TO_FILE_PAGE,
        TO_POLYGON_PAGE,
        TO_FERN_PAGE,
        EXIT
    };
}

class TPageManager {
    sf::Font mainFont_;
    short currentPage_ = GuiPage::MENU_PAGE;

public:
    TextBoxContainer pageTextBoxes_;
    ButtonContainer pageButtons_;
    SliderContainer pageSliders_;

    TPageManager(sf::Font &buttonFont);
    void ClearEverything();
    void MenuPage();
    void SierpinskiPage();
    void FernPage();
    void PolygonPage();
    void FilePage();

    void TakeInputs(sf::Event &e, sf::RenderWindow& window);
    void Render(sf::RenderWindow &window);

    short getCurrentPage() {
        return this->currentPage_;
    }
};

}

#endif //EFFECTO_TPAGE_H
