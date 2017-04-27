//Resources.c
//contains all resources needed for the game
//
//

#include <stdint.h>
#include "ST7735.h"
	struct Character{
		uint8_t xpos,ypos;
		uint8_t alive; //set to 1 if alive, 0 if not alive
		uint8_t lives;
		int8_t verticalvector; //speed of movement up or down (up is positive down is negative)
		uint32_t score;
		uint8_t onground; //set to 1 if ontop of a block, 0 if not
		const uint8_t *currentgraphic;
		const uint8_t *graphics[2];
	};
	typedef struct Character Character;
	
	struct Block{
		uint8_t xpos,ypos;
		uint8_t created; // set to 1 if created by level, 0 if created by player
		uint32_t color;
		int8_t verticalvector; //speed of movement up or down (up is positive down is negative)
		const uint8_t *graphic;
		};
	typedef struct Block Block;
	
		
	struct Dropper{
		uint8_t xpos,ypos;
		const uint8_t *currentgraphic;
		const uint8_t *graphics[2];
		};
	typedef struct Dropper Dropper;
		
	struct Spikes{
		uint8_t xpos,ypos;
		const uint8_t *graphic;
	};
	typedef struct Spikes Spikes;
	
	struct Fruit{
		uint8_t xpos,ypos;
		int8_t boostlvl; //its effect on gravity
		const uint8_t *graphic[2];
	};
	typedef struct Fruit Fruit;
	
	
	
// all the graphics go below here
	
	
