---
title: 'El mapeo de campo es el futuro: Un flujo de trabajo del Gestor de Tareas utilizando
  ODK'
date: 2022-08-24 13:34:00 Z
published: false
---

**La cartografía de campo realizada por la población local es clave para el futuro del mapeo abierto. Sin embargo, las herramientas disponibles para la cartografía de campo -a pesar de que muchas son de gran calidad- no forman un ecosistema coherente que permita liberar el potencial de la cartografía de campo comunitaria. Falta algo. ¿Podría ser un Gestor de Tareas para la cartografía de campo?**

**Resumen (TL:DR)**

Aunque tenemos aplicaciones de mapeo de campo bastante buenas, no tenemos grandes herramientas para coordinar el mapeo de campo. Sin embargo, tenemos la mayoría de los elementos necesarios para crear una versión orientada al mapeo de campo del Gestor de Tareas de HOT (Tasking Manager), que permite seleccionar áreas específicas y completar tareas de forma coordinada y organizada.

Ya es posible implementar una especie de flujo de trabajo del Gestor de Tareas de mapeo de campo utilizando las herramientas existentes (en su mayoría basadas en ODK, en particular la nueva funcionalidad "seleccionar del mapa"), pero es bastante laborioso y complicado. Estamos trabajando en una automatización que alivie los puntos difíciles, lo que nos acerca a un Gestor de Tareas completo.

En colaboración con el equipo de Tecnología y Comunidades, y los Grupos de Trabajo de Comunidad y Formación, el Equipo de Programas de Campo de HOT organizará una sesión de intercambio de habilidades el 9 de septiembre del 2022, durante la cual los asistentes podrán obtener una comprensión y algo de experiencia con la idea; utilizaremos los comentarios de esta sesión para medir el interés y la participación para continuar el desarrollo. Animamos a las personas y a las comunidades interesadas en las herramientas de coordinación del mapeo de campo a que asistan.

**La asignación de tareas permite un mejor mapeo remoto**

Uno de los elementos más impactantes del ecosistema de mapeo abierto en los últimos diez años ha sido el Gestor de Tareas de HOT. El propio OpenStreetMap creó un repositorio abierto y masivamente escalable de datos geográficos, y herramientas como el ID Editor y el Editor Java de OpenStreetMap (JOSM) proporcionaron herramientas de primer orden para añadir datos al mapa de forma remota. Sin embargo, entre las herramientas de edición y el repositorio existía una brecha: ¿cómo podía la gente elegir fácilmente zonas para cartografiarlas completamente y con alta calidad?

Se necesitaba algo: una forma de asignar tareas pequeñas y manejables a las personas, hacer seguimiento de su progreso, comprobar la calidad y validar su trabajo, e integrar sin problemas los nuevos datos en OpenStreetMap sin dañar los datos existentes. El Gestor de Tareas de HOT sirvió de elemento unificador; una herramienta para que la comunidad definiera las necesidades de datos y para que los cartógrafos individuales contribuyeran con facilidad y confianza.

![Screen Shot 2022-08-24 at 3.14.13 PM-ce4f17.png](/uploads/Screen%20Shot%202022-08-24%20at%203.14.13%20PM-ce4f17.png)

¿Qué pasa con la asignación de tareas para el mapeo de campo?
Hay una serie de grandes herramientas de recogida de datos sobre el terreno. 

El poderoso OpenDataKit y las numerosas plataformas construidas a partir de él, como Kobo Toolbox, hacen posible que cualquier persona con un dispositivo Android pueda recopilar datos mediante formularios flexibles y potentes diseñados en una hoja de cálculo. 

![Screen Shot 2022-08-24 at 3.15.46 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.15.46%20PM.png)

*La hoja de cálculo de la izquierda crea el cuestionario y la actividad "Seleccionar del mapa" en el teléfono.*

Vespucci aporta gran parte de la potencia de JOSM a un editor móvil. EveryDoor ofrece a los usuarios de Android y iPhone una plataforma sencilla para editar los datos de OSM, y StreetComplete hace lo mismo para los usuarios de Android. OSMAND y Organic Maps permiten la navegación y la visualización de mapas sin conexión con los datos de OSM, así como cierta capacidad básica para añadir o editar características para contribuir a OSM.

![Screen Shot 2022-08-24 at 3.27.54 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.27.54%20PM.png)

*Capturas de pantalla de EveryDoor, Vespucci, OSMAnd y Organic Maps*

Al igual que en el caso del mapeo remoto, disponemos de un excelente repositorio de datos (OSM) y de magníficas herramientas de edición y/o recopilación de datos, pero *no existe una plataforma de coordinación que facilite el mapeo de campo a gran escala y de alta calidad para OpenStreetMap.* 

Proponemos un Gestor de Tareas de mapeo de campo para cubrir esta necesidad.

**Los componentes de un Gestor de Tareas de mapeo de campo ya están construidos en su mayoría**

Si empezáramos desde cero, esto sería una propuesta desalentadora. Sin embargo, gracias al increíble trabajo de Nafundi, los principales desarrolladores de OpenDataKit (ODK), y a algunos trabajos relacionados que se están llevando a cabo en HOT y en la comunidad de mapeo abierto en general, las piezas ya están en su sitio.

**¿Qué se necesita para un Gestor de Tareas de mapeo de campo?**

¿Qué se necesita para implementar un Gestor de Tareas de mapeo de campo? Necesitamos una manera de:

* Definir un área de interés y dividirla en tareas más pequeñas
Asignar las tareas a las personas de forma que no haya duplicidades ni brechas
* Supervisar el progreso de las tareas de mapeo de campo
* Convertir los resultados del mapeo de campo (envíos) en un formato adecuado para su validación 
* Validar el trabajo y proporcionar retroalimentación a los mapeadores si es necesario (incluyendo pedirles que revisen o corrijan errores)
* Integrar los nuevos datos en OSM u otras plataformas
       * Idealmente, con atribución específica al mapeador de campo 
         para los datos que haya creado, lo que es una petición de 
         larga data de la comunidad OSM, que valora la 
         responsabilidad individual de las ediciones sobre las 
         importaciones de datos agregados.

**¿Qué tenemos ya?**

A mediados de 2022, disponemos de herramientas que pueden cumplir todos los requisitos anteriores. Una funcionalidad similar a la del Gestor de Tareas ya puede lograrse con (mucho) trabajo manual. Con un poco de automatización podemos hacer esto mucho más simple, y eventualmente crear un flujo de trabajo de un Gestor de Tareas de mapeo de campo altamente accesible y funcional. 

**Nueva funcionalidad de ODK "seleccionar del mapa" y asignación de formularios individuales**




