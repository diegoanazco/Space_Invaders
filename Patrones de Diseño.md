# Patrones de Diseño
* Un patrón de diseño es una solución general repetible a un problema común en el diseño de software.
* Es una descripción o plantilla de cómo resolver un problema que se puede utilizar en diferentes situaciones.


## Facade
#### Intención: 
* Proporcionar una interfaz unificada para un conjunto de interfaces en un subsistema. Facade define una interfaz de nivel superior que hace que el subsistema se más fácil de usar.
* Envuelve un subsistema complicado con una interfaz más simple.
#### Problema:
* El cliente necesita una interfaz simplicada para la funcionalidad general del subsistema complejo.
#### Diagrama:
![facade1](https://user-images.githubusercontent.com/38145376/42285314-d45ac424-7f74-11e8-9d61-f386dd1bdcfc.png)




## Bridge
#### Intención:
* Separa una abstracción de su implementación para que ambas puedan variar de forma independiente.
* Publicar una interfaz en una jerarquía de herencia y separar la implementación en su propia jerarquía de herencia.
#### Problema:
* Hay un problema de bloqueo en el enlace en tiempo de compilación entre la interfaz y la impleentación. La abstracción y la implementación no se pueden extender o componer independientemente.
#### Diagrama:
![bridge](https://user-images.githubusercontent.com/38145376/42285397-1ede2874-7f75-11e8-8bd9-3f94a38eb46c.png)


## Abstract Factory
#### Intención:
* Proporcionar una interfaz para crear familias de objetos relacionados o dependientes sin especificar sus clases concretas.
* Encapsulación, muchas posibles "plataformas" y la construcción de un conjunto de "productos".
#### Problema: 
* Si una aplicación debe ser portátil, debe encapsular las dependencias de la plataforma. Con demasiada frecuencia, esta encapsulación no está diseñada de antemano, y muchas declaraciones de "ifdef" comienzan a definirse demasiadas veces en todo el código.
#### Diagrama:
![abstract_factory](https://user-images.githubusercontent.com/38145376/42285453-4bdf9998-7f75-11e8-9fa5-f74206d1aa97.png)



## Flyweight
#### Intención:
* Se usa para admitir una gran cantidad de objetos de pequeño tamaño de manera eficiente.
#### Problema:
* Diseñar objetos hasta los niveles más bajos de "granularidad" del sistema proporciona una flexibilidad óptima, pero puede ser inaceptablemente costoso en términos de rendimiento y uso de la memoria.
#### Diagrama:
![3](https://user-images.githubusercontent.com/38145376/42289342-8b6ab1ce-7f84-11e8-9cc5-f562798d893f.png)
