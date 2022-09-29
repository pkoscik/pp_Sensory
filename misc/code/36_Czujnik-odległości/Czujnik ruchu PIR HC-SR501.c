/* Infinite loop */
/* USER CODE BEGIN WHILE */
while(1){

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		if(HAL_GPIO_ReadPin(PIR_GPIO_Port, PIR_Pin))
			HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
		else
			HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
}
	/* USER CODE END 3 */