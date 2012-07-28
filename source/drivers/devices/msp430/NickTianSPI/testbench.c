#include "./spi_Tian_Nick.h"
//#include <i2c.h>
//#include <error_codes.h>
#include <stdio.h>
//#include <timing.h>

char tx[512] = {0};
char rx[512] = {0};

float a = 0;
float b = 0;

int spitestbench()
{ 
        int i = 0;
        

    
	//WDTCTL = WDTPW + WDTHOLD;			// Stop WDT
      
       // timing_init(); *********TODO*******
	__enable_interrupt();				// Enable Interrupts
	int error = 0;//NO_ERROR;
	
	//error = i2c_enable();				// Set up I2C module
	if(error)
		printf("Error: enable_i2c()\n");
	
	a = timing_read();
        error = sd_init();					// Power up the SD card
        b = timing_read();
        //printf("%f\n", (b-a));	
        
        //while (1);
	if(error)
		printf("Error: init_sd()\n");
	
	printf("Init done\n");
	
	//error = sd_get_csd();
	if(error)
		printf("Error: get_csd_sd()\n");
	
        //generate test data
        for (i = 0; i < 10; i++)
        {  tx[i] = i%0xff;
        }

        //write and read data
        a = timing_read();
        error = sd_write(tx,10, 1);       
         b = timing_read();
        printf("%f\n", (b-a));	
        
        a = timing_read();
        error = sd_read(rx, 10,1);
        
        printf("%x\n", error);
        b = timing_read();
        printf("%f\n", (b-a));
        
        //verify the data...
        for (i = 0; i < 10; i++)
          printf("0x%02x ", rx[i]);
        
	printf("Test 2\n");
	
	error = sd_power_down();			// Power down the SD card
	if(error)
		printf("Error: power_down_sd()\n");
	
	return 0;
}
