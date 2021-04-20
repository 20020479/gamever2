#include"COMMON_FUNCTION.h"
#include"MainObject.h"
#include"ChickenObject.h"

 
bool Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	 {
      return false;
	 }
 
    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
 
	if (g_screen == NULL)
	 {
      return false;
	 }

  return true;
}

 
 
int main(int arc, char* argv[])
{  
	int bkg_y = 0;
	bool is_quit = false;
	if (Init() == false)
	return 0;
	g_bkground = SDL_CF::LoadImage("img/sky.png");
	
	if (g_bkground == NULL)
	 {
      return 0;
	 }
 
   // nhan vat chinh la may bay:
 
	MainObject plane_object;
	plane_object.SetRect(300,400);
	bool ret = plane_object.LoadImage("img/plane.png");
	if(!ret)
		{
			return 0;
		}
   
	//muc tieu duoc random len man hinh:

   Chicken* p_chickens = new Chicken[NUM_CHICKEN];
 
	for(int t = 0; t < NUM_CHICKEN; t++)
		{
			Chicken* p_chicken = (p_chickens + t);
			if(p_chicken)
			{
          
			bool  ret = p_chicken->LoadImage("img/ck1.png");
			if(ret = false)
				{
				 return 0;
				}
			p_chicken->SetRect(SCREEN_WIDTH + t*400,SCREEN_HEIGHT*0.2);
			p_chicken->set_x_val(5);

			//trứng:
			Bullet* p_egg = new Bullet();
			p_chicken->Initegg(p_egg);
	  
			}
		}


   Chicken* p_chicken = new Chicken();
   ret = p_chicken->LoadImage("img/ck1.png");
   if(ret = false)
   {
	   return 0;
   }
   p_chicken->SetRect(SCREEN_WIDTH,SCREEN_HEIGHT*0.2);
   p_chicken->set_x_val(5);


   Bullet* p_egg = new Bullet();
   p_chicken->Initegg(p_egg);



  
   while (!is_quit) 
  {
    while (SDL_PollEvent(&g_even)) 
    {
      if (g_even.type == SDL_QUIT)
      {
        is_quit = true;
        break;
      }
	  plane_object.HandleInputAction(g_even);
    }

	//man hinh va di chuyen man hinh:
	
	bkg_y += 3;
	SDL_CF:: ApplySurface(g_bkground, g_screen, 0, bkg_y);
	SDL_CF:: ApplySurface(g_bkground, g_screen, 0, bkg_y - SCREEN_HEIGHT);
	if(bkg_y >= SCREEN_HEIGHT)
	{
		bkg_y = 0;
	}
	
	plane_object.HandleMove();
	plane_object.Show(g_screen);

	
 	for(int i = 0; i < plane_object.Getbulletlist().size(); i++)
	{
		std::vector<Bullet*> bullet_list = plane_object.Getbulletlist();
		Bullet* p_bullet = bullet_list.at(i);
		if(p_bullet!= NULL)
		{
			if(p_bullet->get_is_move())
			{
				p_bullet->Show(g_screen);
				p_bullet->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				//check collision bullet and chicken:
				bool check = SDL_CF::checkcollision(p_bullet->GetRect(), p_chicken->GetRect());
				if(check)
				{
					delete [] p_chicken;
					delete[] p_bullet;
					 SDL_CF:: CleanUp();
					  SDL_Quit();
					  return 1;

				}
				

			}
			else
			{
				if(p_bullet!= NULL)
				{
					bullet_list.erase(bullet_list.begin()+i);
					plane_object.Set_bullet_list(bullet_list);
					delete p_bullet;
					p_bullet = NULL;
				}
			}
		}
	}
 
	//run chicken
	for(int tt=0; tt<NUM_CHICKEN; tt++)
	{
		  Chicken* p_chicken = p_chickens + tt;
		if(p_chicken)
		{
			
			  p_chicken->HandleMoveRight(SCREEN_WIDTH, SCREEN_HEIGHT);
			  p_chicken->Show(g_screen);
			 p_chicken->Makeegg(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
			 

			  
		// check collision plane and threat:
			 bool is_col = SDL_CF::checkcollision(plane_object.GetRect(), p_chicken->GetRect());
			 if(is_col)
			 {
				  if( MessageBox(NULL,L"GAME OVER!", L"END",MB_OK) == IDOK)
				 {
					 delete [] p_chickens;
					 SDL_CF:: CleanUp();
					  SDL_Quit();
					  return 1;
				 }
			 }
			
		}
	
	}
	

    
  }
  SDL_CF:: CleanUp();
  SDL_Quit();
   return 1;
}