//
//  torqure.c
//  
//
//  Created by Joshua Hernandez on 12-05-07.
//  Copyright (c) 2012.
//



#include <stdio.h>


#define VECTOR_LENGTH 3
#define MAX_INT 2147483647


typedef enum{
	
    FALSE,
    TRUE
	
}boolean;


float* calcMoment(float* tau,float* BField){
	
	/*
	 
	 tau = 3d torque requiered
	 BField = 3d magnetic field of current position
	 moment = 3d magnetic moment needed
	 
	 unit-A == unit vector in the direction of A

	 | Vector | == magnitude of vector
	 
	 -------------------------------------
	 
	 tau = moment X BField
	 
	 unit-tau = unit-moment X unit-BField
	 
	 enforce that unit-moment is pertendicular to both
	 tau and BField. Thus creating a right-handed set of vectorts
	 So we have the following:
	 
	 unit-moment = unit-BField X unit-tau
	 
	 So we can conclude that:
	 
	 moment = ( BField X tau ) / | BField |^2
	 
	 */
	
	
	
	float* moment;
	float BFieldMagSq=0;
	float i=0;
	
	
	moment = malloc( sizeof(float)*VECTOR_LENGTH );

	for(i=0 ; i<VECTOR_LENGTH ; i++){

		BFieldMagSq += BField[i]*BField[i];
	}
	
	moment[1-1]=BField[2-1]*tau[3-1] - BField[3-1]*tau[2-1] ;
	moment[2-1]=BField[3-1]*tau[1-1] - BField[1-1]*tau[3-1] ;
	moment[3-1]=BField[1-1]*tau[2-1] - BField[2-1]*tau[1-1] ;
	
	for(i=0 ; i<VECTOR_LENGTH ; i++){
		
		moment[i]=moment[i]/BFieldMagSq;
	}
	
	return moment;
}

float* orthogonalComp(float* a, float* b){

	/*
	
		proj_B(A) = ( A dot unit-B ) unit-B
		
				  = ( A dot B ) B / |B|^2
		
		orthognal comp of A with respect to B
		
		A - proj_B(A)
	
	*/
	
	float* proj;
	float normBSq;
	float aDotB;
	int i=0;
	
	proj = malloc( sizeof(float)*VECTOR_LENGTH) );
	
	for(i=0;i<VECTOR_LENGTH;i++){
		normBSq += b[i]*b[i];
		aDotB += a[i]*b[i];
	}
	
	for(i=0;i<VECTOR_LENGTH;i++){
	
		proj[i]=aDotB*b[i]/normBSq;
	}
	
	return proj;
}

float sqrt(float x){

	float rootx=0;;
	int i=0;
	int isquare=0;
	int max_iter = 10;
	
	while(isquare<MAX_INT && isquare<x){
		isquare = i*i;
		i++;
	}
	i--;

	if( abs(isquare - x) < abs(i*i - x)  ){
		rootx=isquare;
	}
	else{
		rootx=i*i;
	}
	
	for(i=0, i< max_iter ; i++){
		rootx = 0.5*( rootx + (x/rootx) );
	}
	
	return rootx;
}

float abs(x){

	if(x>0){
		return x;
	else{
		return -x;
	}
}

boolean testCross(float* a,float* b,float* c){
	
	boolean returnBool=TRUE;
	float tol;
	
	// tests A = B X C
	
	// where A,B,C are all vectors
	
	tol = 0.00001
	
	if( a[1-1] - ( b[2-1]*c[3-1] - b[3-1]*c[2-1] ) < tol ) {
		returnBool=FALSE;
	}
	if( a[2-1] - ( b[3-1]*c[1-1] - b[1-1]*c[3-1]  ) < tol ){
		returnBool=FALSE;
	}
	if( a[3-1] - ( b[1-1]*c[2-1] - b[2-1]*c[1-1] ) < tol  ){
		returnBool=FALSE;
	}
	
	return returnBool;
}