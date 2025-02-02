#include<stdlib.h>
#include<stdio.h>
#include<iostream>

#define rand100 rand()%100+1

const char enflag[] = {
  0x0C,0x17,0x80,0x40,0x29,0x34,0x0C,0x29,0x28,0xA1,
  0x3A,0x80,0x82,0x1D,0x00,0x18,0xC3,0xCA,0x10,0x2E,
  0xD3,0x21,0x48,0xA5,0x3A,0x99,0xFB,0x46,0x0F,0xC6,
  0x78
};

void gen_rand(){
	srand(0);
	for(int i=0;i<31;i++){
		if(i%2==0)printf("\n");
		for(int j=0;j<5;j++){
			printf("0x%02X,",rand100);
		}
	}
}

const char random_list[] = {
  0x27,0x14,0x27,0x26,0x38,0x62,0x42,0x56,0x33,0x0D,
  0x36,0x01,0x2B,0x52,0x26,0x16,0x2E,0x56,0x62,0x51,
  0x4D,0x5C,0x38,0x07,0x3A,0x18,0x52,0x29,0x1A,0x4F,
  0x2F,0x5B,0x29,0x58,0x08,0x26,0x0C,0x12,0x39,0x44,
  0x22,0x4F,0x18,0x58,0x62,0x55,0x0D,0x0C,0x4F,0x43,
  0x1E,0x05,0x50,0x06,0x59,0x32,0x1E,0x4D,0x20,0x41,
  0x0F,0x25,0x1D,0x03,0x35,0x05,0x26,0x39,0x63,0x49,
  0x62,0x0E,0x54,0x04,0x3D,0x2B,0x30,0x4C,0x48,0x05,
  0x4A,0x35,0x14,0x05,0x28,0x57,0x05,0x26,0x18,0x24,
  0x22,0x5E,0x15,0x4B,0x54,0x3E,0x19,0x42,0x46,0x1F,
  0x44,0x25,0x32,0x25,0x14,0x1C,0x01,0x18,0x17,0x4B,
  0x0C,0x3F,0x42,0x5C,0x14,0x30,0x33,0x15,0x23,0x45,
  0x19,0x4E,0x2F,0x20,0x3B,0x49,0x1F,0x23,0x52,0x24,
  0x44,0x3D,0x0F,0x2B,0x4D,0x1C,0x18,0x5F,0x45,0x2D,
  0x19,0x16,0x08,0x61,0x1B,0x40,0x29,0x3F,0x30,0x51,
  0x30,0x1D,0x0E,0x54,0x3C
};

char encode(int input,int i){
	input ^= random_list[i*5];
	input += random_list[i*5+1];
	input *= random_list[i*5+2];
	input -= random_list[i*5+3];
	input %= 66666;
	return input&0xFF;
}

void brute(){
	for(int i=0;i<31;i++){
		for(int j=33;j<125;j++){
			if(encode(j,i) == enflag[i]){
				printf("%c",j);
				//break;	
			}
		}
		printf("\n");	
	}
}

int main(){
	brute();
} 
