  while (1)
  {
	  HAL_Delay(100);
	  if(HAL_GPIO_ReadPin(PE2_Sense_GPIO_Port, PE2_Sense_Pin)){
		  HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
	  }
	  else HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
    /* USER CODE END WHILE */
