#include<allegro.h>


BITMAP* buffer;
BITMAP* bobby;
BITMAP* back1;
BITMAP* bobbyWalk;
BITMAP* bobbyLuger;
BITMAP* bobbyLugerWalk;
BITMAP* Luger;
BITMAP* BobbyLugerFire;
BITMAP* BobbyLugerReload;
BITMAP* back1_1;
BITMAP* back1_2;
BITMAP* back1_3;
BITMAP* back1_4;
BITMAP* bobbyDouble;
BITMAP* bobbyDoubleWalk;
BITMAP* bobbyDoubleFire;
BITMAP* bobbyDoubleReload;
BITMAP* Double;
BITMAP* bobbyPython;
BITMAP* bobbyPythonWalk;
BITMAP* bobbyPythonFire;
BITMAP* bobbyPythonReload;
BITMAP* Python;
BITMAP* bobbyEagle;
BITMAP* bobbyEagleWalk;
BITMAP* bobbyEagleFire;
BITMAP* bobbyEagleReload;
BITMAP* Eagle;

int eagleGet;
int ammoClipEagle;
int ammoEagle;
int pythonGet;
int ammoChamberPython;
int ammoPython;
int doubleGet;
int ammoChamberDouble;
int ammoDouble;
int reload;
int level=1;
int shootTrigger;
int ammoClipLuger;
int ammoLuger;
int scrollX;
int jumpDir;
int jumpSpeed;
int jump;
int Level_1Ground=600;
int fire;
int weapon=0;
int bobX=100;
int bobY=600;
int walk;
int walkFrame;
int walkLoop;
int aPress;
int dPress;
int lugerGet;


void update(){
              draw_sprite( screen, buffer, 0, 0);
              if(level==1){draw_sprite( buffer, back1, 0-scrollX, 0);
              draw_sprite( buffer, back1_1, 900-scrollX, 0);
              draw_sprite( buffer, back1_2, 1800-scrollX, 0);
              draw_sprite( buffer, back1_3, 2700-scrollX, 0);
              draw_sprite( buffer, back1_4, 3600-scrollX, 0);
              }
              if(weapon==0){
                             if(jump==1){draw_sprite( buffer, bobbyWalk, bobX, bobY);}
                             if(walk==0 && fire==0 && jump==0 && reload==0){draw_sprite(buffer, bobby, bobX, bobY);}
                             if(key[KEY_A] && bobX>5){bobX=bobX-5; walk=1; aPress=1;}
                             if(key[KEY_D]){bobX=bobX+5; walk=1; dPress=1;}
                             if( !key[KEY_A] && aPress==1){walk=0; aPress=0;}
                             if( !key[KEY_D] && dPress==1){walk=0; dPress=0;}
                             if(walk==1){
                                         if(walkFrame==1 && jump==0){ if(reload==0){draw_sprite( buffer, bobbyWalk, bobX, bobY);} walkFrame=0; walkLoop=1;}
                                         if(walkFrame==0 && walkLoop==0){ if(reload==0){draw_sprite( buffer, bobby, bobX, bobY);} walkFrame=1;}               
              }
              }
              if(weapon==1){
                             if(jump==1 && reload==0 && fire==0){draw_sprite( buffer, bobbyLugerWalk, bobX, bobY);}
                             if(walk==0 && fire==0 && jump==0 && reload==0){draw_sprite( buffer, bobbyLuger, bobX, bobY);}
                             if(key[KEY_A] && bobX>5){bobX=bobX-5; walk=1; aPress=1;}
                             if(key[KEY_D]){bobX=bobX+5; walk=1; dPress=1;}
                             if( !key[KEY_A] && aPress==1){walk=0; aPress=0;}
                             if( !key[KEY_D] && dPress==1){walk=0; dPress=0;}
                             if(walk==1){
                                         if(walkFrame==1 && jump==0){ if(reload==0){draw_sprite(buffer, bobbyLugerWalk, bobX, bobY);} walkFrame=0; walkLoop=1;}
                                                                                       
                                         if(walkFrame==0 && walkLoop==0){ if(reload==0){draw_sprite( buffer, bobbyLuger, bobX, bobY);} walkFrame=1;}               
              }
              }
              
              if(weapon==2){
                             if(jump==1 && reload==0 && fire==0){draw_sprite( buffer, bobbyDoubleWalk, bobX, bobY);}
                             if(walk==0 && fire==0 && jump==0 && reload==0){draw_sprite( buffer, bobbyDouble, bobX, bobY);}
                             if(key[KEY_A] && bobX>5){bobX=bobX-4; walk=1; aPress=1;}
                             if(key[KEY_D]){bobX=bobX+4; walk=1; dPress=1;}
                             if( !key[KEY_A] && aPress==1){walk=0; aPress=0;}
                             if( !key[KEY_D] && dPress==1){walk=0; dPress=0;}
                             if(walk==1){
                                         if(walkFrame==1 && jump==0){ if(reload==0){draw_sprite(buffer, bobbyDoubleWalk, bobX, bobY);} walkFrame=0; walkLoop=1;}
                                                                                       
                                         if(walkFrame==0 && walkLoop==0){ if(reload==0){draw_sprite( buffer, bobbyDouble, bobX, bobY);} walkFrame=1;} 
              
              
              }
              }
               if(weapon==3){
                             if(jump==1 && reload==0 && fire==0){draw_sprite( buffer, bobbyPythonWalk, bobX, bobY);}
                             if(walk==0 && fire==0 && jump==0 && reload==0){draw_sprite( buffer, bobbyPython, bobX, bobY);}
                             if(key[KEY_A] && bobX>5){bobX=bobX-5; walk=1; aPress=1;}
                             if(key[KEY_D]){bobX=bobX+5; walk=1; dPress=1;}
                             if( !key[KEY_A] && aPress==1){walk=0; aPress=0;}
                             if( !key[KEY_D] && dPress==1){walk=0; dPress=0;}
                             if(walk==1){
                                         if(walkFrame==1 && jump==0){ if(reload==0){draw_sprite(buffer, bobbyPythonWalk, bobX, bobY);} walkFrame=0; walkLoop=1;}
                                                                                       
                                         if(walkFrame==0 && walkLoop==0){ if(reload==0){draw_sprite( buffer, bobbyPython, bobX, bobY);} walkFrame=1;} 
              
              
              }
              }
              if(weapon==4){
                             if(jump==1 && reload==0 && fire==0){draw_sprite( buffer, bobbyEagleWalk, bobX, bobY);}
                             if(walk==0 && fire==0 && jump==0 && reload==0){draw_sprite( buffer, bobbyEagle, bobX, bobY);}
                             if(key[KEY_A] && bobX>5){bobX=bobX-5; walk=1; aPress=1;}
                             if(key[KEY_D]){bobX=bobX+5; walk=1; dPress=1;}
                             if( !key[KEY_A] && aPress==1){walk=0; aPress=0;}
                             if( !key[KEY_D] && dPress==1){walk=0; dPress=0;}
                             if(walk==1){
                                         if(walkFrame==1 && jump==0){ if(reload==0){draw_sprite(buffer, bobbyEagleWalk, bobX, bobY);} walkFrame=0; walkLoop=1;}
                                                                                       
                                         if(walkFrame==0 && walkLoop==0){ if(reload==0){draw_sprite( buffer, bobbyEagle, bobX, bobY);} walkFrame=1;} 
              
              
              }
              }
              
              if(bobX>365-scrollX && bobX<440-scrollX && weapon!=1 && bobY>599 && lugerGet==0){lugerGet=1; weapon=1; ammoLuger=132;}
              if(lugerGet==0){draw_sprite( buffer, Luger, 400-scrollX, 600);}
              
              if(bobX>465-scrollX && bobX<600-scrollX && weapon!=2 && bobY>599 && doubleGet==0){doubleGet=1; weapon=2; ammoDouble=32;}
              if(doubleGet==0){draw_sprite( buffer, Double, 500-scrollX, 600);}
              
              if(bobX>665-scrollX && bobX<725-scrollX && weapon!=3 && bobY>599 && pythonGet==0){pythonGet=1; weapon=3; ammoPython=66;}
              if(pythonGet==0){draw_sprite( buffer, Python, 700-scrollX, 600);}
              
              if(bobX>765-scrollX && bobX<825-scrollX && weapon!=4 && bobY>599 && eagleGet==0){eagleGet=1; weapon=4; ammoEagle=67;}
              if(eagleGet==0){draw_sprite( buffer, Eagle, 800-scrollX, 600);}

              if(weapon==1){textprintf_ex(buffer,font,15,15, makecol(0,0,0),-1,"Ammunition:%i-%i",ammoLuger,ammoClipLuger);}              
              if(weapon==2){textprintf_ex(buffer,font,15,15, makecol(0,0,0),-1,"Ammunition:%i-%i",ammoDouble,ammoChamberDouble);} 
              if(weapon==3){textprintf_ex(buffer,font,15,15, makecol(0,0,0),-1,"Ammunition:%i-%i",ammoPython,ammoChamberPython);} 
              if(weapon==4){textprintf_ex(buffer,font,15,15, makecol(0,0,0),-1,"Ammunition:%i-%i",ammoEagle,ammoClipEagle);} 
              
              if(weapon==0){textprintf_ex(buffer,font,15,25, makecol(0,0,0),-1,"Weapon=None",NULL);}    
              if(weapon==1){textprintf_ex(buffer,font,15,25, makecol(0,0,0),-1,"Weapon=Luger P08",NULL);} 
              if(weapon==2){textprintf_ex(buffer,font,15,25, makecol(0,0,0),-1,"Weapon=12 Gauge Double Barrel",NULL);} 
              if(weapon==3){textprintf_ex(buffer,font,15,25, makecol(0,0,0),-1,"Weapon=Colt Python",NULL);} 
              if(weapon==4){textprintf_ex(buffer,font,15,25, makecol(0,0,0),-1,"Weapon=Desert Eagle",NULL);} 
              
              if(weapon==1){
                  if(key[KEY_SPACE] && ammoLuger>0 && ammoClipLuger>0){shootTrigger=1;}
                  if(!key[KEY_SPACE] && shootTrigger==1 && reload==0){fire=1; ammoClipLuger=ammoClipLuger-1; shootTrigger=0;}                  
                  if(fire>0 && weapon==1){draw_sprite( buffer, BobbyLugerFire, bobX, bobY);}
                  if(ammoClipLuger==0 && ammoLuger>0 && jump==0){   
                                  reload=1;
                                   ammoClipLuger=ammoClipLuger+8; 
                                ammoLuger=ammoLuger-8;shootTrigger=0;
                                  
                  }
                 if(reload>0 && reload!=40){reload=reload+1;}
                 if(reload==40){reload=0; shootTrigger=0;}
                                
                 if(fire>0){fire=fire+1;}
                 if(fire==5){fire=0;}
              }
              if(weapon==2){
                  if(key[KEY_SPACE] && ammoDouble>0 && ammoChamberDouble>0){shootTrigger=1;}
                  if(!key[KEY_SPACE] && shootTrigger==1 && reload==0){fire=1; ammoChamberDouble=ammoChamberDouble-1; shootTrigger=0;}                  
                  if(fire>0){draw_sprite( buffer, bobbyDoubleFire, bobX, bobY);}
                  if(ammoChamberDouble==0 && ammoDouble>0 && jump==0){
                                  reload=1;
                                  ammoChamberDouble=ammoChamberDouble+2; 
                                  ammoDouble=ammoDouble-2;
                                  }
                 if(reload>0 && reload!=70){reload=reload+1;}
                 if(reload==70){reload=0; shootTrigger=0;}
                 if(fire>0){fire=fire+1;}
                 if(fire==10){fire=0;}
              
              }
              
              if(weapon==3){
                  if(key[KEY_SPACE] && ammoPython>0 && ammoChamberPython>0){shootTrigger=1;}
                  if(!key[KEY_SPACE] && shootTrigger==1 && reload==0){fire=1; ammoChamberPython=ammoChamberPython-1; shootTrigger=0;}                  
                  if(fire>0){draw_sprite( buffer, bobbyPythonFire, bobX, bobY);}
                  if(ammoChamberPython==0 && ammoPython>0 && jump==0){
                                  reload=1;
                                  ammoChamberPython=ammoChamberPython+6; 
                                  ammoPython=ammoPython-6;
                                  }
                 if(reload>0 && reload!=70){reload=reload+1;}
                 if(reload==70){reload=0; shootTrigger=0;}
                 if(fire>0){fire=fire+1;}
                 if(fire==10){fire=0;}
              
              }
              if(weapon==4){
                  if(key[KEY_SPACE] && ammoEagle>0 && ammoClipEagle>0){shootTrigger=1;}
                  if(!key[KEY_SPACE] && shootTrigger==1 && reload==0){fire=1; ammoClipEagle=ammoClipEagle-1; shootTrigger=0;}                  
                  if(fire>0){draw_sprite( buffer, bobbyEagleFire, bobX, bobY);}
                  if(ammoClipEagle==0 && ammoEagle>0 && jump==0){
                                  reload=1;
                                  ammoClipEagle=ammoClipEagle+7; 
                                  ammoEagle=ammoEagle-7;
                                  }
                 if(reload>0 && reload!=40){reload=reload+1;}
                 if(reload==40){reload=0; shootTrigger=0;}
                 if(fire>0){fire=fire+1;}
                 if(fire==13){fire=0;}
              
              }
              
              if(key[KEY_W] && jump==0 && reload==0){jump=1; jumpSpeed=20;}
              if(jump==1){bobY=bobY-jumpSpeed; jumpDir=0;
                         if(jumpDir==0){jumpSpeed=jumpSpeed-1;}
                         if(jumpDir==1){jumpSpeed=jumpSpeed+1;}
              }
              if(jumpSpeed<1){jumpDir=1;}
              if(bobY>Level_1Ground-10){jump=0;}              
              
              if(weapon!=2){
                            if(bobX>745 && scrollX<3600){scrollX=scrollX+5; bobX=bobX-5;}
                            if(bobX<90 && scrollX!=0){scrollX=scrollX-5; bobX=bobX+5;}
              }
              if(weapon==2){
                            if(bobX>745 && scrollX<3600){scrollX=scrollX+4; bobX=bobX-4;}
                            if(bobX<90 && scrollX!=0){scrollX=scrollX-4; bobX=bobX+4;}
              }
              if(key[KEY_1] && lugerGet==1){weapon=1;}
              if(key[KEY_2] && doubleGet==1){weapon=2;}
              if(key[KEY_3] && pythonGet==1){weapon=3;}
              if(key[KEY_4] && eagleGet==1){weapon=4;}
              
              if(weapon==0 && walk==0 && fire==0 && jump==0){draw_sprite( buffer, bobby, bobX, bobY);}
              if(weapon==1 && walk==0 && fire==0 && jump==0 && reload==0){draw_sprite( buffer, bobbyLuger, bobX, bobY);}
              if(weapon==1 && fire==0 && reload>0){draw_sprite( buffer, BobbyLugerReload, bobX, bobY);}
              if(weapon==2 && walk==0 && fire==0 && jump==0 && reload==0){draw_sprite( buffer, bobbyDouble, bobX, bobY);}
              if(weapon==2 && fire==0 && reload>0){draw_sprite( buffer, bobbyDoubleReload, bobX, bobY);}            
              if(weapon==3 && walk==0 && fire==0 && jump==0 && reload==0){draw_sprite( buffer, bobbyPython, bobX, bobY);}
              if(weapon==3 && fire==0 && reload>0){draw_sprite( buffer, bobbyPythonReload, bobX, bobY);}
              if(weapon==4 && walk==0 && fire==0 && jump==0 && reload==0){draw_sprite( buffer, bobbyEagle, bobX, bobY);}
              if(weapon==4 && fire==0 && reload>0){draw_sprite( buffer, bobbyEagleReload, bobX, bobY);}
              
              
              walkLoop=0;
              rest(40);
              }

void setup(){
     
     buffer = create_bitmap( 900, 680);
     bobby = load_bitmap( "bobby.bmp", NULL);
     back1 = load_bitmap( "back1.bmp", NULL);
     bobbyWalk = load_bitmap( "bobbyWalk.bmp", NULL);
     bobbyLuger = load_bitmap( "bobby Luger.bmp", NULL);
     bobbyLugerWalk = load_bitmap( "bobby Luger Walk.bmp", NULL);
     Luger = load_bitmap( "Luger.bmp", NULL);
     BobbyLugerFire = load_bitmap( "Bobby Luger Fire.bmp", NULL);
     BobbyLugerReload = load_bitmap( "Bobby Luger Reload.bmp", NULL);
     back1_1 = load_bitmap( "back1_1.bmp", NULL);
     back1_2 = load_bitmap( "back1_2.bmp", NULL);
     back1_3 = load_bitmap( "back1_3.bmp", NULL);
     back1_4 = load_bitmap( "back1_4.bmp", NULL);
     bobbyDouble = load_bitmap( "bobbyDoubleBarrel.bmp", NULL);
     bobbyDoubleWalk = load_bitmap( "bobbyWalkDoubleBarrel.bmp", NULL);
     bobbyDoubleFire = load_bitmap( "bobbyDoubleBarrelFire.bmp", NULL);
     bobbyDoubleReload = load_bitmap( "bobbyDoubleBarrelReload.bmp", NULL);
     Double = load_bitmap( "DoubleBarrel.bmp", NULL);
     bobbyPython = load_bitmap( "bobbyPython.bmp", NULL);
     bobbyPythonWalk = load_bitmap( "bobbyPythonWalk.bmp", NULL);
     bobbyPythonFire = load_bitmap( "bobbyPythonFire.bmp", NULL);
     bobbyPythonReload = load_bitmap( "bobbyPythonReload.bmp", NULL);
     Python = load_bitmap( "Python.bmp", NULL);
     bobbyEagle = load_bitmap( "bobbyEagle.bmp", NULL);
     bobbyEagleWalk = load_bitmap( "bobbyEagleWalk.bmp", NULL);
     bobbyEagleFire = load_bitmap( "bobbyEagleFire.bmp", NULL);
     bobbyEagleReload = load_bitmap( "bobbyEagleReload.bmp", NULL);
     Eagle = load_bitmap( "Eagle.bmp", NULL);
}          
int main(){
    
    allegro_init();
    install_mouse();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 900, 680, 0, 0);
    set_window_title("Robot Defender(C)");
    
    setup();
    
    while( !key[KEY_ESC]){
           
           update();
           
           
    }

    return 0;
    
}
END_OF_MAIN();

