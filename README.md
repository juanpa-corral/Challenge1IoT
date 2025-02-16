# Challenge1IoT
Made by Juan Pablo Corral and Juan Esteban Ocampo
## 1. Resumen general, motivación, justificación y estructura de la documentación
### Resumen general
Colombia es un país con una diversidad geográfica y sus patrones climáticos que cambian constantemente, se enfreta con bastante frecuencia a crecidas de ríos, especialmente en las temporadas de lluvias y de fenómenos como "La Niña". Esto provoca inundaciones que pueden tener un impacto negativo en la comunidades y en la infraestructura, como ocurrió en 2024 en Bogotá y en otras regiones del País.

Este proyecto se centra en desarrollar un prototipo de sistema IoT (Internet of Things) para monitorear en tiempo real el nivel del agua en los ríos y detectar posibles crecidas de manera temprana. Para ello, se emplea un Arduino uno como microcontrolador, junto a sensores ultrasónicos y de lluvia qe miden el nivel del agua y las precipitaciones. Cuando el sistema detecta un aumento peligroso en el nivel del río, activa un alerta visual (LED RGB) y auditiva (zumbador) para asi advertir a quienes se encuentren in situ. Además, la información de este nivel de agua se muestra en tiempo real en una pantalla (LCD 16x2), permitiendonos ver el nivel de distancia entre el sensor y el agua, y el estado en el que se encuentra el nivel del agua (SEGURO, PRECAUCIÓN Y PELIGRO).

Este prototipo es un primer paso hacia la implementación de un sistema de alerta temprana que podría ayudar a proteger a las comunidades y mitigar daños ocasionados por las inundaciones.

### Motivación
Las crecidas de los rión en Colombia representan una amenza constante, con unas posibles consecuencias que pueden ser devastadoras. Además de posibles muertes, este tipo de desastres pueden ocasionar la destrucción de viviendas, dañar infraestructuras y afectar la economía de las comunidades.

Por esto mismo, es fundamental contar con medidas de prevención y mitigación que ayuden a reducir estos riesgos. La implementación de sistemas de IoT de monitoreo en tiempo real permite detectar crecidas con antelación, brindando alertas tempranas tanto a las autoridades como a la población. Esto ayuda a la toma de decisiones oportuna y la implementación de medidas preventivas que pueden salvar vidas y minimizar los daños materiales.

### Justificación

Este proyecto busca abordar el problema de las crecidas de ríos proporcionando información y alertas tempranas y precisas sobre los niveles de agua. Gracias al uso de sensores ultrasónicos y de lluvia, el sistema puede medir el nivel del agua y detectar cambios repeninos que indiquen un posible riesgo de inundación.

Una de las principales ventajas es la capacidad de emitir alertas visuales y sonoras, directamente en el lugar, permitiendo asi advertir a las personas cercanas y autoridades necesarias, incluso si no se tiene acceso a internet o a otros medio de comunicación. Esto resulta especialmente útil para comunidades en zonas remotas o de difícil acceso.

Además, al mostrar información en tiempo real, el sistema facilita el monitoreo continuo tanto para la población como para las autoridades, contribuyendo a una mejor preparación y respuesta ante posibles emergencias.

### Estructura de la documentación
Este documento técnico describe el diseño, desarrollo, implementación y validación del prototipo del sistema IoT para el monitoreo de crecidas. La documentación se organiza de la siguiente manera:

*    Sección 2: Solución propuesta. Se presentan las restricciones de diseño, la arquitectura del sistema (tanto en hardware como en software), el desarrollo teórico modular y los estándares utilizados en el diseño.
*    Sección 3: Configuración experimental, resultados y análisis. Se describe el entrono de prueba, los resultados obtenidos y el análisis de los datos recopilados.
*    Sección 4: Autoevaluación del protocolo de pruebas. Se evalúa la efectividad del protocolo de pruebas implementado y se propones posibles mejoras.
*    Sección 5: Conclusiones, retos, trabajo futuro y referencias. Se resumen los principales logros del proyecto, los desafíos enfrentados durante su desarrollo, las oportunidades de mejora y las referencias bibliográficas utilizadas.
*    Sección 6: Anexos. Se incluyen el código fuente, los esquematicos del sistema y otro material complementario.
*    Sección 7: Video demostrativo. Se presenta un video explicativo que muestra el funcionamiento del prototipo en acción.


## 2.Solución Propuesta
### Restricciones de diseño identificadas
El desarrollo del prototipo de sistema de IoT para el monitoreo de crecidas estuvo sujeto a diversas restriscciones de
diseño las cuales se presentan a continuación:

#### Técnicas:

*    Rango del sensor ultrasónico: El sensor HC-SR04 tiene un rango de medición de 2 cm a 400 cm, por lo
que habia que tener en cuenta hasta que punto debiamos poner la alerta de peligro. En el futuro se podrias explorar
sensores con mayor alcance para monitorear ríos mas grandes o con variaciones de nivel más sutiles.
*    Limitaciones de la pantalla LCD: La pantalla LCD 16x2 solo puede mostrar una cantidad limitada de información,
lo que restringe cuanta información al tiempo se pude evidenciar.

#### Disponibilidad
*    Solo uso de los sensores en aula de clase: Dado que los dispositivos y los sensores son parte de la Universidad,
estos solo estaban disponibles en el horario de clases o un horario permitido dentro de la universidad.

#### De Espacio

*    Tamaño compacto: El diseño deber fácil de instalar y transportar.

#### Escalabilidad

*    Expansión: Diseñado para monitorear un solo punto, pero con posibilidad de escalar a múltuples ubicaciones. Además
con posibilidad de incluir sensores mas precisos y con diferentes tecnologías para un rio de verdad.

#### Tiempo
*    Tiempo limitado para el desarrollo: El tiempo disponible para el desarrollo e implementación del prototipo fue
limitado, dado que los sensores solo estaban disponibles en horario de clase o horario permitidos dentro de la universidad
lo que requirió priorizar funcionalidades y el proceso de diseño y construcción.

### Arquitectura propuesta
Revisar imagenes de Diagrama de bloques para hardware y software. Localizado en BlockDiagrams en el repositorio.

### Desarrollo teórico modular
Para construir el prototipo, se adoptó un enfoque modular, estructurando el sistema en componentes con funciones específicas para facilitar su diseño y funcionamiento.

*    Sensor de lluvia SunFounder: Se eligió un sensor capaz de dectectar la presencia de lluvia con la sensibilidad adecuada para activar el sistema de alerta en caso de ser necesario. El sensor funciona mediante la detección de cambios en la conductividad eléctrica cuando el agua hace contacto con las pistas conductoras.
*    Sensor ultrasónico: Se utilizo el modelo HC-SR04 debido a su precisión y rango de medición, lo que permite determinar el nivel del agua dentro de un rango relevante.
*    Alarma(LED RGB y zumbador): Se diseño una alarma que combina señales visuales (LED RGB) y sonoras (zumbador) para alertar sobre la situación. La luz verde significa seguro, la luz azul más el sonido intermitente significa precaución y por último la luz roja más el sonido continuo representa peligro.
*    Pantalla LCD 16x2: Se configuró una pantalla LCD 16x2 para mostrar de manera clara y concisa información en tiempo rela, incluyendo el nivel agua y el estado del sistema.

Este tipo de diseño modular le permite a cada componente cumplir una función específic, mejorando la eficiencia y facilidad de mantenimineto del sistema.

### Diagrama de UML
Revisar Diagramas en la parte de DiagramsUML

### Esquemático de Hardware

### Estándares de diseño de ingeniería aplicados
Se priorizó la facilidad de uso y comprensión del sistema, tanto para los usuarios que interactuan con el prototipo, como para las personas que reciben las alertas. Se busco que la informacion mostrada sea clara y concisa, y que las alertas sean percebtibles en diferentes entornos, como por ejemplo, si es de noche se escucha bien y se ve bien el LED, pero si es de día podria no verse mucho el LED entonces por eso se puso un zumbador.

## 3.Configuración experimental, resultados y análisis
### Descripción del entorno de prueba
Las pruebas se llevaron a cabo en el laboratorio de electrónica de la Universidad de la Sabana, un ambiente interior controlado y libre de condiciones climáticas externas que pudieran afectar los resultados

Para la realización de las pruebas, se utilizaron los siguientes equipos y materiales:
*    Sensor ultrasónico HC-SR04
*    Sensor de lluvia SunFounder
*    Arduino Uno
*    Jumpers
*    Protoboard
*    LED RGB
*    Zumbador Activo
*    Resistencias de 1k y 220 ohmnios
*    Termo y coca (Utilizados para simular la lluvia)
*    Recipiente de plástico (Utilizado para simular un río)

Cabe recalcar que para estas pruebas, el estado seguro de rio esta para más de 8 centímetros de distancia del sensor, el estado de precaución esta entre 8 y 4 centímetros de distancia y por el ultimo el estado peligro es para menos 4 centímetros.

### Procedimiento
1.  Montaje del prototipo: Se conectaron todos los componentes (sensores, Arduino, LED RGB, zumbador) en la protoboard siguiendo el esquemático de hardware.
2.  Carga del programa: Se cargo el programa Arduino a través del puerto USB y con la laptop.
3.  Preparación del entorno: Se llenó el recipiente plástico con agua hasta un nivel inicial considerado seguro. Se midió la distancia entre el sensor ultrasónico y el nivel del agua, resgitrando el valro como punto de referencia.
4.  Simulación de lluvia: Utilizando el termo y la coca, se vertió agua de forma gradual en el recipiente para simular de esta manera la lluvia y aumentar el nivel del agua. Se realizó el vertido del agua de forma continua pero controlada para así observar los cambios de estado del sistema.
5.  Observación y registro: Se observó el comportamiento del LED RGB y el zumbador a medida que el nivel del agua se elevaba al igual que la LCD brindará la información correcta. Se regisrtro la distancia mediad por el sensor ultrasónico en el se producian las transiciones entre los estados (seguro, precaución y peligro).

### Resultados
| Nivel del Agua (distancia entre sensor y el agua) cm | Color del LED RGB | Zumbador             | Estado en pantalla LCD |
| :------------------------------------------------- | :--------------- | :------------------- | :-------------------- |
| 10                                                 | Verde            | No está sonando       | SEGURO                |
| 9                                                  | Verde            | No está sonando       | SEGURO                |
| 8                                                  | Azul             | Sonido Intermitente   | PRECAUCION            |
| 7                                                  | Azul             | Sonido Intermitente   | PRECAUCION            |
| 6                                                  | Azul             | Sonido Intermitente   | PRECAUCION            |
| 5                                                  | Azul             | Sonido Intermitente   | PRECAUCION            |
| 4                                                  | Azul             | Sonido Intermitente   | PRECAUCION            |
| 3                                                  | Rojo             | Sonido constante      | Peligro               |
| 2                                                  | Rojo             | Sonido constante      | Peligro               |

### Análisis
Los resultados obtenidos dfemuestran que el prototipo es capaz de dectectar cambio en el nivel del agua debido a las precipitaciones y alertar al usuario mediante señales visuales (LED RGB) y sonoras (zumbador).

Específicamente, se comprobó que:

*    El sistema identifica de manera correcta un estado de agua seguro (LED verde, zumbador inactivo) (+8cm).
*    Ante un aumento simulado del nivel del agua, el sistema transiciona a un estado de precaución (LED azul, zumbador intermitente)(entre 8cm y 4cm).
*    Al alcanzar un estado de peligro, el sistema emite una alerta clara (LED rojo, zumbador continuo) (-4cm).

Es importante recalcar que después de diversas pruebas es recomnedable realizar las otras pruebas en condiciones de lluvia reales para validar el comportamiento del sistema. Pero en estas condiciones simuladas el sistema mostró ser capaz de detectar posibles crecidas de rios (nivel del agua en el recipiente).

## Autoevaluación del protocolo de pruebas
### Evaluación de la efectividad del protocolo
* ¿El protocolo permitió validar correctamente el funcionamiento del prototipo? Sí, el protocolo de pruebas implementado permitió validar de manera efectiva el el funcionamiento básico del prototipo. Se realizaron pruebas en distintos escenarios de nivel de agua, permitiendo observar cómo el sistema respondía mediante el LED RGB, el zumbador y la pantalla LCD. Los resultados confirmaron que el prototipo dertecta cambios en el nivel del agua y alerta in sity de acuerdo a los umbrales establecidos.
* ¿Se identificaron todos los posibles escenarios de uso? Aunque el protocolo permitió evaluar el funcionamiento general, no se consideraron todas las situaciones que podrían pasar en un entorno real. Por ejemplo, las pruebas se realizaron en un ambiente controlado y no se simularon condiciones climáticas extremas como lluvia intensa o ventiscas 
