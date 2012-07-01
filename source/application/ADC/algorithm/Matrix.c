//////////////////////////////////////////////////////////////////
//                                                              //
//    Application source                                        //
//    last edited by:  Chen Liu                                 //
//    date: July 1, 2012                                        //
//                                                              //
//////////////////////////////////////////////////////////////////



#include<stdio.h>
#include"matrix.h"

/* matric add operation for two 3 by 3 matrix */
/* the result matrix is stored in result matrix */
/* optimization for the msp430 processor will be done in the future */

void matrix_add(int M1[3][3], int M2[3][3],int result[3][3])
{
	int r,c;
	for(r=0;r<3;r++)
		for(c=0;c<3;c++)
			result[r][c]=M1[r][c]+M2[r][c];

}
