#include <stm32f4xx_hal.h>

void SysTick_Handler(void)
{
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

static TIM_HandleTypeDef htim2 = {
    .Instance = TIM2
};

void InitializeTimer()
{
    __TIM2_CLK_ENABLE();
    htim2.Init.Prescaler = 40000;
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.Period = 500;
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim2.Init.RepetitionCounter = 0;
    HAL_TIM_Base_Init(&htim2);
    HAL_TIM_Base_Start(&htim2);
}

void InitializeLED()
{
    __GPIOD_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Pin = GPIO_PIN_12;

    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
}

int main(void)
{
    HAL_Init();
    InitializeLED();
    InitializeTimer();

    for (;;)
    {
        int timerValue = __HAL_TIM_GET_COUNTER(&htim2);
        if (timerValue == 400)
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
        if (timerValue == 500)
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    }
}
