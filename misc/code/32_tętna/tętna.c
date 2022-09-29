float x;
uint32_t sample;
/* USER CODE END PV */
 
 
  /* USER CODE BEGIN WHILE */
 
  while (1)
  {
      HAL_ADC_Start(&hadc1);
      if(HAL_ADC_PollForConversion(&hadc1, 1000)==HAL_OK){
          sample = HAL_ADC_GetValue(&hadc1);
      }
    HAL_Delay(100);
   }