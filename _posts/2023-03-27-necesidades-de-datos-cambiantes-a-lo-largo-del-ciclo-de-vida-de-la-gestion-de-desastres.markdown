---
title: Las necesidades de datos cambian a lo largo del ciclo de vida de la gestión
  de desastres
date: 2023-03-27 23:36:00 Z
categories:
- Mapping
- data
tags:
- datos
- openstreetmap
- mapeo abierto
- mapeo humanitario
- gestion de riesgos
Summary Text: Ya ha pasado dos meses desde que el primer terremoto de magnitud 7,7
  sacudió Turquía y Siria el lunes 6 de febrero. Aunque se trata de una emergencia
  en curso con grandes necesidades humanitarias, ahora estamos pasando a una fase
  de apoyo continuo a las comunidades afectadas y el inicio de los esfuerzos de reconstrucción
  donde sea factible hacerlo. A medida que cambia la fase de la respuesta a desastres,
  también cambian las necesidades de datos y los requisitos de datos y calidad.
Feature Image: https://cdn.hotosm.org/website/Disaster_Response_PhasesC.png
Person:
- Paul Uithol
- Jessica Pechmann
Working Group:
- Quality Control and Assurance
---

## Disponibilidad y usos de los datos: los datos de OSM en las fases de la gestión de desastres

Durante cada fase del "ciclo de gestión de desastres", existen diferentes necesidades, usos y requisitos de datos. Primero echemos un breve vistazo a las diferentes fases.

Las actividades de **respuesta** inmediatamente después de un desastre para ayudar a las personas afectadas incluyen búsqueda y rescate para salvar vidas y satisfacer las necesidades humanitarias básicas: agua, alimentos, ropa, asistencia médica, refugio, etc.

Las actividades iniciales de datos implican evaluar la disponibilidad y las lagunas de los datos de OSM, obtener la mayor cantidad posible de imágenes de código abierto previas y posteriores al evento (satélite y UAV), y respaldar las evaluaciones de daños y necesidades humanitarias y logísticas.

**Conjuntos de datos relacionados con la respuesta:**

<table style="border-bottom: none">
<tr>
<th style="border-bottom-width: 2px"><span style="font-weight: bold">Conjuntos de datos</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Necesidades y uso de datos</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Fuente</span></th>
</tr>
<tr>
<td>Construcciones</td>
<td style="border-left: 1px solid black">Estimaciones de población y #/% afectados.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Caminos</td>
<td style="border-left: 1px solid black">Enrutamiento y logística.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Nombres de lugares</td>
<td style="border-left: 1px solid black">Enrutamiento y navegación.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Datos del evento</td>
<td style="border-left: 1px solid black">Área de impacto y severidad para estimar la población afectada.</td>
<td style="border-left: 1px solid black"><a href="https://www.gdacs.org/">GDACS</a></td>
</tr>
<tr>
<td>Datos de infraestructura específicos del contexto</td>
<td style="border-left: 1px solid black">Los ejemplos incluyen instalaciones de salud, sitios de evacuación, aeropuertos y sitios de aterrizaje de helicópteros.

         Lo que es relevante y necesario depende del tipo de desastre y el contexto.
        </td>
        <td style="border-left: 1px solid black">Mezcla de OSM, <a href="https://data.humdata.org/dashboards/overview-of-data-grids">Cuadrículas de datos HDX</a>, conjuntos de datos de terceros</td>
    </tr>
    <tr>
        <td style="border-bottom: none;">Datos programáticos y de necesidades</td>
        <td style="border-left: 1px solid black; border-bottom: none;">Evaluaciones de necesidades humanitarias, actividades del programa, etc.</td>
        <td style="border-left: 1px solid black; border-bottom: none;">Conjuntos de datos de terceros</td>
    </tr>

</table>
<br><br>

Las actividades de **recuperación** se centran en devolver la situación a condiciones y circunstancias normales (e idealmente mejores y más resilientes) para las personas afectadas. El enfoque sigue siendo satisfacer las necesidades básicas de la población afectada, pero también se va desplazando hacia evaluaciones más exhaustivas de seguridad y daños, limpieza y reconstrucción.

**Conjuntos de datos relacionados con la recuperación:**

<table style="border-bottom: none">
<tr>
<th style="border-bottom-width: 2px"><span style="font-weight: bold">Conjuntos de datos</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Necesidades y uso de datos</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Fuente</span></th>
</tr>
<tr>
<td>Construcciones</td>
<td style="border-left: 1px solid black">Estimaciones de población y direccionamiento: capacidad de análisis con otros conjuntos de datos.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Caminos</td>
<td style="border-left: 1px solid black">Enrutamiento y logística para la entrega continua de ayuda humanitaria.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Evaluaciones de daños</td>
<td style="border-left: 1px solid black">Combinación de datos de OSM con conjuntos de datos externos y de terceros para ayudar en las evaluaciones de daños.</td>
<td style="border-left: 1px solid black"><a href="https://unosat.org/products/">UNOSAT</a>, <a href="https://emergency.copernicus.eu/mapping/copernicus-emergency-management-service#zoom=3&lat=0.62225&lon=-2.25351&layers=0BT00">Copernicus</a>, etc.</td>
</tr>
<tr>
<td>Datos de infraestructura específicos del contexto</td>
<td style="border-left: 1px solid black">Lo que es relevante y necesario depende del tipo de evento de desastre y el contexto. Esto podría ser para educación, salud, mercados, servicios financieros u otras áreas.</td>
<td style="border-left: 1px solid black">Combinación de conjuntos de datos de OSM y de terceros</td>
</tr>
<tr>
<td style="border-bottom: none;">Datos programáticos</td>
<td style="border-left: 1px solid black; border-bottom: none;">Evaluaciones de necesidades humanitarias y de desarrollo, actividades de programas, etc.</td>
<td style="border-left: 1px solid black; border-bottom: none;">Conjuntos de datos de terceros</td>
</tr>
</table>
<br><br>

Las actividades de **preparación** incluyen planificación y preparación para mejorar la capacidad local y la resiliencia para hacer frente a futuros eventos y emergencias. A menudo, se define una fase separada de "mitigación" entre la recuperación y la preparación, enfocándose en la prevención y reduciendo la probabilidad de efectos e impactos. En este caso, cuando analizamos las necesidades de datos (geoespaciales), combinamos la mitigación con la preparación.

**Conjuntos de datos relacionados con la preparación:**

<table style="border-bottom: none">
<tr>
<th style="border-bottom-width: 2px"><span style="font-weight: bold">Conjuntos de datos</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Necesidades y uso de datos</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Fuente</span></th>
</tr>
<tr>
<td>Infraestructura clave (específica del contexto), como infraestructura de agua y drenaje, transporte público o salud y educación</td>
<td style="border-left: 1px solid black">Intervenciones específicas en un área para mejorar la resiliencia y la preparación.</td>
<td style="border-left: 1px solid black; border-bottom: none" rowspan="4">Conjuntos de datos OpenStreetMap más gubernamentales o de terceros</td>
</tr>
<tr>
<td>Entorno natural: como humedales, llanuras aluviales y manglares o sistemas fluviales</td>
<td style="border-left: 1px solid black">Comprender un ecosistema más amplio y los impactos de las intervenciones y las inversiones.</td>
</tr>
<tr>
<td>Conjuntos de datos específicos del proyecto</td>
<td style="border-left: 1px solid black">Intervenciones específicas en un área para mejorar la resiliencia y la preparación.</td>
</tr>
<tr>
<td style="border-bottom: none;">Sitios de evacuación y capacidad de afrontamiento</td>
<td style="border-left: 1px solid black; border-bottom: none;">Creación de planes de evacuación y escalada.</td>
</tr>
</table>
<br>

**[Puedes acceder a los datos de OSM a través de la página HDX de HOT](https://data.humdata.org/organization/hot.).**
<br><br>

## Requisitos y calidad de los datos: enfoque a las necesidades de calidad de datos en evolución en HOT

Así como el uso de datos difiere para cada fase de una respuesta, también lo hacen las expectativas y los requisitos de los datos en sí. A menudo, se esperan estándares de calidad de datos más altos de los datos en ubicaciones y tiempos "estables" que en la fase de respuesta inmediata al desastre.

**Fase de respuesta**

Durante la **fase de respuesta** inmediata, la disponibilidad de datos es clave, y la calidad de los datos suele ser lo suficientemente buena siempre que no obstaculice el uso principal de los datos. Por ejemplo, las construcciones raras, superpuestas o que no son cuadriláteras en realidad no hacen que las estimaciones de población sean significativamente incorrectas. Sin embargo, las carreteras principales que no se conectan causan problemas para la navegación y la logística de rutas.

![DataPhasesEq2.png](https://cdn.hotosm.org/website/DataPhasesEq2.png)
<figcaption align = "left"><h6>Comparación de mapeos del 10 de febrero (izquierda) al 22 de marzo (derecha). El azul claro denota áreas de construcciones mapeadas en OSM.</h6></figcaption>
<br>
Los datos completos pueden ser escasos e inicialmente difíciles de obtener, especialmente si se trata de un área que no se cartografió bien en el pasado. El ritmo de mapeo en el Tasking Manager invariablemente superará los controles y la validación de la calidad de los datos.

Para complementar la asignación de tareas y la creación de datos, llevemos a cabo una Evaluación de riesgos de protección de datos para asegurarnos de que consideramos los factores de riesgo locales y los daños potenciales del mapeo, y consideramos posibles mejoras y mitigaciones. Por ejemplo, tengamos cuidado con los problemas relacionados con la representación y la exclusión de las poblaciones rurales o grupos étnicos a través de nuestras áreas y definiciones de tareas y qué tipos de infraestructura solicitamos (o no solicitamos) que se mapeen.

**Fase de recuperación**

Durante la **Fase de recuperación**, nos enfocaremos más en poner un esfuerzo concertado en la limpieza y validación de datos. Además, es posible que estemos apoyando esfuerzos de recuperación específicos, como evaluaciones de daños más completas, brindando asistencia humanitaria continua a refugios y campamentos, y planificando los esfuerzos de reconstrucción. Esto requiere que los datos sean de mayor calidad en general y se vinculen o incorporen elementos de datos adicionales, como direccionamiento detallado.

**Fase de preparación**

Para la **Fase de preparación**, se requiere datos de alta calidad y fidelidad, especialmente cuando se considera la implementación de proyectos específicos para la reducción del riesgo de desastres, la resiliencia o la acción anticipatoria. A menudo, los resultados de la recopilación de datos y el mapeo se destinarán a proporcionar datos para la toma de decisiones e información de referencia sobre intervenciones e inversiones específicas. Ejemplos de este tipo de proyectos se pueden encontrar en el programa Ciudades Abiertas (por ejemplo, en [Accra, Ghana](https://www.hotosm.org/projects/open-cities-africa-accra-city-project-ghana/)). Estos proyectos tienen como objetivo desarrollar la resiliencia ante desastres en las ciudades en los que tienen lugar y requieren datos detallados y de alta calidad sobre aspectos específicos de la infraestructura, como el diseño exacto y la capacidad de los sistemas de drenaje y agua, los sistemas de transporte público o las instalaciones de salud.

![DataPhasesEq3.png](https://cdn.hotosm.org/website/DataPhasesEq3.png)

¿Quieres contribuir con OSM para necesidades humanitarias? Visita [el Tasking Manager de HOT](https://tasks.hotosm.org/explore) para proyectos desde nivel principiante, y lee [Tips para mapeadores del Equipo de Datos de HOT](https://www.hotosm.org/updates/tips-para-mapeadores-del-equipo-de-datos-de-hot/).
**[Puedes acceder a los datos de OSM a través de la página HDX de HOT](https://data.humdata.org/organization/hot.).**