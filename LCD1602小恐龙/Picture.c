#include "LCD1602.h"

void Dinosaur()//自定义恐龙字符  0x00
{
		LCD_WriteCommand(0x40);		//01 000 000
		LCD_WriteData(0x0F);
		
		LCD_WriteCommand(0x41);		//01 000 001
		LCD_WriteData(0x0B);
		
		LCD_WriteCommand(0x42);		//01 000 010
		LCD_WriteData(0x0E);
		
		LCD_WriteCommand(0x43);		//01 000 011
		LCD_WriteData(0x0F);
		
		LCD_WriteCommand(0x44);		//01 000 100
		LCD_WriteData(0x0E);
		
		LCD_WriteCommand(0x45);		//01 000 101
		LCD_WriteData(0x0E);
		
		LCD_WriteCommand(0x46);		//01 000 110
		LCD_WriteData(0x1E);
		
		LCD_WriteCommand(0x47);		//01 000 111
		LCD_WriteData(0x0A);
}

void Cactus()//自定义仙人掌字符  0x01
{
		LCD_WriteCommand(0x48);		//01 001 000
		LCD_WriteData(0x00);
		
		LCD_WriteCommand(0x49);		//01 001 001
		LCD_WriteData(0x04);
		
		LCD_WriteCommand(0x4A);		//01 001 010
		LCD_WriteData(0x05);
		
		LCD_WriteCommand(0x4B);		//01 001 011
		LCD_WriteData(0x05);
		
		LCD_WriteCommand(0x4C);		//01 001 100
		LCD_WriteData(0x17);
		
		LCD_WriteCommand(0x4D);		//01 001 101
		LCD_WriteData(0x14);
		
		LCD_WriteCommand(0x4E);		//01 001 110
		LCD_WriteData(0x1C);
		
		LCD_WriteCommand(0x4F);		//01 001 111
		LCD_WriteData(0x04);
}

void Heart()//自定义心形字符  0x02
{
		LCD_WriteCommand(0x50);		//01 010 000
		LCD_WriteData(0x00);
		
		LCD_WriteCommand(0x51);		//01 010 001
		LCD_WriteData(0x00);
		
		LCD_WriteCommand(0x52);		//01 010 010
		LCD_WriteData(0x1B);
		
		LCD_WriteCommand(0x53);		//01 010 011
		LCD_WriteData(0x1F);
		
		LCD_WriteCommand(0x54);		//01 010 100
		LCD_WriteData(0x1F);
		
		LCD_WriteCommand(0x55);		//01 010 101
		LCD_WriteData(0x0E);
		
		LCD_WriteCommand(0x56);		//01 010 110
		LCD_WriteData(0x04);
		
		LCD_WriteCommand(0x57);		//01 010 111
		LCD_WriteData(0x00);
}