#include <avr/io.h>

//---------------------------------GLOBALS-------------------//
 
typedef struct _coord{
	unsigned char x;
	unsigned char y;
	unsigned char fall;
} coord;

// GLOBAL ARRAY OF ARROWS
// (x,y) and falling bit
coord arrows[4];

unsigned char c=0;
unsigned char indx=0;
unsigned char msp=0; //wrong press bit, 1 if wrong 0 if correct
unsigned char lives=3;
unsigned char stop=0;
unsigned char begin=0;
unsigned char win=2;
unsigned char wval=0;
unsigned char left_press=0;
unsigned char up_press=0;
unsigned char down_press=0;
unsigned char right_press=0;
unsigned char mksnd=0;
unsigned char bval=0;
unsigned char level_time=0;

 
//-----------------------HEADER FILES-----------------------//
 #include <timer.h>
#include <light.h>
#include <all_arrows.h>
// #include <check_left.h>
// #include <check_up.h>
// #include <check_down.h>
// #include <check_right.h>

// //----------------------------------------------------------//

int main(void)
{
	DDRD= 0x00; PORTD= 0xFF;
	DDRB= 0xFF; PORTB= 0x00;
		
	
	
	//---------DECLARE INITIAL STATES-------------//
	
	//Bstate= Binit; //button press SM
	Lstate= Linit; //LEFT arrow falling SM
	Ustate= Uinit; //UP SM
	Dstate= Dinit; //DOWN SM
	Rstate= Rinit; //UP SM
	/*B3State= off;*/
	//Ranstate= Raninit;
	
	
	//----------Button Check States--------------//
 	LCstate= LCinit;
 	UCstate= UCinit;
 	DCstate= DCinit;
 	RCstate= RCinit;
	
	//--------------------------------------------
	
	//--------------------------------------------//
	
	
	//---------LOAD INITIAL ARROW POINT LOCATIONS-------------//
	
	load_vals(arrows,0,1,5,0);
	load_vals(arrows,1,4,6,0);
	load_vals(arrows,2,7,5,0);
	load_vals(arrows,3,10,5,0);
	
	//--------------------------------------------------------//
	
	//---------DECLARE OTHER VARIABLES-------------//
	srand(1000);
	begin= GetBit(PIND,4); //gets a ready bit from microcont. 2
	indx=rand()%4;
	lives=5;
	stop=0;
	
	TimerSet(10);
	TimerOn();
	win=10;

	
	
	while(1)
	{
		
		
		while(GetBit((PIND),4) != 0)
		{
			mksnd= ( GetBit((PIND),6) );
			
			left_pr();
			up_pr();
			down_pr();
			right_pr();
			
		if(!stop && GetBit(PIND,4) )
		{
							
			arrows[indx].fall=1;
			
			while(!TimerFlag)
			{
				draw(arrows,indx);
			}
			TimerFlag=0;
	
			if(indx==0)
			left();
			else if(indx==1)
			up();
			else if(indx==2)
			down();
			else if(indx==3)
			right();
					

			if(indx==0 && Lbottom)
			{
				indx= rand()%4;
				win--;
			}
			else if(indx==1 && Ubottom)
			{
				indx= 0;
				win--;
			}
			else if(indx==2 && Dbottom)
			{
				indx= rand()%4;
				win--;
			}
			else if(indx==3 && Rbottom)
			{
				indx= 1;
				win--;
			}

			if(win==0)
			{
				PORTB=0x18;
				stop=1;
				
			}
			if(stop)
				break;
			
		}//end of if
		
	else{
			light(0,0);
			if(lives==0){
				light(5,5);
				light(7,5);
				light(4,1);
				light(5,2);
				light(6,2);
				light(7,2);
				light(8,1);
			}
			else if(win==0 && lives!=0)
			{
				
					light(5,5);
					light(7,5);
					light(3,4);
					light(4,3);
					light(4,4);
					light(5,2);
					light(6,2);
					light(7,2);
					light(8,3);
					light(9,4);
			}
	}		
	}// end of pind loop
			
  }// end of while
	

} // end of main