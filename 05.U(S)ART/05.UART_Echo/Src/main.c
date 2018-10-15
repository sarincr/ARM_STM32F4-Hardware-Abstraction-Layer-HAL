#include <stm32f4xx_hal.h>
#include <stm32_hal_legacy.h>
UART_HandleTypeDef huart2;

uint8_t byte;

void SystemClock_Config(void);

void USART2_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart2);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART2)
  {

    HAL_UART_Transmit(&huart2, &byte, 1, 100);


    HAL_UART_Receive_IT(&huart2, &byte, 1);
  }
}

void uart_gpio_init()
{
  GPIO_InitTypeDef GPIO_InitStruct;

  __GPIOA_CLK_ENABLE();


  GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void uart_init()
{
  __USART2_CLK_ENABLE();

  huart2.Instance = USART2;
  huart2.Init.BaudRate =9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart2);

  HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART2_IRQn);
}

int main(void)
{
  HAL_Init();

  uart_gpio_init();
  uart_init();

  HAL_UART_Receive_IT(&huart2, &byte, 1);

  while(1)
  {

  }
}
