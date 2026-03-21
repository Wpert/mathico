#include "../include/ui_lib/page.hpp"
#include "../tcolors.hpp"

using namespace vie;

void WorkArea::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(area_, states);
}

WorkArea::WorkArea(sf::Vector2f pos, sf::Vector2f size)
{
    area_.setSize(size);
    area_.setPosition(pos);
    area_.setFillColor(vertexesAreaColor);
}

void WorkArea::setSize(sf::Vector2f size)
{
    area_.setSize(size);
}

void WorkArea::setColor(sf::Color clr)
{
    area_.setFillColor(clr);
}

PageManager::PageManager() : area_({220, 10}, {794, 580}){};

PageManager::~PageManager()
{
}

void PageManager::takeInputs(sf::RenderWindow &window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    while (const std::optional<sf::Event> e = window.pollEvent())
    {
        if (!e.has_value())
        {
            continue;
        }

        assert(e.has_value());

        buttons_.takeInput(e, window);
        sliders_.takeInput(e, window);
        textboxes_.takeInput(e, window);

        if (e->is<sf::Event::Closed>())
        {
            window.close();
            break;
        }

        // do i really need to check it iside buttons and etc ?
        // i mean i do check here, so no need to double check
        if (e->is<sf::Event::MouseButtonPressed>() &&
            e->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left)
        {
            // define which button has clicked
            for (const auto &button : buttons_)
            {
                assert(button.get() && "nullptr");
                if (button->contains(mousePosition))
                {
                    bool exitFlag = button->callFunc();
                    if (exitFlag)
                        break;
                }
            }
        }

        if (e->is<sf::Event::FocusLost>())
        {
            isMainWindowActive_ = false;
        }
        else if (e->is<sf::Event::FocusGained>())
        {
            isMainWindowActive_ = true;
        }
    }
}

void PageManager::clearPage()
{
    buttons_.clear();
    textboxes_.clear();
    sliders_.clear();
}
