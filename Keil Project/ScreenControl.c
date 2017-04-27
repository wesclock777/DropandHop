// ScreenControl.c
// Runs on TM4C123
// Game for Lab 10
// Handles output to the Adafruit 1.8" SPI display
// Two array handle pixel output
// One is used for actual drawing of the screen
// and Two holds the ownership of each pixel
// 16-bit color, 128 wide by 160 high LCD
#include <stdint.h>
#include "ST7735.h"
#include "Resources.c"


//constants that depend on the block width (note replace with values of the bitmaps)
#define Player_height 0
#define Player_width	0
#define Spikes_height	0
#define Spikes_width	0
#define Block_height	0
#define Block_width		0


static Block block[50];
static int nblocks; //holds the humber of blocks currently on the screen
static Spikes spikes[5];
static int nspikes; //holds the number of spikes currently on the screen
static Character player;
static Dropper dropper;
static Fruit fruits[5];
static int nfruit; //holds the number of fruit currently on the screen
static int gravity; //holds the rate at which the object advance toward the bottom of the screen (pixels per second)


void refreshScreen(void){
	ST7735_PlotClear(0,160);
	// a lot of stuff goes here to define screen construction


}

void checkOffscreen(void){
	if(player.xpos+Player_width>=128||player.xpos<=0){player.alive=0;} //player dies if they go outside the screen
	if(player.ypos+Player_height>=160||player.ypos>=160){player.alive=0;}
}

void checkCollision(void){
	uint8_t i=0;
	if(player.alive==0){return;}
	//check player collision with spikes
	for(i=0; i<nspikes;i++){
		if((player.xpos+Player_width>=spikes[i].xpos)||(player.xpos<=spikes[i].xpos+Spikes_width))
			{
			if((player.ypos+Player_height>=spikes[i].ypos)){
				//player has been hit by a spike
				player.currentgraphic= &somethinggoeshere; //replace with hurt graphic
				player.lives --;
				//add invinciblity timer here
			}
		}
	
	}
	
	//check player collision with blocks
	
	
	
	//check player collision with fruit (changes gravity)
	
}

void GPIOPortE_Handler(void){ //interrupt for button press
	GPIO_PORTE_ICR_R = 0x20 //ackowledge flaged interrupt
	playerjump(player.xpos, player.ypos);
}	

void playerjump(uint8_t xpos, uint8_t ypos){ //players or enemies can jump causing their velocity to change to an upward vector
	uint8_t i=0;
	if(player.alive==0){return;}
	if(player.onground==0){return;} //player cannot jump unless they on ground and alive
	player.verticalvector= -1*gravity;
	return;
}
		

