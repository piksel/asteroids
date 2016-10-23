#include "main.h"
#include "boulder.h"

using namespace std;


int difficulty = 10;
vector<Boulder*> boulders;

void loadStage()
{
  for(int i=0; i<difficulty; i++)
  {
    Boulder *boulder = new Boulder(3);
    boulders.push_back(boulder);
  }

}

int main(int argc, char *argv[])
{

  // Create the main window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids");

  sf::Clock clkUpdate;
  sf::Time frqUpdate = sf::seconds(.05);

  sf::Clock clkDraw;
  sf::Time frqDraw = sf::seconds(1.0 / 60); // 60 fps

  bool redraw = false;
  bool update = false;

  loadStage();

  while (window.isOpen())
   {
       // Process events
       sf::Event event;
       while (window.pollEvent(event))
       {
           // Close window: exit
           if (event.type == sf::Event::Closed)
               window.close();
       }

       if(clkDraw.getElapsedTime() > frqDraw) {

         // Clear screen
         window.clear();
         redraw = true;
       }
       else {
         redraw = false;
       }

       if(clkUpdate.getElapsedTime() > frqUpdate) {
         clkUpdate.restart();
         update = true;
       }
       else {
         update = false;
       }

       sf::Vector2u viewPort = window.getSize();

       for(int i=0; i<boulders.size(); i++)
       {
         Boulder* b = boulders[i];
         sf::Vector2f pos = b->Shape.getPosition();

         if(update) {

           b->Shape.move(b->Speed);
           b->Shape.rotate(b->Spin);

           //cout << viewPort.x << endl;

           if(pos.x > viewPort.x) b->Shape.setPosition(0, pos.y);
           else if(pos.x < 0) b->Shape.setPosition(viewPort.x, pos.y);

           if(pos.y > viewPort.y) b->Shape.setPosition(pos.x, 0);
           else if(pos.y < 0) b->Shape.setPosition(pos.x, viewPort.y);

         }

         if(redraw) {
           sf::FloatRect bounds = b->Shape.getGlobalBounds();
           window.draw(boulders[i]->Shape);
           if(pos.x + bounds.width > viewPort.x) {
             b->Shape.setPosition(pos.x - viewPort.x, pos.y);
             window.draw(b->Shape);
             b->Shape.setPosition(pos);
           }
           else if(pos.x + bounds.left < 0) {
            b->Shape.setPosition(viewPort.x + pos.x, pos.y);
            window.draw(b->Shape);
            b->Shape.setPosition(pos);
          }
          if(pos.y + bounds.height > viewPort.y) {
            b->Shape.setPosition(pos.x, pos.y - viewPort.y);
            window.draw(b->Shape);
            b->Shape.setPosition(pos);
          }
          else if(pos.y + bounds.top < 0) {
             b->Shape.setPosition(pos.x, viewPort.y + pos.y);
             window.draw(b->Shape);
             b->Shape.setPosition(pos);
           }
         }
       }
       // Draw the sprite
       //window.draw(sprite);
       // Draw the string
       //window.draw(text);
       // Update the window
       if(redraw) {
         window.display();
         clkDraw.restart();
       }
   }
   return EXIT_SUCCESS;

  return 0;
}
