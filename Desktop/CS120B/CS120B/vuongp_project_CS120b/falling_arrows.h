#ifndef __FALLING_ARROWS__
#define __FALLING_ARROWS__

//** THIS FILE DECREMENTS THE Y VALUE IN THE POINT OF THE ARROW ** //

//#include <light.h>
#include <check_button.h>

enum Fstates{Finit, fall_down, fall_others, check_press, reset_y} Fstate;


/*void falling(){*/
	
	switch(Fstate){
		case Finit:
			if(arrows[indx].fall==0)
				Fstate= Finit;
			else if( (indx==2) && (arrows[indx].fall==1) )
				Fstate= fall_down;
			else if ( ( (indx==0) || (indx==1) || (indx==3) ) && (arrows[indx].fall==1) )
				Fstate= fall_others;
			break;
			
		case fall_down:
			if(arrows[indx].y!=1 && arrows[indx].fall==1)
				Fstate=fall_down;
			else if (arrows[indx].y==1 && arrows[indx].fall==1)
				Fstate= check_press;
			break;
			
		case fall_others:
			if(arrows[indx].y!=2 && arrows[indx].fall==1)
				Fstate= fall_others;
			else if (arrows[indx].y==2 && arrows[indx].fall==1)
				Fstate= check_press;
			break;
			
		case check_press:
			Fstate= reset_y;
			break;
		
		case reset_y:
			break;
		default:
			break;
	}
	
	switch(Fstate){
		case fall_down:
			arrows[indx].y--;
			break;
			
		case fall_others:
			arrows[indx].y--;
			break;
			
		case check_press:
			if(check(arrows,indx))
				PORTB=0x08;
			else
				PORTB=0x00;
			break;
			
		case reset_y:
			light(0,0);
			if((indx==0)|| (indx==2) || (indx==3))
				arrows[indx].y=5;
			else if (indx==1)
				arrows[indx].y=6;
			arrows[indx].fall=0;
			PORTB=0x00;
			break;
	}
/*}*/



#endif