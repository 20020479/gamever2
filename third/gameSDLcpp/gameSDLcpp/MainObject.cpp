

#include"MainObject.h"
#include"COMMON_FUNCTION.h"

MainObject::MainObject()
{ 
	rect_.x=0;
	rect_.y=0;
	rect_.h=HEIGHT_MAIN_OBJECT;
	rect_.w=WIDTH_MAIN_OBJECT;
	x_val_=0;
	y_val_=0;

}
 MainObject::~MainObject()
{

}
void MainObject::  HandleInputAction(SDL_Event events)
{
	if(events.type == SDL_KEYDOWN )
	{
		switch(events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_-=HEIGHT_MAIN_OBJECT/10;
			break;
		case SDLK_DOWN:
			//todo
			y_val_+=HEIGHT_MAIN_OBJECT/10;
			break;
		case SDLK_LEFT:
			//todo
			x_val_-=WIDTH_MAIN_OBJECT/10;
			break;
		case SDLK_RIGHT:
			x_val_+=WIDTH_MAIN_OBJECT/10;
			//todo
			break;

		default:
			break;

		}
	}
	else if(events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_+=HEIGHT_MAIN_OBJECT/10;
			break;
		case SDLK_DOWN:
			y_val_-=HEIGHT_MAIN_OBJECT/10;
			break;
		case SDLK_LEFT:
			x_val_+=WIDTH_MAIN_OBJECT/10;
			break;
		case SDLK_RIGHT:
			x_val_-=WIDTH_MAIN_OBJECT/10;
			break;
		default:
			break;
		}
	}
	else if (events.type == SDL_MOUSEBUTTONUP)
	{
		Bullet* p_bullet = new Bullet();
        if (events.button.button == SDL_BUTTON_LEFT)
        {
            p_bullet->setwidthheight(WIDTH_LAZER, HEIGHT_LAZER);
			p_bullet->LoadImage("img/laser.png");
			p_bullet->set_type(Bullet::LAZER);
		}
		 else if (events.button.button == SDL_BUTTON_RIGHT)
        {
			p_bullet->setwidthheight(WIDTH_SPHERE, HEIGHT_SPHERE);
			p_bullet->LoadImage("img/sphere.png");
			p_bullet->set_type(Bullet::SPHERE);
           
        }
        p_bullet->SetRect(this->rect_.x + 20, this->rect_.y + 22);
        p_bullet->set_is_move(true);
        p_bullet_list.push_back(p_bullet);
	}
	else if(events.type == SDL_MOUSEBUTTONDOWN)
	{
		  
	}

}
void MainObject::HandleMove()
{
	rect_.x+=x_val_;
	if(rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH)
	{
		rect_.x-=x_val_;
	}



	rect_.y+=y_val_;
	if(rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT-50 )
	{
		rect_.y-=y_val_;
	}
}
