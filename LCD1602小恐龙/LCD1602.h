#ifndef _LCD1602_H_
#define _LCD1602_H_

void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Data);
void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char Data[]);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned char Lenth,unsigned int Data);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,unsigned char Lenth,int Data);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned char Lenth,unsigned int Data);
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned char Lenth,unsigned int Data);

void LCD_WriteCommand(unsigned char Command);
void LCD_WriteData(unsigned char Data);

#endif