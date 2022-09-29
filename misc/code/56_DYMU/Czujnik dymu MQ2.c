/* USER CODE BEGIN PV */
uint16_t Analog_val;
GPIO_PinState Digital_state;
/* USER CODE END PV */

/* USER CODE BEGIN 2 */
HAL_ADC_Start(&hadc3);
/* USER CODE END 2 */

/* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while(1){

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		if (HAL_ADC_PollForConversion(&hadc3, 10) == HAL_OK) {
			Analog_val = HAL_ADC_GetValue(&hadc3);
					HAL_ADC_Start(&hadc3);
		}
		Digital_state = !HAL_GPIO_ReadPin(DOUT_GPIO_Port, DOUT_Pin);

		if(Digital_state){
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
			HAL_Delay(100);
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);

			HAL_Delay(100);

			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			HAL_Delay(100);
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

			HAL_Delay(100);

			HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
			HAL_Delay(100);
			HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);

			HAL_Delay(100);
		}
		else{
			HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 0);
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
			HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
		}
	}
  /* USER CODE END 3 */