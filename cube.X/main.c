/*
 * File:   main.c
 * Author: USER
 *
 * Created on December 30, 2017, 7:22 AM
 */

#include "spi.h"
#include <xc.h>
#include <stdlib.h>
#define _XTAL_FREQ 1000000

#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config MCLRE = OFF
#pragma config PBADEN = OFF
#pragma config OSC = INTIO67

// 1 = white
// 2 = orange
// 3 = green
// 4 = red
// 5 = blue
// 6 = yellow
char surface_one[4] = {'1', '1', '1', '1'};
char surface_two[4] = {'2', '2', '2', '2'};
char surface_three[4] = {'3', '3', '3', '3'};
char surface_four[4] = {'4', '4', '4', '4'};
char surface_five[4] = {'5', '5', '5', '5'};
char surface_six[4] = {'6', '6', '6', '6'};
char temp[4] = {'0', '0', '0', '0'};

const char native_surface_one[4] = {'1', '1', '1', '1'};
const char native_surface_two[4] = {'2', '2', '2', '2'};
const char native_surface_three[4] = {'3', '3', '3', '3'};
const char native_surface_four[4] = {'4', '4', '4', '4'};
const char native_surface_five[4] = {'5', '5', '5', '5'}; 
const char native_surface_six[4] = {'6', '6', '6', '6'};

char re;

void led(char rotate);
void fixed();

// up rotate clockwise
void U() {
    int i;
    
    for(i=0;i<2;i++) {
        temp[i] = surface_three[i];
        surface_three[i] = surface_four[i];
        surface_four[i] = surface_five[i];
        surface_five[i] = surface_two[i];
        surface_two[i] = temp[i];
    }
    led('U');
}

// up rotate counterclockwise
void Ui() {
    int i;
    for(i=0;i<2;i++) {
        temp[i] = surface_three[i];
        surface_three[i] = surface_two[i];
        surface_two[i] = surface_five[i];
        surface_five[i] = surface_four[i];
        surface_four[i] = temp[i];
    }
    led('U');
}

// down rotate clockwise
void D() {
     int i;
     for(i=2;i<4;i++) {
        temp[i] = surface_three[i];
        surface_three[i] = surface_two[i];
        surface_two[i] = surface_five[i];
        surface_five[i] = surface_four[i];
        surface_four[i] = temp[i];
    }
     led('D');
}

// down rotate counterclockwise
void Di() {
    int i;
    for(i=2;i<4;i++) {
        temp[i] = surface_three[i];
        surface_three[i] = surface_four[i];
        surface_four[i] = surface_five[i];
        surface_five[i] = surface_two[i];
        surface_two[i] = temp[i];
    }
    led('D');
}

// left rotate clockwise
void L() {
    int i;
    for(i=0;i<3;i+=2) {
        temp[i] = surface_three[i];
        surface_three[i] = surface_one[i];
        surface_one[i] = surface_two[i];
        surface_two[i] = surface_six[i];
        surface_six[i] = temp[i];
    }
    led('L');
}

// left rotate counterclockwise
void Li() {
    int i;
    for(i=0;i<3;i+=2) {
        temp[i] = surface_three[i];
        surface_three[i] = surface_six[i];
        surface_six[i] = surface_two[i];
        surface_two[i] = surface_one[i];
        surface_one[i] = temp[i];
    }
    led('L');
}

// right rotate clockwise
void R() {
    int i;
    for(i=1;i<4;i+=2) {
        temp[i] = surface_three[i];
        surface_three[i] = surface_six[i];
        surface_six[i] = surface_two[i];
        surface_two[i] = surface_one[i];
        surface_one[i] = temp[i];
    }
    led('R');
}

// right rotate counterclockwise
void Ri() {
    int i;
    for(i=1;i<4;i+=2) {
        temp[i] = surface_three[i];
        surface_three[i] = surface_one[i];
        surface_one[i] = surface_two[i];
        surface_two[i] = surface_six[i];
        surface_six[i] = temp[i];
    }
    led('R');
}

// front rotate clockwise
void F() {
    int i;
    for(i=2;i<=3;i++) {
        temp[i] = surface_one[i];
        surface_one[i] = surface_two[i];
        surface_two[i] = surface_six[i];
        surface_six[i] = surface_four[i];
        surface_four[i] = temp[i];
    }
    led('F');
} 

// front rotate counterclockwise
void Fi() {
    int i;
    for(i=2;i<=3;i++) {
        temp[i] = surface_one[i];
        surface_one[i] = surface_four[i];
        surface_four[i] = surface_six[i];
        surface_six[i] = surface_two[i];
        surface_two[i] = temp[i];
    }
    led('F');
}

// back rotate clockwise
void B() {
    int i;
    for(i=0;i<=1;i++) {
        temp[i] = surface_one[i];
        surface_one[i] = surface_four[i];
        surface_four[i] = surface_six[i];
        surface_six[i] = surface_two[i];
        surface_two[i] = temp[i];
    }
    led('B');
}

// back rotate counterclockwise
void Bi() {
    int i;
    for(i=0;i<=1;i++) {
        temp[i] = surface_one[i];
        surface_one[i] = surface_two[i];
        surface_two[i] = surface_six[i];
        surface_six[i] = surface_four[i];
        surface_four[i] = temp[i];
    }
    led('B');
}

void led(char rotate) {
    int i;
    char num = '1';
    int count = 0;
    TRISAbits.RA0 = 0;
    TRISAbits.RA1 = 0;
    TRISAbits.RA2 = 0;
    TRISAbits.RA3 = 0;
    TRISAbits.RA4 = 0;
    TRISAbits.RA5 = 0;
    RA0 = 1;
    RA1 = 1;
    RA2 = 1;
    RA3 = 1;
    RA4 = 1;
    RA5 = 1;
    if(rotate == 'U') {
        for(i=0;i<2;i++) {
            for(count=0;count<6;count++) {
                if(surface_two[i] == num+count) {
                    RA1 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('m'+ count);
                        re = spiRead();
                    }
                    RA1 = 1;
                }
                if(surface_three[i] == num+count) {
                    RA2 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('m'+ count);
                        re = spiRead();
                    }
                    RA2 = 1;
                }
                if(surface_four[i] == num+count) {
                    RA3 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('m'+ count);
                        re = spiRead();
                    }
                    RA3 = 1;
                }
                if(surface_five[i] == num+count) {
                    RA4 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('m'+ count);
                        re = spiRead();
                    }
                    RA4 = 1;
                }
            }
            __delay_ms(5);  
        }
    }
    else if(rotate == 'D') {
        for(i=2;i<=3;i++) {
            for(count=0;count<6;count++) {
                if(surface_two[i] == num+count) {
                    RA1 = 0;
                    if(i == 0) {
                        spiWrite('g' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA1 = 1;
                }
                if(surface_three[i] == num+count) {
                    RA2 = 0;
                    if(i == 0) {
                        spiWrite('g' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA2 = 1;
                }
                if(surface_four[i] == num+count) {
                    RA3 = 0;
                    if(i == 0) {
                        spiWrite('g' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA3 = 1;
                }
                if(surface_five[i] == num+count) {
                    RA4 = 0;
                    if(i == 0) {
                        spiWrite('g' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA4 = 1;
                }
            }
            __delay_ms(5);
        }
    }
    else if(rotate == 'L') {
        for(i=0;i<=3;i+=2) {
            for(count=0;count<6;count++) {
                if(surface_one[i] == num+count) {
                    RA0 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('g'+ count);
                        re = spiRead();
                    }
                    RA0 = 1;
                }
                if(surface_two[i] == num+count) {
                    RA1 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('g'+ count);
                        re = spiRead();
                    }
                    RA1 = 1;
                }
                if(surface_three[i] == num+count) {
                    RA2 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('g'+ count);
                        re = spiRead();
                    }
                    RA2 = 1;
                }
                if(surface_six[i] == num+count) {
                    RA5 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('g'+ count);
                        re = spiRead();
                    }
                    RA5 = 1;
                }
            }
            __delay_ms(5);
        }
    }
    else if(rotate == 'R') {
        for(i=1;i<=3;i+=2) {
            for(count=0;count<6;count++) {
                if(surface_one[i] == num+count) {
                    RA0 = 0;
                    if(i == 0) {
                        spiWrite('m' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA0 = 1;
                }
                if(surface_two[i] == num+count) {
                    RA1 = 0;
                    if(i == 0) {
                        spiWrite('m' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA1 = 1;
                }
                if(surface_three[i] == num+count) {
                    RA2 = 0;
                    if(i == 0) {
                        spiWrite('m' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA2 = 1;
                }
                if(surface_six[i] == num+count) {
                    RA5 = 0;
                    if(i == 0) {
                        spiWrite('m' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA5 = 1;
                }
            }
            __delay_ms(5);
        }
    }
    else if(rotate == 'F') {
        for(i=2;i<=3;i++) {
            for(count=0;count<6;count++) {
                if(surface_one[i] == num+count) {
                    RA0 = 0;
                    if(i == 0) {
                        spiWrite('g' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA0 = 1;
                }
                if(surface_two[i] == num+count) {
                    RA1 = 0;
                    if(i == 0) {
                        spiWrite('g' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA1 = 1;
                }
                if(surface_four[i] == num+count) {
                    RA3 = 0;
                    if(i == 0) {
                        spiWrite('g' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA3 = 1;
                }
                if(surface_six[i] == num+count) {
                    RA5 = 0;
                    if(i == 0) {
                        spiWrite('g' + count);
                        re = spiRead();
                    } else {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA5 = 1;
                }
            }
            __delay_ms(5);
        }
    }
    else if(rotate == 'B') {
        for(i=0;i<=1;i++) {
            for(count=0;count<6;count++) {
                if(surface_one[i] == num+count) {
                    RA0 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('m'+ count);
                        re = spiRead();
                    }
                    RA0 = 1;
                }
                if(surface_two[i] == num+count) {
                    RA1 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('m'+ count);
                        re = spiRead();
                    }
                    RA1 = 1;
                }
                if(surface_four[i] == num+count) {
                    RA3 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('m'+ count);
                        re = spiRead();
                    }
                    RA3 = 1;
                }
                if(surface_six[i] == num+count) {
                    RA5 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else {
                        spiWrite('m'+ count);
                        re = spiRead();
                    }
                    RA5 = 1;
                }
            }
            __delay_ms(5);
        }
    }
    else if(rotate == 'A') {
        for(i=0;i<=3;i++) {
            for(count=0;count<6;count++) {
                if(surface_one[i] == num+count) {
                    RA0 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else if(i == 1){
                        spiWrite('m'+ count);
                        re = spiRead();
                    } else if(i == 2) {
                        spiWrite('g'+ count);
                        re = spiRead();
                    } else if(i == 3) {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA0 = 1;
                }
                if(surface_two[i] == num+count) {
                    RA1 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else if(i == 1){
                        spiWrite('m'+ count);
                        re = spiRead();
                    } else if(i == 2) {
                        spiWrite('g'+ count);
                        re = spiRead();
                    } else if(i == 3) {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA1 = 1;
                }
                if(surface_three[i] == num+count) {
                    RA2 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else if(i == 1){
                        spiWrite('m'+ count);
                        re = spiRead();
                    } else if(i == 2) {
                        spiWrite('g'+ count);
                        re = spiRead();
                    } else if(i == 3) {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA2 = 1;
                }
                if(surface_four[i] == num+count) {
                    RA3 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else if(i == 1){
                        spiWrite('m'+ count);
                        re = spiRead();
                    } else if(i == 2) {
                        spiWrite('g'+ count);
                        re = spiRead();
                    } else if(i == 3) {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA3 = 1;
                }
                if(surface_five[i] == num+count) {
                    RA4 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else if(i == 1){
                        spiWrite('m'+ count);
                        re = spiRead();
                    } else if(i == 2) {
                        spiWrite('g'+ count);
                        re = spiRead();
                    } else if(i == 3) {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA4 = 1;
                }
                if(surface_six[i] == num+count) {
                    RA5 = 0;
                    if(i == 0) {
                        spiWrite('a' + count);
                        re = spiRead();
                    } else if(i == 1){
                        spiWrite('m'+ count);
                        re = spiRead();
                    } else if(i == 2) {
                        spiWrite('g'+ count);
                        re = spiRead();
                    } else if(i == 3) {
                        spiWrite('s'+ count);
                        re = spiRead();
                    }
                    RA5 = 1;
                }
            }
            __delay_ms(5);
        }
    }
}

void interrupt scramble() {
 //write it in interrupt 
    int i;
    int random;
    srand(TMR0);
    for(i=1;i<=20;i++) {
        random = rand() % 12 + 1;
        switch(random) {   
            case 1:
                U();
                break;
            case 2:
                Ui();
                break;
            case 3:
                D();
                break;
            case 4:
                Di();
                break;
            case 5:
                L();
                break;
            case 6:
                Li();
                break;
            case 7:
                R();
                break;
            case 8:
                Ri();
                break;
            case 9:
                F();
                break;
            case 10:
                Fi();
                break;
            case 11:
                B();
                break;
            case 12:
                Bi();
                break;
        }
    }
    INTCONbits.GIEH = 0;
    RCONbits.IPEN = 0;
}

void restore() {
    int i;
    for(i=0;i<4;i++) {
        surface_one[i] = native_surface_one[i];
        surface_two[i] = native_surface_two[i];
        surface_three[i] = native_surface_three[i];
        surface_four[i] = native_surface_four[i];
        surface_five[i] = native_surface_five[i];
        surface_six[i] = native_surface_six[i];
        led('A');
    }
}

void fixed() {
    int i;
    for(i=0;i<4;i++) {
        surface_one[i] = '1';
        surface_two[i] = '1';
        surface_three[i] = '1';
        surface_four[i] = '1';
        surface_five[i] = '1';
        surface_six[i] = '1';
    }
    led('A');
}

int check(void) {
    int i;
    for(i=0;i<4;i++) {
        if(surface_one[i] != native_surface_one[i]) {
            return 0;
        }
        else if(surface_two[i] != native_surface_two[i]) {
            return 0;
        }
        else if(surface_three[i] != native_surface_three[i]) {
            return 0;
        }
        else if(surface_four[i] != native_surface_four[i]) {
            return 0;
        }
        else if(surface_five[i] != native_surface_five[i]) {
            return 0;
        }
        else if(surface_six[i] != native_surface_six[i]) {
            return 0;
        }
    }
    return 1;
}


void main(void) {
    // input button initialize
    TRISCbits.RC7 = 1; //U
    TRISCbits.RC6 = 1; //Ui
    TRISBbits.RB5 = 1; //D
    TRISBbits.RB4 = 1; //Di
    TRISBbits.RB3 = 1; //L
    TRISBbits.RB2 = 1; //Li
    TRISBbits.RB1 = 1; //R
    TRISBbits.RB0 = 1; //Ri
    TRISDbits.RD7 = 1; //F
    TRISDbits.RD6 = 1; //Fi
    TRISDbits.RD5 = 1; //B
    TRISDbits.RD4 = 1; //Bi
    TRISDbits.RD3 = 1; //scramble
    TRISDbits.RD2 = 1; //fixed
    
    int i, j;
    int solved = 1;
    int pause = 0;
    
    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
    
    led('A');
    
    while(1) {
        if(PORTDbits.RD3 == 0 && solved == 1) {
            RCONbits.IPEN = 1;
            INTCONbits.GIEH = 1;
            solved = 0;
            
        }
        else if(PORTDbits.RD2 == 0) {
            fixed();
        }
        while(solved == 0) {
            if(PORTCbits.RC7 == 0) {
                U();
            }
            else if(PORTCbits.RC6 == 0) {
                Ui();
            }
            else if(PORTBbits.RB5 == 0) {
                D();
            }
            else if(PORTBbits.RB4 == 0) {
                Di();
            }
            else if(PORTBbits.RB3 == 0) {
                L();
            }
            else if(PORTBbits.RB2 == 0) {
                Li();
            }
            else if(PORTBbits.RB1 == 0) {
                R();
            }
            else if(PORTBbits.RB0 == 0) {
                Ri();
            }
            else if(PORTDbits.RD7 == 0) {
                F();
            }
            else if(PORTDbits.RD6 == 0) {
                Fi();
            }
            else if(PORTDbits.RD5 == 0) {
                B();
            }
            else if(PORTDbits.RD4 == 0) {
                Bi();
            }
            else if(PORTDbits.RD3 == 0) {
                //pause = 1;
                //while(pause == 1) {
                    //if(PORTDbits.RD3 == 0) {
                        restore();
                        solved = 1;
                //        pause = 0;
                //    }
                //}
            }
            solved = check();
        }
    }
}
