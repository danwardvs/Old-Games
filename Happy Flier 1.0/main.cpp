 #include<allegro.h>

BITMAP* buffer;
BITMAP* robot;
BITMAP* robotfire;
BITMAP* menu;
BITMAP* space;

int gravity;
int window;
int speed;
int rocket;

struct energy{
       BITMAP* energyball;
       int x;
       int y;
}energyB[1];

void game(){
              draw_sprite(screen,buffer,0,0);
              draw_sprite(buffer,space,0,0);
              if(rocket==0){draw_sprite(buffer,robot,20,400-gravity);}
              if(rocket==1){draw_sprite(buffer,robotfire,20,400-gravity);}
              if(key[KEY_ESC]){window=1;}
              if(key[KEY_W]){rocket=1; speed++;}
              if(!key[KEY_W]){rocket=0;speed=speed-1;}
              if(key[KEY_S]){gravity=gravity-5;}
              gravity=gravity+speed;
              gravity=gravity-2;
              if(gravity+400>800){speed=15; gravity=2;}
              if(gravity+400<250){speed=15; gravity=2;}
              
              draw_sprite(buffer,energyB[
              
              rest(20);
}
void setup(){
             buffer = create_bitmap( 800, 600);
             robot = load_bitmap( "robot.bmp", NULL);
             robotfire = load_bitmap( "robotfire.bmp", NULL);
             menu = load_bitmap( "menu.bmp", NULL);
             space = load_bitmap( "space.bmp", NULL);
             energyB[1].energyball = load_bitmap( "energyball.bmp", NULL);
}

int main(){
    
    allegro_init();
    install_mouse();
    install_keyboard();
    set_color_depth(16);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,".");
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    set_window_title("Robot Flier");
    
    
    setup();
    
    while(window!=1){

           game();
           
           
    }

    return 0;
    
}
END_OF_MAIN();
