#include<allegro.h>

BITMAP* buffer;
BITMAP* back;
BITMAP* image1;
BITMAP* hButton;
BITMAP* resizer;
BITMAP* screenshot;
BITMAP* saved;

int saveloop;
int save;
int w=250;
int h=250;
int dragClick;
int resizeX;
int resizeY;

void Vscreenshot(){
            screenshot = create_sub_bitmap(screen, 0, 0, SCREEN_W, SCREEN_H);
            save_bitmap("screenshot.bmp", screenshot, NULL);
            destroy_bitmap(screenshot);
}

void square(){
              if(h>w){
                      do{
                         h--;
                         }while(h!=w);
                         }
              if(w>h){
                      do{
                         w--;
                         }while(w!=h);
                         }
                         
}
void update(){
     draw_sprite(screen,buffer,0,0);
     
     draw_sprite(buffer,back,0,0);
     
     draw_sprite(buffer,resizer,w-41,h-36);
     
     if(save==0){
                 stretch_sprite(buffer, image1, 0, 0, w, h);
     }else{
           stretch_sprite(buffer, image1, 640-w, 480-h, w, h);
           }
     if(key[KEY_DOWN]){h++;}
     if(key[KEY_UP]){h--;}
     if(key[KEY_LEFT]){w--;}
     if(key[KEY_RIGHT]){w++;}
     
     if(mouse_b & 1 && mouse_x>w && mouse_x+9 && mouse_y<h+9 && mouse_y>h-36){dragClick=1;}
     if(mouse_b & 1 && mouse_x>w-36 && mouse_x && mouse_y<h && mouse_y>h-9){dragClick=1;}
     
     if(dragClick==1){w=w+mouse_x-w; h=h+mouse_y-h;}
     if(!mouse_b & 1){dragClick=0;}
     
     if(key[KEY_S]){square();}
     if(key[KEY_LSHIFT]){square();}
     if(key[KEY_F12]){Vscreenshot();}
     saveloop++;
     if(key[KEY_A] && save==0){save=1; saveloop=0;}
     if(key[KEY_A] && save==1 && saveloop==2){saved = create_sub_bitmap(screen, 640-w, 480-h, SCREEN_W, SCREEN_H);
                   save_bitmap("resizedImage1.bmp", saved, NULL);
                   destroy_bitmap(saved);
                   save=0;
                   allegro_message("Your file has been saved as resizedImage1.bmp");
                   }
     
     textprintf_ex(buffer,font,570,20, makecol(0,0,0),-1,"%iX%i",w,h);  
     textprintf_ex(buffer,font,570,30, makecol(0,0,0),-1,"%i,%i",mouse_x,mouse_y);
     
     rest(20);
}
void setup(){
             buffer = create_bitmap( 640, 480);
             
             if (!(back = load_bitmap("back.bmp", NULL)))
             {
              allegro_message("Cannot find image Back.bmp\nPlease check your files and try again");
              exit(-1);
    }
    if (!(image1 = load_bitmap("image1.bmp", NULL)))
             {
              allegro_message("Cannot find image Image1.bmp\nPlease check your files and try again");
              exit(-1);

  }
    if (!(resizer = load_bitmap("resizer.bmp", NULL)))
             {
              allegro_message("Cannot find image Image1.bmp\nPlease check your files and try again");
              exit(-1);
}
}
int main(){
    
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(16);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,".");
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    
    show_mouse(screen);
    
    set_window_title("Error");
    setup();
    set_window_title("Image Resizer");
    while( !key[KEY_ESC]){

           update();
           
           
    }

    return 0;
    
}
END_OF_MAIN();
