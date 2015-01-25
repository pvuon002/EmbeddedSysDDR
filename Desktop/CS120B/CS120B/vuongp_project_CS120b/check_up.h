#ifndef _CHECK_UP_H_
#define _CHECK_UP_H_
#include <bit.h>

enum UCStates{UCinit, UCstandby, UChit, UCwait, UCend} UCstate;
unsigned char UCcnt;

void up_pr(){
switch(UCstate){
	case UCinit:
		UCstate= UCstandby;
		break;
		
	case UCstandby:
		if( GetBit((~PIND),1) == 0 ) //not pressed
			UCstate= UCstandby;
			else if( !(GetBit((~PIND),0)) && (GetBit((~PIND),1)) && !(GetBit((~PIND),2)) && !(GetBit((~PIND),3)) )// if pressed go to LC hit
			UCstate= UChit;
		break;
		
	case UChit:
		UCstate= UCwait;
		break;
		
	case UCwait:
		if( (UCcnt < 10) && (GetBit((~PIND),1)==1) )
		// if still pressed then wait for 10 ms
			UCstate= UCwait;
		else if ( !(UCcnt<10) ||  (GetBit((~PIND),1) == 0) ) 
		//if count is done OR button is let go
			UCstate= UCend;
		break;
		
	case UCend:
		if((GetBit((~PIND),1)==0))
			UCstate= UCend;
		else
			UCstate= UCstandby;
		break;
		
	default:
		break;
} //end of transitions

switch(UCstate){
	case UCstandby:
		UCcnt=0;
		up_press=0;
		break;
		
	case UChit:
		up_press=1;
		break;
		
	case UCwait:
		UCcnt++;
		break;
		
	case UCend:
		up_press=0;
		break;
		
	default:
		break;
} // end of actions 
}

#endif