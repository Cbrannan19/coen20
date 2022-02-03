#include <stdio.h>

/*function decs*/
int32_t Bits2Signed(int8_t bits[8]) ;            // Convert array of bits to signed int.
uint32_t Bits2Unsigned(int8_t bits[8]) ;         // Convert array of bits to unsigned int
void Increment(int8_t bits[8]) ;                 // Add 1 to value represented by bit pattern
void Unsigned2Bits(uint32_t n, int8_t bits[8]) ; // Opposite of Bits2Unsigned.

int32_t Bits2Signed(int8_t bits[8]){
	int32_t retVal = Bits2Unsigned(bits);        //call unsigned for value from 0-255
	if(retVal >= 128){                           //stops being positive at 128 (10000000)
		retVal -= 256;
	}
	return retVal;
}

uint32_t Bits2Unsigned(int8_t bits[8]){
	uint32_t retVal = 0;                         //call retVal
	int i;
	for(i = 7; i >=0; i--){                      //loop to determine unsigned value
		retVal = 2*retVal + bits[i];             //using polynomial exp
	}
	return retVal;
}

void Increment(int8_t bits[8]){
	int i;
	for(i = 0; i < 8; i++){                      //loop to see whole bit array
		if(bits[i] == 0){                        //if 0 it should increment to 1
			bits[i] = 1;
			break;
		}
		if(bits[i] == 1){                        //keep looping until it changes
			bits[i] = 0;
		}
	}
	return;
}

void Unsigned2Bits(uint32_t n, int8_t bits[8]){
	int i = 0;
	int r;
	while(i < 8){
		r = n%2;                                 //modulus is assigned to r
		n = n/2;                                 //find integer value of division
		bits[i] = r;                             //bits get filled in by remainders
		i++;
	}
	return;
}