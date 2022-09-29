/* USER CODE BEGIN PV */
float value;
uint32_t raw_sample;

/* USER CODE END PV */ 
/* USER CODE BEGIN WHILE */
  while (1)
  {
	     HAL_ADC_Start(&hadc1);
	     HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	     raw_sample = HAL_ADC_GetValue(&hadc1);
	     value = (raw_sample*5.0)/4096;
		 HAL_Delay(10);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
