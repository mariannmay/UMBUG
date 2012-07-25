//////////////////////////////////////////////////////////////////
//                                                              //
//    PSK source                                                //
//    last edited by: Tong Duan                                 //
//    date: July 19, 2012                                       //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "String.h"
#include "PSK.h"
#include "Math.h"

Word phaseChange(int digital[])
{
	int i, final = 0;
    for(i = 0; i < 5; i++) 
    {
        final = final + digital[i] * pow(10,4-i);
    }
    printf("final: %d\n",final);
	float temp_dChange = 0.0;
	Word degreeChange = 0;
	switch(final)
	{
		case 0: temp_dChange = 0.0;break;
		case 1: temp_dChange = 11.25;break;
		case 10: temp_dChange = 33.75;break;
		case 11: temp_dChange = 22.50;break;
		case 100: temp_dChange = 78.75;break;
		case 101: temp_dChange = 67.50;break;
		case 110: temp_dChange = 45.00;break;
		case 111: temp_dChange = 56.25;break;
		case 1000: temp_dChange = 168.75;break;
		case 1001: temp_dChange = 157.50;break;
		case 1010: temp_dChange = 135.00;break;
		case 1011: temp_dChange = 146.25;break;
		case 1100: temp_dChange = 90.00;break;
		case 1101: temp_dChange = 101.25;break;
		case 1110: temp_dChange = 123.75;break;
		case 1111: temp_dChange = 112.50;break;
		case 10000: temp_dChange = 348.75;break;
		case 10001: temp_dChange = 337.50;break;
		case 10010: temp_dChange = 315.00;break;
		case 10011: temp_dChange = 326.25;break;
		case 10100: temp_dChange = 270.00;break;
		case 10101: temp_dChange = 281.25;break;
		case 10110: temp_dChange = 303.75;break;
		case 10111: temp_dChange = 292.50;break;
		case 11000: temp_dChange = 180.00;break;
		case 11001: temp_dChange = 191.25;break;
		case 11010: temp_dChange = 213.75;break;
		case 11011: temp_dChange = 202.50;break;
		case 11100: temp_dChange = 258.75;break;
		case 11101: temp_dChange = 247.50;break;
		case 11110: temp_dChange = 225.00;break;
		case 11111: temp_dChange = 236.25;break;
	}
	degreeChange = (unsigned int)temp_dChange;
	printf("degreeChange: %d\n",degreeChange);
	return degreeChange;
}

void convertBinaryToPSK(Byte data[], int size)
{
	Word previous = 0, next = 0, pChange = 0;
	int tempB[8],binary[12],phase[5];
	int front = 0, rear = 0, i,j,k,outNo = 0,occupyNo = 0;
	for(i=0;i<12;i++){
		binary[i] = 0;
	}
	for(i=0;i<size;i++)
	{
		printf("\n TEST ROUND %d\n",i);
		Byte current = data[i];
		printf("current: %d\n",current);
        printf("tempB: ");
        for(j = 0; j < 8; j++) 
        {                       //convert hex into 4 bits binary array
    	    char temp = (char)(((current >> (7-j)) & 1) + '0');
            int intemp = atoi(&temp);
            printf("%d",intemp);
            tempB[j] = intemp;
        }
        printf("\n");
        
        for(j=0;j<8;j++)    //load next byte into the binary array
        {
        	if((rear + j) < 12){
        	    binary[rear+j] = tempB[j];
        	}else{
        		binary[(rear+j)%12] = tempB[j];
        	}
        	occupyNo = occupyNo + 1;
        }
        rear = (rear + 8) % 12;
        int tMod = occupyNo/5;   //calculate how many times extraction after this round of loading      
        
        for(j=0;j<tMod;j++)
        {
        	printf("\nInter TEST %d:\n",j);
        	pChange = 0;
        	for(k=0;k<5;k++)
        	{                  //extract uniform 5 bits into a phase from the binary array
        		if((front + k) < 12){
        			phase[k] = binary[front+k];
        			binary[front+k] = 2;
        		}else{
        			phase[k] = binary[(front+k)%12];
        			binary[(front+k)%12] = 2;
        		}
        		occupyNo = occupyNo - 1;
        	}
            front = (front + 5) % 12;
            
        	pChange = phaseChange(phase); 
        	next = previous + pChange;
		    devices.testPSK->value = next;
		    printf("outputNo: %d\n",outNo);
		    outNo = outNo + 1;
		    printf("next: %d\n",next);
		    sendAnalogOutput(devices.testPSK);
		    previous = next;
        }
        if(i == size-1 && (occupyNo%5) != 0) //Check if facing the end of incoming data, if so, do clearance.
        { 
        	printf("\nClear TEST:\n");
        	printf("The rest binary is: ");
        	for(k=0;k<12;k++){
        		printf("%d",binary[k]);
        	}
        	printf("\n");
        	pChange = 0;
        	int reminder = 0,rest = 0;
        	reminder = occupyNo%5;
        	for(k=5-reminder;k<5;k++)
        	{             //extract the reminder bits into the last phase from the binary array
        		if((front + rest) < 12){
        			phase[k] = binary[front+rest];
        			binary[front+rest] = 2;
        		}else{
        			phase[k] = binary[(front+rest)%12];
        			binary[(front+rest)%12] = 2;
        		}
        		rest = rest + 1;
        		occupyNo = occupyNo - 1;
        	}
            printf("Number of Occupy: %d\n",occupyNo);
            for(k=0;k<5-reminder;k++)
            {
            	phase[k] = 0;
            }
        	pChange = phaseChange(phase); 
        	next = previous + pChange;
		    devices.testPSK->value = next;
		    printf("outputNo: %d\n",outNo);
		    outNo = outNo + 1;
		    printf("next: %d\n",next);
		    sendAnalogOutput(devices.testPSK);
		    previous = next;
        }
        
	}
}

void testPSK(void)
{
	Byte data[8];
	data[0] = 0x01;
	data[1] = 0x02;
	data[2] = 0x03;
	data[3] = 0x04;
	data[4] = 0xFF;
	data[5] = 0x06;
	data[6] = 0x07;
	data[7] = 0xF8;
	convertBinaryToPSK(data,8);
	fflush(stdout);
}



