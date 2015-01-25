#include <avr/io.h>
#include <bit.h>
#include <timer.h>

unsigned char level=1;
unsigned char mksnd=0;

#include <keypad.h>
#include <lcd_8bit_task.h>
#include <speaker.h>

//--------Find GCD function --------------------------------------------------
unsigned long int findGCD(unsigned long int a, unsigned long int b)
{
	unsigned long int c;
	while(1){
		c = a%b;
	if(c==0){return b;}
	a = b;
	b = c;
}
return 0;
}
//--------End find GCD function ----------------------------------------------

// Struct for Tasks represent a running process in our simple real-time operating system.
typedef struct _task {
	/*Tasks should have members that include: state, period,
		a measurement of elapsed time, and a function pointer.*/
	signed char state; //Task's current state
	unsigned long int period; //Task period
	unsigned long int elapsedTime; //Time elapsed since last task tick
	int (*TickFct)(int); //Task tick function
} task;

enum key_sm {press};
 unsigned short x; //stores key press value
// unsigned short kp; //key press


// SynchSM for testing the LCD interface -- waits for button press, fills LCD with repeated random num

enum LT_States { init, greet, w1, w2, w3, w4, select, w_mde, disp_mde, lives_disp,wait, };
unsigned char cnt=0;
unsigned char lives=5;
unsigned char Bval;


int LT_Tick(int state) {
	switch(state){
		case init:
			state= greet;
			LCD_go_g=0;
			break;
			
		case greet:
			if(!(cnt<50)){
				
				state= w1;
				cnt=0;
			}
			else
				state= greet;
			break;
			
		case w1:
			if(!LCD_rdy_g)
				state= w1;
			else{
				state= select;
// 				Bval= SetBit(Bval,0,1);
// 				PORTB=Bval;
			}				
			break;
		case select:
			state= w_mde;
			break;
		
		case w_mde:
			if(x== '\0')
				state= w_mde;
			else if (x!= '\0')
				state= w2;
			break;
		
		case w2:
			if(!LCD_rdy_g)	
				state= w2;
			else 
				state= disp_mde;
			break;
		
		case disp_mde:
			if(cnt < 50)
				state= disp_mde;
			else
			{
				state= w3;
				cnt=0;
			}				
			break;
		
		case w3:
			if(!LCD_rdy_g)
				state= w3;
			else
				state= lives_disp;
			break;
		
		case lives_disp:
			if(cnt<50)
   				state=lives_disp;
   			else if (!(cnt<50) )
			{
				state= w4;
				cnt=0;
			}
   			break;
		case w4:
			if(!LCD_rdy_g)
				state= w4;
			else
				state= wait;
			break;
			
		case wait:
			if(GetBit(PINA,1) && !GetBit(PINA,2)){
				lives--;
				state= lives_disp;
			}				
			else
				state= wait;
			break;
	}   // transitions   
	
	switch(state){
		case init:
			Bval= SetBit(Bval,0,0);
			PORTB=Bval;
			lives=3;
			break;
		case greet:
			cnt++;
			strcpy(LCD_string_g,"Let's play DDR!  ");
			LCD_go_g=1;
			break;
		case w1:
			LCD_go_g=0;
			break;
		case select:
			strcpy(LCD_string_g,"Select a mode.  ");
			LCD_go_g=1;
			break;
		case w_mde:
			x= GetKeypadKey();
			break;
		case w2:
			LCD_go_g=0;
			break;
		case disp_mde:
			if(x == '3')
				strcpy(LCD_string_g,"Easy Peasy!     ");
			else if(x== '1')
				strcpy(LCD_string_g,"Challenge Mode. ");
			cnt++;
			LCD_go_g=1;
			break;
		case w3:
			LCD_go_g=0;
			break;
		case lives_disp:
			cnt++;
			if(lives==5)
			strcpy(LCD_string_g,"You have 5 Lives");
			LCD_go_g=1;
			break;
		case w4:
			LCD_go_g=0;
			//Bval= SetBit(Bval,0,1);
			if(x == '1')
				/*Bval= SetBit(Bval,2,1);*/
				PORTB=0x05;
			else
				PORTB=0x01;
				
			//PORTB=Bval;
			/*mksnd=0;*/
			break;
			
	}// state actions	

	return state;
}


int main(void)
{
	DDRB=0xFF; PORTB=0x00;
	DDRC = 0xF0; PORTC = 0x0F; // Keypad
	DDRD= 0xFF; PORTD= 0x00; // LCD
	Bval= PORTB;
	
	static task task1,task2;
	task *tasks[]= {&task1,&task2};
	const unsigned short numtasks=sizeof(tasks)/sizeof(task*);
	
	unsigned long int LT_calc = 10;
	unsigned long int LI_calc = 10;
	
	
	unsigned long int tmpGCD = 2;
	tmpGCD = findGCD(LT_calc, LI_calc);
// 	tmpGCD= findGCD(tmpGCD,P_calc);
	
	unsigned long int GCD = tmpGCD;
	
// 	unsigned long int LT_period = LT_calc/GCD;
// 	unsigned long int LI_period = LI_calc/GCD;
// 	unsigned long int P_period= P_calc/GCD;
// 	
	task1.state= init;
	task1.elapsedTime= LT_calc;
	task1.period= LT_calc;
	task1.TickFct= &LT_Tick;
	
	task2.state= -1;
	task2.elapsedTime= LI_calc;
	task2.period= LI_calc;
	task2.TickFct= &LCDI_SMTick;
	
// 	task3.state= off;
// 	task3.elapsedTime= P_calc;
// 	task3.period= P_calc;
// 	task3.TickFct= &psound;

	TimerSet(GCD);
	TimerOn();
	
	unsigned char i=0;
	
	while(1)
	{		 
		 for ( i = 0; i < numtasks; i++ ) {
			 // Task is ready to ticks
			 if ( tasks[i]->elapsedTime == tasks[i]->period ) {
				 // Setting next state for task
				 tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
				 // Reset the elapsed time for next tick.
				 tasks[i]->elapsedTime = 0;
			 }
			 tasks[i]->elapsedTime += 1;
		 }
		 while(!TimerFlag);
		 TimerFlag = 0;
	}
}