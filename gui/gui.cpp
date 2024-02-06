#include "gui.h"

using namespace vie;

TWorkArea::TWorkArea(sf::Vector2f pos, sf::Vector2f size) {
    this->area_.setSize(size);
    this->area_.setPosition(pos);
    this->area_.setFillColor(vertexesAreaColor);
}

void TWorkArea::SetSize(sf::Vector2f size) {
    this->area_.setSize(size);
}

void TWorkArea::Render(sf::RenderWindow &window) {
    window.draw(this->area_);
}

TLogic::TLogic(sf::Font font)
        : mainFont_(font)
        , graphWorkspace_({220, 10}, {794, 580})
        , mainGui_(font)
{
    renderingSprite_.setPosition({220, 10});
    mainGui_.MenuPage();
}

void TLogic::InteractMenu(sf::RenderWindow &window, Button &button) {
    switch (button.enumNumber_) {
        case ButtonAction::TO_SIERP_PAGE:
        {
            this->mainGui_.SierpinskiPage();
        }
            break;
        case ButtonAction::TO_FERN_PAGE:
        {
            this->mainGui_.FernPage();
        }
            break;
        case ButtonAction::TO_POLYGON_PAGE:
        {
            this->mainGui_.PolygonPage();
        }
            break;
        case ButtonAction::TO_FILE_PAGE:
        {
            this->mainGui_.FilePage();
        }
            break;
        case ButtonAction::EXIT:
        {
            window.close();
        }
            break;
        default:
        {
            std::cout << "Kek!" << std::endl;
        }
            break;
    }
}

void TLogic::InteractSierpinski(sf::RenderWindow &window, Button &button) {
    switch (button.enumNumber_)
    {
    case ButtonAction::DRAW_SIERP:
    {
        size_t width = 500;
        size_t height = 500;
        this->editableImage_.create(width, height, vertexesAreaColor);
        
        size_t N = this->mainGui_.pageSliders_.GetNumber(Sliders::SIERPINSKI_DOTS);
        std::vector<std::pair<float, float>> points = {{0.0, 0.0}, {width - 1, 0.0}, {width - 1, height - 1}};
        
        for (int i = 0; i < N; ++i) {
            int rnd_ind = std::rand() % 3;
            
            std::pair<float, float> prev_point = points[points.size() - 1];
            std::pair<float, float> attr_point = points[rnd_ind];

            std::pair<float, float> new_point = {(prev_point.first + attr_point.first) / 2, (prev_point.second + attr_point.second) / 2};
            points.push_back(std::move(new_point));
        }

        for (int i = 0; i < points.size(); ++i) {
            editableImage_.setPixel((int) points[i].first, (int) points[i].second, activeOutlineColor);
        }

        this->loadingTexture_.loadFromImage(editableImage_);
        this->renderingSprite_.setTexture(loadingTexture_);
    }
        break;
    case ButtonAction::TO_MENU_PAGE:
    {
        this->mainGui_.MenuPage();
    }
        break;
    case ButtonAction::EXIT:
    {
        window.close();
    }
        break;
    default:
        break;
    }
}

void TLogic::InteractFern(sf::RenderWindow &window, Button &button) {
    switch (button.enumNumber_)
    {
    case ButtonAction::DRAW_FERN:
    {
        size_t width = 500;
        size_t height = 500;
        this->editableImage_.create(width, height, vertexesAreaColor);
        sf::Vector2f v = {0, 0};
        sf::Vector2f vn = {0, 0};

        size_t N = this->mainGui_.pageSliders_.GetNumber(Sliders::FERN_DOTS);


        for (int i = 0; i < N; ++i) {
            double decideDraw = vmath::rand0_1();
            
            if (decideDraw <= 0.01) {
                vn = vmath::func_1(v);
            }
            else if (decideDraw <= 0.86) {
                vn = vmath::func_2(v);
            }
            else if (decideDraw <= 0.93) {
                vn = vmath::func_3(v);
            }
            else {
                vn = vmath::func_4(v);
            }

            editableImage_.setPixel((int)(vn.x * 80) + 250, 490 - (int)(vn.y * 32), sf::Color::White);
            v = vn;
        }

        this->loadingTexture_.loadFromImage(editableImage_);
        this->renderingSprite_.setTexture(loadingTexture_);

    }
        break;
    case ButtonAction::TO_MENU_PAGE:
    {
        this->mainGui_.MenuPage();
    }
        break;
    case ButtonAction::EXIT:
    {
        window.close();
    }
        break;
    default:
        break;
    }
}

void TLogic::InteractPolygon(sf::RenderWindow &window, Button &button) {
    switch (button.enumNumber_)
    {
    case ButtonAction::DRAW_POLYGON:
    {
        using namespace vmath;
        float width = 500;
        float height = 500;
        // this->editableImage_.create(width, height, sf::Color(0, 0, 0));
        
        PolygonTexture_.create(width, height, true);
        PolygonTexture_.clear(vertexesAreaColor);

        int N = std::stoi(mainGui_.pageTextBoxes_.GetString(TextBoxes::SET_N));
        int X = std::stoi(mainGui_.pageTextBoxes_.GetString(TextBoxes::SET_X));
        int Y = std::stoi(mainGui_.pageTextBoxes_.GetString(TextBoxes::SET_Y));
        
        if (N < 2)
            break;

        Point startPoint(X, Y);
        Polygon intPoly = makeIntPolygon(startPoint, N);
        Polygon tttPoly = makeRegularPolygon(startPoint, N);
        // calculate(intPoly, startPoint);

        intPoly.ChangePosition({2 * width / 3, height / 2});
        tttPoly.ChangePosition({2 * width / 3, height / 2});

        PolygonTexture_.draw(intPoly);
        PolygonTexture_.draw(tttPoly);

        this->renderingSprite_.setTexture(PolygonTexture_.getTexture());
    }
        break;
    case ButtonAction::TO_MENU_PAGE:
    {
        this->mainGui_.MenuPage();
    }
        break;
    case ButtonAction::EXIT:
    {
        window.close();
    }
        break;
    default:
        break;
    }
}

void TLogic::InteractFiles(sf::RenderWindow &window, Button &button) {
    switch (button.enumNumber_)
    {
    case ButtonAction::SAVE_IMAGE:
    {
        std::string path(__FILE__);
        std::cout << __FILE__ << std::endl;
        path = path.substr(0, path.rfind('/')); // ../folder/gui
        path = path.substr(0, path.rfind('/') + 1); // ../folder/

        std::string filename = this->mainGui_.pageTextBoxes_.GetString(TextBoxes::SET_FILENAME);
        this->editableImage_.saveToFile(path + "pictures/" + filename);
    }
        break;
    case ButtonAction::TO_MENU_PAGE:
    {
        this->mainGui_.MenuPage();
    }
        break;
    case ButtonAction::EXIT:
    {
        window.close();
    }
        break;
    default:
        break;
    }
}

void TLogic::guiInteraction(sf::RenderWindow &window, Button &button) {    
    switch (this->mainGui_.getCurrentPage())
    {
    case GuiPage::MENU_PAGE:
    {
        this->InteractMenu(window, button);
    }
        break;
    case GuiPage::FERN:
    {
        this->InteractFern(window, button);
    }
        break;
    case GuiPage::SIERPINSKI:
    {
        this->InteractSierpinski(window, button);
    }
        break;
    case GuiPage::POLYGON:
    {
        this->InteractPolygon(window, button);
    }
        break;
    case GuiPage::SAVE:
    {
        this->InteractFiles(window, button);
    }
        break;
    default:
        break;
    }
}

void TLogic::Render(sf::RenderWindow &mainWindow) {
    if (!isMainWindowActive_) {
        return;
    }

    mainWindow.clear(backgroundColor);
    graphWorkspace_.Render(mainWindow);

    mainGui_.Render(mainWindow);

    mainWindow.draw(renderingSprite_);

    mainWindow.display();
}

void TLogic::ReadInputs(sf::RenderWindow &mainWindow) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(mainWindow);
    sf::Event e;

    while (mainWindow.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            mainWindow.close();
        }
        mainGui_.TakeInputs(e, mainWindow);

        if (e.type == sf::Event::MouseButtonPressed &&
            e.mouseButton.button == sf::Mouse::Left) {
            // define which button has clicked
            for (auto &button : mainGui_.pageButtons_.buttons_)
                if (button.Contains(mousePosition)) {
                    guiInteraction(mainWindow, button);
                    // this->TPageManager.interact();    
                }
        }

        if (e.type == sf::Event::LostFocus) {
            isMainWindowActive_ = false;
        }
        else if (e.type == sf::Event::GainedFocus) {
            isMainWindowActive_ = true;
        }
    }
}