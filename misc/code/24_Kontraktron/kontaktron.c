  while (1)
  {
	  if(HAL_GPIO_ReadPin(SIG_Input_GPIO_Port, SIG_Input_Pin)){
		  HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_RESET);
	  }
	  HAL_Delay(100);
  }