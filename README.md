# CDyM TP4 2024 Grupo 1 Control de LED RGB

Este proyecto implementa el control de un LED RGB utilizando la técnica de modulación por ancho de pulso (PWM) y un microcontrolador (MCU). El objetivo es controlar la intensidad y el color del LED RGB a través de comandos enviados por la interfaz serie UART y un potenciómetro para ajuste de brillo. El proyecto está desarrollado utilizando Atmel Studio y Proteus.

## Contenido del Repositorio
- `tp4-ent/`: Contiene el proyecto completo desarrollado en Atmel Studio.
- `tp4.pdsprj`: Contiene el diseño del circuito en Proteus.
- `README.md`: Este archivo, proporcionando una visión general del proyecto y las instrucciones para su uso.

## Requerimientos del Sistema
- **LED RGB (ánodo común)**: Conectado a los terminales PB5, PB2, y PB1 del MCU.
- **Resistencias de limitación de 220 ohms**: Conectadas en serie con cada terminal del LED RGB.
- **Potenciómetro**: Conectado al terminal ADC3 del MCU para ajustar el brillo.
- **Comunicación Serie UART**: Para la recepción de comandos desde una PC.

## Funcionalidades
- **Control de Color mediante PWM**: Generación de tres señales PWM de frecuencia ≥ 50Hz y con una resolución de 8 bits en los terminales PB5, PB2, y PB1 para controlar los colores rojo, verde y azul respectivamente.
- **Selección de Color**: Modificación de la intensidad de cada color mediante comandos recibidos por UART (`R` para rojo, `G` para verde, `B` para azul).
- **Ajuste de Brillo**: Uso del potenciómetro para variar el brillo del color seleccionado.
- **Interfaz Serie UART**: Implementación de la comunicación asincrónica para recibir comandos de control.

## Instrucciones para la Instalación y Uso

### Atmel Studio
Clonar el Repositorio:

```bash
git clone https://github.com/IacobucciB/CDyM-TP4-2024-G1-ControlLED
```
Abrir el Proyecto:
Abre el archivo del proyecto (`tp4-ent.atsln`) en Atmel Studio.

### Configurar el Hardware:

- Conecta el LED RGB a los terminales PB5, PB2 y PB1 del MCU, con resistencias de limitación de 220 ohms en cada terminal.
- Conecta el potenciómetro al terminal ADC3 del MCU.
- Conecta el MCU a la PC mediante la interfaz USB.

### Compilar y Cargar el Código:

- Compila el proyecto en Atmel Studio.
- Carga el firmware al MCU utilizando Atmel Studio y el programador correspondiente.

### Proteus
Abrir el Diseño:
Abre el archivo del diseño (`tp4.pdsprj`) en Proteus.

Simulación:
Ejecuta la simulación en Proteus para verificar el funcionamiento del circuito antes de implementarlo físicamente.

## Uso del Sistema
Iniciar el Sistema:

Conecta el MCU a la PC y abre una terminal serie (por ejemplo, PuTTY o Tera Term).

Configura la terminal serie con la velocidad en baudios especificada en el código (por ejemplo, 9600 baudios).

### Control de Color y Brillo:

- Envía `R`, `G` o `B` para seleccionar el color que deseas modificar.
- Ajusta el potenciómetro para cambiar el brillo del color seleccionado. 

Observa los cambios de color en el LED RGB de acuerdo con los comandos y ajustes de brillo.