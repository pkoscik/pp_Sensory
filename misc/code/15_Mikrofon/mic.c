 /* USER CODE BEGIN WHILE */
  while (1)
  {
	  // Start ADC Conversion
	          HAL_ADC_Start(&hadc1);
	         // Poll ADC1 Perihperal & TimeOut = 1mSec
	          HAL_ADC_PollForConversion(&hadc1, 1);
	         // Read The ADC Conversion Result & Map It To PWM DutyCycle
	          AD_RES = HAL_ADC_GetValue(&hadc1);
	          TIM2->CCR1 = (AD_RES<<4);
	          HAL_Delay(1);
	    	  HAL_ADC_Start(&hadc1);
	    	   HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	    	   AdcValue = HAL_ADC_GetValue(&hadc1);
	    	   HAL_Delay(100);
    /* USER CODE END WHILE */