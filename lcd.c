#include <reg51.h>

#define LCD P2   // LCD connected to Port 2

sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

// Delay function
void delay() {
    int i, j;
    for(i=0;i<100;i++)
        for(j=0;j<1000;j++);
}

// Command function
void lcd_cmd(unsigned char cmd) {
    LCD = cmd;
    RS = 0;   // Command mode
    RW = 0;   // Write mode
    EN = 1;
    delay();
    EN = 0;
}

// Data function
void lcd_data(unsigned char data) {
    LCD = data;
    RS = 1;   // Data mode
    RW = 0;
    EN = 1;
    delay();
    EN = 0;
}

// String display
void lcd_string(char *str) {
    while(*str) {
        lcd_data(*str++);
    }
}

// Main function
void main() {
    lcd_cmd(0x38); // 8-bit, 2 line
    lcd_cmd(0x0C); // Display ON
    lcd_cmd(0x01); // Clear screen
    lcd_cmd(0x06); // Entry mode

    lcd_string("Hello World");

    while(1);
}
