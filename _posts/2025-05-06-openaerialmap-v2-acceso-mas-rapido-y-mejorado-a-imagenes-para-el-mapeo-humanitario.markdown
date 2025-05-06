---
title: 'OpenAerialMap v2: Acceso más rápido y mejorado a imágenes para el mapeo humanitario'
date: 2025-05-06 16:41:00 Z
Summary Text: OpenAerialMap está evolucionando para ofrecer un acceso más rápido y
  confiable a imágenes satelitales y de drones para el mapeo humanitario. Con una
  nueva infraestructura basada en STAC y herramientas modernas, HOT y Development
  Seed están reconstruyendo OAM para responder a las necesidades urgentes de mapeo
  actuales. Descubre cómo esta actualización mejorará la interoperabilidad, velocidad
  y usabilidad en los esfuerzos de respuesta y recuperación ante desastres.
Feature Image: "/uploads/OAMv2Banner.jpg"
Person: Cristiano Giovando
---

Las imágenes satelitales y de drones en alta resolución son fundamentales para el mapeo humanitario efectivo. Permiten visualizar la situación en terreno, identificar zonas afectadas, planificar respuestas y monitorear procesos de recuperación. Desde 2015, el Equipo Humanitario de OpenStreetMap (HOT) ha desarrollado y mantenido [OpenAerialMap](https://openaerialmap.org/) (OAM) como una plataforma clave para alojar, compartir y acceder a estas imágenes esenciales.

Un principio fundamental de OAM es su compromiso con los datos abiertos. Todas las imágenes disponibles en OAM tienen licencias abiertas, lo que garantiza que puedan ser utilizadas y compartidas libremente por cualquier persona. Este compromiso es clave para la misión de organizaciones como HOT y la comunidad de mapeo abierto en general, especialmente en contextos de respuesta a desastres, donde el acceso rápido y sin restricciones es vital. Desde la respuesta al terremoto de Nepal en 2015 hasta los ciclones tropicales recientes, el terremoto de Turquía y Siria en 2023, y la respuesta al sismo en Myanmar, OAM ha sido fundamental para poner imágenes rápidamente en manos de las personas mapeadoras.

!\[OAM Screenshot.jpg\](/uploads/OAM%20Screenshot.jpg)\
**Ejemplo de imágenes de dron de Monrovia central subidas a OpenAerialMap.**

Sin embargo, encontrar las imágenes adecuadas y accesibles, y hacerlas fáciles de usar, sigue siendo un desafío. Los proyectos de mapeo, especialmente las respuestas rápidas coordinadas a través del [Tasking Manager de HOT](https://tasks.hotosm.org/), necesitan una manera fluida de evaluar las imágenes disponibles y acceder a ellas mediante servicios estándar de mapas por mosaicos (TMS).

## Es hora de una actualización: Explora lo que viene

Aunque OAM ha servido bien a la comunidad, desde su desarrollo inicial entre 2015 y 2017 principalmente ha recibido mantenimientos menores. Su tecnología e infraestructura base se han quedado atrás y requieren modernización para estar al nivel de los estándares, herramientas y demandas actuales. En promedio, se suben más de 100 nuevas imágenes a OAM cada mes, y más de 5,000 personas acceden a OAM y sus imágenes a través de la interfaz del mapa y los servicios de mosaicos.

Curiosamente, el diseño original de OAM [pionero en la idea de un catálogo distribuido](https://openimagerynetwork.github.io/) —indexando imágenes alojadas en distintos "buckets" por diversos proveedores, accesibles desde una sola interfaz— es muy similar a la especificación del [Catálogo de Activos Espacio-Temporales (STAC)](https://stacspec.org/en/), que se ha convertido en el estándar moderno para describir activos geoespaciales.

¡Por eso nos entusiasma anunciar un gran esfuerzo de actualización! Gracias a una generosa donación de [Cisco](https://www.cisco.com/) a través de su [programa de respuesta a crisis de CyberGrants](https://www.cisco.com/c/m/en_us/about/csr/esg-hub/social-impact/crisis-response.html), HOT se ha aliado con [Development Seed](https://developmentseed.org/) para reconstruir la infraestructura de backend de OAM, adoptando completamente el estándar STAC.

## ¿Por qué STAC?

Adoptar STAC ofrece ventajas significativas:

* **Interoperabilidad**: Proveedores importantes como Maxar, Planet, Satellogic y Umbra, así como NASA y ESA, ya usan STAC. OAM podrá indexar imágenes fácilmente desde sus programas de Datos Abiertos.

* **Eficiencia**: Al aprovechar catálogos STAC existentes, reducimos el tiempo para mostrar y acceder a imágenes tras un desastre. ¡Adiós a los largos procesos de ingestión!

* **Infraestructura moderna**: Usaremos herramientas como GeoTIFFs optimizados en la nube (COGs), PostgreSQL con pgstac, stac-fastapi, y [TiTiler](https://developmentseed.org/titiler/) para generar mapas dinámicos más rápidos y confiables.

## Una nueva cara: Renovación del navegador de OAM

Junto con la actualización del backend, reconstruiremos la interfaz del navegador de OAM. Aprovecharemos el [excelente trabajo de diseño del equipo de Kontur](https://www.kontur.io/blog/oam-redesign/) y bibliotecas abiertas de STAC y mapeo web.

!\[OAM-prototype.png\](/uploads/OAM-prototype.png)\
**Prototipo de la nueva versión. Fuente: Kontur.**

## ¡Involúcrate y entérate más!

Esta es una evolución emocionante para OAM y queremos que la comunidad participe:

* **Sigue el desarrollo**: [GitHub Project Board](https://github.com/orgs/hotosm/projects/42)

* **Únete a la conversación**: canal #OpenAerialMap en [HOT Slack](https://slack.hotosm.org/)

* **Recibe actualizaciones**: escribe a [info@openaerialmap.org](mailto:info@openaerialmap.org) para recibir noticias quincenales sobre el desarrollo

### Próximas presentaciones

* [CNG 2025](https://conference.cloudnativegeo.org/CNGConference2025) (Utah, 30 abril – 2 mayo)

* [State of the Map US 2025](https://openstreetmap.us/events/state-of-the-map-us/2025/) (Boston, 19–21 junio)

Creemos que estas mejoras aumentarán significativamente la utilidad de OAM, haciendo que las imágenes satelitales y aéreas sean más accesibles y útiles para esfuerzos humanitarios alrededor del mundo. ¡Sigue conectado para más novedades!