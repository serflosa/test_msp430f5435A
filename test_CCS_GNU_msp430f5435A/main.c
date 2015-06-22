#include <msp430.h> 

#define LEDS_OUT   P6OUT

#define LED_GREEN     	(1 << 5) // pin 6.5
#define LED_YELLOW     	(1 << 6) // pin 6.6
#define LED_RED     	(1 << 7) // pin 6.7

#define led_on(led)			LEDS_OUT |= led
#define led_off(led) 		LEDS_OUT &= ~(led)
#define led_toggle(led)		LEDS_OUT ^= led
#define leds_init()			do {\
								/*Set pins 6.5, 6.6 and 6.7 as output. */\
								P6DIR |= LED_GREEN;\
							    P6DIR |= LED_YELLOW;\
							    P6DIR |= LED_RED;\
							    /* Set pin 6.5, 6.6 and 6.7 function as I/O. */\
								P6SEL &= ~(LED_GREEN);\
							    P6SEL &= ~(LED_YELLOW);\
							    P6SEL &= ~(LED_RED);\
							    /* Turn leds off. */\
								led_off(LED_GREEN);\
								led_off(LED_YELLOW);\
								led_off(LED_RED);\
							}while(0)


/*
 * main.c
 */

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    _disable_interrupts();
    leds_init();
    led_on(LED_RED);

    led_on(LED_YELLOW);

	return 0;
}
