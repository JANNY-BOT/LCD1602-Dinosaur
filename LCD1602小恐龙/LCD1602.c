#include <REGX52.H>
#include <INTRINS.H>

sbit LCD_EN=P2^7;
sbit LCD_RS=P2^6;
sbit LCD_WR=P2^5;
#define LCD_DataPort P0

void LCD_Delay()		//@11.0592MHz		1ms
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

/**
	*@brief		写命令
	*@param		Command，命令
	*@retval	无	
*/
void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;//	数据/命令选择段低电平
	LCD_WR=0;
	LCD_DataPort=Command;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}

/**
	*@brief		写数据
	*@param		Data，数据
	*@retval	无	
*/
void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;//	数据/命令选择段高电平
	LCD_WR=0;
	LCD_DataPort=Data;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}

/**
	*@brief		LCD初始化
	*@param		无
	*@retval	无	
*/
void LCD_Init()
{
	LCD_WriteCommand(0x38);//8位数据接口，两行显示，5*7点阵
	LCD_WriteCommand(0x0c);//显示开，光标关，闪烁关
	LCD_WriteCommand(0x06);//数据读写操作后，光标自动加一，画面不动
	LCD_WriteCommand(0x01);//清屏
}

/**
	*@brief		光标位置
	*@param		Line，行
	*@param		Column，列	
	*@retval	无	
*/
void LCD_SetAC(unsigned char Line,unsigned char Column)
{
		if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Column-1)+0x40);
	}
}

/**
	*@brief		LCD显示字符
	*@param		Line，行
	*@param		Column，列
	*@param		Data，显示字符
	*@retval	无	
*/
void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Data)
{
	LCD_SetAC(Line,Column);
	LCD_WriteData(Data);
}

/**
	*@brief		LCD显示字符串
	*@param		Line，行
	*@param		Column，列
	*@param		Data[]，显示字符串
	*@retval	无	
*/
void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char Data[])
{
	unsigned char i;
	LCD_SetAC(Line,Column);
	for(i=0;Data[i]!='\0';i++)
	{
			LCD_WriteData(Data[i]);
	}
}

/**
	*@brief		LCD乘方函数
	*@param		x，底数
	*@param		y，次方
	*@retval	result，结果	
*/
int LCD_Pow(int x, int y)
{
	unsigned char i;
	int result=1;
	
	for(i=0;i<y;i++)
	{
		result*=x;
	}
	return result;
}

/**
	*@brief		LCD显示无符号数字
	*@param		Line，行
	*@param		Column，列
	*@param		Lenth,长度
	*@param		Data，显示数字	
	*@retval	无	
	*@notice 	89c516rd+为16位，每次运算数据最大不超过65535
*/
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned char Lenth,unsigned int Data)
{
	unsigned char i;
	LCD_SetAC(Line,Column);
	for(i=1;i<=Lenth;i++)
	{
		LCD_WriteData(0x30+Data/LCD_Pow(10,(Lenth-i))%10);
	}
}

/**
	*@brief		LCD显示符号数字
	*@param		Line，行
	*@param		Column，列
	*@param		Lenth,长度
	*@param		Data，显示数字	
*/
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,unsigned char Lenth,int Data)
{
	unsigned char i;
	unsigned int DataShow;
	LCD_SetAC(Line,Column);
	if(Data>=0)
	{
		LCD_WriteData('+');
		DataShow=Data;
	}
	else
	{
		LCD_WriteData('-');
		DataShow=-Data;		
	}
	for(i=1;i<=Lenth;i++)
	{
		LCD_WriteData(0x30+DataShow/LCD_Pow(10,(Lenth-i))%10);
	}	
}

/**
	*@brief		LCD显示十六进制数字
	*@param		Line，行
	*@param		Column，列
	*@param		Lenth,长度
	*@param		Data，显示数字	
	*@retval	无	
*/
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned char Lenth,unsigned int Data)
{
	unsigned char i;
	unsigned char flag;//判断是否大于等于10
	LCD_SetAC(Line,Column);
	for(i=1;i<=Lenth;i++)
	{
		flag=Data/LCD_Pow(16,(Lenth-i))%16;
		if(flag<10)
		{
			LCD_WriteData(0x30+flag);			
		}
		else
		{
			LCD_WriteData('A'+flag-10);						
		}
	}
}

/**
	*@brief		LCD显示二进制数字
	*@param		Line，行
	*@param		Column，列
	*@param		Lenth,长度
	*@param		Data，显示数字	
	*@retval	无	
*/
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned char Lenth,unsigned int Data)
{
	unsigned char i;
	LCD_SetAC(Line,Column);
	for(i=1;i<=Lenth;i++)
	{
		LCD_WriteData(0x30+Data/LCD_Pow(2,(Lenth-i))%2);
	}
}