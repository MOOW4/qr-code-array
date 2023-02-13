#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>


void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool
bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool
bytes[rows][8]);
void reverse_array(bool array[]);

int main() {
	/*
	char character = 'A';
	bool bits[8];
	encode_char(character, bits);

	for (size_t i = 0; i < 8; i++){
		printf("%d",bits[i]);
	}

	printf("\n%c\n", decode_byte(bits));

	char* text = "Hello, how are you?";
	const int len = strlen(text);
	bool bytes1[len+1][8];
	encode_string(text, bytes1);
	for(int j = 0; j <= len; j++){
    		printf("%c: ", text[j]);
    		for(int i = 0; i < 8; i++){
       			 printf("%d", bytes1[j][i]);
    		}		
   		 printf("\n");
	}	
	bool bytes2[7][8] = {
	    {0,1,0,0,1,0,0,0},
	    {0,1,1,0,0,1,0,1},
	    {0,1,1,0,1,1,0,0},
	    {0,1,1,0,1,1,0,0},
	    {0,1,1,0,1,1,1,1},
	    {0,0,1,0,0,0,0,1},
	    {0,0,0,0,0,0,0,0}
	};
	char string[7];
	decode_bytes(7, bytes2, string);
	printf("%s\n", string);	

	int length = 4+1, cols = 3, offset = 2;
	bool bytes3[4+1][8] = {
	    {0,1,0,0,0,0,0,1},
	    {0,1,1,0,1,0,0,0},
	    {0,1,1,0,1,1,1,1},
	    {0,1,1,0,1,0,1,0},
	    {0,0,0,0,0,0,0,0}
	};
	bool blocks1[offset*8][cols];
	bytes_to_blocks(cols, offset, blocks1, length, bytes3);
	for(int j = 0; j < offset*8; j++){
	    for(int i = 0; i < cols; i++){
	        printf("%d ", (blocks1[j][i] == true) ? 1 : 0);
	    }
	    printf("\n");
	    if(j % 8 == 7){
	        printf("\n");
	    }
	}
	
	bool bytes[7][8] = {
		{0, 1, 1, 1, 0, 0, 1, 1},
		{0, 1, 1, 0, 1, 0, 1, 1},
		{0, 1, 1, 0, 0, 1, 0, 1},
		{0, 1, 1, 0, 1, 1, 1, 0},
		{0, 1, 1, 0, 0, 1, 0, 1},
		{0, 1, 1, 1, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};
	bool blocks[2*8][4];
	bytes_to_blocks(4,2,blocks,7,bytes);
	for(int j = 0; j < 16; j++){
	    for(int i = 0; i < 4; i++){
	        printf("%d ", (blocks[j][i] == true) ? 1 : 0);
	    }
	    printf("\n");
	    if(j % 8 == 7){
	        printf("\n");
	    }
	}	
	bool blocks2[2*8][3] = {
	    {0,0,0},
	    {1,1,1},
	    {0,1,1},
	    {0,0,0},
	    {0,1,1},
	    {0,0,1},
	    {0,0,1},
	    {1,0,1},
	    {0,0,0},
	    {1,0,0},
	    {1,0,0},
	    {0,0,0},
	    {1,0,0},
	    {0,0,0},
	    {1,0,0},
	    {0,0,0}
	};
	int length = 4+1, cols = 3, offset = 2;
	
	bool bytes4[length][8];
	blocks_to_bytes(cols, offset, blocks2, length, bytes4);
	for(int j = 0; j < length; j++){
	    for(int i = 0; i < 8; i++){
	        printf("%d", bytes4[j][i]);
	    }
	    printf("\n");
	}	
	//TEST BLOCKS_TO_BYTES ARENA		
	bool blocks[2*8][4] = {
		{0, 0, 0, 0},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 0, 0, 0},
		{0, 1, 0, 1},
		{0, 0, 1, 1},
		{1, 1, 0, 1},
		{1, 1, 1, 0},
		{0, 0, 0, 0},
		{1, 1, 0, 0},
		{1, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 0, 0},
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{1, 0, 0, 0}
	};
	bool bytes[7][8];
	int length = 7;
	blocks_to_bytes(4,2,blocks, length, bytes);
	for(int j = 0; j < length; j++){
	    for(int i = 0; i < 8; i++){
	        printf("%d", bytes[j][i]);
	    }
	    printf("\n");
	}
	*/
	return 0;
}


void encode_char(const char character, bool bits[8]){
	
	int num = character;
	for(int i = 0; i < 8; i++){
		bits[i] = num % 2;
		num /= 2;
	}
	reverse_array(bits);
}
void reverse_array(bool array[]){
	int temporary, y = 7, i = 0;
	while(i<y){
		temporary = array[i];
		array[i] = array[y];
		array[y] = temporary;
		i++;
		y--;
	}
}

char decode_byte(const bool bits[8]){
	int binary[] = {128,64,32,16,8,4,2,1};
	int num = 0;
	for (size_t i = 0; i < 8; i++){
		if (bits[i] == 1){
			num += binary[i];
		}
	}
	char ch = num;
	return ch;
}
void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
	int length = strlen(string);
	for (int i = 0; i < length+1; i++){
		bool array[8];
		char ch = string[i];
		encode_char(ch, array);
		for (int j = 0; j < 8; j++){
			bytes[i][j] = array[j];
		}
	}
}
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){

	for (int i = 0; i < rows; i++){
		char ch;
		ch = decode_byte(bytes[i]);
		string[i] = ch;
	}
}
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool
bytes[rows][8]){
	int a ,b;
	for (int i = 0; i < offset*8; i++){//vytvoreny row
		int q = i / 8;
	//	printf("%d",q);
		for (int j = 0; j < cols; j++){//vytvoreny column
			if (i >= 8){
				a = i - 8*q;//stlpec odkial beriem
				b = j + cols*q;//riadok odkial beriem
			}
			else{
				a = i;
				b = j;
			}
			if(b >= rows){//if offset*columns>length error not enough rows
				blocks[i][j] = 0;	
			}
			else{
				blocks[i][j] = bytes[b][a];
			}
			
		}
	}
}
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool
bytes[rows][8]){
	int a ,b;
	for (int i = 0; i < rows; i++){//vytvoreny row
		int q = i / cols;
	//	printf("%d",q);
		for (int j = 0; j < 8; j++){//vytvoreny column
			if (i >= cols){
				a = i - q*cols ;//column odkial beriem
				b = j + 8*q;//row odkial beriem
			}
			else{
				a = i;
				b = j;
			}


		bytes[i][j] = blocks[b][a];	
		}
	}
}
