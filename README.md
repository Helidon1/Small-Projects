# Small-Projects
# Bare-Metal STM32 Projects

This repository contains a collection of embedded systems projects developed specifically for the **STM32** microcontroller family (targeting the STM32F401RE ARM Cortex-M4). 

### Development: 100% Bare-Metal
To maximize technical understanding and maintain absolute control over the hardware, **no Hardware Abstraction Layers (HAL) or non-standard vendor libraries are used in this repository.** 

Every project in this collection is built from the ground up using:
*   **Direct Register Manipulation:** All peripheral configurations (GPIO, RCC, etc.) are handled by directly interacting with memory-mapped registers via C pointers.
*   **Standard C:** Pure, bare-metal C programming without the crutch of auto-generated setup code.
*   **Datasheet-Driven Design:** Code architecture is derived directly from the STM32F4 Reference Manuals rather than high-level APIs. 

*(Note: STM32CubeIDE is utilized strictly as a compiler, linker, and ST-Link debugging environment, with the graphical HAL code-generator completely bypassed).*

---

###  Project Directory
*   **[Bare-Metal 4x4 Matrix Keypad](./YOUR_FOLDER_NAME)**
    *   *Features:* Direct GPIO polling, software state-trapping for debouncing, and ST-Link hardware isolation. Output routed through SWV ITM Data Console. 
