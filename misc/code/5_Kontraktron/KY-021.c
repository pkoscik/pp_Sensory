/* USER CODE BEGIN PV */
_Bool zamkniecie_obwodu = 0;
/* USER CODE END PV */

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  HAL_Delay(100);
	  if(HAL_GPIO_ReadPin(PB0_signal_GPIO_Port, PB0_signal_Pin)){
		  zamkniecie_obwodu = 1;
	  }
	  else
	  {
		  zamkniecie_obwodu = 0;
	  }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}