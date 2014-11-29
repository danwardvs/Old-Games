/*Written by Danward Van Stemp, With collaboration with A.D.S. Games©
* ©2012 iPod Emulator
*/

#include<allegro.h>

BITMAP* buffer;
BITMAP* homescreen;
BITMAP* calendar;
BITMAP* calendarpage;
BITMAP* cursor;
BITMAP* lockoff;
BITMAP* lockon;
BITMAP* slider;
BITMAP* mappage;
BITMAP* mapicon;
BITMAP* calpage;
BITMAP* calicon;
BITMAP* debugicon;

double cal1;
int decimaldigit;
int decimal2;
int decimal;
int debugtoggle;
int digit;
int calnew;
int display;
int calP;
int slide;
int lock=2;
int home=0;
int calendarP=0;
int mapsP;

void calMath(){
     
     if(decimal2!=1 && decimal!=1){
     if(calnew==10){cal1=cal1-1;}
     cal1=cal1*10;
     cal1=cal1+calnew;
     display=cal1;
     digit=digit+5;
     rest(200);
     }
     if(decimal2==1){
                     if(calnew==10){decimal=decimal-1;}
                     decimal=decimal*10;
                     decimal=decimal+calnew;
                     
                     decimaldigit=decimaldigit+10;
                     }
}

void update(){
     draw_sprite( screen, buffer, 0, 0);
      
     /* Home-key routines*/
     if(key[KEY_H]){
                    if(lock==0){
                                home=0; calendarP=0; mapsP=0; calP=0;}
                    if(lock==1){lock=2;}
                    }
     /*Lock-button routines*/
     if(key[KEY_L]){
                    if(lock==0){lock=1;rest(200);}
                    else{lock=2;}
                    }
     /*Draw homescreen routines*/
     if(home==0){
      draw_sprite( buffer, homescreen, 0, 0);
      draw_sprite( buffer, calendar, 163, 26);
      draw_sprite( buffer, mapicon, 3, 205);
      draw_sprite( buffer, calicon, 236,204 );
      draw_sprite( buffer, debugicon, 235,294 );
      }
     /*Calendar routines*/
     if(calendarP==1 && lock==0){draw_sprite( buffer, calendarpage, 0, 0);}
                                      
      if(mouse_b & 1 && mouse_x>163 && mouse_x<221 && mouse_y>26 && mouse_y<83){
                 home=1;
                 calendarP=1;
                 }
     
     /*Map routines*/
     if(mapsP==1 && lock==0){draw_sprite( buffer, mappage, 0, 0);}
                                      
      if(mouse_b & 1 && mouse_x>3 && mouse_x<60 && mouse_y>205 && mouse_y<263){
                 home=1;
                 mapsP=1;
                 }
       /*Calculator routines*/
     if(calP==1 && lock==0){
                draw_sprite( buffer, calpage, 0, 0);
                textprintf_ex(buffer,font,240-digit,80,makecol(0,0,0),-1,"%i",display);
                
      if(mouse_b & 1 && mouse_x>11 && mouse_x<75 && mouse_y>365 && mouse_y<406){calnew=1; calMath();}
      if(mouse_b & 1 && mouse_x>89 && mouse_x<153 && mouse_y>365 && mouse_y<406){calnew=2; calMath();}
      if(mouse_b & 1 && mouse_x>167 && mouse_x<231 && mouse_y>365 && mouse_y<406){calnew=3; calMath();}
      if(mouse_b & 1 && mouse_x>11 && mouse_x<153 && mouse_y>427 && mouse_y<466 && digit!=0){calnew=10; calMath();}
      if(mouse_b & 1 && mouse_x>11 && mouse_x<75 && mouse_y>305 && mouse_y<345){calnew=4; calMath();}
      if(mouse_b & 1 && mouse_x>89 && mouse_x<153 && mouse_y>305 && mouse_y<345){calnew=5; calMath();}
      if(mouse_b & 1 && mouse_x>167 && mouse_x<231 && mouse_y>305 && mouse_y<345){calnew=6; calMath();}
      if(mouse_b & 1 && mouse_x>11 && mouse_x<75 && mouse_y>244 && mouse_y<284){calnew=7; calMath();}
      if(mouse_b & 1 && mouse_x>89 && mouse_x<153 && mouse_y>244 && mouse_y<284){calnew=8; calMath();}
      if(mouse_b & 1 && mouse_x>167 && mouse_x<231 && mouse_y>244 && mouse_y<284){calnew=9; calMath();}
      if(mouse_b & 1 && mouse_x>167 && mouse_x<231 && mouse_y>427 && mouse_y<467){decimal2=1; calMath();}
      }                                        
      if(mouse_b & 1 && mouse_x>236 && mouse_x<293 && mouse_y>205 && mouse_y<263){
                 home=1;
                 calP=1;
                 } 
      /*Debug routines*/
                                 
      if(mouse_b & 1 && mouse_x>235 && mouse_x<292 && mouse_y>294 && mouse_y<351){
                 debugtoggle=1;
                 } 
      if(debugtoggle==1){
                         textprintf_ex(buffer,font,10,10,makecol(1234,123,123),-1,"Cal New- %i",calnew);
                         } 
       
       /*Lockpage routines*/
       if(lock==1){draw_sprite( buffer, lockoff, 0,0);}
       
       if(lock==2){draw_sprite( buffer, lockon, 0,0);}
       
       if(lock==2){
                   if(mouse_b & 1 && mouse_y>408 && mouse_y<452 && mouse_x>22 && mouse_x<92){
                   slide=1;
                   }
       }
       /*Slider draw routines*/
       if(slide==1){draw_sprite( buffer, slider, mouse_x,408);}
       
       if(lock==2 && slide==0){draw_sprite( buffer, slider, 22,408);}
       
       /*Slider stopslide routines*/
       if(slide==1){
                    if(mouse_y>452){slide=0;}
                    if(mouse_y<408){slide=0;}
                    if(mouse_x<22){slide=0;}
                    if(!mouse_b & 1){slide=0;}
                    if(lock==0){slide=0;}
                    }
       /*Unlock routines*/
       if(slide==1 && mouse_x>230){lock=0;}
                                   
       
       /*Draw cursor routines*/
       draw_sprite( buffer, cursor, mouse_x, mouse_y);

}

void setup(){
     /*creating buffer*/
     buffer = create_bitmap( 320, 475);
     
     /*Assigning .bmp file to BITMAP*/
     homescreen = load_bitmap( "ipodhome.bmp", NULL);
     calendar = load_bitmap( "calendaricon.bmp", NULL);
     calendarpage = load_bitmap( "calendarpage.bmp", NULL);
     cursor = load_bitmap( "cursor.bmp", NULL);
     lockoff = load_bitmap( "lockscreen.bmp", NULL);
     lockon = load_bitmap( "lockonslide.bmp", NULL);
     slider = load_bitmap( "slider.bmp", NULL);
     mappage = load_bitmap( "maps.bmp", NULL);
     mapicon = load_bitmap( "mapicon.bmp", NULL);
     calpage = load_bitmap( "calculator.bmp", NULL);
     calicon = load_bitmap( "calculatoricon.bmp", NULL);
     debugicon = load_bitmap( "debugicon.bmp", NULL);
}

int main(){
    
    allegro_init();
    install_mouse();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 320, 475, 0, 0);
    set_window_title("iPod Emulator(C)");
    
    setup();
    
    while( !key[KEY_ESC]){
           
           update();
           
           
    }

    return 0;
    
}
END_OF_MAIN();
