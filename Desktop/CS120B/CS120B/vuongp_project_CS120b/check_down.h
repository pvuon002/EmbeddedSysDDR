#ifndef _CHECK_DOWN_H_
#define _CHECK_DOWN_H_
#include <bit.h>

enum DCStates{DCinit, DCstandby, DChit, DCwait, DCend} DCstate;
unsigned char DCcnt;

void down_pr(){
switch(DCstate){
	case DCinit:
		DCstate= DCstandby;
		break;
		
	case DCstandby:
		if( GetBit((~PIND),2) == 0) //not pressed
			DCstate= DCstandby;
		else if( !(GetBit((~PIND),0)) && !(GetBit((~PIND),1)) && (GetBit((~PIND),2)) && !(GetBit((~PIND),3)) )// if pressed go to DC hit
			DCstate= DChit;
		break;
		
	case DChit:
		DCstate= DCwait;
		break;
		
	case DCwait:
		if(DCcnt < 10 && (GetBit((~PIND),2)) )
		// if still pressed then wait for 10 ms
			DCstate= DCwait;
		else if ( !(DCcnt<10) || ( (GetBit((~PIND),2))== 0) ) 
		//if count is done OR button is let go
			DCstate= DCend;
		break;
		
	case DCend:
		if((GetBit((~PIND),2)==1))
			DCstate= DCend;
		else
			DCstate= DCstandby;
		break;
		
	default:
		break;
} //end of transitions

switch(DCstate){
	case DCstandby:
		DCcnt=0;
		break;
	
	case DChit:
		down_press=1;
		break;
		
	case DCwait:
		DCcnt++;
		break;
		
	case DCend:
		down_press=0;
		break;
		
	default:
		break;
} // end of actions 
}

#endif