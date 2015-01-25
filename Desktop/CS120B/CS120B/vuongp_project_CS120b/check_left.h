#ifndef _CHECK_LEFT_H_
#define _CHECK_LEFT_H_
#include <bit.h>

enum LCStates{LCinit, LCstandby, LChit, LCwait, LCend} LCstate;
unsigned char LCcnt;

void left_pr(){
switch(LCstate){
	case LCinit:
		LCstate= LCstandby;
		break;
		
	case LCstandby:
		if( GetBit((~PIND),0) == 0 ) //not pressed
			LCstate= LCstandby;
			else if( (GetBit((~PIND),0)) && !(GetBit((~PIND),1)) && !(GetBit((~PIND),2)) && !(GetBit((~PIND),3)) )// if pressed go to LC hit
			LCstate= LChit;
		break;
		
	case LChit:
		LCstate= LCwait;
		break;
		
	case LCwait:
		if(LCcnt < 10 && (GetBit((~PIND),0)==1) )
		// if still pressed then wait for 10 ms
			LCstate= LCwait;
		else if ( !(LCcnt<10) ||  (GetBit((~PIND),0) == 0) ) 
		//if count is done OR button is let go
			LCstate= LCend;
		break;
		
	case LCend:
		if((GetBit((~PIND),0)==1))
			LCstate= LCend;
		else
			LCstate= LCstandby;
		break;
		
	default:
		break;
} //end of transitions

switch(LCstate){
	case LCstandby:
		LCcnt=0;
		break;
		
	case LChit:
		left_press=1;
		break;
		
	case LCwait:
		LCcnt++;
		break;
		
	case LCend:
		left_press=0;
		break;
		
	default:
		break;
} // end of actions 
}

#endif