/* USER CODE BEGIN 0 */
GPIO_PinState USERBtn_state;
GPIO_PinState Laser_state;
/* USER CODE END 0 */

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin) == 1)
		  HAL_GPIO_WritePin(KY008_GPIO_Port, KY008_Pin, 1);

	  else
		  HAL_GPIO_WritePin(KY008_GPIO_Port, KY008_Pin, 0);

	  USERBtn_state = HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin);
	  HAL_Delay(100);
	  Laser_state = HAL_GPIO_ReadPin(KY008_GPIO_Port, KY008_Pin);
	  HAL_Delay(5);

  }
  /* USER CODE END 3 */