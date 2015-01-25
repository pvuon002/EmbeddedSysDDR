#ifndef _ALL_ARROWS_H_
#define _ALL_ARROWS_H_

#include <check_left.h>
#include <check_up.h>
#include <check_down.h>
#include <check_right.h>

void check_level(){
	if(mksnd)
	{
		level_time=30;
		
	}
	else
	{
		level_time= 65;
		
	}
}

enum Lstates {Linit,Lwait,fall_left,chk_left,rst_left} Lstate;
unsigned char Lbottom=0; //if reaches bottom =1; ready to re-fall
unsigned long Lcnt;

void checkb ( unsigned char in){
	if(in==0 )
	{
		if(arrows[in].y==2 && left_press && !up_press && !down_press && !right_press)
			c=1;
		else
			c=0;
	}
	
	else if(in==1)
	{
		if(arrows[in].y==2 && up_press && !left_press && !down_press && !right_press)
			c=1;
		else
			c=0;
	}	
		
	else if(in==2)
	{
		if(arrows[in].y==1 && !up_press && !left_press && down_press && !right_press)
			c=1;
		else
			c=0;
	}
		
	else if(in==3)
	{
		if(arrows[in].y==2 && !up_press && !left_press && !down_press && right_press)
			c=1;
		else
			c=0;
	}
	else if(in==4)
	{
		if(arrows[in].y==2 && up_press && left_press && !down_press && right_press)
			c=1;
		else
			c=0;
	}		
}//end of checkb

void left()
{
	check_level();
	switch(Lstate){
		case Linit:
			if(!(arrows[0].fall) )
				Lstate= Linit;
			else
				Lstate= Lwait;
			break;
			
		case fall_left:
			if(arrows[0].y==2 )
				Lstate= chk_left;
			else
				Lstate= Lwait;
			break;
			
		case Lwait:
			if( (Lcnt<level_time) )
				Lstate= Lwait;
			else if ( !(Lcnt<level_time) /*&& (arrows[0].y!=2)*/ ){
				Lstate= fall_left;
				Lcnt=0;
			}				
			break;
					
		case chk_left:
				Lstate= rst_left;
			break;
			
		case rst_left:
			Lstate= Linit;
			break;
			
		default:
			break;
	} // end of left transitions
	
	switch(Lstate){
		case Linit:
			break;
		case fall_left:
			arrows[0].y--;
			Lcnt=0;
			break;
			
		case Lwait:
			Lcnt++;
			break;
			
		case chk_left:
			checkb(0);
			if(c){
				PORTB=0x08;
				
			}				
			else{
				PORTB=0x10;
				lives--;
				if(lives==0){
					stop=1;	
				}					
			}						
 			Lbottom=1;
			break;
			
		case rst_left:
			light(0,0);
			arrows[0].y=5;
			arrows[0].fall=0;
			PORTB=0x00;
			Lbottom=0;
			Lcnt=0;
			c=0; // reset c
			break;
	}// end of left actions
}

enum Ustates{Uinit,Uwait,fall_up,chk_up,rst_up} Ustate;
unsigned char Ubottom=0;//if reaches bottom =1; ready to re-fall
unsigned long Ucnt;

void up()
{
	check_level();
	switch(Ustate){
		case Uinit:
		if(!(arrows[1].fall) )
			Ustate= Uinit;
		else
			Ustate= Uwait;
		break;
		
		case fall_up:
		if(arrows[1].y==2)
		Ustate= chk_up;
		else
		Ustate= Uwait;
		break;
		
		case Uwait:
		if( (Ucnt<level_time) )
		Ustate= Uwait;
		else if ( !(Ucnt<level_time) )
		Ustate= fall_up;
		break;
		
		case chk_up:
		Ustate= rst_up;
		break;
		case rst_up:
		Ustate= Uinit;
		break;
		default:
		break;
	} // end of up transitions
	
	switch(Ustate){
		case Uinit:
			PORTB=0x00;
		case fall_up:
			arrows[1].y--;
			Ucnt=0;
			break;
		case Uwait:
			Ucnt++;
			break;
		case chk_up:		
			checkb(1);
			if(c)
				PORTB=0x08;
			else{
				PORTB=0x10;
				lives--;
				if(lives==0){
					stop=1;
					
				}					
			}				
			Ubottom=1;
			break;
		case rst_up:
			light(0,0);
			arrows[1].y=6;
			arrows[1].fall=0;
			PORTB=0x00;
			Ubottom=0;
			c=0;
			break;
	 
	}// end of up actions
}

enum Dstates{Dinit,Dwait,fall_down,chk_down,rst_down} Dstate;
unsigned char Dbottom=0; //if reaches bottom =1; ready to re-fall
unsigned long Dcnt;

void down()
{
	check_level();
	switch(Dstate)
	{
		case Dinit:
		if(!(arrows[2].fall) )
		Dstate= Dinit;
		else
		Dstate= Dwait;
		break;
		
		case fall_down:
		if(arrows[2].y==1)
		Dstate= chk_down;
		else
		Dstate= Dwait;
		break;
		
		case Dwait:
		if( (Dcnt<level_time) )
		Dstate= Dwait;
		else if ( !(Dcnt<level_time) )
		Dstate= fall_down;
		break;
		
		case chk_down:
		Dstate= rst_down;
		break;
		case rst_down:
		Dstate= Dinit;
		break;
		default:
		break;
	} // end of down transitions
	
	switch(Dstate)
	{
		case fall_down:
			arrows[2].y--;
			Dcnt=0;
			break;
		case Dwait:
			Dcnt++;
			break;
		case chk_down:
			checkb(2);
			if(c){
				PORTB=0x08;
			
			}				
			else{
				PORTB=0x10;
				lives--;
				if(lives==0){
					stop=1;
				}					
			}				
			Dbottom=1;
			break;
		case rst_down:
			light(0,0);
			arrows[2].y=5;
			arrows[2].fall=0;
			PORTB=0x00;
			Dbottom=0;
			c=0;
			break; 
			
	} // end of down actions
}

enum Rstates{Rinit,Rwait,fall_right,chk_right,rst_right} Rstate;
unsigned char Rbottom=0; //if reaches bottom =1; ready to re-fall
unsigned long Rcnt;

void right()
{
	check_level();
	switch(Rstate)
	{
		case Rinit:
			if(!(arrows[3].fall) )
				Rstate= Rinit;
			else
				Rstate= Rwait;
			break;
		
		case fall_right:
			if(arrows[3].y==2)
				Rstate= chk_right;
			else
				Rstate= Rwait;
			break;
		
		case Rwait:
			if( (Rcnt<level_time) )
				Rstate= Rwait;
			else if ( !(Rcnt<level_time) )
				Rstate= fall_right;
			break;
		
		case chk_right:
			Rstate= rst_right;
			break;
			
		case rst_right:
			Rstate= Rinit;
			break;
		default:
		break;
	} //end of right transitions
	
	switch(Rstate)
	{
		case fall_right:
			arrows[3].y--;
			Rcnt=0;
			break;
			
		case Rwait:
			Rcnt++;
			break;
			
		case chk_right:
			checkb(3);
			if(c)
				PORTB=0x08;
			else{
				PORTB=0x10;
				lives--;
				if(lives==0){
					stop=1;
				}				
			}			
			Rbottom=1;
			break;
			
		case rst_right:
			light(0,0);
			arrows[3].y=5;
			arrows[3].fall=0;
			PORTB=0x00;
			Rbottom=0;
			c=0;
			break;
			
	} //end of right actions 
}





#endif