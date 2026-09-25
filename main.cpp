#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <path_to_image>\n";
    return 1;
  }

  const std::string imagePath = argv[1];

  sf::Texture texture;
  if (!texture.loadFromFile(imagePath)) {
    std::cerr << "Error: could not load image \"" << imagePath << "\"\n";
    return 1;
  }

  sf::Sprite sprite(texture);
  sf::Vector2u imgSize = texture.getSize();

  // Start the window at the image size (capped so huge images don't
  // spawn a window bigger than the screen).
  unsigned int winW = std::min(imgSize.x, 1600u);
  unsigned int winH = std::min(imgSize.y, 900u);

  sf::RenderWindow window(sf::VideoMode(winW, winH),
                          "C++ Image Viewer - " + imagePath,
                          sf::Style::Default);
  window.setFramerateLimit(60);

  sf::View view = window.getDefaultView();
  const sf::View defaultView = view;

  bool dragging = false;
  sf::Vector2i lastMousePos;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
          window.close();
        if (event.key.code == sf::Keyboard::R) {
          view = defaultView;
          window.setView(view);
        }
      }

      if (event.type == sf::Event::Resized) {
        sf::FloatRect visibleArea(0, 0, static_cast<float>(event.size.width),
                                  static_cast<float>(event.size.height));
        view = sf::View(visibleArea);
        window.setView(view);
      }

      if (event.type == sf::Event::MouseWheelScrolled) {
        float zoomFactor = (event.mouseWheelScroll.delta > 0) ? 0.9f : 1.1f;
        view.zoom(zoomFactor);
        window.setView(view);
      }

      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          dragging = true;
          lastMousePos = sf::Mouse::getPosition(window);
        }
      }

      if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left)
          dragging = false;
      }

      if (event.type == sf::Event::MouseMoved && dragging) {
        sf::Vector2i newPos = sf::Mouse::getPosition(window);
        sf::Vector2f delta = window.mapPixelToCoords(lastMousePos) -
                             window.mapPixelToCoords(newPos);
        view.move(delta);
        window.setView(view);
        lastMousePos = newPos;
      }
    }

    window.clear(sf::Color(30, 30, 30));
    window.draw(sprite);
    window.display();
  }

  return 0;
}
