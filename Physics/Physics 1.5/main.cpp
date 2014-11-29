#include<allegro.h>

BITMAP* buffer;
BITMAP* wood;
BITMAP* back;
BITMAP* slider;
BITMAP* cursor;
BITMAP* slidee;
BITMAP* cement;
BITMAP* rubber;
BITMAP* ipod;
BITMAP* ipodsmash;
BITMAP* newipod;
BITMAP* mainmenu;
BITMAP* backdrop;
BITMAP* play;
BITMAP* exitbutton;
BITMAP* credits;
BITMAP* creditspageB;

SAMPLE* bounce;
SAMPLE* thud;
SAMPLE* woodland;
SAMPLE* glass;

int sizeW=89;
int sizeH=69;
int angle;
int slideeX=135;
int slideeY=555;
int drag;
int TWOslideeX=335;
int TWOslideeY=555;
int TWOdrag;
int gravity;
int woodX=100;
int woodY=100;
int drop;
int stop;
int material=1;
int smash;
int menu=0;
int exitT;
int creditspage;

void update(){
              
              draw_sprite(screen,buffer,0,0);
              
              
              if(menu==0){
                          draw_sprite(buffer,mainmenu,0,0);
                          draw_sprite(buffer,play,307,200);
                          if(mouse_b & 1 && mouse_x>307 && mouse_x<482 && mouse_y>200 && mouse_y<270){
                                     menu=1;
                                     }
                          draw_sprite(buffer,exitbutton,345,400);
                          if(mouse_b & 1 && mouse_x>350 && mouse_x<535 && mouse_y>400 && mouse_y<470){
                          exitT=1;
                          }
                          draw_sprite(buffer,credits,345,350);
                          
                          if(mouse_b & 1 && mouse_x>350 && mouse_x<535 && mouse_y>350 && mouse_y<420){
                          creditspage=1;
                          }
                          if(creditspage==1){
                                             draw_sprite(buffer,creditspageB,0,0);
                                             }
                          if(key[KEY_ESC])creditspage=0;
                          }
              
              
              if(menu==1){
              
              if(key[KEY_N])smash=0;
              
              
              if(woodX>600)woodX=600;
              
              if(key[KEY_ESC])menu=0;
              
              if(drop==0)draw_sprite(buffer,back,0,0);
              if(drop==1)draw_sprite(buffer,backdrop,0,0);
              
              if(material==1){
                              stretch_sprite(buffer,wood,woodX,woodY,sizeW,sizeH);
                              draw_sprite(buffer,wood,500,100);
                              }
              if(material==2){
                              stretch_sprite(buffer,cement,woodX,woodY,sizeW,sizeH);
                              draw_sprite(buffer,cement,500,100);
                              }
              if(material==3){
                              stretch_sprite(buffer,rubber,woodX,woodY,sizeW,sizeH);
                              draw_sprite(buffer,rubber,500,100);
                              }
              if(material==4){
                              if(smash==0)stretch_sprite(buffer,ipod,woodX,woodY,sizeW,sizeH);
                              if(smash==1)stretch_sprite(buffer,ipodsmash,woodX,woodY,sizeW,sizeH);
                              draw_sprite(buffer,newipod,600,100);
                              if(mouse_b & 1 && mouse_x>600 && mouse_x<686 && mouse_y>100 && mouse_y<131){
                                         smash=0;
                                         }
                              draw_sprite(buffer,ipod,500,100);
                              }
              
              if(drop==0){
                          draw_sprite(buffer,slider,50,550);
                          draw_sprite(buffer,slider,250,550);
                          
              draw_sprite(buffer,slidee,slideeX,slideeY);
              if(mouse_b & 1 && mouse_x>slideeX-30 && mouse_x<slideeX+30 && mouse_y>slideeY-30 && mouse_y<slideeY+30){
              drag=1;           
              if(drag==1){
                          slideeX=mouse_x;
                          sizeH=(slideeX-135)+69;
                          if(slideeX<59){slideeX=59;}
                          if(slideeX>214){slideeX=214;}
              }
              }
              
              draw_sprite(buffer,slidee,TWOslideeX,TWOslideeY);
              if(mouse_b & 1 && mouse_x>TWOslideeX-30 && mouse_x<TWOslideeX+30 && mouse_y>TWOslideeY-30 && mouse_y<TWOslideeY+30){
              TWOdrag=1;           
              if(TWOdrag==1){
                          TWOslideeX=mouse_x;
                          sizeW=(TWOslideeX-335)+89;
                          if(TWOslideeX<259){TWOslideeX=259;}
                          if(TWOslideeX>414){TWOslideeX=414;}
              }
              }
              }
              if(key[KEY_E]){drop=0; gravity=0; woodX=100; woodY=100; stop=0;}
              if(key[KEY_D]){drop=1;}
              if(drop==1)woodY=woodY+gravity;
              if(drop==1 && stop==0 && !mouse_b & 1)gravity++;
              if((woodY+sizeH)>599 && gravity<10){if(material!=3){stop=1; gravity=0;}}
              if((woodY+sizeH)>596 && gravity<2){if(material==3){stop=1; gravity=0;}}
              
              if(material==1){if((woodY+sizeH)>599 && gravity>10){play_sample(woodland,255,125,1000,0); gravity=gravity-((gravity*2-10)-(sizeW/10));}
              }
              if(material==2){if((woodY+sizeH)>599 && gravity>10){play_sample(thud,255,125,1000,0); gravity=0;}
              }
              if(material==3){if((woodY+sizeH)>599 && gravity>10){play_sample(bounce,255,125,1000,0);  gravity=gravity-(gravity*2-5);}
              }
              if(material==4){if((woodY+sizeH)>599 && gravity>10){play_sample(glass,255,125,1000,0); smash=1;gravity=gravity-((gravity*2-10)-(sizeW/10));}
              }
              
              if(mouse_b & 1 && drop==1){
                                         if(material!=4){           
                                                   woodX=mouse_x-(sizeW/2);
                                                   woodY=mouse_y-(sizeH/2);
                                                   stop=0;
                                                   gravity=0;
                                                   }
                                         if(material==4){
                                                         if(mouse_x>600 && mouse_x<686 && mouse_y>100 && mouse_y<131){
                                                         }else{woodX=mouse_x-(sizeW/2);
                                                         woodY=mouse_y-(sizeH/2);
                                                         stop=0;
                                                         gravity=0;
              }                                          
              }
              }
              if(woodX>600)woodX=600;
              
              if(key[KEY_1])material=1;
              if(key[KEY_2])material=2;
              if(key[KEY_3])material=3;
              if(key[KEY_4])material=4;
              }
              
              rest(20);
              rotate_sprite(buffer, cursor, mouse_x, mouse_y, itofix(angle));
              angle++;
              
              
}

void setup(){
             buffer = create_bitmap( 800, 600);
              
              if (!(wood = load_bitmap("wood.bmp", NULL)))
             {allegro_message("Cannot find image wood.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(back = load_bitmap("back.bmp", NULL)))
             {allegro_message("Cannot find image back.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(slider = load_bitmap("slider.bmp", NULL)))
             {allegro_message("Cannot find image slider.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(cursor = load_bitmap("cursor.bmp", NULL)))
             {allegro_message("Cannot find image cursor.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(slidee = load_bitmap("slidee.bmp", NULL)))
             {allegro_message("Cannot find image slidee.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(cement = load_bitmap("cement.bmp", NULL)))
             {allegro_message("Cannot find image cement.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(rubber = load_bitmap("rubber.bmp", NULL)))
             {allegro_message("Cannot find image rubber.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(ipod = load_bitmap("ipod.bmp", NULL)))
             {allegro_message("Cannot find image ipod.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(ipodsmash = load_bitmap("ipodsmash.bmp", NULL)))
             {allegro_message("Cannot find image ipodsmash.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(newipod = load_bitmap("newipod.bmp", NULL)))
             {allegro_message("Cannot find image newipod.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(mainmenu = load_bitmap("mainmenu.bmp", NULL)))
             {allegro_message("Cannot find image mainmenu.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(backdrop = load_bitmap("backdrop.bmp", NULL)))
             {allegro_message("Cannot find image backdrop.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(play = load_bitmap("play.bmp", NULL)))
             {allegro_message("Cannot find image play.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(exitbutton = load_bitmap("exit.bmp", NULL)))
             {allegro_message("Cannot find image exit.bmp\nPlease check your files and try again");
              exit(-1);
              }
             if (!(credits = load_bitmap("credits.bmp", NULL)))
             {allegro_message("Cannot find image credits.bmp\nPlease check your files and try again");
              exit(-1);
              }
            if (!(creditspageB = load_bitmap("creditspage.bmp", NULL)))
             {allegro_message("Cannot find image creditspageB.bmp\nPlease check your files and try again");
              exit(-1);
              }

             if (!(bounce = load_sample("bounce.wav")))
             {allegro_message("Cannot find sound bounce.wav\nPlease check your files and try again");
              exit(-1);
              }
             if (!(thud = load_sample("thud.wav")))
             {allegro_message("Cannot find sound thud.wav\nPlease check your files and try again");
              exit(-1);
              }
              if (!(woodland = load_sample("woodland.wav")))
             {allegro_message("Cannot find sound woodland.wav\nPlease check your files and try again");
              exit(-1);
              }
              if (!(glass = load_sample("glass.wav")))
             {allegro_message("Cannot find sound glass.wav\nPlease check your files and try again");
              exit(-1);
              }
}
int main(){
    
    allegro_init();
    install_mouse();
    if (install_keyboard())
             {allegro_message("Physics failed to initilize a keyboard\nTry attaching a keyboard");
              exit(-1);
              }
    
    set_color_depth(16);
    if (install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"."))
             {allegro_message("Physics failed to initilize sound\n");
              exit(-1);
              }
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,".");
    set_window_title("Error");
    if (set_gfx_mode( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0))
             {allegro_message("Physics failed to initialize window\nYour screen resolution may be smaller than 800 x 600\nTry changing your resolution to larger tham 800 x 600");
              exit(-1);
              }
    
    
    setup();
    set_window_title("Physics!");
    
    while(exitT!=1){

           update();
           
           
    }

    return 0;
    
}
END_OF_MAIN();
