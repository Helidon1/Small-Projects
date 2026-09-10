Bare-Metal 4x4 Matrix Keypad Driver for STM32F401RE
A bare-metal C driver for a 4x4 matrix keypad using the STM32F401RE Nucleo board.
Independent library developed by user Helidon1 (Vincent Veizi).

*   **Microcontroller:** STM32F401RE Nucleo-64
*   **Peripherals:** Mikroelektronika 4x4 Matrix Keypad
*   **Wiring Strategy:**
Initially, Port A (PA0-PA7) was targeted for all rows and columns.
However, pins PA2 and PA3 are hardwired to the onboard ST-Link debugger's transmission lines, causing severe interference and false triggers when configured as inputs. 
To solve this, the matrix was split: **Port A** pushes power (Rows/Outputs), and **Port C** reads the voltage (Columns/Inputs).


### Pinout Mapping

| Keypad Wire | STM32 Pin | Role | Register Configuration |
| :--- | :--- | :--- | :--- |
| **Row 1** | PA4 | Output | Push-Pull, No Pull |
| **Row 2** | PA5 | Output | Push-Pull, No Pull |
| **Row 3** | PA6 | Output | Push-Pull, No Pull |
| **Row 4** | PA7 | Output | Push-Pull, No Pull |
| **Col 1** | PC0 | Input | Pull-Down Resistor Enabled |
| **Col 2** | PC1 | Input | Pull-Down Resistor Enabled |
| **Col 3** | PC2 | Input | Pull-Down Resistor Enabled |
| **Col 4** | PC3 | Input | Pull-Down Resistor Enabled |


**Software Architecture:**
The core logic resides in `readKeypad()`, which operates via a polling method:
1.  **Row Scanning:** The CPU sequentially drives one Row HIGH (3.3V) while keeping the others LOW.
2.  **State Capture:** A snapshot of the Port C Input Data Register (`IDR`) is taken using direct pointer dereferencing and masked to read only bits 0-3.
3.  **Decoding:** A `switch` statement translates the resulting binary value into the corresponding key press.
4.  **Debouncing:** A `while` loop actively traps the CPU by monitoring the `IDR` until the voltage drops to 0, ensuring a single physical press registers as a single software event.

**How to Run & View Output**
1. Flash the code to the STM32F401RE using STM32CubeIDE.
2. Open the **Debug Configurations** -> **Debugger** tab.
3. Enable **Serial Wire Viewer (SWV)** and set the Core Clock to **16.0 MHz**.
4. Open the **SWV ITM Data Console** window.
5. Configure the Trace (wrench icon) and enable **Port 0**.
6. Click the red Record button to start the trace, then resume code execution. Pressing keys will output directly to the console.

**Physical Wiring Image:**
<img width="823" height="933" alt="image" src="https://github.com/user-attachments/assets/4c1e89f4-2aa0-4374-ac32-a936fb2c5b40" />



**SWV outputs:**
https://youtu.be/3i-kuUZCWDo
