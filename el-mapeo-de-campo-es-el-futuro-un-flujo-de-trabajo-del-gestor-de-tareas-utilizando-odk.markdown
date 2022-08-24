---
title: 'El mapeo de campo es el futuro: Un flujo de trabajo del Gestor de Tareas utilizando
  ODK'
date: 2022-08-24 13:34:00 Z
---

**La cartografía de campo realizada por la población local es clave para el futuro del mapeo abierto. Sin embargo, las herramientas disponibles para la cartografía de campo -a pesar de que muchas son de gran calidad- no forman un ecosistema coherente que permita liberar el potencial de la cartografía de campo comunitaria. Falta algo. ¿Podría ser un Gestor de Tareas para la cartografía de campo?**

> **Resumen (TL:DR)**
>
> Aunque tenemos aplicaciones de mapeo de campo bastante buenas, no tenemos grandes herramientas para coordinar el mapeo de campo. Sin embargo, tenemos la mayoría de los elementos necesarios para crear una versión orientada al mapeo de campo del Gestor de Tareas de HOT (Tasking Manager), que permite seleccionar áreas específicas y completar tareas de forma coordinada y organizada.
>
> Ya es posible implementar una especie de flujo de trabajo del Gestor de Tareas de mapeo de campo utilizando las herramientas existentes (en su mayoría basadas en ODK, en particular la nueva funcionalidad "seleccionar del mapa"), pero es bastante laborioso y complicado. Estamos trabajando en una automatización que alivie los puntos difíciles, lo que nos acerca a un Gestor de Tareas completo.
>
> En colaboración con el equipo de Tecnología y Comunidades, y los Grupos de Trabajo de Comunidad y Formación, el Equipo de Programas de Campo de HOT organizará una [sesión de intercambio de habilidades el 9 de septiembre del 2022](https://www.eventbrite.com/e/field-mapping-is-the-future-a-tasking-manager-workflow-for-odk-tickets-400186387257), durante la cual los asistentes podrán obtener una comprensión y algo de experiencia con la idea; utilizaremos los comentarios de esta sesión para medir el interés y la participación para continuar el desarrollo. Animamos a las personas y a las comunidades interesadas en las herramientas de coordinación del mapeo de campo a que asistan.

**La asignación de tareas permite un mejor mapeo remoto**

Uno de los elementos más impactantes del ecosistema de mapeo abierto en los últimos diez años ha sido el [Gestor de Tareas de HOT](https://tasks.hotosm.org/). El propio [OpenStreetMap](https://www.openstreetmap.org) creó un repositorio abierto y masivamente escalable de datos geográficos, y herramientas como el [ID Editor](http://ideditor.com/) y el [Editor Java de OpenStreetMap (JOSM)](https://josm.openstreetmap.de/) proporcionaron herramientas de primer orden para añadir datos al mapa de forma remota. Sin embargo, entre las herramientas de edición y el repositorio existía una brecha: ¿cómo podía la gente elegir fácilmente zonas para cartografiarlas completamente y con alta calidad?

Se necesitaba algo: una forma de asignar tareas pequeñas y manejables a las personas, hacer seguimiento de su progreso, comprobar la calidad y validar su trabajo, e integrar sin problemas los nuevos datos en OpenStreetMap sin dañar los datos existentes. El Gestor de Tareas de HOT sirvió de elemento unificador; una herramienta para que la comunidad definiera las necesidades de datos y para que los cartógrafos individuales contribuyeran con facilidad y confianza.

![Screen Shot 2022-08-24 at 3.14.13 PM-ce4f17.png](/uploads/Screen%20Shot%202022-08-24%20at%203.14.13%20PM-ce4f17.png)

¿Qué pasa con la asignación de tareas para el mapeo de campo?
Hay una serie de grandes herramientas de recogida de datos sobre el terreno.

El poderoso [OpenDataKit](https://getodk.org/) y las numerosas plataformas construidas a partir de él, como [Kobo Toolbox](https://www.kobotoolbox.org/), hacen posible que cualquier persona con un dispositivo Android pueda recopilar datos mediante formularios flexibles y potentes diseñados en una hoja de cálculo.

![Screen Shot 2022-08-24 at 3.15.46 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.15.46%20PM.png)

*La hoja de cálculo de la izquierda crea el cuestionario y la actividad "Seleccionar del mapa" en el teléfono.*

[Vespucci](https://vespucci.io/) aporta gran parte de la potencia de JOSM a un editor móvil. [EveryDoor](https://every-door.app/) ofrece a los usuarios de Android y iPhone una plataforma sencilla para editar los datos de OSM, y StreetComplete hace lo mismo para los usuarios de Android. [OSMAND](https://osmand.net/) y [Organic Maps](https://organicmaps.app/) permiten la navegación y la visualización de mapas sin conexión con los datos de OSM, así como cierta capacidad básica para añadir o editar características para contribuir a OSM.

![Screen Shot 2022-08-24 at 3.27.54 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.27.54%20PM.png)

*Capturas de pantalla de EveryDoor, Vespucci, OSMAnd y Organic Maps*

Al igual que en el caso del mapeo remoto, disponemos de un excelente repositorio de datos (OSM) y de magníficas herramientas de edición y/o recopilación de datos, pero *no existe una plataforma de coordinación que facilite el mapeo de campo a gran escala y de alta calidad para OpenStreetMap.*

Proponemos un Gestor de Tareas de mapeo de campo para cubrir esta necesidad.

**Los componentes de un Gestor de Tareas de mapeo de campo ya están construidos en su mayoría**

Si empezáramos desde cero, esto sería una propuesta desalentadora. Sin embargo, gracias al increíble trabajo de [Nafundi](https://nafundi.com/), los principales desarrolladores de OpenDataKit (ODK), y a algunos trabajos relacionados que se están llevando a cabo en HOT y en la comunidad de mapeo abierto en general, las piezas ya están en su sitio.

**¿Qué se necesita para un Gestor de Tareas de mapeo de campo?**

¿Qué se necesita para implementar un Gestor de Tareas de mapeo de campo? Necesitamos una manera de:

* Definir un área de interés y dividirla en tareas más pequeñas
  Asignar las tareas a las personas de forma que no haya duplicidades ni brechas

* Supervisar el progreso de las tareas de mapeo de campo

* Convertir los resultados del mapeo de campo (envíos) en un formato adecuado para su validación

* Validar el trabajo y proporcionar retroalimentación a los mapeadores si es necesario (incluyendo pedirles que revisen o corrijan errores)

* Integrar los nuevos datos en OSM u otras plataformas
  \* Idealmente, con atribución específica al mapeador de campo
  para los datos que haya creado, lo que es una petición de
  larga data de la comunidad OSM, que valora la
  responsabilidad individual de las ediciones sobre las
  importaciones de datos agregados.

**¿Qué tenemos ya?**

A mediados de 2022, disponemos de herramientas que pueden cumplir todos los requisitos anteriores. Una funcionalidad similar a la del Gestor de Tareas ya puede lograrse con (mucho) trabajo manual. Con un poco de automatización podemos hacer esto mucho más simple, y eventualmente crear un flujo de trabajo de un Gestor de Tareas de mapeo de campo altamente accesible y funcional.

**Nueva funcionalidad de ODK "seleccionar del mapa" y asignación de formularios individuales**

Desde mediados de 2022, ODK incorpora una nueva funcionalidad, la [selección desde el mapa](https://forum.getodk.org/t/odk-collect-v2022-2-beta-select-from-map-geojson-datasets/36913), que permite a los cartógrafos de campo seleccionar un objeto de un mapa, ver los atributos existentes y rellenar un formulario añadiendo nueva información y atributos a ese objeto. Por ejemplo, un cartógrafo puede acercarse a un edificio, seleccionar ese edificio desde una vista de mapa dentro de ODK en su teléfono móvil, y añadir el horario de apertura, el número de plantas, el material de construcción o cualquier número de atributos útiles en un formato de cuestionario bien estructurado\*.

*Esto replica en su mayor parte la funcionalidad del tan extrañado [OpenMapKit](http://www.openmapkit.org/), una bifurcación muy útil de ODK creada por la Cruz Roja Americana con el apoyo de HOT y otras agencias, que permitía a los usuarios lanzar formularios desde una vista de mapa y seleccionar edificios/características para añadirles atributos. Lamentablemente, OMK ya no recibe mantenimiento y no se puede utilizar de forma fiable.*

![Screen Shot 2022-08-24 at 3.34.04 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.34.04%20PM.png)

Además, la nueva aplicación del servidor web [ODK Central](https://docs.getodk.org/central-intro/) contiene herramientas muy granulares para asignar formularios a usuarios individuales. De hecho, es posible crear cuestionarios individuales para un número arbitrario de áreas pequeñas (como barrios), cada una con su propio conjunto de características (como edificios). Estos formularios pueden asignarse a "usuarios de la aplicación" específicos, con acceso a formularios específicos (y por tanto a barrios/áreas) definidos por un código QR.

![Screen Shot 2022-08-24 at 3.35.11 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.35.11%20PM.png)

*ODK Central admite la asignación de formularios individuales -y las características correspondientes, como los edificios- a usuarios individuales*

¿Cómo facilita este sistema de "usuarios de aplicaciones" un Gestor de Tareas? Nos alegra que lo preguntes. Creando un código QR  para cada barrio (o "tarea"), y asignándolos uno a uno a las personas, podemos:

* Asignar áreas específicas a personas específicas (ya sea asignándoselas directamente o proporcionando una selección de áreas y dejando que la gente elija)

* Llevar un registro de las áreas que han sido asignadas y completadas (y, con un poco más de trabajo, validadas) Llevar un registro de quién mapeó cada área

* Asignar nuevas áreas a las personas que han terminado las suyas

* Llevar un registro de las áreas que aún requieren ser mapeadas (o completadas/corregidas después de la validación)

Por el momento, esto supone mucho trabajo manual. Sin embargo, ODK Central cuenta con una [potente y bien documentada API](https://odkcentral.docs.apiary.io/#), y la creación de tareas/áreas individuales, la asignación a usuarios específicos, el seguimiento de los resultados entrantes y la congelación de los formularios ya asignados, ¡puede automatizarse!

Aunque ya podemos asignar las tareas manualmente, el siguiente paso obvio es un mapa web que permita a los cartógrafos de campo seleccionar un área fácilmente. El equipo de [OpenMapDevelopment Tanzania (OMDTZ)](https://www.omdtz.or.tz/about/) ha sido pionero en la creación de [mapas web interactivos que se integran con ODK Central](https://millmaps.org/), lo que muestra un camino prometedor.

**Conversión de los envíos de ODK a OSM XML para su validación y carga**

El equipo técnico de HOT ya ha creado un conjunto de scripts que hacen la conversión de  formularios ODK a OSM XML, el formato de datos nativo de OpenStreetMap. Esto permite que los envíos de mapeo de campo entren fácilmente en la tubería de datos tradicional de validación en JOSM, seguido por la carga a OSM atribuida a la ID de OSM del mapeador de campo.

La existencia de estos scripts facilita una funcionalidad más parecida a la del Gestor de Tareas, ya que la conversión de los envíos a conjuntos de datos listos para su validación es directa y fácilmente automatizable. Los scripts son especialmente fáciles de adaptar cuando se dirigen a formularios ODK estandarizados de buena calidad, una ventaja clave de todo este sistema.

**¿Qué necesitamos construir?**

En principio, ya podemos implementar un flujo de trabajo del Gestor de Tareas de mapeo de campo, pero requiere mucho trabajo manual complicado. Nuestro plan es hacerlo y automatizar gradualmente los puntos problemáticos. El camino más probable es el siguiente:

1. Crear un mapa web para móviles (no una aplicación móvil, sólo una aplicación web) que:

* Muestre todas las tareas individuales de un proyecto,
  codificadas por colores según el estado de
  asignación/realización

* Permita a los mapeadores hacer clic en una tarea cerca de su
  ubicación física y que se les asigne (ya sea con un código QR o
  con un lanzamiento directo de ODK Collect con la configuración
  pertinente)

* Permita a los mapeadores, validadores y administradores ver el
  progreso y seleccionar tareas para su posterior mapeo o
  validación

1. Crear un mapa web para pantallas de ordenador que facilite la creación de proyectos y tareas individuales

   * Lo ideal es utilizar las redes de carreteras y vías fluviales
     para dividir las tareas de forma sensata para el mapeo de
     campo, en lugar de utilizar cuadrículas arbitrarias

   * Automatiza el proceso de descarga de datos OSM (probablemente
     construcciones como primera prioridad) para el área cubierta
     por cada tarea y conversión en características seleccionables
     en un formulario ODK para cada área de la tarea

   *Similar a la interfaz de usuario del Gestor de Tareas de HOT y posiblemente basada en ella, aunque optimizada para móviles; las personas que utilizan el Gestor de Tareas están, por definición, utilizando una pantalla de ordenador, mientras que los cartógrafos de campo están, por definición, utilizando un dispositivo móvil.*

2. Perfeccionar y ampliar los formularios disponibles para cubrir las necesidades de datos cartográficos de campo más importantes de las comunidades

   * La mayoría de los datos de mapeo de campo se cargan actualmente en OSM como importaciones masivas atribuidas a la organización, el proyecto o el validador. Esto es una fuente de frustración para la comunidad de OSM, que valora mucho la responsabilidad individual de las ediciones individuales añadidas al mapa.\*

3. Agilizar el proceso de validación e importación de datos

4. Y así sucesivamente...

Próximos pasos

En colaboración con el equipo de Tecnología y Comunidades, y los Grupos de Trabajo de Comunidad y Formación, el Equipo de Programas de Campo de HOT organizará un intercambio de habilidades  el 9 de septiembre del 2022, donde demostraremos el uso de un flujo de trabajo rudimentario del Gestor de Tareas de mapeo de campo. Todos son bienvenidos.

Las sesiones en francés e inglés se celebrarán en varios husos horarios, y podrán añadirse sesiones adicionales si hay interés de otros husos horarios e idiomas (probablemente podamos organizar una sesión en español si los participantes están dispuestos a escuchar la lengua de Cervantes despiadadamente tratada).

Si, tras la sesión de intercambio de conocimientos, hay un interés sustancial de la comunidad en utilizar este flujo de trabajo, seguiremos construyéndolo en colaboración con esos usuarios. Así que si crees que esto es algo que podrías querer o necesitar, asegúrate de inscribirte en la sesión de intercambio de conocimientos en [tinyurl.com/field-mapping-tools1](https://tinyurl.com/field-mapping-tools1).