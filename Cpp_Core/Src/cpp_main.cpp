#include "cpp_main.hpp"
#include "usart.h"
#include "usbd_rndis_core.h"
#include "stm32h7xx_hal.h"

extern rndis_rxproc_t rndis_rxproc;

void rxproc(const char *data, int size)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)data, size, 1000);
}

int cpp_main()
{

	MX_USB_DEVICE_Init();
	HAL_Delay(1000);
	rndis_rxproc = rxproc;

	while (1)
	{
		printf("while...\n");
		static char data[1024] = "eset of all peripherals, Initializes the Flash interface and the Systick"
								 "eset of all peripherals, Initializes the Flash interface and the Systick"
								 "	eset of all peripherals, Initializes the Flash interface and the Systick"
								 "		eset of all peripherals, Initializes the Flash interface and the Systick"
								 "			eset of all peripherals, Initializes the Flash interface and the Systick";
		rndis_send(data, 50);
		HAL_Delay(1000);
	}
}