#ifndef _CHECK_RIGHT_H_
#define _CHECK_RIGHT_H_
#include <bit.h>

enum RCStates{RCinit, RCstandby, RChit, RCwait, RCend} RCstate;
unsigned char RCcnt;

void right_pr()
{
	switch(RCstate){
		case RCinit:
			RCstate= RCstandby;
			break;
		
		case RCstandby:
			if( GetBit((~PIND),3) == 0) //not pressed
				RCstate= RCstandby;
			else if( !(GetBit((~PIND),0)) && !(GetBit((~PIND),1)) && !(GetBit((~PIND),2)) && (GetBit((~PIND),3)) )// if pressed go to RC hit
				RCstate= RChit;
			break;
		
		case RChit:
			RCstate= RCwait;
			break;
		
		case RCwait:
			if(RCcnt < 10 && (GetBit((~PIND),3)) )
			// if still pressed then wait for 10 ms
				RCstate= RCwait;
			else if ( !(RCcnt<10) || ( (GetBit((~PIND),3))== 0) ) 
			//if count is done OR button is let go
				RCstate= RCend;
			break;
		
		case RCend:
			if( (GetBit((~PIND),3)==1) )
				RCstate= RCend;
			else
				RCstate= RCstandby;
			break;
		
		default:
			break;
	} //end of transitions

	switch(RCstate){
		case RCstandby:
			RCcnt=0;
			break;
	
		case RChit:
			right_press=1;
			break;
		
		case RCwait:
			RCcnt++;
			break;
		
		case RCend:
			right_press=0;
			break;
		
		default:
			break;
	} // end of actions 
}

#endif