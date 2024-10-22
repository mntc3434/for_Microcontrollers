  // Lcd pinout settings
sbit LCD_RS at RD0_bit;
sbit LCD_EN at RD1_bit;
sbit LCD_D7 at RD5_bit;
sbit LCD_D6 at RD4_bit;
sbit LCD_D5 at RD3_bit;
sbit LCD_D4 at RD2_bit;

// Pin direction
sbit LCD_RS_Direction at TRISD0_bit;
sbit LCD_EN_Direction at TRISD1_bit;
sbit LCD_D7_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD2_bit;
 char txt1[]="WELCOME TO";
 char txt2[]="CIRCUIR DESIGN";
 char txt3[]="16*2";
 char txt4[]="LCD DISPLAY MINTE";
 char i;
void main() {

   Lcd_Init();
   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Cmd(_LCD_CURSOR_OFF);
   Lcd_Out(1, 1,txt1);
   Lcd_Out(2, 1,txt2);
   Delay_ms(2000);
   Lcd_cmd(_LCD_CLEAR);
   Lcd_Out(1, 1,txt3);
   Lcd_Out(2, 1,txt4);
   while(1){
   for(i=0;i<20;i++){
   Lcd_Cmd(_LCD_SHIFT_LEFT);
   Delay_ms(300);
   }
   for(i=0;i<20;i++){
   Lcd_Cmd(_LCD_SHIFT_RIGHT);
   Delay_ms(300);
   }
    }
   
}
