# Programación Distribuida y Tiempo Real - Teoría - Clase 9: Estilos arquitecturales

Para nuestro estudio, la idea de estilo arquitectónico es importante. Tal estilo se formula en términos de componentes, la forma en que los componentes interactúan entre sí, el intercambio de datos entre los componentes y, por último, en cómo es que estos elementos se configuran juntos en un sistema.
Un **componente** es una unidad modular con las _interfaces_/ requeridas bien definidas; dicha unidad es reemplazable dentro de su ambiente. El de conector, el cual generalmente se describe como un mecanismo que media la comunicación, coordinación o cooperación entre componentes (Mehta y cols., 2000; y Shaw y Clements, 1997). Por ejemplo, un conector puede formarse por los medios disponibles para hacer llamadas a procedimientos (remotos), paso de mensajes, o flujo de datos.

Por medio de componentes y conectores podemos lograr varias configuraciones, las cuales se
han clasificado en estilos arquitectónicos. Varios estilos ya están identificados y los más importantes para sistemas distribuidos son:
1. **Arquitecturas en capas**: el componente de la capa $L_i$ se le permite llamar a componentes de la capa subyacente $L_{i-1}$, pero no del resto de capas. El control generalmente fluye de capa a capa: las peticiones se mueven hacia abajo en la jerarquía mientras que los resultados se mueven hacia arriba.
![alt text](image-9.png)
2. **Arquitecturas basadas en objetos**: pensar todo el sistema distribuido como objetos que se encuentran distribuidos, cada objeto es un componente y éstos se conectan a trvés de un mecanismo de llamadas a procedimientos (remotos). Proporcionan una forma de _encapsulamiento_ de los datos (estado de un objeto) y las oepraciones que se pueden reazliar sobre esos datos en una sola entidad. La interfaz ofrecida por un objeto oculta los detalles de implementación. 
![alt text](image-10.png)
Esta separación entre las interfaces y los objetos que implementan dichas interfaces nos permite ubicar una interfaz en una máquina, mientras que el objeto en sí reside en otra máquina. Esta organización, que se muestra en la Figura 2.6, se conoce comúnmente como un **objeto distribuido**.
![alt text](image-11.png)

3. **Arquitecturas centradas en recursos**: se puede considerar un sistema distribuido como una gran colección de recursos que son gestionados individualmente por componentes. Los recursos pueden ser añadidos o eliminados por aplicaciones (remotas), y de la misma manera, pueden ser recuperados o modificados. Este enfoque ha sido ampliamente adoptado para la Web y se conoce como Representational State Transfer (REST). Características clave:
    1. Los recursos son identificados a través de un esquema de nombres único.
    2. Todos los servicios ofrecen la misma interfaz.
    3. Los mensajes enviados hacia o desde un servicio están complementamente autodescriptos. 
    4. Después de ejecutar una operación en un servicio, ese componente olvida todo sobre el cliente. 
4. **Arquitecturas basadas en eventos**: los procesos se comunican a través de la propagaión de eventos, los que opcionalmente transportan datos. Para sitemas distribuidos, la propagación de eventos se ha asociado con el sistema **Publish/Subscribe**: los procesos publican eventos después de los cuales el middleware asegura que sólo aquellos procesos suscritos a tales eventos los recibirán. La principal ventaja de los sistemas basados en eventos es que los procesos están libremente acoplados, no necesitan referirse uno a otro explícitamente. 
Contiene componentes que generaran eventos (_publicadores_) y componentes que manejan eventos (_suscriptores_), todo el sistema se construye a partir de estos dos. 
El estilo de Publicación/Suscripción es notable por las formas en que desacopla los componentes, Los componentes no interactúan directamente entre sí, sino con el middleware o servicio de transporte de eventos. Esto orienta la identificación de requerimientos.

![alt text](image-12.png)

| Architecture Style | Componente | Interface | Organizacion | Comunicacion |
| -- | -- | -- | -- | -- | 
| Layered architectures | capas | cliente/servidor | cliente/servidor, niveles de abstracción | requerimientos y respuestas |
| objetos distribuidos | metodos | distribuir los objetos en todo el sistema | métodos |
| acceso a recursos | manejadores, servidores de recursos | servicios, los mismos para atodos, sin estados | distribuir manejadores/recursos en el sistema | interfaces, servicios |
| Publish/Subscribe | procesos, modulos o hilos | publicación y suscripción de eventos | distribuir procesos y publicación y notificación de eventos | definidas por el middleware de p-s | 
