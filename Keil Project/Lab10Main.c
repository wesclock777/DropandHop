// Lab10Main.c
// Runs on TM4C123
// Game for Lab 10
// Wesley Klock and Meiling Teng
// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected 
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO), high for data, low for command
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 
// Gnd (pin 1) connected to ground
#include <stdio.h>
#include <stdint.h>
#include "ST7735.h"
#include "tm4c123gh6pm.h"
#include "TExaS.h"

void EnableInterrupts(void);
void DisableInterrupts(void);

// Initialize Port F so PF1, PF2 and PF3 are heartbeats
void PortF_Init(void){
// Intialize PortF for hearbeat
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000020;
	delay = 100;
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DEN_R |= 0x0E;
}





int main(void){
	TExaS_Init();
  ST7735_InitR(INITR_REDTAB);  
  PortF_Init();
  ST7735_SetCursor(0,0);
	
  
  ST7735_OutString("Welcome to Hop and Drop");

  ST7735_FillScreen(0xFFFF);            // set screen to white
  ST7735_FillScreen(0);            // set screen to black
	while(1){
	
	
	
	}
		
}