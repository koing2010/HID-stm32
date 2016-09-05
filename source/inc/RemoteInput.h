#ifndef  __REMOTEINPUT_H
#define  __REMOTEINPUT_H

typedef struct REMOTE__
{
 unsigned char D0  :1;
 unsigned char D1  :1;
 unsigned char D2  :1;
 unsigned char D3  :1;
 unsigned char D4  :1;
}REMOTE,*PREMOTE;

 void SndRmtCmd();


#endif
