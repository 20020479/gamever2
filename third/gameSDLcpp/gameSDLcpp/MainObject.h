#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_
#include"COMMON_FUNCTION.h"
#include"BaseObject.h"
#include"Bullet.h"
#include<vector>
#define WIDTH_MAIN_OBJECT 91
#define HEIGHT_MAIN_OBJECT 56
class MainObject: public BaseObject
{  
public:
	MainObject();
	~MainObject();
	void HandleInputAction(SDL_Event events);
	void HandleMove();
	void Set_bullet_list(std::vector<Bullet*> bullet_list)
	{
		p_bullet_list = bullet_list;
	}
	std::vector<Bullet*>Getbulletlist() const
	{
		return p_bullet_list;
	}
private:
	int x_val_;
	int y_val_;

	 std:: vector<Bullet*>  p_bullet_list;

};


#endif