#ifndef STM32_REGISTERS_H_
#define STM32_REGISTERS_H_

#include <stdint.h>

// 1. Clock Control Register Bit Fields (RCC_AHB1ENR)
typedef struct {
    uint32_t GPIOAEN  : 1;  // Bit 0
    uint32_t GPIOBEN  : 1;  // Bit 1
    uint32_t GPIOCEN  : 1;  // Bit 2
    uint32_t GPIODEN  : 1;  // Bit 3
    uint32_t GPIOEEN  : 1;  // Bit 4
    uint32_t reserved : 2;  // Bits 5-6
    uint32_t GPIOHEN  : 1;  // Bit 7
    uint32_t reserved1: 4;  // Bits 8-11
    uint32_t CRCEN    : 1;  // Bit 12
    uint32_t reserved2: 8;  // Bits 13-20
    uint32_t DMA1EN   : 1;  // Bit 21
    uint32_t DMA2EN   : 1;  // Bit 22
    uint32_t reserved3: 9;  // Bits 23-31
} RCC_AHB1ENR_t;

// 2. GPIO Mode Register Bit Fields (MODER) - 2 bits per pin
typedef struct {
    uint32_t MODER0  : 2;
    uint32_t MODER1  : 2;
    uint32_t MODER2  : 2;
    uint32_t MODER3  : 2;
    uint32_t MODER4  : 2;
    uint32_t MODER5  : 2;
    uint32_t MODER6  : 2;
    uint32_t MODER7  : 2;
    uint32_t MODER8  : 2;
    uint32_t MODER9  : 2;
    uint32_t MODER10 : 2;
    uint32_t MODER11 : 2;
    uint32_t MODER12 : 2;
    uint32_t MODER13 : 2;
    uint32_t MODER14 : 2;
    uint32_t MODER15 : 2;
} GPIO_MODER_t;

// 3. GPIO Input Data Register Bit Fields (IDR) - 1 bit per pin
typedef struct {
    uint32_t IDR0  : 1;
    uint32_t IDR1  : 1;
    uint32_t IDR2  : 1;
    uint32_t IDR3  : 1;
    uint32_t IDR4  : 1;
    uint32_t IDR5  : 1;
    uint32_t IDR6  : 1;
    uint32_t IDR7  : 1;
    uint32_t IDR8  : 1;
    uint32_t IDR9  : 1;
    uint32_t IDR10 : 1;
    uint32_t IDR11 : 1;
    uint32_t IDR12 : 1;
    uint32_t IDR13 : 1;
    uint32_t IDR14 : 1;
    uint32_t IDR15 : 1;
    uint32_t reserved : 16;
} GPIO_IDR_t;

// 4. GPIO Output Data Register Bit Fields (ODR) - 1 bit per pin
typedef struct {
    uint32_t ODR0  : 1;
    uint32_t ODR1  : 1;
    uint32_t ODR2  : 1;
    uint32_t ODR3  : 1;
    uint32_t ODR4  : 1;
    uint32_t ODR5  : 1;
    uint32_t ODR6  : 1;
    uint32_t ODR7  : 1;
    uint32_t ODR8  : 1;
    uint32_t ODR9  : 1;
    uint32_t ODR10 : 1;
    uint32_t ODR11 : 1;
    uint32_t ODR12 : 1;
    uint32_t ODR13 : 1;
    uint32_t ODR14 : 1;
    uint32_t ODR15 : 1;
    uint32_t reserved : 16;
} GPIO_ODR_t;

typedef struct {
    uint32_t PUPDR0  : 2;
    uint32_t PUPDR1  : 2;
    uint32_t PUPDR2  : 2;
    uint32_t PUPDR3  : 2;
    uint32_t PUPDR4  : 2;
    uint32_t PUPDR5  : 2;
    uint32_t PUPDR6  : 2;
    uint32_t PUPDR7  : 2;
    uint32_t PUPDR8  : 2;
    uint32_t PUPDR9  : 2;
    uint32_t PUPDR10 : 2;
    uint32_t PUPDR11 : 2;
    uint32_t PUPDR12 : 2;
    uint32_t PUPDR13 : 2;
    uint32_t PUPDR14 : 2;
    uint32_t PUPDR15 : 2;
} GPIO_PUPDR_t;

#define RCC_BASE    0x40023800
#define GPIOA_BASE  0x40020000
#define GPIOB_BASE  0x40020400
#define GPIOC_BASE  0x40020800

//offset 0x30
#define RCC_AHB1ENR  ((volatile RCC_AHB1ENR_t*)(RCC_BASE + 0x30))
#define GPIOA_MODER  ((volatile GPIO_MODER_t*)(GPIOA_BASE + 0x00))
#define GPIOA_IDR    ((volatile GPIO_IDR_t*)(GPIOA_BASE + 0x10))
#define GPIOA_ODR    ((volatile GPIO_ODR_t*)(GPIOA_BASE + 0x14))

#define GPIOB_MODER  ((volatile GPIO_MODER_t*)(GPIOB_BASE + 0x00))
#define GPIOB_IDR    ((volatile GPIO_IDR_t*)(GPIOB_BASE + 0x10))
#define GPIOB_ODR    ((volatile GPIO_ODR_t*)(GPIOB_BASE + 0x14))
#define GPIOA_PUPDR  ((volatile GPIO_PUPDR_t*)(GPIOA_BASE + 0x0C))

#define GPIOC_BASE  0x40020800
#define GPIOC_MODER ((volatile GPIO_MODER_t*)(GPIOC_BASE + 0x00))
#define GPIOC_PUPDR ((volatile GPIO_PUPDR_t*)(GPIOC_BASE + 0x0C))

#endif /* STM32_REGISTERS_H_ */
