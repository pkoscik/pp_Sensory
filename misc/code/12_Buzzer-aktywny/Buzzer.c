/* USER CODE BEGIN 0 */
GPIO_PinState USERBtn_state;
GPIO_PinState Buzzer_state;
/* USER CODE END 0 */

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin) == 1)
		  HAL_GPIO_WritePin(HW508_GPIO_Port, HW508_Pin, 1);

	  else
		  HAL_GPIO_WritePin(HW508_GPIO_Port, HW508_Pin, 0);

	  USERBtn_state = HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin);
	  HAL_Delay(100);
	  Buzzer_state = HAL_GPIO_ReadPin(HW508_GPIO_Port, HW508_Pin);
	  HAL_Delay(5);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */