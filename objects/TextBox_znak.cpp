#include "TextBox_znak.h"

TextBox_znak::TextBox_znak(float rozmiar_x, float rozmiar_y, float initialX, float initialY, sf::Color color, sf::RenderWindow* window, sf::Keyboard::Key bind,
	int character_size)
{
	shape.setSize(sf::Vector2f(rozmiar_x, rozmiar_y));
	shape.setFillColor(color);
	if (!font.loadFromFile("fonts/ARIAL.TTF"))
		std::cout << "Nie zaladowano fonta" << std::endl;
	text.setFont(font);
    this->bind = bind;
	text.setString(klawisz_na_unicode(this->bind));
	text.setCharacterSize(character_size);
	text.setFillColor(sf::Color::Black);
	text.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
	text.setPosition(initialX + rozmiar_x / 2, initialY + rozmiar_y / 2);
	setPos(initialX, initialY);
	this->window = window;
	this->rozmiar_x = rozmiar_x;
	this->rozmiar_y = rozmiar_y;
}

void TextBox_znak::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
	shape.setPosition(x, y);
}

sf::Vector2f TextBox_znak::getPos()
{
	return sf::Vector2f(x, y);
}

bool TextBox_znak::mouse_over()
{
	sf::Vector2i pos1 = sf::Vector2i(sf::Mouse::getPosition(*window));
	sf::Vector2f pos = window->mapPixelToCoords(pos1);
	return shape.getGlobalBounds().contains(pos.x, pos.y);
}

bool TextBox_znak::clicked(sf::Event event)
{

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (!mouse_over()) {
            pomoc = false;
            pomoc1 = true;
            zmien_nazwe(klawisz_na_unicode(this->bind));
            return false;
        }
        return true;
    }
    return false;
}

void TextBox_znak::render()
{
	window->draw(shape);
}

void TextBox_znak::zmien_nazwe(std::string napis)
{
	text.setString(napis);
	text.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
	text.setPosition(x + (rozmiar_x / 2), y + (rozmiar_y / 2));
}


void TextBox_znak::key_bind(sf::Event event)
{
	if (clicked(event))
		pomoc = true;
	if (pomoc && pomoc1)
	{
		pomoc1 = false;
		zmien_nazwe("[Wprowadz]");
	}
	if (pomoc)
	{
		if (event.type == sf::Event::KeyPressed 
            && event.key.scancode != sf::Keyboard::Scancode::Escape 
            && event.key.scancode != sf::Keyboard::Scancode::LSystem
            && event.key.scancode != sf::Keyboard::Scancode::RSystem)
		{
            if (klawisz_na_unicode(sf::Keyboard::localize(event.key.scancode)) == "Unknown")
                return;
			bind = sf::Keyboard::localize(event.key.scancode);
            zmien_nazwe(klawisz_na_unicode(bind));
            pomoc = false;
            pomoc1 = true;
			
		}
	}
}

std::string TextBox_znak::klawisz_na_unicode(sf::Keyboard::Key k)
{
        std::string ret;
        switch (k) {

        case sf::Keyboard::A:

            ret = "A";
            break;
        case sf::Keyboard::B:

            ret = "B";
            break;
        case sf::Keyboard::C:

            ret = "C";
            break;
        case sf::Keyboard::D:

            ret = "D";
            break;
        case sf::Keyboard::E:

            ret = "E";
            break;
        case sf::Keyboard::F:

            ret = "F";
            break;
        case sf::Keyboard::G:

            ret = "G";
            break;
        case sf::Keyboard::H:

            ret = "H";
            break;
        case sf::Keyboard::I:

            ret = "I";
            break;
        case sf::Keyboard::J:

            ret = "J";
            break;
        case sf::Keyboard::K:

            ret = "K";
            break;
        case sf::Keyboard::L:

            ret = "L";
            break;
        case sf::Keyboard::M:

            ret = "M";
            break;
        case sf::Keyboard::N:

            ret = "N";
            break;
        case sf::Keyboard::O:

            ret = "O";
            break;
        case sf::Keyboard::P:

            ret = "P";
            break;
        case sf::Keyboard::Q:

            ret = "Q";
            break;
        case sf::Keyboard::R:

            ret = "R";
            break;
        case sf::Keyboard::S:

            ret = "S";
            break;
        case sf::Keyboard::T:

            ret = "T";
            break;
        case sf::Keyboard::U:

            ret = "U";
            break;
        case sf::Keyboard::V:

            ret = "V";
            break;
        case sf::Keyboard::W:

            ret = "W";
            break;
        case sf::Keyboard::X:

            ret = "X";
            break;
        case sf::Keyboard::Y:

            ret = "Y";
            break;
        case sf::Keyboard::Z:

            ret = "Z";
            break;
        case sf::Keyboard::Num0:

            ret = "0";
            break;
        case sf::Keyboard::Num1:

            ret = "1";
            break;
        case sf::Keyboard::Num2:

            ret = "2";
            break;
        case sf::Keyboard::Num3:

            ret = "3";
            break;
        case sf::Keyboard::Num4:

            ret = "4";
            break;
        case sf::Keyboard::Num5:

            ret = "5";
            break;
        case sf::Keyboard::Num6:

            ret = "6";
            break;
        case sf::Keyboard::Num7:

            ret = "7";
            break;
        case sf::Keyboard::Num8:

            ret = "8";
            break;
        case sf::Keyboard::Num9:

            ret = "9";
            break;
        case sf::Keyboard::Escape:

            ret = "Escape";
            break;
        case sf::Keyboard::LControl:

            ret = "LControl";
            break;
        case sf::Keyboard::LShift:

            ret = "LShift";
            break;
        case sf::Keyboard::LAlt:

            ret = "LAlt";
            break;
        case sf::Keyboard::LSystem:

            ret = "LSystem";
            break;
        case sf::Keyboard::RControl:

            ret = "RControl";
            break;
        case sf::Keyboard::RShift:

            ret = "RShift";
            break;
        case sf::Keyboard::RAlt:

            ret = "RAlt";
            break;
        case sf::Keyboard::RSystem:

            ret = "RSystem";
            break;
        case sf::Keyboard::Menu:

            ret = "Menu";
            break;
        case sf::Keyboard::LBracket:

            ret = "[";
            break;
        case sf::Keyboard::RBracket:

            ret = "]";
            break;
        case sf::Keyboard::SemiColon:

            ret = ";";
            break;
        case sf::Keyboard::Comma:

            ret = ",";
            break;
        case sf::Keyboard::Period:

            ret = ".";
            break;
        case sf::Keyboard::Quote:

            ret = "\"";
            break;
        case sf::Keyboard::Slash:

            ret = "/";
            break;
        case sf::Keyboard::BackSlash:

            ret = "\\";
            break;
        case sf::Keyboard::Tilde:

            ret = "~";
            break;
        case sf::Keyboard::Equal:

            ret = "=";
            break;
        case sf::Keyboard::Hyphen:

            ret = "-";
            break;
        case sf::Keyboard::Space:

            ret = "Space";
            break;
        case sf::Keyboard::Return:

            ret = "Enter";
            break;
        case sf::Keyboard::BackSpace:

            ret = "BackSpace";
            break;
        case sf::Keyboard::Tab:

            ret = "Tab";
            break;
        case sf::Keyboard::PageUp:

            ret = "PageUp";
            break;
        case sf::Keyboard::PageDown:

            ret = "PageDown";
            break;
        case sf::Keyboard::End:

            ret = "End";
            break;
        case sf::Keyboard::Home:

            ret = "Home";
            break;
        case sf::Keyboard::Insert:

            ret = "Insert";
            break;
        case sf::Keyboard::Delete:

            ret = "Delete";
            break;
        case sf::Keyboard::Add:

            ret = "+";
            break;
        case sf::Keyboard::Subtract:

            ret = "-";
            break;
        case sf::Keyboard::Multiply:

            ret = "*";
            break;
        case sf::Keyboard::Divide:

            ret = "/";
            break;
        case sf::Keyboard::Left:

            ret = "Left";
            break;
        case sf::Keyboard::Right:

            ret = "Right";
            break;
        case sf::Keyboard::Up:

            ret = "Up";
            break;
        case sf::Keyboard::Down:

            ret = "Down";
            break;
        case sf::Keyboard::Numpad0:

            ret = "Numpad0";
            break;
        case sf::Keyboard::Numpad1:

            ret = "Numpad1";
            break;
        case sf::Keyboard::Numpad2:

            ret = "Numpad2";
            break;
        case sf::Keyboard::Numpad3:

            ret = "Numpad3";
            break;
        case sf::Keyboard::Numpad4:

            ret = "Numpad4";
            break;
        case sf::Keyboard::Numpad5:

            ret = "Numpad5";
            break;
        case sf::Keyboard::Numpad6:

            ret = "Numpad6";
            break;
        case sf::Keyboard::Numpad7:

            ret = "Numpad7";
            break;
        case sf::Keyboard::Numpad8:

            ret = "Numpad8";
            break;
        case sf::Keyboard::Numpad9:

            ret = "Numpad9";
            break;
        case sf::Keyboard::F1:

            ret = "F1";
            break;
        case sf::Keyboard::F2:

            ret = "F2";
            break;
        case sf::Keyboard::F3:

            ret = "F3";
            break;
        case sf::Keyboard::F4:

            ret = "F4";
            break;
        case sf::Keyboard::F5:

            ret = "F5";
            break;
        case sf::Keyboard::F6:

            ret = "F6";
            break;
        case sf::Keyboard::F7:

            ret = "F7";
            break;
        case sf::Keyboard::F8:

            ret = "F8";
            break;
        case sf::Keyboard::F9:

            ret = "F9";
            break;
        case sf::Keyboard::F10:

            ret = "F10";
            break;
        case sf::Keyboard::F11:

            ret = "F11";
            break;
        case sf::Keyboard::F12:

            ret = "F12";
            break;
        case sf::Keyboard::F13:

            ret = "F13";
            break;
        case sf::Keyboard::F14:

            ret = "F14";
            break;
        case sf::Keyboard::F15:

            ret = "F15";
            break;
        case sf::Keyboard::Pause:

            ret = "Pause";
            break;
        case sf::Keyboard::KeyCount:

            ret = "KeyCount";
            break;

        default:
            ret = "Unknown";
            break;
        }
        return ret;

}