/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
/* USER CODE END Includes */

/* USER CODE BEGIN PTD */
#define usTIM	TIM4
/* USER CODE END PTD */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim4;
UART_HandleTypeDef huart2;


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM4_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
void usDelay(uint32_t uSec);
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
//Speed of sound in cm/usec
const float speedOfSound = 0.0343/2;
float distance;

char uartBuf[100];
/* USER CODE END 0 */

/* USER CODE BEGIN 1 */
uint32_t numTicks = 0;
/* USER CODE END 1 */

/* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while(1){

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		//Set TRIG to LOW for few uSec
				HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, GPIO_PIN_RESET);
				usDelay(3);

				HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, GPIO_PIN_SET);
				usDelay(10);
				HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, GPIO_PIN_RESET);


				while(HAL_GPIO_ReadPin(ECHO_GPIO_Port, ECHO_Pin) == GPIO_PIN_RESET);


				numTicks = 0;
				while(HAL_GPIO_ReadPin(ECHO_GPIO_Port, ECHO_Pin) == GPIO_PIN_SET)
				{
					numTicks++;
					usDelay(2); //2.8usec
				};


				distance = (numTicks + 0.0f)*2.8*speedOfSound;


				if(distance > 20){
					HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 0);
					HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
					HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
				}
				else if(distance > 15 && distance <= 20){
					HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 1);
					HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
					HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
				}
				else if(distance > 7 && distance <= 15){
					HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 1);
					HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
					HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
				}
				else if(distance <= 7){
					HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 1);
					HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
					HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
				}

				HAL_Delay(100);
	}
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */
void usDelay(uint32_t uSec)
{
	if(uSec < 2) uSec = 2;
	usTIM->ARR = uSec - 1; 	
	usTIM->EGR = 1;
	usTIM->SR &= ~1;
	usTIM->CR1 |= 1;
	while((usTIM->SR&0x0001) != 1);
	usTIM->SR &= ~(0x0001);
}
/* USER CODE END 4 */