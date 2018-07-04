# UML Version 1
En un principio se pensó utilizar el patrón de diseño Flyweight, con el fin de que las imágenes tanto de las naves como de las balas no ocuparan tanto espacio en la memoria.

![1](https://user-images.githubusercontent.com/38145376/42285967-ceab2b84-7f76-11e8-80af-fe4bc4ed4762.png)

Como podemos observar en el diagrama tenemos un "Flyweight_Factory" del cual dependen dos clases: La clase flyweight del soldado (en un futuro se convertiría en las naves, tanto naves enemigas como la nave héroe) y la clase balas (que diferenciará las balas del enemigo con las balas de la nave héroe.



# UML Version 2
En la segunda versión del diagrama, implementamos los patrones de diseño Facade y Bridge.

El patrón Facade lo utilizamos para que el usuario no tenga que ver toda la implementación del juego. El solo tiene que inciar el "main" y empezar a jugar, no tiene porque configurar algún parámetro para que este funcione correctamente o adquiera alguna característica especial.

![2](https://user-images.githubusercontent.com/38145376/42286178-978288ea-7f77-11e8-9cd6-1f7757ea6e6f.png)

El patrón Bridge se usó con el fin de separar la abstracción de su implementación, en este caso la clase "implementor" esla clase que tiene todas las funciones necesarias para que funcione el juego. De este mismo hereda una clase "allegro_game" donde se encuentran todas las funciones propias de la librería Allegro.

Finalmente se implementó en su totalidad el patrón de diseño Flyweight, como se explicó en la versión anterior, para todas las naves y todas las balas, sean las naves,balas enemigas o del héroe.

