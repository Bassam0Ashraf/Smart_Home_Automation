/******************************************************************************
 *
 * Main Application
 *
 * File Name: Smart_Home.c
 *
 * Description: Source file for the Smart Home Application.
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/

/* Include header file "Smart_Home.h" that contain all file we need */
#include "Smart_Home.h"

/*******************************************************************************
 *                     		  Main Program                                     *
 *******************************************************************************/

int main()
{
	/* Initialize all drivers we need. */
	LEDS_init();
	LCD_init();
	Buzzer_init();
	FlameSensor_init();
	DcMotor_Init();
	ADC_init();

	/* Define two variable to store the temperature and LDR intensity value. */
	uint8 LDR_Intensity = 0 ;
	uint8 LM35_Temperature = 0 ;

	/* Clear LCD first and display the string "Temp=" & "LDR=   %" */
	LCD_clearScreen();
	LCD_displayStringRowColumn(1, 0, "Temp=");
	LCD_displayStringRowColumn(1, 8, "LDR=   %");

	for(;;)
	{
		/* Get value of temperature and LDR. */
		LDR_Intensity = LDR_getLightIntensity() ;
		LM35_Temperature = LM35_getTemperature();

        /* Set the max Temperature to 99 */
        LM35_Temperature = (LM35_Temperature > 99) ? 99 : LM35_Temperature ;



        /* Display state of fan,temperature and LDR on LCD  */

        /* Display state of fan */
		if( LM35_Temperature >= 25 )
		{
			LCD_displayStringRowColumn(0, 3, "Fan is ON ");
		}
		else
		{
			LCD_displayStringRowColumn(0, 3, "Fan is OFF");
		}

		/* Display temperature value */
		if(LM35_Temperature >= 100)
		{
			LCD_moveCursor(1, 5);
			LCD_intgerToString(LM35_Temperature);
		}
		else
		{
			LCD_moveCursor(1, 5);
			LCD_intgerToString(LM35_Temperature);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

		/* Display LDR intensity value */
		if(LDR_Intensity >= 100)
		{
			LCD_moveCursor(1, 12);
			LCD_intgerToString(LDR_Intensity);
		}
		else
		{
			LCD_moveCursor(1, 12);
			LCD_intgerToString(LDR_Intensity);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}



		/* LEDs controller */
		if( LDR_Intensity <= 15 )
		{
			LED_on( LED_RED   );
			LED_on( LED_GREEN );
			LED_on( LED_BLUE  );
		}
		else if ( LDR_Intensity >= 16 && LDR_Intensity <= 50 )
		{
			LED_on ( LED_RED   );
			LED_on ( LED_GREEN );
			LED_off( LED_BLUE  );
		}
		else if ( LDR_Intensity >= 51 && LDR_Intensity <= 70 )
		{
			LED_on ( LED_RED   );
			LED_off( LED_GREEN );
			LED_off( LED_BLUE  );
		}
		else
		{
			LED_off( LED_RED   );
			LED_off( LED_GREEN );
			LED_off( LED_BLUE  );
		}



		/* Fan controller */
		if( LM35_Temperature >= 40 )
		{
			DcMotor_Rotate( CW , 100 );
		}
		else if ( LM35_Temperature >= 35 && LM35_Temperature <= 39 )
		{
			DcMotor_Rotate( CW , 75 );
		}
		else if ( LM35_Temperature >= 30 && LM35_Temperature <= 34 )
		{
			DcMotor_Rotate( CW , 50 );
		}
		else if ( LM35_Temperature >= 25 && LM35_Temperature <= 29 )
		{
			DcMotor_Rotate( CW , 25 );
		}
		else
		{
			DcMotor_Rotate( STOP , 0);
		}



		/* Flame sensor controller */
		if( FlameSensor_getValue() )
		{
			Buzzer_on();											// Turn ON buzzer.
			LCD_clearScreen();										// Clear LCD.
			LCD_displayStringRowColumn(0, 1, "Critical Alert!");	// Display string "Critical Alert!".
			while( FlameSensor_getValue() );						// wait till flame sensor doesn't detect flame anymore.
			Buzzer_off();											// Turn OFF buzzer.
			LCD_clearScreen();										// Clear LCD.

			/* continue display state of fan,temperature and ldr on LCD  */
			LCD_displayStringRowColumn(1, 0, "Temp=");
			LCD_displayStringRowColumn(1, 8, "LDR=   %");
			if( LM35_Temperature >= 25 )
			{
				LCD_displayStringRowColumn(0, 3, "Fan is ON ");
			}
			else
			{
				LCD_displayStringRowColumn(0, 3, "Fan is OFF");
			}
		}

	}

	return 0;
}
