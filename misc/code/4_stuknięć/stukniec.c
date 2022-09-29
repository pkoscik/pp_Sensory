/* USER CODE BEGIN WHILE */
  while (1)
  {
	  //HAL_Delay(100);
	    //   if(HAL_GPIO_ReadPin(pin1_GPIO_Port, pin1_Pin)){
	      //     signal = 1;
	        //   stukniecie += 1;
	      // }
	      // else signal = 0;
	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	  LD1_State = HAL_GPIO_ReadPin(LD2_GPIO_Port, LD2_Pin);
	  HAL_Delay(1000);
    /* USER CODE END WHILE */