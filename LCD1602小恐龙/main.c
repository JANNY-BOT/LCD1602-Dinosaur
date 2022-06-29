#include <REGX52.H>
#include <INTRINS.H>
#include "LCD1602.h"
#include "Key.h"
#include "Picture.h"

void Move_Delay(int ms)		//@11.0592MHz,1ms
{
	unsigned char i, j;
	
	while(ms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);	
	}
}

void main()
{	
	unsigned char Dy=2;	//恐龙纵坐标
	unsigned char Cx=16;	//仙人掌横坐标

	unsigned char KeyNum;
	unsigned char Score=0;
	unsigned char HH=11;//血量横坐标(上限)
	unsigned char HL=8;//血量横坐标(下限)	

	LCD_Init();
	Dinosaur();
	Cactus();	
	Heart();
	
	while(1)
	{
		for(Cx=16;Cx>0;Cx--)
		{		
			unsigned char H=HH;
			KeyNum=Key();
			
			LCD_ShowNum(1,14,3,Score);//分数
			
			//血量
			for(H=HH;H>HL;H--)
			{
				LCD_ShowChar(1,H,0x02);				
			}
			
			//移动
			if(KeyNum==1)Dy=1;
			else Dy=2;
			LCD_ShowChar(Dy,2,0x00);//恐龙动
			
			LCD_ShowChar(2,Cx,0x01);//仙人掌动
			Move_Delay(400);
			LCD_Init();//刷新
			
			if(Dy==2 && Cx==3)//死亡判定
			{
				LCD_ShowNum(1,14,3,Score);
				HH--;
				if(HH==HL)while(1){LCD_ShowString(2,3,"Game Over!!!");}
			}
			else if(Dy==1 && Cx==3)//加分判定
			{
				Score++;
			}
			else if(KeyNum==3)//暂停
			{
	
				while(KeyNum!=4)
				{				
					KeyNum=Key();		
					LCD_ShowNum(1,14,3,Score);//分数
					LCD_ShowChar(2,Cx,0x01);//仙人掌动
					LCD_ShowChar(Dy,2,0x00);//恐龙动
					for(H=HH;H>HL;H--)
					{
						LCD_ShowChar(1,H,0x02);				
					}				
					LCD_ShowString(1,4,"STOP");//分数
				}
			}
		}
	}
}

