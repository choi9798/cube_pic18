// CONFIG
/*#pragma config FOSC = XT   // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF  // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF   // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF   // Data EEPROM Memory Code Protection bit 
#pragma config WRT = OFF   // Flash Program Memory Write Enable bits 
#pragma config CP = OFF    // Flash Program Memory Code Protection bit*/

#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config MCLRE = OFF
#pragma config PBADEN = OFF
#pragma config OSC = INTIO67

#include <xc.h>
//#include <pic16f877a.h>
#include "spi.h"

#define _XTAL_FREQ 1000000

void led_off();
void whatled();

  char a[4];
  char temp = 'k';
  int num = 97;
  //char mem[4];

void main()
{
  TRISC7 = 0;
  TRISA = 0x00;
  TRISB = 0x00;
  TRISCbits.RC0 = 0;
  TRISCbits.RC1 = 0;
  TRISD = 0x00;
  int i;

  spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);

  while(1)
  {
    RA0 = 0; //Slave Select
    /*if(i > 3)
        i=0;*/
    if(spiDataReady())
    {
        a[i] = spiRead();
        spiWrite(temp);
        i++;
    }
    /*if(i > 3) {
        whatled();
    }*/
    
    RA0 = 1; //Slave Deselect
  }
}

void led_off()
{
    int i;
    /*for(i=0;i<4;i++) {
        if(mem[i] == 'a') {
            RA1 = 0;
            continue;
        }
        else if(mem[i] == 'b') {
            RA2 = 0;
            continue;
        }
        else if(mem[i] == 'c') {
            RA3 = 0;
            continue;
        }
        else if(mem[i] == 'd') {
            RA4 = 0;
            continue;
        }
        else if(mem[i] == 'e') {
            RA5 = 0;
            continue;
        }
        else if(mem[i] == 'f') {
            RE0 = 0;
            continue;
        }
        if(mem[i] == 'g') {
            RE1 = 0;
            continue;
        }
        else if(mem[i] == 'h') {
            RE2 = 0;
            continue;
        }
        else if(mem[i] == 'i') {
            RA7 = 0;
            continue;
        }
        else if(mem[i] == 'j') {
            RA6 = 0;
            continue;
        }
        else if(mem[i] == 'k') {
            RC0 = 0;
            continue;
        }
        else if(mem[i] == 'l') {
            RC1 = 0;
            continue;
        }
        if(mem[i] == 'm') {
            RB5 = 0;
            continue;
        }
        else if(mem[i] == 'n') {
            RB4 = 0;
            continue;
        }
        else if(mem[i] == 'o') {
            RB3 = 0;
            continue;
        }
        else if(mem[i] == 'p') {
            RB2 = 0;
            continue;
        }
        else if(mem[i] == 'q') {
            RB1 = 0;
            continue;
        }
        else if(mem[i] == 'r') {
            RB0 = 0;
            continue;
        }
        if(mem[i] == 's') {
            RD7 = 0;
            continue;
        }
        else if(mem[i] == 't') {
            RD6 = 0;
            continue;
        }
        else if(mem[i] == 'u') {
            RD5 = 0;
            continue;
        }
        else if(mem[i] == 'v') {
            RD4 = 0;
            continue;
        }
        else if(mem[i] == 'w') {
            RC7 = 0;
            continue;
        }
        else if(mem[i] == 'x') {
            RC6 = 0;
            continue;
        }
    }*/
    
    if(RA1 == 1)
        RA1 = 0;
    else if(RA2 == 1)
        RA2 = 0;
    else if(RA3 == 1)
        RA3 = 0;
    else if(RA4 == 1)
        RA4 = 0;
    else if(RA5 == 1)
        RA5 = 0;
    else if(RE0 == 1)
        RE0 = 0;
    if(RE1 == 1)
        RE1 = 0;
    else if(RE2 == 1)
        RE2 = 0;
    else if(RA7 == 1)
        RA7 = 0;
    else if(RA6 == 1)
        RA6 = 0;
    else if(RC0 == 1)
        RC0 = 0;
    else if(RC1 == 1)
        RC1 = 0;
    if(RB5 == 1)
        RB5 = 0;
    else if(RB4 == 1)
        RB4 = 0;
    else if(RB3 == 1)
        RB3 = 0;
    else if(RB2 == 1)
        RB2 = 0;
    else if(RB1 == 1)
        RB1 = 0;
    else if(RB0 == 1)
        RB0 = 0;
    if(RD7 == 1)
        RD7 = 0;
    else if(RD6 == 1)
        RD6 = 0;
    else if(RD5 == 1)
        RD5 = 0;
    else if(RD4 == 1)
        RD4 = 0;
    else if(RC7 == 1)
        RC7 = 0;
    else if(RC6 == 1)
        RC6 = 0;
    
}

void whatled()
{
    int i;
    led_off();
    for(i=0;i<4;i++) {
        if(a[i] == 'a') {
            RA1 = 1;
            //mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'b') {
            RA2 = 1;
            //mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'c') {
            RA3 = 1;
          //  mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'd') {
            RA4 = 1;
          //  mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'e') {
            RA5 = 1;
          //  mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'f') {
            RE0 = 1;
           // mem[i] = a[i];
            continue;
        }
        if(a[i] == 'g') {
            RE1 = 1;
           // mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'h') {
            RE2 = 1;
          //  mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'i') {
            RA7 = 1;
           // mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'j') {
            RA6 = 1;
         //   mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'k') {
            RC0 = 1;
          //  mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'l') {
            RC1 = 1;
         //   mem[i] = a[i];
            continue;
        }
        if(a[i] == 'm') {
            RB5 = 1;
          //  mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'n') {
            RB4 = 1;
          //  mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'o') {
            RB3 = 1;
           // mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'p') {
            RB2 = 1;
          //  mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'q') {
            RB1 = 1;
           // mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'r') {
            RB0 = 1;
         //   mem[i] = a[i];
            continue;
        }
        if(a[i] == 's') {
            RD7 = 1;
           // mem[i] = a[i];
            continue;
        }
        else if(a[i] == 't') {
            RD6 = 1;
           // mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'u') {
            RD5 = 1;
          //  mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'v') {
            RD4 = 1;
           // mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'w') {
            RC7 = 1;
           // mem[i] = a[i];
            continue;
        }
        else if(a[i] == 'x') {
            RC6 = 1;
           // mem[i] = a[i];
            continue;
        }
    }
}