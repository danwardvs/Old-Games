#include<allegro.h>

BITMAP* buffer;
BITMAP* bobby;
BITMAP* scene1;
BITMAP* screenShot;

int bobX=600;
int bobY=600;
int flip;
int loop;
int angle;
int h=25;
int w=25;

void update(){
              draw_sprite( screen, buffer, 0, 0);
              draw_sprite( buffer, scene1, 0, 0);
              if(flip==0){draw_sprite(buffer,bobby, 600, 600); flip=1; loop=1;}
              if(flip==1 && loop==0){draw_sprite_h_flip(buffer,bobby, 600, 600); flip=0;}
              loop=0;
              
              angle=angle+5;                      
              rotate_sprite(buffer, bobby, 400, 600, itofix(angle));
              
              stretch_sprite(buffer, bobby, 500, 600, w, h);
              
              stretch_sprite(buffer, bobby, 300, 600, w, 50);
              
              stretch_sprite(buffer, bobby, 200, 600, 50, h);
              
              w++;
              h++;
              
              if(w==75){w=25;}
              if(h==75){h=25;}

              rest(100);
}
void setup(){
     
     buffer = create_bitmap( 900, 680);
     if (!(bobby = load_bitmap("bobby.bmp", NULL)))
    {
        allegro_message("Cannot find image Bobby.bmp\nPlease check your files and try again");
        exit(-1);
    }
      if (!(scene1 = load_bitmap("scene1.bmp", NULL)))
    {
        allegro_message("Cannot find image Scene1.bmp\nPlease check your files and try again");
        exit(-1);
    }

}
int main(){
    
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,".");
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 900, 680, 0, 0);
    
    show_mouse(screen);
    
    set_window_title("Error");
    setup();
    set_window_title("Epic Sprites");
    while( !key[KEY_ESC]){

           update();
           
           
    }

    return 0;
    
}
END_OF_MAIN();

 
