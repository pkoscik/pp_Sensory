/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
 
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */
 
 
/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
#define DS18B20_PORT DATA_GPIO_Port
#define DS18B20_Pin DATA_Pin
 
/* USER CODE END PD */
 
/* Private variables ---------------------------------------------------------*/
 
TIM_HandleTypeDef htim6;
 
UART_HandleTypeDef huart3;
 
/* USER CODE BEGIN PV */
 
uint8_t Rh1, Rh2, Temp1, Temp2;
 
float temperature =0;
uint8_t presence =0;
uint16_t TEMP;
char message[19];
 
/* USER CODE END PV */
 
 
/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void delay (uint32_t us)
{
    __HAL_TIM_SET_COUNTER(&htim6,0);
    while ((__HAL_TIM_GET_COUNTER(&htim6))<us);
}
 
 
void SET_PIN_OUTPUT(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
    GPIO_InitTypeDef GPIO_InitStruct ={0};
    GPIO_InitStruct.Pin = GPIO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
 
}
 
void SET_PIN_INPUT(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
    GPIO_InitTypeDef GPIO_InitStruct ={0};
    GPIO_InitStruct.Pin = GPIO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
 
}
 
uint8_t Start(){
    uint8_t response = 0;
    SET_PIN_OUTPUT(DS18B20_PORT, DS18B20_Pin);
    HAL_GPIO_WritePin(DS18B20_PORT, DS18B20_Pin, 0);
    delay(480);
    SET_PIN_INPUT(DS18B20_PORT, DS18B20_Pin);
    delay(80);
    if(!(HAL_GPIO_ReadPin(DS18B20_PORT, DS18B20_Pin))) response=1;
    else response =-1;
    delay(400);
    return response;
}
 
void write (uint8_t data){
 
    SET_PIN_OUTPUT(DS18B20_PORT, DS18B20_Pin);
 
    for (int i=0; i<8; i++)
    {
 
        if ((data & (1<<i))!=0)
        {
 
            SET_PIN_OUTPUT(DS18B20_PORT, DS18B20_Pin);
            HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_Pin, 0);
            delay (1);
 
            SET_PIN_INPUT(DS18B20_PORT, DS18B20_Pin);
            delay (50);
        }
 
        else
        {
 
 
            SET_PIN_OUTPUT(DS18B20_PORT, DS18B20_Pin);
            HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_Pin, 0);
            delay (50);
 
            SET_PIN_INPUT(DS18B20_PORT, DS18B20_Pin);
        }
    }
}
 
 
uint8_t read(){
 
    uint8_t value=0;
    SET_PIN_INPUT(DS18B20_PORT, DS18B20_Pin);
 
    for (int i=0;i<8;i++)
    {
        SET_PIN_OUTPUT(DS18B20_PORT, DS18B20_Pin);
 
        HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_Pin, 0);
        delay (2);
 
        SET_PIN_INPUT(DS18B20_PORT, DS18B20_Pin);
        if (HAL_GPIO_ReadPin (DS18B20_PORT, DS18B20_Pin))
        {
            value |= 1<<i;
        }
        delay (50);
    }
    return value;
}
/* USER CODE END 0 */
 
 /* USER CODE BEGIN WHILE */
  while (1)
  {
      presence = Start();
      HAL_Delay (1);
      write(0xCC);
      write(0x44);
      HAL_Delay (800);
 
      presence = Start ();
      HAL_Delay(1);
      write (0xCC);
      write (0xBE);
 
      Temp1 = read();
      Temp2 = read();
      TEMP = (Temp2<<8)|Temp1;
      temperature = (float)TEMP/16;
      sprintf(message, "Temp: %f \n\r", temperature);
      HAL_UART_Transmit(&huart3, &message, sizeof(message)-1, 100);
      HAL_Delay(1000);
    /* USER CODE END WHILE */
 
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
 