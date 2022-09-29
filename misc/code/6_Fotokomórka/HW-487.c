/* USER CODE BEGIN PV */
_Bool sig;

/* USER CODE END PV */


/* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	HAL_Delay(100);
	if(HAL_GPIO_ReadPin(sensor_GPIO_Port, sensor_Pin)){
		sig = 1;
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
	}
	else{
		sig = 0;
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
	}
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */