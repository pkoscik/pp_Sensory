  /* USER CODE BEGIN 1 */
GPIO_PinState RelayOff = GPIO_PIN_RESET;
GPIO_PinState RelayState;
  /* USER CODE END 1 */

  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  RelayState = HAL_GPIO_ReadPin(Relay_s_GPIO_Port,Relay_s_Pin);
	  if(RelayState==1){
		  HAL_GPIO_WritePin(Relay_s_GPIO_Port,Relay_s_Pin,RelayOff);
	  }
	  else if(RelayState==0)
		  HAL_GPIO_WritePin(Relay_s_GPIO_Port,Relay_s_Pin,1);
	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}