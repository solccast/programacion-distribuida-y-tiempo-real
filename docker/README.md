# Contenedor docker 
Contiene una imagen de ubuntu de forma liviana. 

## Consideraciones 
La red fue modificada de modo que sea la misma que del host (se eliminó el bridge por defecto) por lo tanto reconoce las redes privadas con el formato `192.168.56.x`

## Uso 
Para probar en Windows(PowerShell): 
- **Crear una imagen**
```bash
docker build -t ubuntu-c-nc:latest .
```

- **Levantar un contenedor**: 
```bash
docker run --rm -it `
  -v "${PWD}:/app" `
  ubuntu-c-nc
```
> No olvidar activar siempre el daemon de docker 

En el sitio donde se levante el contenedor será usado como volumen desde el host de modo con que los archivos se encuentren en el mismo sitio donde se ejecutó el comando serán reconocidos por Docker incluso en tiempo de ejecución. 

> Se pueden levantar múltiples contenedores a partir de la misma imagen con sus particularidades y configuraciones a partir las options de 
`docker run`


wsl.exe -d Ubuntu