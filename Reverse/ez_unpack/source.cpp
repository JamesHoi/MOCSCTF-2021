#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef unsigned char     uint8;
typedef unsigned long    uint32;

static uint8 alphabet_map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static uint8 reverse_map[] =
{
     255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
     255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
     255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 62, 255, 255, 255, 63,
     52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 255, 255, 255, 255, 255, 255,
     255,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
     15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 255, 255, 255, 255, 255,
     255, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
     41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 255, 255, 255, 255, 255
};

uint32 base64_encode(const uint8 *text, uint32 text_len, uint8 *encode)
{
    uint32 i, j;
    for (i = 0, j = 0; i+3 <= text_len; i+=3)
    {
        encode[j++] = alphabet_map[text[i]>>2];                             //ȡ����һ���ַ���ǰ6λ���ҳ���Ӧ�Ľ���ַ�
        encode[j++] = alphabet_map[((text[i]<<4)&0x30)|(text[i+1]>>4)];     //����һ���ַ��ĺ�2λ��ڶ����ַ���ǰ4λ������ϲ��ҵ���Ӧ�Ľ���ַ�
        encode[j++] = alphabet_map[((text[i+1]<<2)&0x3c)|(text[i+2]>>6)];   //���ڶ����ַ��ĺ�4λ��������ַ���ǰ2λ��ϲ��ҳ���Ӧ�Ľ���ַ�
        encode[j++] = alphabet_map[text[i+2]&0x3f];                         //ȡ���������ַ��ĺ�6λ���ҳ�����ַ�
    }

    if (i < text_len)
    {
        uint32 tail = text_len - i;
        if (tail == 1)
        {
            encode[j++] = alphabet_map[text[i]>>2];
            encode[j++] = alphabet_map[(text[i]<<4)&0x30];
            encode[j++] = '=';
            encode[j++] = '=';
        }
        else //tail==2
        {
            encode[j++] = alphabet_map[text[i]>>2];
            encode[j++] = alphabet_map[((text[i]<<4)&0x30)|(text[i+1]>>4)];
            encode[j++] = alphabet_map[(text[i+1]<<2)&0x3c];
            encode[j++] = '=';
        }
    }
    return j;
}

int main(void)
{
    char input[256];
    printf("Welcome to MOCSCTF, wish you can catch the flag\n");
    printf("Please input your flag:");
    scanf("%s", input);
    uint8 *text = (uint8 *)input;
    uint32 text_len = (uint32)strlen((char *)text);
    
    uint8 buffer[1024];
    uint32 size = base64_encode(text, text_len, buffer);
    buffer[size] = 0;
    
    uint8 code[] = {84,85,57,68,85,48,78,85,82,110,116,87,90,88,74,53,88,48,86,54,88,49,86,117,99,68,66,106,97,49,57,83,77,72,90,108,99,110,78,108,88,50,104,104,75,109,104,104,102,81,61,61};
    for(int i=0;i<size;i++){
    	if(buffer[i] != code[i]){
    		printf("Sorry, plz try again");
			break;
		}
	}
	printf("Jesus, You are so handsome!!");
    return 0;
}
