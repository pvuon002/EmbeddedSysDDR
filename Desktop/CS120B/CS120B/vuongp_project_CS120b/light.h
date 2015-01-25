#ifndef _LIGHT_H_
#define _LIGHT_H_
#include <util/delay.h>

//*THIS FILE CONTAINS A STRUCT OF UNSIGNED CHARS X AND Y 
// WHICH REPRESENTS A X,Y COORDINATE OF EACH LED LIGHT IN THE MATRIX

// THE FUNCTION LOAD_VALS ACCEPTS AN ARRAY, ARRAY INDEX, X AND Y 
// AND LOADS ALL VALUES INTO THE ARRAY PASSED IN

// THE FUNCTION RST RESETS ALL ORIGINAL VALUES OF THE POINTS OF EACH ARROW

// THE FUNCTION LIGHT LIGHTS EACH LED SPECIFIED IN THE X AND Y COORDINATE

// THE FUNCTION DRAW DRAWS EACH ARROW ACCORDING TO THE POINT COORDINATE OF THE ARROW
// IN THE DRAW FUNCTION, ANOTHER FUNCTION CHECK, CHECKS FOR CORRECTNESS OF
// BUTTON PRESS. 

//*




void load_vals(coord a[],unsigned char loc, unsigned char x_loc, unsigned char y_loc, unsigned char f)
{
	a[loc].x= x_loc;
	a[loc].y= y_loc;
	a[loc].fall= f;	
}

void light(unsigned char x, unsigned char y){
	switch(x){
		case 0:
			DDRA,DDRC = 0x00;
			PORTA,PORTC = 0x00;
			break;
		case 1:
			switch(y){
				case 1:			//1, 1
					DDRA= 0x01;
					DDRC= 0x20;
					PORTA= 0x00;
					PORTC= 0x20;
					asm("nop");
					break;
				case 2:			//1, 2
					DDRA = 0x01;
					DDRC = 0x10;
					PORTA = 0x00;
					PORTC = 0x10;
					asm("nop");
					break;
				case 3:			//1, 3
					DDRA = 0x01;
					DDRC = 0x08;
					PORTC = 0x08;
					PORTA = 0x00;
					asm("nop");
					break;
				case 4:			//1, 4
					DDRA = 0x01;
					DDRC = 0x04;
					PORTC = 0x04;
					PORTA = 0x00;
					asm("nop");
					break;
				case 5:			//1, 5
					DDRA = 0x01;
					DDRC = 0x02;
					PORTA = 0x00;
					PORTC = 0x02;
					asm("nop");
					break;
				case 6:			//1, 6
					DDRA = 0x01;
					DDRC = 0x01;
					PORTA = 0x00;
					PORTC = 0x01;
					asm("nop");
					break;
			}
			break;
		case 2:
			switch(y){
				case 1:		//2, 1
				DDRA = 0x02;
				DDRC = 0x20;
				PORTA = 0x00;
				PORTC = 0x20;
				asm("nop");
				break;
				case 2:		//2, 2
				DDRA = 0x02;
				DDRC = 0x10;
				PORTA = 0x00;
				PORTC = 0x10;
				asm("nop");
				break;
				case 3:		//2, 3
				DDRA = 0x02;
				DDRC = 0x08;
				PORTA = 0x00;
				PORTC = 0x08;
				asm("nop");
				break;
				case 4:		//2, 4
				DDRA = 0x02;
				DDRC = 0x04;
				PORTA = 0x00;
				PORTC = 0x04;
				asm("nop");
				break;
				case 5:		//2, 5
				DDRA = 0x02;
				DDRC = 0x02;
				PORTA = 0x00;
				PORTC = 0x02;
				asm("nop");
				break;
				case 6:		//2, 6
				DDRA = 0x02;
				DDRC = 0x01;
				PORTA = 0x00;
				PORTC = 0x01;
				asm("nop");
				break;		
			}
			break;
		case 3:
			switch(y){
				case 1:		//3, 1
				DDRA = 0x04;
				DDRC = 0x20;
				PORTA = 0x00;
				PORTC = 0x20;
				asm("nop");
				break;
				case 2:		//3, 2
				DDRA = 0x04;
				DDRC = 0x10;
				PORTA = 0x00;
				PORTC = 0x10;
				asm("nop");
				break;
				case 3:		//3, 3
				DDRA = 0x04;
				DDRC = 0x08;
				PORTA = 0x00;
				PORTC = 0x08;
				asm("nop");
				break;
				case 4:		//3, 4
				DDRA = 0x04;
				DDRC = 0x04;
				PORTA = 0x00;
				PORTC = 0x04;
				asm("nop");
				break;
				case 5:		//3, 5
				DDRA = 0x04;
				DDRC = 0x02;
				PORTA = 0x00;
				PORTC = 0x02;
				asm("nop");
				break;
				case 6:		//3, 6
				DDRA = 0x04;
				DDRC = 0x01;
				PORTA = 0x00;
				PORTC = 0x01;
				asm("nop");
				break;
			}
			break;
		case 4:
			switch(y){
				case 1:		//4, 1
				DDRA = 0x08;
				DDRC = 0x20;
				PORTA = 0x00;
				PORTC = 0x20;
				asm("nop");
				break;
				case 2:		//4, 2
				DDRA = 0x08;
				DDRC = 0x10;
				PORTA = 0x00;
				PORTC = 0x10;
				asm("nop");
				break;
				case 3:		//4, 3
				DDRA = 0x08;
				DDRC = 0x08;
				PORTA = 0x00;
				PORTC = 0x08;
				asm("nop");
				break;
				case 4:		//4, 4
				DDRA = 0x08;
				DDRC = 0x04;
				PORTA = 0x00;
				PORTC = 0x04;
				asm("nop");
				break;
				case 5:		//4, 5
				DDRA = 0x08;
				DDRC = 0x02;
				PORTA = 0x00;
				PORTC = 0x02;
				asm("nop");
				break;
				case 6:		//4, 6
				DDRA = 0x08;
				DDRC = 0x01;
				PORTA = 0x00;
				PORTC = 0x01;
				asm("nop");
				break;				
			}
			break;
		case 5:
			switch(y){
				case 1:		//5, 1
				DDRA = 0x10;
				DDRC = 0x20;
				PORTA = 0x00;
				PORTC = 0x20;
				asm("nop");
				break;
				case 2:		//5, 2
				DDRA = 0x10;
				DDRC = 0x10;
				PORTA = 0x00;
				PORTC = 0x10;
				asm("nop");
				break;
				case 3:		//5, 3
				DDRA = 0x10;
				DDRC = 0x08;
				PORTA = 0x00;
				PORTC = 0x08;
				asm("nop");
				break;
				case 4:		//5, 4
				DDRA = 0x10;
				DDRC = 0x04;
				PORTA = 0x00;
				PORTC = 0x04;
				asm("nop");
				break;
				case 5:		//5, 5
				DDRA = 0x10;
				DDRC = 0x02;
				PORTA = 0x00;
				PORTC = 0x02;
				asm("nop");
				break;
				case 6:		//5, 6
				DDRA = 0x10;
				DDRC = 0x01;
				PORTA = 0x00;
				PORTC = 0x01;
				asm("nop");
				break;
			}
			break;
		case 6:
			switch(y){
				case 1:		//6, 1
				DDRA = 0x20;
				DDRC = 0x20;
				PORTA = 0x00;
				PORTC = 0x20;
				asm("nop");
				break;
				case 2:		//6, 2
				DDRA = 0x20;
				DDRC = 0x10;
				PORTA = 0x00;
				PORTC = 0x10;
				asm("nop");
				break;
				case 3:		//6, 3
				DDRA = 0x20;
				DDRC = 0x08;
				PORTA = 0x00;
				PORTC = 0x08;
				asm("nop");
				break;
				case 4:		//6, 4
				DDRA = 0x20;
				DDRC = 0x04;
				PORTA = 0x00;
				PORTC = 0x04;
				asm("nop");
				break;
				case 5:		//6, 5
				DDRA = 0x20;
				DDRC = 0x02;
				PORTA = 0x00;
				PORTC = 0x02;
				asm("nop");
				break;
				case 6:		//6, 6
				DDRA = 0x20;
				DDRC = 0x01;
				PORTA = 0x00;
				PORTC = 0x01;
				asm("nop");
				break;
			}
			break;
		case 7:
			switch(y){
				case 1:		//7, 1
				DDRA = 0x40;
				DDRC = 0x20;
				PORTA = 0x00;
				PORTC = 0x20;
				asm("nop");
				break;
				case 2:		//7, 2
				DDRA = 0x40;
				DDRC = 0x10;
				PORTA = 0x00;
				PORTC = 0x10;
				asm("nop");
				break;
				case 3:		//7, 3
				DDRA = 0x40;
				DDRC = 0x08;
				PORTA = 0x00;
				PORTC = 0x08;
				asm("nop");
				break;
				case 4:		//7, 4
				DDRA = 0x40;
				DDRC = 0x04;
				PORTA = 0x00;
				PORTC = 0x04;
				asm("nop");
				break;
				case 5:		//7, 5
				DDRA = 0x40;
				DDRC = 0x02;
				PORTA = 0x00;
				PORTC = 0x02;
				asm("nop");
				break;
				case 6:		//7, 6
				DDRA = 0x40;
				DDRC = 0x01;
				PORTA = 0x00;
				PORTC = 0x01;
				asm("nop");
				break;				
			}
			break;
		case 8:
			switch(y){
				case 1:		//8, 1
				DDRA = 0x80;
				DDRC = 0x20;
				PORTA = 0x00;
				PORTC = 0x20;
				asm("nop");
				break;
				case 2:		//8, 2
				DDRA = 0x80;
				DDRC = 0x10;
				PORTA = 0x00;
				PORTC = 0x10;
				asm("nop");
				break;
				case 3:		//8, 3
				DDRA = 0x80;
				DDRC = 0x08;
				PORTA = 0x00;
				PORTC = 0x08;
				asm("nop");
				break;
				case 4:		//8, 4
				DDRA = 0x80;
				DDRC = 0x04;
				PORTA = 0x00;
				PORTC = 0x04;
				asm("nop");
				break;
				case 5:		//8, 5
				DDRA = 0x80;
				DDRC = 0x02;
				PORTA = 0x00;
				PORTC = 0x02;
				asm("nop");
				break;
				case 6:		//8, 6
				DDRA = 0x80;
				DDRC = 0x01;
				PORTA = 0x00;
				PORTC = 0x01;
				asm("nop");
				break;				
			}
			break;
			case 9:
			switch(y){
				case 1:		//8, 1
				DDRC = 0xA0;
				PORTC = 0x20;
				asm("nop");
				break;
				case 2:		//8, 2
				DDRC = 0xB0;
				PORTC = 0x10;
				asm("nop");
				break;
				case 3:		//8, 3
				DDRC = 0x88;
				PORTC = 0x08;
				asm("nop");
				break;
				case 4:		//8, 4
				DDRC = 0x84;
				PORTC = 0x04;
				asm("nop");
				break;
				case 5:		//8, 5
				DDRC = 0x82;
				PORTC = 0x02;
				asm("nop");
				break;
				case 6:		//8, 6
				DDRC = 0x81;
				PORTC = 0x01;
				asm("nop");
				break;
			}
			break;
			case 10:
			switch(y){
				case 1:		//8, 1
				DDRC = 0x60;
				PORTC = 0x20;
				asm("nop");
				break;
				case 2:		//8, 2
				DDRC = 0x50;
				PORTC = 0x10;
				asm("nop");
				break;
				case 3:		//8, 3
				DDRC = 0x48;
				PORTC = 0x08;
				asm("nop");
				break;
				case 4:		//8, 4
				DDRC = 0x44;
				PORTC = 0x04;
				asm("nop");
				break;
				case 5:		//8, 5
				DDRC = 0x42;
				PORTC = 0x02;
				asm("nop");
				break;
				case 6:		//8, 6
				DDRC = 0x41;
				PORTC = 0x01;
				asm("nop");
				break;
			}
			break;
	}
	_delay_ms(5);
}

void draw(coord arr[], unsigned char d){
	//unsigned char p= (~PIND) & 0x0F;
	
	//LEFT 
 		if(d==0 && arr[d].fall){ 
// 			
// 			if(arr[0].y==2 && left_press && !up_press && !down_press && !right_press )
// 				PORTB=0x08; 						
// 			else if ( (arr[0].y==2 && (!left_press || up_press || down_press || right_press  ) ) || 
// 						(arr[0].y!=2 && (left_press || up_press || down_press || right_press  )) )
// 				PORTB=0x10;
				
			light(arr[0].x, arr[0].y);
			light(arr[0].x+1, arr[0].y+1);
			light(arr[0].x+1, arr[0].y-1);	
								
		}
	//UP
		else if (d== 1 && arr[d].fall){
			//if(arr[0].y==2 && p)
			//	PORTB=0x08;
			light(arr[1].x, arr[1].y);
			light(arr[1].x-1, arr[1].y-1);
			light(arr[1].x+1, arr[1].y-1);
		}
	//DOWN
		else if (d== 2 && arr[d].fall){
			//if(arr[0].y==1 && p)
			//	PORTB=0x08;
			light(arr[2].x, arr[2].y);
			light(arr[2].x-1, arr[2].y+1);
			light(arr[2].x+1, arr[2].y+1);
		}
	//RIGHT
		else if (d == 3 && arr[d].fall){
			//if(arr[0].y==2 && p)
			//	PORTB=0x08;
			light(arr[3].x, arr[3].y);
			light(arr[3].x-1, arr[3].y+1);
			light(arr[3].x-1, arr[3].y-1);
		}
// 		else if(d == 5 && arr[0].fall && arr[1].fall){
// 			light(arr[0].x, arr[0].y);
// 			light(arr[0].x+1, arr[0].y+1);
// 			light(arr[0].x+1, arr[0].y-1);
// 			
// 			light(arr[1].x, arr[1].y);
// 			light(arr[1].x-1, arr[1].y-1);
// 			light(arr[1].x+1, arr[1].y-1);
// 		}

}



#endif