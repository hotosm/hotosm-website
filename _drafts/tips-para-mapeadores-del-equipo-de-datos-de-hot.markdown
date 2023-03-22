---
title: Tips para mapeadores del Equipo de Datos de HOT
date: 2023-03-13 21:44:00 Z
categories:
- Mapping
- data
Summary Text: Tanto si recien empiezas a crear mapas para apoyar la respuesta al terremoto
  en Turquía y Siria como si has estado haciendo mapas durante años, siempre es útil
  leer consejos y ver tutoriales para mejorar tus habilidades y mantener las mejores
  prácticas. Estos son algunos de los mejores consejos de los miembros del Equipo
  de Datos de HOT.
Person:
- Dinar Adiatma
- Samson Ngumenawe
---

## Mapeo mediante el Tasking Manager de HOT

* Lee todas las instrucciones para un proyecto de mapeo específico y concentra tus esfuerzos en las características solicitadas en el proyecto. Puedes mapear otras características, pero ten en cuenta que es posible que no sean mapeadas en otras tareas del proyecto. Esto puede afectar el que se completen los datos y afectar el tiempo que lleva validarlos.

* Utiliza las imágenes especificadas en las instrucciones.(Por supuesto, usa otras imágenes si la imagen especificada no está clara en una tarea determinada o para verificar tus ediciones).

* Concéntrate primero en el área de prioridad, generalmente dibujada en un polígono rojo en cada proyecto. Aquí un ejemplo del proyecto #14234.

![Mapping Tips 1.png](/uploads/Mapping%20Tips%201.png)

*Fig 1. Áreas prioritarias en el Tasking Manager*

## Conectividad de carreteras

Los datos de OpenStreetMap se utilizan mucho en las aplicaciones de enrutamiento. Consulta la página Wiki [Enrutamiento](https://wiki.openstreetmap.org/wiki/ES:Enrutamiento). Estos son algunos consejos para que tus ediciones en OpenStreetMap sean útiles para otras personas:

* **Asegúrate de mapear solo autopistas y carreteras que estén conectadas.** Las carreteras desconectadas que conducen a ninguna parte no deberían ser mapeadas.

* **Todas las autopistas y caminos deben conectarse entre sí al menos desde el inicio** del segmento de autopista o camino o desde donde el segmento se une a otra autopista o camino. Esto se puede lograr acercando y conectando los segmentos recién creados a las autopistas y caminos existentes. La mejor práctica es comenzar pegado a una autopista o camino existente mientras se traza el nuevo camino.

![Mapping Tips 2.png](/uploads/Mapping%20Tips%202.png)

*Fig. 2. Una carretera no conectada debe vincularse a una ruta cercana.*

## Geometría/Precisión posicional

La geometría incorrecta puede dar como resultado una mala visualización, un enrutamiento inexacto y riesgos de seguridad potencialmente graves si los datos se utilizan para la navegación. La geometría imprecisa también puede afectar la calidad del análisis y la visualización de datos, lo que dificulta que los usuarios de datos comprendan y utilicen los datos para tomar decisiones. Por ejemplo, suponga que la geometría de un edificio o del uso del suelo de una región es incorrecta. En ese caso, podría ser difícil realizar un análisis espacial, como determinar la distancia entre dos ubicaciones o el tamaño de un uso de suelo específico. Aquí algunos consejos para que sus ediciones en OpenStreetMap sean útiles para otras personas:

* Cuadra los edificios (pulsando Q tanto en JOSM como en iD Editor). A menos que las imágenes satelitales indiquen claramente algo diferente, se puede suponer que la mayoría de los edificios son rectangulares.

![Mapping Tips 3.png](/uploads/Mapping%20Tips%203.png)

*Fig 3. Edificio sin cuadrar en iD Editor*

* Solo mapea objetos de los que estas seguro y puedas ver claramente.

* No dibujes objetos que se crucen entre sí. Si es necesario conectar los nodos/vía, hazlo compartiendo nodos.

![Connected Node not Overlap.png](/uploads/Connected%20Node%20not%20Overlap.png)

*Fig. 4. Rutas no conectadas vs. rutas conectadas*

## Gestión/autoría de proyectos en el Tasking Manager

Para administradores de proyecto o autores

* Projects in densely developed urban areas should be prioritized for intermediate and advanced mappers. However, projects in peri-urban or rural developed areas should be made open for all mapper levels. This speeds up the validation process.

* Sometimes, overdue projects can become stale, and to stay on schedule, project creators should publish projects one at a time. If the project takes a long time to complete, imagery may change during the mapping or validation process, affecting the data's recency.

* Invite experienced mappers to become validators. People can establish [their own team](https://tasks.hotosm.org/manage/teams/new/) or sign up for the [HOT Global Validator](https://tasks.hotosm.org/teams/7/membership/) community. For Turkey/Syria mapping activation, validation is only carried out by the validator teams.

* Keep an eye on the topic in the Questions & Comments section. Feedback is important for ensuring good data quality.

* You can [review detailed project management guidelines here](https://learnosm.org/en/coordination/tm-admin/).

**A message from Ralph to all validators:**

> "Validators, your role is to check the standard of the work. If it is of an acceptable standard, then you validate it. If it has a few errors, then you can decide to fix it yourself and validate it. If there is an appreciable amount of errors, then you invalidate it. If the work was done recently, you can message the mapper to advise them on improving their mapping. It is not the prime task of validators to clean up the mapping (although we use validators for that as they have the necessary skills to do that efficiently). Remember that by invalidating a task, you are sending a message to the Project Creators that there is something wrong with the mapping, and this can result in the project creator raising the level of mapper allowed to map and trainers revising the way they train the mappers. That does not mean that you are not allowed to fix up mapping. You are volunteers, and that is your decision to make. We are all concerned about maintaining the standard of the mapping we put onto OpenStreetMap."