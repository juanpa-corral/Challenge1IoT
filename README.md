# Challenge1IoT
Made by Juan Pablo Corral and Juan Esteban Ocampo
## 1. Resumen general, motivación, justificación y estructura de la documentación
### Resumen general
Colombia es un país con una diversidad geográfica y sus patrones climáticos que cambian constantemente, se enfreta con bastante frecuencia a crecidas de ríos, especialmente en las temporadas de lluvias y de fenómenos como "La Niña". Esto provoca inundaciones que pueden tener un impacto negativo en la comunidades y en la infraestructura, como ocurrió en 2024 en Bogotá y en otras regiones del País.

Este proyecto se centra en desarrollar un prototipo de sistema IoT (Internet of Things) para monitorear en tiempo real el nivel del agua en los ríos y detectar posibles crecidad de manera temprana. Para ello, se emplea un Arduino uno como microcontrolador, junto a sensores ultrasónicos y de lluvia qe miden el nivel del agua y las precipitaciones. Cuando el sistema detecta un aumento peligroso en el nivel del río, activa un alerta visual (LED RGB) y auditiva (zumbador) para asi advertir a quienes se encuentren in situ. Además, la información de esta el nivel del agua se muestra en tiempo real en una pantalla (LCD 16x2), permitiendonos ver el nivel de distancia entre el sensor y el agua, y en la situación en la que se encuentra el nivel del agua (SEGURO, PRECAUCIÓN Y PELIGRO).

Este prototipo es un primer paso hacia la implementación de un istema de alerta temprana que podría ayudar a proteger a las comunidades y mitigar daños ocasionados por las inundaciones.

### Motivación
Las crecidas de los rión en Colombia representan una amenza constante, con unas posibles consecuencias que pueden ser devastadoras. Además de posibles muertes, este tipo de desastres pueden ocasionar la destrucción de viviendas, dañar infraestructuras y afectar la economía de las comunidades.

Por esto mismo, es fundamental contar con medidas de prevención y mitigación que ayuden a reducir estos riesgos. La implementación de sistemas de IoT de monitoreo en tiempo real permite detectar crecidas con antelación, brindando alertas tempranas tanto a las autoridades como a la población. Esto ayuda a la toma de decisiones oportuna y la implementación de medidas preventivas que pueden salvar vidas y minimizar los daños materiales.

### Justificación

Este proyecto busca abordar el problema de las crecidas de ríos proporcionando información y alertas tempranas y precisas sobre los niveles de agua. Gracias al uso de sensores ultrasónicos y de lluvia, el sistema puede medir el nivel del agua y dectectar cambios repeninos que indiquen un posible riesgo de inundación.

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

### Diagramas de UML
Revisar Diagramas en la parte de DiagramsUML

### Esquematico de Hardware

### Estándares de diseño de ingeniería aplicados
Se priorizó la facilidad de uso y comprensión del sistema, tanto para los usuarios que interactuan con el prototipo, como para las personas que reciben las alertas. Se busco que la informacion mostrada sea clara y concisa, y que las alertas sean percebtibles en diferentes entornos, como por ejemplo, si es de noche se escucha bien y se ve bien el LED, pero si es de día podria no verse mucho el LED entonces por eso se puso un zumbador.


