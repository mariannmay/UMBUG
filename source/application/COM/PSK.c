//////////////////////////////////////////////////////////////////
//                                                              //
//    PSK source                                                //
//    last edited by: Tong Duan                                 //
//    date: July 30, 2012                                       //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "String.h"
#include "PSK.h"
#include "Math.h"

///////////////////////////////////////////////////////////////////

UI16 currentToneIndex = 0;
bool toggle = high;

#if COM_PROCESSOR_COMPILE
	#pragma vector=TIMERA0_VECTOR
	__interrupt void timerA0int()
	{
	
		if(TAIV && TAIV_TACCR1)	//if capture compare reg 1 interrupt
		{
			if (currentToneIndex >= SINE_LENGTH)
			{
				currentToneIndex = (currentToneIndex % SINE_LENGTH);
			}
			devices.radio.microphone->value = getToneValueAt(currentToneIndex);
			currentToneIndex += 100;
			startNewDigitalToAnalogConversion(devices.radio.microphone->value);
		}
		else
		{
		}
	}
#endif


///////////////////////////////////////////////////////////////////

#if DebugMode
	#include <stdio.h>
	#define PRINT_PSK_TRACE 0
#else
	#define PRINT_PSK_TRACE 0
#endif

Word phaseChange(int digital[])
{
	UI16 i, final = 0;
	
	#if PRINT_PSK_TRACE
		printf(" Word phaseChange(int digital[]) ...\n");
		printf(" digital = ");
		for (i = 0; i < 5; i++)
		{
			printf("%d ", digital[i]);
		}
		printf("\n");
	#endif
	
    for(i = 0; i < 5; i++) 
    {
        final += (digital[i] * pow(10,4-i));
        
        #if PRINT_PSK_TRACE
        	printf(" tallying up 'final': %d\n", final);
        #endif
    }
    
    #if PRINT_PSK_TRACE
		printf(" searching switch statement...\n");
	#endif
	
	float temp_dChange = 0.0;
	
	switch(final)
	{
		case     0: temp_dChange = 0.0;		break;
		case     1: temp_dChange = 11.25;	break;
		case    10: temp_dChange = 33.75;	break;
		case    11: temp_dChange = 22.50;	break;
		case   100: temp_dChange = 78.75;	break;
		case   101: temp_dChange = 67.50;	break;
		case   110: temp_dChange = 45.00;	break;
		case   111: temp_dChange = 56.25;	break;
		case  1000: temp_dChange = 168.75;	break;
		case  1001: temp_dChange = 157.50;	break;
		case  1010: temp_dChange = 135.00;	break;
		case  1011: temp_dChange = 146.25;	break;
		case  1100: temp_dChange = 90.00;	break;
		case  1101: temp_dChange = 101.25;	break;
		case  1110: temp_dChange = 123.75;	break;
		case  1111: temp_dChange = 112.50;	break;
		case 10000: temp_dChange = 348.75;	break;
		case 10001: temp_dChange = 337.50;	break;
		case 10010: temp_dChange = 315.00;	break;
		case 10011: temp_dChange = 326.25;	break;
		case 10100: temp_dChange = 270.00;	break;
		case 10101: temp_dChange = 281.25;	break;
		case 10110: temp_dChange = 303.75;	break;
		case 10111: temp_dChange = 292.50;	break;
		case 11000: temp_dChange = 180.00;	break;
		case 11001: temp_dChange = 191.25;	break;
		case 11010: temp_dChange = 213.75;	break;
		case 11011: temp_dChange = 202.50;	break;
		case 11100: temp_dChange = 258.75;	break;
		case 11101: temp_dChange = 247.50;	break;
		case 11110: temp_dChange = 225.00;	break;
		case 11111: temp_dChange = 236.25;	break;
		default:	
					#if PRINT_PSK_TRACE
						printf("\n\n\nfailure in PSK.c: Word phaseChange(int digital[])\n    variable final: %d\n", final);
						fflush(stdout);
					#endif
					
					system_abort();
	}
	Word degreeChange = (unsigned int)temp_dChange;
    #if PRINT_PSK_TRACE
    	printf("     degreeChange: %d\n",degreeChange);
    #endif
	return degreeChange;
}

void convertBinaryToPSK(Byte data[], int size)
{
	// initializers ///////////////////////////////////////////
	
	int tempB[8], binary[14], phase[5] = {0, 0, 0, 0, 0}, tpBinary[14];
	int front = 0, rear = 0, i, j, k, outNo = 0, occupyNo = 0;
	
	for(i = 0; i < 14; i++)
	{
		binary[i] = 0;
		tpBinary[i] = 3;
	}
	
	// cycle through incoming bytes ///////////////////////////
	
	for(i = 0; i < size; i++)
	{
		UI8 fiveCount = 0, former = 0, latter = 0;
		Byte current = data[i];
		
		#if PRINT_PSK_TRACE
			printf("\n TEST ROUND %d\n ------------\r\n",i);
			printf(" current: %x\n",current);
        	printf(" tempB: ");
    	#endif
    	
        for(j = 0; j < 8; j++) 
        {
        	//convert hex into 8 binary char
    	    char temp = (char)(((current >> (7-j)) & 1) + '0');
            Byte intemp = atoi(&temp);
            tempB[j] = intemp;
            
            #if PRINT_PSK_TRACE
            	printf("%c",temp);
            	if (j == 7) { printf("\n"); }
            #endif
        }
        
        for(j = 0; j < 8; j++)    //load next byte into the binary array
        {
        	if((rear + j) < 14)
        	{
        	    binary[rear+j] = tempB[j];
        	}
        	else
        	{
        		binary[(rear+j)%14] = tempB[j];
        	}
        	occupyNo++;
        }
        rear = (rear + 8) % 14;
        
        #if PRINT_PSK_TRACE
        	printf("\n");
        	printf(" After load...\n");
        	printf("          array: ");
        	for(j = 0; j < 14; j++)
        	{
       		 	printf("%d", binary[j]);
       		}
        	printf("\n");
        #endif
        
        for(j = 0; j < 14; j++)
        {
		    tpBinary[j] = 3;		// reset
	    }
        for(j = 0; j < occupyNo; j++)
        {
        	if((front + j) < 14)
        	{
        		tpBinary[j] = binary[front+j];
        	}
        	else
        	{
        		tpBinary[j] = binary[(front+j)%14];
        	}
        }
        
        #if PRINT_PSK_TRACE
        	printf("          front: %d\n", front);
        	printf("           rear: %d\n", rear);
        #endif
        
        
        // bit-stuffing ///////////////////////////////////////
        
        for(j = 0; j < 13; j++)
        {
        	if(tpBinary[j] == 1)
        	{
        		// check if we've got 5 consecutive 1s yet
        		fiveCount++;
        		if(fiveCount == 5)
        		{
        			// insert a 0
        			for(k = 0; k < 13 - j; k++)
        			{
        			    latter = tpBinary[j+k+1];
        			    tpBinary[j+k+1] = former;
        			    former = latter;
        			}
        			latter = 0, former = 0, fiveCount = 0;	// reset
        			occupyNo++;
        			rear = (rear + 1) % 14;
        		}
        	}
        	else
        	{
        		fiveCount = 0;
        	}
        }
        
        for(j = 0; j < occupyNo; j++){
        	if((front + j) < 14)
        	{
        		binary[front+j] = tpBinary[j];
        	}
        	else
        	{
        		binary[(front+j)%14] = tpBinary[j];
        	}
        }
        
        #if PRINT_PSK_TRACE
        	printf("\n");
        	printf(" After bit-stuffing...\n");
        	printf("          array: ");
        	for(j = 0; j < 14; j++){
        		printf("%d",binary[j]);
        	}
        	printf("\n");
        	printf("          front: %d\n", front);
        	printf("           rear: %d\n", rear);
        #endif
        
        // done bit-stuffing //////////////////////////////////////
        
        
        //calculate how many times extraction after this round of loading
        int tMod = (int) (occupyNo / 5);      
        
        for(j = 0; j < tMod; j++)
        {
        	#if PRINT_PSK_TRACE
        		printf("\n Inter TEST %d:\n", j);
        		assert(front < 14);
        	#endif
        	
        	for(k = 0; k < 5; k++)
        	{
				//extract uniform 5 bits into a phase from the binary array
        		if((front + k) < 14)
        		{
        			phase[k] = binary[front+k];
        			binary[front+k] = 2;
        		}
        		else
        		{
        			phase[k] = binary[(front+k)%14];
        			binary[(front+k)%14] = 2;
        		}
        		occupyNo--;
        	}
            front = (front + 5) % 14;
            
            // find the phase change!
        	currentToneIndex += (ToneIndexPositionsPerDegreePhase * phaseChange(phase));
		    
		    #if PRINT_PSK_TRACE
		    	printf("\n");
            	printf(" After extraction...\n");
            	printf("          front: %d\n", front);
            	printf("           rear: %d\n", rear);
            	printf("       outputNo: %d\n", outNo);
		    #endif
		    		   
		    outNo = outNo + 1;
        }
        if(i == size-1 && (occupyNo%5) != 0) //Check if facing the end of incoming data, if so, do clearance.
        { 
        	#if PRINT_PSK_TRACE
        		printf("\n Clear TEST:\n");
        		printf(" The rest binary is: ");
        		for(k=0;k<12;k++){
        			printf("%d",binary[k]);
        		}
        		printf("\n");
        	#endif
        	
        	int reminder = 0,rest = 0;
        	reminder = occupyNo%5;
        	for(k = 5-reminder; k < 5; k++)
        	{
				//extract the reminder bits into the last phase from the binary array
        		if((front + rest) < 14)
        		{
        			phase[k] = binary[front+rest];
        			binary[front+rest] = 2;
        		}
        		else
        		{
        			phase[k] = binary[(front+rest)%14];
        			binary[(front+rest)%14] = 2;
        		}
        		rest = rest + 1;
        		occupyNo = occupyNo - 1;
        	}
            
            for(k = 0; k < 5-reminder; k++)
            {
            	phase[k] = 0;
            }

        	currentToneIndex += (ToneIndexPositionsPerDegreePhase * phaseChange(phase));
        	
		    #if PRINT_PSK_TRACE
            	printf(" Number of Occupy: %d\n", occupyNo);
		    	printf(" outputNo: %d\n", outNo);
		    #endif
		    
		    outNo = outNo + 1;
		    
        }
        
	}
}

///////////////////////////////////////////////////////////////////




