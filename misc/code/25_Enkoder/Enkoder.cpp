/* USER CODE BEGIN 1 */
uint32_t impulsy;
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */
  HAL_TIM_Encoder_Start(&htim8,TIM_CHANNEL_ALL); //uruchomienie enkodera z wykorzystaniem timera 8
/* USER CODE END2 */

/* USER CODE BEGIN WHILE */
  while (1)
  {

	  impulsy = __HAL_TIM_GET_COUNTER(&htim8);  // zliczanie impulsów enkodera (1 krok to jeden impuls)
	  HAL_Delay(50);
     /* USER CODE END WHILE */
  }