---
title: "¡Prueba las nuevas funciones de la Herramienta de Exportación de HOT!"
date: 2024-02-27 21:10:00 Z
Summary Text: OpenStreetMap (OSM) es más que el mapa base que ves en osm.org u otros
  servicios geoespaciales. La base de datos detrás del mapa está llena de datos espaciales
  de colaboración abierta con etiquetado sistematizado que se traduce en atributos
  en los sistemas GIS. Para los analistas de datos y cartógrafos que desean acceder
  a conjuntos de datos de OSM para usarlos en QGIS u otras aplicaciones similares,
  ¡la herramienta de exportación de HOT ahora es mucho más útil!
Feature Image: "/uploads/Export%20Lead.png"
Person: Kshitij Sharma
Working Group:
- TechandInnovation
---

Si estás buscando datos OSM confiables en varios formatos de archivo que sean fáciles de descargar en unos pocos pasos y en un par de minutos, se han agregado nuevas funciones a la [Herramienta de exportación de HOT](https://export.hotosm.org /en/v3/)! El desarrollador de HOT, Kshitij, ha estado trabajando durante varios meses en estas mejoras y queremos enviarle un enorme agradecimiento.

¡Mira el tutorial que te guiará a través de todas las funciones y explóralas tú mismo! Si tienes algún comentario, ponte en contacto agregando una propuesta a [Github](https://github.com/hotosm/osm-export-tool) o uniéndote a #export-tool [canal Slack](https://slack.hotosm.org/).

<iframe width="560" height="315" src="https://www.youtube.com/embed/vxEDFAVfOTo?si=kdBJGdubn3UrqdnS" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

También tenemos a continuación todas las actualizaciones explicadas con capturas de pantalla.

**1. Exporta datos de OSM con tres nuevos formatos (FlatGeobuf, CSV, y SQL)**

* **Flat Geobuf** es muy rápido en comparación con shapefile, lo que permite a los usuarios realizar operaciones espaciales con índices espaciales. La herramienta de exportación ahora proporciona datos de OSM en formato flatgeobuf.
* **CSV** será útil para el analista de datos y para cualquier persona interesada en utilizar datos de OSM [etiquetados](https://wiki.openstreetmap.org/wiki/Tags) en su investigación/trabajo/educación.
* **SQL** será muy útil para los programadores/visualizadores que quieran ejecutar sus propias consultas y permitir el análisis espacial utilizando las potentes funciones de PostGIS.

**2. Descarga todo lo que hay en el área**

Las actualizaciones de la herramienta de exportación introducen una nueva función que permite a los usuarios descargar todos los datos de OSM disponibles dentro del área. Puedes utilizar esta casilla de verificación Download all OSM data (Descargar todos los datos de OSM) que figura en la pestaña Datos. Esto incluirá todas las etiquetas en los atributos, lo que te permitirá filtrar los datos que necesitas o crear un mapa base a partir de las características exportadas.

![Export 1.png](/uploads/Export%201.png)

**3. Obtén límites de proyecto en el HOT Tasking Manager con la herramienta de exportación**

Ahora, la herramienta de exportación puede admitir el ID del proyecto del Tasking Manager como entrada directamente en la barra de búsqueda. El ID del proyecto debe ir seguido de la palabra tm. Cuando un usuario selecciona un ID de proyecto del Tasking Manager como área de interés, se exportarán los datos de OSM asociados con ese proyecto.

![Export 2.png](/uploads/Export%202.png)

**4. Cargar características OSM individuales como límite**

La herramienta de exportación ahora también te brinda una opción para exportar datos dentro de características individuales de [relación OSM](https://wiki.openstreetmap.org/wiki/Relation). Por ejemplo, para llevar este [límite de municipio](https://www.openstreetmap.org/relation/6104486#map=11/28.2094/83.9733) de OSM a la herramienta de exportación, simplemente puedes escribir OSM y su identificación como se ve en la imagen  continuación y exportar las características requeridas.

![Export 3.png](/uploads/Export%203.png)

**5. Obtén información rápida sobre tu área de exportación antes de hacer una solicitud de exportación real**

La herramienta de exportación tiene una nueva característica llamada información sobre la integridad de los datos. Cuando creas una geom o haces una carga en la herramienta de exportación, después de un par de segundos, verás información justo encima de la marca de tiempo del sistema. Lo llamamos métricas de integridad de datos, posible a través de varias fuentes que se pueden encontrar como se enumeran [aquí](https://github.com/hotosm/raw-data-api/blob/develop/docs/src/stats/indicators.md). ¡Te dará un vistazo rápido sobre el área donde planeas exportar!

![Export 4.png](/uploads/Export%204.png)

**6. Implementación de OSM Oauth2.0**

Hemos implementado la autenticación oauth2.0 para OSM. Esto significa un gran cambio referido a la forma de iniciar sesión. Primero deberás cerrar sesión y luego iniciar sesión nuevamente en la herramienta de exportación, ¡y todo lo demás debería funcionar como antes! Verás un banner como el siguiente en tu pantalla.

![Export 5.png](/uploads/Export%205.png)

**7. Nuevo backend para la herramienta de exportación: Raw data API (API de datos sin procesar) -noticias interesantes para los desarrolladores-, el umbral de área se ha incrementado en un 50 %**

La Raw data API (https://github.com/hotosm/raw-data-api/) ahora sirve como un nuevo backend para la herramienta de exportación de OSM para todos los formatos seleccionados en la imagen adjunta. Es decir, GeoJSON, Shapefile, Geopackage, Google Earth KML, Flatgeobuf, y CSV. El umbral de área para esos formatos también se ha incrementado en un 50%. Puedes acceder a la documentación de la API [aquí](https://api-prod.raw-data.hotosm.org/v1/redoc). Enlace a Github [aquí](https://github.com/hotosm/export-tool-api) y nuevo [diagrama de arquitectura](https://miro.com/welcomeonboard/OFIxRlBWUHU0bmIyb2FPZkJqSDhYVzc1ektqZDFzSXRJU1VHTTdYRVlraFVkNUVmUTcweHRvZXRwTDJKZ0ZsMnwzNDU4NzY0NTE1MDkwMjQ0MzIzfDI=?share_link_id=26271906711). La nueva API te permite realizar exportaciones de países, exportaciones personalizadas y también métricas de integridad de datos para el área. Los formatos Garmin, OSM y OSMAnd aún no están disponibles a través de la API y es posible que no tengan el mismo rendimiento que otros.

fAIr, HOT Tasking Manager, y FMTM ya usan la Raw data API, SQL y Mbtiles. Esta nueva integración de backend te brindará resultados más rápidos para los formatos de archivo seleccionados.

![Export 6.png](/uploads/Export%206.png)

**¿Qué más puedes esperar de la herramienta de exportación?**

Planeamos hacer otra publicación sobre exportaciones de datos a nivel de país y su mejora relacionada con los conjuntos de datos HDX. Como siempre, nos encantaría saber de ti y qué piensas de estos nuevos desarrollos. También agradeceríamos aportes para mejorar la documentación de la herramienta de exportación [aquí](https://github.com/hotosm/osm-export-tool/tree/master/ui/app/components/help).

Únete al canal de Slack #export-tool o ponte en contacto con [Kshitij](mailto:kshitij.sharma@hotosm.org) si tienes alguna pregunta o deseas enviar una nota de agradecimiento.
