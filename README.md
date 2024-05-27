# Nutrifit
Trabajo final de Proyectos de Programación.

## Módulo Social

En este módulo se permite a los usuarios crear una cuenta proporcionando su nombre, correo electrónico, contraseña, peso y altura, los cuales se almacenan en el archivo usuarios.txt. Los usuarios pueden iniciar sesión con su correo electrónico y contraseña, y el sistema verifica las credenciales comparándolas con los datos en usuarios.txt.

Una vez autenticados, los usuarios pueden interactuar con un sistema de publicaciones gestionado por la clase Publication, cuyas instancias se almacenan en publications.txt. La clase User define las propiedades de un usuario y métodos para la gestión de la creación y autenticación de usuarios. La clase Publication define las propiedades de una publicación y métodos para crear, leer, actualizar y eliminar publicaciones. Al iniciar el programa, se presenta un menú para registrarse o iniciar sesión. Tras el registro, los datos se guardan en usuarios.txt y el usuario es redirigido al menú principal. Si el usuario inicia sesión, el programa verifica las credenciales y, si son correctas, el usuario puede gestionar publicaciones.
