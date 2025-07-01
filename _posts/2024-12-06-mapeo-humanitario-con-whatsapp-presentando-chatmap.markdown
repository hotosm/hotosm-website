---
title: 'Mapeo Humanitario con WhatsApp: Introduciendo ChatMap'
date: 2024-12-06 19:57:00 Z
Summary Text: ChatMap convierte los chats de WhatsApp en mapas instantáneos, extrayendo
  datos de ubicación y mensajes. Ideal para áreas propensas a desastres, fortalece
  a comunidades con habilidades tecnológicas limitadas, incluso sin conexión.
Feature Image: https://cdn.hotosm.org/website/chatmap+whatsapp+humanitarian+openstreetmap.jpg
Person: Emilio Mariscal
---

[English version](https://www.hotosm.org/updates/humanitarian-mapping-with-whatsapp-introducing-chatmap/)

Hace algunos meses, Céline Jacquin, Gerente Senior del Hub de América Latina y el Caribe, mencionó una comunidad que necesitaba mapeo humanitario, donde los residentes tenían nulos o mínimos conocimientos tecnológicos.

> *"Muchas de las personas involucradas no tienen conocimientos tecnológicos; incluso personas muy mayores me dicen que solo usan sus teléfonos para WhatsApp y nada más."*

Unos meses después, en la ciudad de Porto Alegre, Brasil, unas [grandes inundaciones afectaron una vasta área](https://www.hotosm.org/updates/recuperacion-de-la-infraestructura-social-en-porto-alegre-mapeo-para-la-resiliencia/), impactando a dos millones de personas. Nuevamente, WhatsApp estuvo en la conversación:

> *"Una universidad local está recibiendo fotos y ubicaciones por WhatsApp de las personas afectadas por el desastre. Y la universidad nos pregunta qué hacer con esa información."*

Como bombero voluntario, he vivido esta necesidad de manera directa. En el lugar donde vivo, los nombres de las calles son algo relativamente nuevo, por lo que es común que las personas compartan su ubicación a través de sus teléfonos para ayudarnos a encontrar sus casas durante emergencias.

![Humanitarian Mapping ChatMap WhatsApp.jpg](https://cdn.hotosm.org/website/Humanitarian+Mapping+ChatMap+WhatsApp.jpg)

# WhatsApp ChatMap

Mi objetivo era crear algo increíblemente simple y accesible, algo que cualquiera pudiera usar, incluso quienes no están familiarizados con coordenadas geográficas. La mensajería instantánea es ampliamente utilizada, casi todos tienen una aplicación instalada para eso y saben cómo enviar mensajes. WhatsApp está instalado en casi todos los teléfonos en América Latina, pero también en otras partes del mundo. Por ejemplo, solo en India hay 535.8 millones de usuarios.

Después de explorar opciones, se me ocurrió una idea: ¿y si pudiéramos exportar las conversaciones de chat y extraer los datos de ubicación junto con los mensajes asociados? La solución sería una aplicación sencilla en la que los usuarios puedan subir sus chats exportados y generar instantáneamente un mapa que muestre todas las ubicaciones y mensajes compartidos. No se necesitarían cuentas empresariales ni integraciones complejas, solo una herramienta lista para usar desde el primer día.

**ChatMap** —[chatmap.hotosm.org](https://chatmap.hotosm.org/)— es una solución de mapeo directa y sencilla que aprovecha WhatsApp, una aplicación utilizada por 2.78 mil millones de personas en todo el mundo. Su simplicidad y accesibilidad la convierten en una herramienta eficaz para comunidades con conocimientos técnicos limitados. ¡Incluso funciona sin conexión! Se basa en la señal GPS para las ubicaciones y almacena los datos en el teléfono hasta que se dispone de conectividad.

Esta solución ofrece completa independencia, ya que no requiere que los usuarios adopten una tecnología que dependa del mantenimiento de terceros. Es un flujo de datos simple con un script igualmente sencillo que cualquier persona interesada puede mejorar en GitHub.

# Casos de Uso

¡Ya estamos utilizándola! Recientemente, como parte de un proyecto de mapeo comunitario para evaluar los riesgos en las laderas de la Comuna 8 en Medellín, un área vulnerable a inundaciones recurrentes, un grupo de estudiantes y colectivos locales colaboraron con Humanitarian OpenStreetMap (HOT) para mapear zonas afectadas por deslizamientos y otros impactos de desastres. Esta iniciativa facilitó la identificación y caracterización de asentamientos, apoyando los esfuerzos de ayuda humanitaria.

![Humanitarian Mapping ChatMap.jpg](https://cdn.hotosm.org/website/Humanitarian+Mapping+ChatMap.jpg)

*Foto de Daniela Arbeláez Suárez (fuente: WhatsApp)*

Como se muestra en la foto, la comunidad exploró el área a pie, utilizando sus teléfonos para tomar fotos y notas, y compartiéndolas junto con la ubicación. ¡Fue increíblemente simple!

Los datos recopilados durante esta actividad se transformaron, 20 minutos después (al acceder a una red WiFi), en un mapa que luego fue subido a nuestra plataforma en línea impulsada por uMap ([umap.hotosm.org](https://umap.hotosm.org/en/map/unaula-mapea-con-whatsapp_38)).

![Humanitarian Mapping ChatMap WhatsApp Colombia.jpg](https://cdn.hotosm.org/website/Humanitarian+Mapping+ChatMap+WhatsApp+Colombia.jpg)

Consulta más en: [https://umap.hotosm.org/en/map/unaula-mapea-con-whatsapp_38](https://umap.hotosm.org/en/map/unaula-mapea-con-whatsapp_38#17/6.25014/-75.53986)

# ¿Qué sigue?

Tras las pruebas iniciales, surgieron muchas ideas emocionantes para mejorar la herramienta, pero nuestro enfoque inmediato está en simplificar el proceso de guardar mapas, incluyendo los medios compartidos, para que puedan ser fácilmente accesibles a través de una URL en el futuro. Más allá de eso, estamos explorando formas innovadoras de aprovechar aún más los datos compartidos.

Si tienes curiosidad sobre este proceso, ¿por qué no lo pruebas? Todo lo que necesitas son mensajes de WhatsApp con ubicaciones compartidas, ¡sin configuración adicional!

## Consulta este tutorial en video:

<iframe width="600" height="400" src="https://www.youtube.com/embed/CISWBZSErU8?si=_4fghjl95iLADyxF" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

El código está disponible en [GitHub](https://github.com/), con documentación sobre cómo ejecutarlo y comentarios dentro del código. Puedes contribuir, usarlo, mejorarlo e incluso instalarlo en tus propios servidores.

Cualquier persona interesada en contribuir puede contactar a Emi Mariscal por correo electrónico ([tech-data@hotosm.org](mailto:tech-data@hotosm.org)) o directamente a través del repositorio.