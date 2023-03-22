---
title: Tips para mapeadores del Equipo de Datos de HOT
date: 2023-03-13 21:44:00 Z
categories:
- Mapping
- data
tags:
- mapeadores
- validadores
- OpenStreetMap
Summary Text: Tanto si recién empiezas a crear mapas para apoyar la respuesta al terremoto
  en Turquía y Siria como si has estado haciendo mapas durante años, siempre es útil
  leer consejos y ver tutoriales para mejorar tus habilidades y mantener las mejores
  prácticas. Estos son algunos de los mejores consejos de los miembros del Equipo
  de Datos de HOT.
Feature Image: "/uploads/GAL%20Group%20for%20Mapping%20Tips%20Post.jpg"
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

* Los proyectos en áreas urbanas densamente desarrolladas deben priorizarse para mapeadores intermedios y avanzados. Sin embargo, los proyectos en áreas desarrolladas periurbanas o rurales deben estar abiertos para todos los niveles de mapeadores. Esto acelera el proceso de validación.

* A veces, los proyectos vencidos pueden volverse obsoletos y, para cumplir con el cronograma, los creadores de proyectos deben publicar los proyectos de uno en uno. Si el proyecto tarda mucho en completarse, las imágenes pueden cambiar durante el proceso de mapeo o validación, lo que afecta la actualidad de los datos.

* Invita a mapeadores experimentados a convertirse en validadores. Las personas pueden establecer [su propio equipo](https://tasks.hotosm.org/manage/teams/new/) o registrarse en la comunidad de [Validadores Globales de HOT](https://tasks.hotosm.org/teams/7/membership/). Para la activación del mapeo de Turquía/Siria, la validación solo la llevan a cabo los equipos de validación.

* Estate atento al tema en la sección Preguntas y comentarios. La retroalimentación es importante para garantizar una buena calidad de los datos.

* Puedes [revisar las pautas detalladas de gestión de proyectos aquí](https://learnosm.org/en/coordination/tm-admin/).

## **Un mensaje de Ralph para todos los validadores:**

> "Validadores, su función es verificar el estándar del trabajo. Si tiene un estándar aceptable, entonces lo validan. Si tiene algunos errores, entonces pueden decidir corregirlo y validarlo. Si hay una cantidad apreciable de errores, entonces lo invalidan. Si el trabajo se realizó recientemente, puedes enviar un mensaje al mapeador para asesorarlo sobre cómo mejorar su mapeo. No es la tarea principal de los validadores limpiar el mapeo (aunque usamos validadores para eso ya que tienen las habilidades necesarias para hacerlo de manera eficiente). Recuerda que al invalidar una tarea, estás enviando un mensaje a los creadores del proyecto de que hay algo mal con el mapeo, y esto puede resultar en que el creador del proyecto eleve el nivel de mapeador que puede mapear y los capacitadores revisen la forma en que capacitan a los mapeadores. Eso no significa que no se te permita arreglar el mapeo. Ustedes son voluntarios, y esa es su decisión. Todos estamos preocupados por mantener el estándar del mapeo que hacemos en OpenStreetMap".