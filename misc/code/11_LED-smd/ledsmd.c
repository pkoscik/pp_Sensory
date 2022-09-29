HAL_GPIO_TogglePin(LED_green_GPIO_Port, LED_green_Pin);
  while (1)
  {
		HAL_Delay(1000);
		HAL_GPIO_TogglePin(LED_green_GPIO_Port, LED_green_Pin);
		HAL_GPIO_TogglePin(LED_red_GPIO_Port, LED_red_Pin);
		HAL_Delay(1000);
		HAL_GPIO_TogglePin(LED_red_GPIO_Port, LED_red_Pin);
		HAL_GPIO_TogglePin(LED_blue_GPIO_Port, LED_blue_Pin);
		HAL_Delay(1000);
		HAL_GPIO_TogglePin(LED_blue_GPIO_Port, LED_blue_Pin);
		HAL_GPIO_TogglePin(LED_green_GPIO_Port, LED_green_Pin);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }