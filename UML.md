# UML Versión 1
En un principio se pensó utilizar el patrón de diseño Flyweight, con el fin de que las imágenes tanto de las naves como de las balas no ocuparan tanto espacio en la memoria.

![1](https://user-images.githubusercontent.com/38145376/42285967-ceab2b84-7f76-11e8-80af-fe4bc4ed4762.png)

Como podemos observar en el diagrama tenemos un "Flyweight_Factory" del cual dependen dos clases: La clase flyweight del soldado (en un futuro se convertiría en las naves, tanto naves enemigas como la nave héroe) y la clase balas (que diferenciará las balas del enemigo con las balas de la nave héroe.



# UML Versión 2
En la segunda versión del diagrama, implementamos los patrones de diseño Facade y Bridge.

El patrón Facade lo utilizamos para que el usuario no tenga que ver toda la implementación del juego. El solo tiene que inciar el "main" y empezar a jugar, no tiene porque configurar algún parámetro para que este funcione correctamente o adquiera alguna característica especial.

![2](https://user-images.githubusercontent.com/38145376/42286178-978288ea-7f77-11e8-9cd6-1f7757ea6e6f.png)

El patrón Bridge se usó con el fin de separar la abstracción de su implementación, en este caso la clase "implementor" esla clase que tiene todas las funciones necesarias para que funcione el juego. De este mismo hereda una clase "allegro_game" donde se encuentran todas las funciones propias de la librería Allegro.

Finalmente se implementó en su totalidad el patrón de diseño Flyweight, como se explicó en la versión anterior, para todas las naves y todas las balas, sean las naves,balas enemigas o del héroe.

# UML Versión 3

En la tercera versión del diagrama decidimos cambiar el flyweight por un abstract_factory. 

Además agregamos una nueva clase que es la clase de Escenario, aquella que se encarga de dibujar todas las naves enemigas y la nave héroe en un principio.

![123](https://user-images.githubusercontent.com/38145376/42289078-3433e0d4-7f83-11e8-9169-416652799c5b.png)

Explicando nuestro patrón abstract_factory, creamos dos clases "factory_héroe" y "factory_enemigo" para que pueda llamar a las diferentes clases que depende de el. En este caso, la clase balas y la clase nave. 

Así mismo, la clase balas y la clase nave, tiene dos hijos, uno para las balas de héroe y otro para las del enemigo. De la misma forma para la clase nave. Con el fin de diferenciar ambas partes en el juego.
