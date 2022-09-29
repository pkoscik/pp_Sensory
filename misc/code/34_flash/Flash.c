/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "W25Q64_Flash.h"

  /* USER CODE BEGIN 2 */
  uint8_t read_buffer[256];
  uint8_t write_buffer[256];

  for(int i=0; i< 256; i++)
  {
    write_buffer[i] = i;
  }

  W25Q64_Init();
  W25Q64_SectorErase(0);

  W25Q64_ReadDataBytes(0x0000, read_buffer, 256);
  W25Q64_PageProgram(0x0000, write_buffer, 256);
  W25Q64_ReadDataBytes(0x0000, read_buffer, 256);
  /* USER CODE END 2 */