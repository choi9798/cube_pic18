/*
 * File:   main.c
 * Author: USER
 *
 * Created on December 30, 2017, 7:22 AM
 */

#include <xc.h>
#include <stdlib.h>
#define _XTAL_FREQ 1000000

#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF
#pragma config OSC = INTIO67

// 1 = white
// 2 = orange
// 3 = green
// 4 = red
// 5 = blue
// 6 = yellow
int surface_one[4] = {1, 1, 1, 1};
int surface_two[4] = {2, 2, 2, 2};
int surface_three[4] = {3, 3, 3, 3};
int surface_four[4] = {4, 4, 4, 4};
int surface_five[4] = {5, 5, 5, 5};
int surface_six[4] = {6, 6, 6, 6};
int temp[4] = {0, 0, 0, 0};

const int native_surface_one[4] = {1, 1, 1, 1};
const int native_surface_two[4] = {2, 2, 2, 2};
const int native_surface_three[4] = {3, 3, 3, 3};
const int native_surface_four[4] = {4, 4, 4, 4};
const int native_surface_five[4] = {5, 5, 5, 5}; 
const int native_surface_six[4] = {6, 6, 6, 6};

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
}

void scramble() {
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

void restore() {
    int i;
    for(i=0;i<4;i++) {
        surface_one[i] = native_surface_one[i];
        surface_two[i] = native_surface_two[i];
        surface_three[i] = native_surface_three[i];
        surface_four[i] = native_surface_four[i];
        surface_five[i] = native_surface_five[i];
        surface_six[i] = native_surface_six[i];
    }
}

void main(void) {
    // input button initialize
    TRISBbits.RB7 = 1; //U
    TRISBbits.RB6 = 1; //Ui
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
    TRISCbits.RC7 = 1; //scramble
    
    int i, j;
    int solved = 1;
    int pause = 0;
    while(1) {
        if(PORTCbits.RC7 == 0) {
            scramble();
            solved = 0;
        }
        while(solved == 0) {
            if(PORTBbits.RB7 == 0) {
                U();
            }
            else if(PORTBbits.RB6 == 0) {
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
            else if(PORTCbits.RC7 == 0) {
                // ?????????LED??,???????????, ??????????, ?????
                pause = 1;
                while(pause == 1) {
                    if(PORTCbits.RC7 == 0) {
                        restore();
                        solved = 1;
                        pause = 0;
                    }
                }
            }
            solved = check();
        }
    }
    return;
}