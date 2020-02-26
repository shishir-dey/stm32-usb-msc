/**
  ******************************************************************************
  * @file   fatfs.c
  * @brief  Code for fatfs applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#include "fatfs.h"

uint8_t retUSBH;    /* Return value for USBH */
char USBHPath[4];   /* USBH logical drive path */
FATFS USBHFatFS;    /* File system object for USBH logical drive */
FIL USBHFile;       /* File object for USBH */

/* USER CODE BEGIN Variables */

/* USER CODE END Variables */    

void FatFS_routine(void)
{
	FRESULT res;
	uint32_t byteswritten;

	char wtext[100] = "This line has been written by an STM32 device!\n";

	if(f_mount(&USBHFatFS, (TCHAR const*) USBHPath, 0) == FR_OK)
	{
		res = f_open(&USBHFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE);

		if (res != FR_OK)
		{
			return;
		}

		res = f_write(&USBHFile, wtext, strlen(wtext), (void *)&byteswritten);

		if (res != FR_OK)
		{
			return;
		}

		res = f_sync(&USBHFile);

		if (res != FR_OK)
		{
			return;
		}

		res = f_close(&USBHFile);

		if (res != FR_OK)
		{
			return;
		}
	}
}

void MX_FATFS_Init(void) 
{
  /*## FatFS: Link the USBH driver ###########################*/
  retUSBH = FATFS_LinkDriver(&USBH_Driver, USBHPath);

  /* USER CODE BEGIN Init */
  /* additional user code for init */     
  /* USER CODE END Init */
}

/**
  * @brief  Gets Time from RTC 
  * @param  None
  * @retval Time in DWORD
  */
DWORD get_fattime(void)
{
  /* USER CODE BEGIN get_fattime */
  return 0;
  /* USER CODE END get_fattime */  
}

/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
