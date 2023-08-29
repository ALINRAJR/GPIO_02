/*
===============================================================================
 Displaying 8 bit binary counter by connecting leds to P1.19 to P1.26
 	 	 	   Also testing using the logic analyzer

*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

#define TESTCASE0 1
#define TESTCASE1 0

#define FIO1DIR *((volatile unsigned int *)0x2009C020)
#define FIO1SET *((volatile unsigned int *)0x2009C038)
#define FIO1CLR *((volatile unsigned int *)0x2009C03C)

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/* Crude Delay Implementation */
void vAppDelay(uint32_t count)
{
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<0xA00;j++);
}


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

	uint8_t num=0;
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */

	//FIO1DIR =  1<<19 | 1<<20 | 1<<21 | 1<<22 | 1<<23 | 1<<24 | 1<<25 | 1<<26;

	FIO1DIR =  0xFF<<19;

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {
	    FIO1SET = num << 19;
		vAppDelay(1000);

		FIO1CLR = num << 19;
		vAppDelay(1000);

		num++;

	/*  FIOSET = 1<<19;
	  vAppDelay(1000);

	  FIOCLR = 1<<19;
	  vAppDelay(1000);

	  FIOSET = 2<<19;
	  vAppDelay(1000);

	  FIOCLR = 2<<19;
	  vAppDelay(1000);

	  FIOSET = 3<<19;
	  vAppDelay(1000);

	  FIOCLR = 3<<19;
	  vAppDelay(1000);

	  FIOSET = 4<<19;
	  vAppDelay(1000);

	  FIOCLR = 4<<19;
	  vAppDelay(1000); */





  }
  /* End of Application entry point */
}




