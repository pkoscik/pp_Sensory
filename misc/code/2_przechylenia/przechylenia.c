/* USER CODE BEGIN PV */
_Bool nachylenie = 0;
/* USER CODE END PV */

  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_Delay(100);
	  if(HAL_GPIO_ReadPin(PE2_Sense_GPIO_Port, PE2_Sense_Pin)){
		  nachylenie = 1;
	  }
	  else nachylenie =0;
    /* USER CODE END WHILE */
