..//lcd module connections
   sbit LCD_RS at RC0_bit;
   sbit LCD_EN at RC1_bit;
   sbit LCD_D4 at RC2_bit;
   sbit LCD_D5 at RC3_bit;
   sbit LCD_D6 at RC4_bit;
   sbit LCD_D7 at RC5_bit;
   
     sbit LCD_RS_Direction at TRISC0_bit;
     sbit LCD_EN_Direction at TRISC1_bit;
     sbit LCD_D4_Direction at TRISC2_bit;
     sbit LCD_D5_Direction at TRISC3_bit;
     sbit LCD_D6_Direction at TRISC4_bit;
     sbit LCD_D7_Direction at TRISC5_bit;

//    keypad module connection
   char keypadPort at PORTD;
   
   char k;
   unsigned short kp, cnt, oldstate = 0;
   char txt[6];
void main() {
          cnt = 0;
          Keypad_Init();
          Lcd_Init();
          Lcd_Cmd(_LCD_CLEAR);
          Lcd_Cmd(_LCD_CURSOR_OFF);
          Lcd_Out(1, 1, "  Key :");
          Lcd_Out(2, 1, "Times :");
          
            do {
              kp = 0;
              do
                // kp = Keypad_Key_Press();
                kp = Keypad_Key_Click();
              
              while (!kp);
             // Prepare value for output, transform key to it's ASCII value
              switch (kp) {

                case  1: kp = 55; break; // 7        // Uncomment this block for keypad4x4
                case  2: kp = 56; break; // 8
                case  3: kp = 57; break; // 9
                case  4: kp = 47; break; // division operation
                case  5: kp = 52; break; // 4
                case  6: kp = 53; break; // 5
                case  7: kp = 54; break; // 6
                case  8: kp = 42; break; // multiplication
                case  9: kp = 49; break; // 1
                case 10: kp = 50; break; // 2
                case 11: kp = 51; break; // 3
                case 12: kp = 45; break; // substraction operation
                case 13: kp = 234; break; // C(67)..Omega
                case 14: kp = 48; break; // 0
                case 15: kp = 61; break; // =
                case 16: kp = 43; break; // addition operation
              }

              if (kp != oldstate) {                  // Pressed key differs from previous
                cnt = 1;
                oldstate = kp;
                }
              else {                                 // Pressed key is same as previous
                cnt++;
                }

              Lcd_Chr(1, 10, kp);                    // Print key ASCII value on LCD

              if (cnt == 255) {                      // If counter varialble overflow
                cnt = 0;
                Lcd_Out(2, 10, "   ");
                }

              WordToStr(cnt, txt);                   // Transform counter value to string
              Lcd_Out(2, 10, txt);                   // Display counter value on LCD
            } while (1);

          
          
}
