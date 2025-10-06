# Programación Distribuida y Tiempo Real - Teoría - Clase 7: Ventajas, desventajas y tipos.

Los sistemas distribuidos ofrecen varias ventajas clave en comparación con los sistemas centralizados:
- **Costo/rendimiento**
- **Distribución inherente del problema**: Son adecuados cuando la naturaleza del problema o la aplicación ya está inherentemente distribuida.
- **Crecimiento incremental (o granularidad del crecimiento) del hardware**: Permiten un crecimiento gradual del hardware al ir añadiendo componentes según se necesite, sin requerir grandes inversiones iniciales.
- **Facilitan el uso compartido de recursos**

A pesar de sus ventajas, los sistemas distribuidos presentan desafíos significativos:
- **Software**: Dificultades para el desarollo incluyendo los procesos de ingeniería de software.
- **Administración**: complejidad para el sistema de permisos, accesos y control de los recursos. 
- **Características de las redes actuales**: se enfrentan a problemas inherentes a las redes 
- **Seguridad**: se habla de seguridad como ventaja/desventaja porque al estar distribuido el ataque no afectará al resto pero en la mayoría de los casos eso no ha sucedido.

## Tipos de sistemas distribuidas
Los sistemas distribuidos se clasifican comúnmente en tres categorías principales, dependiendo de su propósito y las características de sus nodos:
### Sistemas Distribuidos de Cómputo (High Performance Distributed Computing)
- **Cluster Computing**: Se compone de una colección de estaciones de trabajo o PC similares, interconectadas mediante una red de área local (LAN) de alta velocidad. Intensivo casi sin necesidad de comunicación con el exterior. 
- **Cómputo en malla**: Se construye como una federación de sistemas de cómputo donde los recursos provienen de distintas organizaciones o dominios administrativos. 
- **Cloud Computing**: Proporciona un grupo de recursos virtualizados de fácil acceso, donde el uso se configura dinámicamente. Generalmente se basa en un modelo de pago por uso (pay-per-use). Los servicios en la nube se ofrecen en tres tipos principales:
    ◦ Infraestructura como Servicio (IaaS)
    ◦ Plataforma como Servicio (PaaS)
    ◦ Software como Servicio (SaaS)

### Sistemas distribuidos de Información (Distributed Information Systems)
Se centran en la gestión y el intercambio de información dentro de las organizaciones.
- **Procesamiento de transacciones**: Manejan operaciones en bases de datos que requieren que todas o ninguna de las operaciones se ejecuten, asegurando las propiedades ACID (Atomicidad, Consistencia, Aislamiento y Durabilidad).

### Sistemas Masivos Distribuidos (Pervasive Systems)
Se caracterizan por ser sistemas inestables compuestos por dispositivos móviles o embebidos.
- **Sistemas de Sensores**: Incluyen redes de sensores cuya información se recopila y a menudo requiere concentración. Los dispositivos suelen ser pequeños, alimentados por batería y con conexión inalámbrica.
- **Sistemas de Cómputo Ubicuo/Móvil**: Orientados a la movilidad, donde la ubicación de los dispositivos cambia constantemente, y la transparencia de la distribución es difícil de lograr.

