#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#define PI 3.14159265

using namespace std;
using namespace sf;

int main()
{
    bool ke1,ke2,ke3,ke4;
    float yaan_ki_gatix=0,yaan_ki_gatiy=0;
    int gati=-5;
    float tvaran=0.005;
    float disha=0.0;
    double more=0;
    float dhruv_x,dhruv_y,dhruv_x1,dhruv_y1;
    
    Texture brahman_d,brahman_ds;
    brahman_d.loadFromFile("spacebg.png");
    brahman_d.setRepeated(true);
    
    IntRect irect(FloatRect(-500000,-500000,1000000,1000000));
    
    Sprite space(brahman_d,irect);
    space.setPosition(-500000,-500000);
    
    brahman_ds.loadFromFile("star.png");
    brahman_ds.setRepeated(true);
    
    IntRect irect1(FloatRect(-500000,-500000,1000000,1000000));
    
    Sprite space1(brahman_ds,irect1);
    space1.setPosition(-500000,-500000);
    
    Texture yan;
    yan.loadFromFile("Yaan.png");
    yan.setSmooth(true);
    Sprite r1(yan);
    r1.setOrigin(33,33);
    r1.setPosition(400,300);
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Majestic Window");
    window.setFramerateLimit(60);
    
    View v1=window.getDefaultView();
    
    Keyboard k1;
    while (window.isOpen())
    {
        sf::Event event;
       
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        ke1=k1.isKeyPressed(Keyboard::Key::Left);
        ke2=k1.isKeyPressed(Keyboard::Key::Up);
        ke3=k1.isKeyPressed(Keyboard::Key::Right);
        ke4=k1.isKeyPressed(Keyboard::Key::Down);
        if(ke1||ke2||ke3||ke4)
        {
            if(ke1==true)
            {
                r1.rotate(-1.3);
                if(yaan_ki_gatiy==0)
                {
                    disha=r1.getRotation();
                }
            }
            else if(ke2==true)
            {
                if(yaan_ki_gatiy>gati)
                {
                    yaan_ki_gatiy-=tvaran;
                }
                
                if(disha!=r1.getRotation())
                {
                    if(disha-r1.getRotation()<0.8 && disha-r1.getRotation()>-0.8)
                    {
                        disha=r1.getRotation();
                    }
                    if(disha>r1.getRotation())
                    {
						if(disha-r1.getRotation()>180)
						{
							disha+=0.8;
						}
						else
						{
							disha-=0.8;
						}
                        
                    }
                    else
                    {
                        if(r1.getRotation()-disha>180)
						{
							disha-=0.8;
						}
						else
						{
							disha+=0.8;
						}
                    }
                    if(disha<0)
                    {
						disha=360.0;
					}
					if(disha>360)
					{
						disha=0.0;
					}
                }
                dhruv_x1=-yaan_ki_gatiy*sin(disha*PI/180);
                dhruv_y1=yaan_ki_gatiy*cos(disha*PI/180);
                
            }
            else if(ke3==true)
            {
                r1.rotate(1.3);
                if(yaan_ki_gatiy==0)
                {
                    disha=r1.getRotation();
                }
            }
            else
            {
                if(yaan_ki_gatiy<0)
                {
                    yaan_ki_gatiy+=tvaran;
                }
                else
                {
                    yaan_ki_gatiy=0.0;
                }
                dhruv_x1=-yaan_ki_gatiy*sin(disha*PI/180);
                dhruv_y1=yaan_ki_gatiy*cos(disha*PI/180);
            }
        }
        //cout<<disha<<" "<<r1.getRotation()<<"\n";
        if(yaan_ki_gatiy!=0)
        {
            r1.move(dhruv_x1,dhruv_y1);
            v1.move(dhruv_x1,dhruv_y1);
            space1.move(dhruv_x1/2,dhruv_y1/2);
            window.setView(v1);
        }
        
        window.clear(Color::Black);
        window.draw(space);
        window.draw(space1);
        window.draw(r1);
        window.display();
    }
}
