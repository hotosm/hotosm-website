---
title: 'La cartographie de terrain est l''avenir : Un flux de travail de Gestionnaire
  de Tâches utilisant ODK'
date: 2022-08-24 12:07:00 Z
---

![Screen Shot 2022-08-24 at 5.33.21 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%205.33.21%20PM.png)


**La cartographie de terrain par les populations locales est la clé de l'avenir de la cartographie ouverte. Cependant, les outils disponibles pour la cartographie de terrain - bien que beaucoup soient de grande qualité - ne forment pas un écosystème cohérent permettant de libérer le potentiel de la cartographie de terrain communautaire. Il manque quelque chose ! Pourrait-il s'agir d'un Gestionnaire de Tâches pour la cartographie de terrain?**

**Résumé (TL:DR)**

**Bien que nous disposions d'assez bonnes applications de cartographie de terrain, nous n'avons pas de grands outils pour coordonner la cartographie de terrain. Cependant, nous disposons de la plupart des éléments nécessaires pour créer une version du Gestionnaire de Tâches HOT orientée vers la cartographie de terrain, qui permet aux gens de sélectionner des zones spécifiques et d'accomplir des tâches de manière coordonnée.

Il est déjà possible de mettre en œuvre une sorte de flux de travail du Gestionnaire de Tâches pour la cartographie de terrain à l'aide d'outils existants (principalement basés sur ODK, en particulier la nouvelle fonctionnalité de "sélection à partir de la carte"), mais c'est assez laborieux et délicat. Nous travaillons sur une certaine automatisation afin d'atténuer les difficultés, ce qui nous rapproche d'un gestionnaire de tâches à part entière.

En collaboration avec l'équipe Tech and Communities et les groupes de travail Community et Training, l'équipe HOT Field Programs organisera une [session de partage de compétences le 9 septembre 2022](https://www.eventbrite.com/e/field-mapping-is-the-future-a-tasking-manager-workflow-for-open-data-kit-tickets-400186387257), au cours de laquelle les gens pourront comprendre et acquérir une certaine expérience de l'idée. Nous utiliserons les commentaires de cette session pour évaluer l'intérêt et la participation afin de poursuivre le développement. Nous encourageons les personnes et les communautés intéressées par les outils de coordination de la cartographie de terrain à y assister!**

**L'attribution de tâches permet une meilleure cartographie à distance**

L'un des éléments les plus marquants de l'écosystème de la cartographie ouverte au cours des dix dernières années a été le [gestionnaire de tâches HOT](https://tasks.hotosm.org/). [OpenStreetMap](https://www.openstreetmap.org/#map=19/75.56995/-116.60797) a créé une base de données ouvert et massivement extensible pour les données géographiques, et des outils comme [ID Editor](http://ideditor.com/) et [Java OpenStreetMap Editor (JOSM)](https://josm.openstreetmap.de/) ont fourni des outils de premier ordre pour ajouter des données à la carte à distance. Cependant, entre les outils d'édition et le référentiel, il y avait un fossé : comment les gens pouvaient-ils facilement choisir des zones à cartographier de manière complète et de haute qualité?

Il fallait quelque chose: un moyen d'attribuer de petites tâches gérables aux individus, de suivre leur progression, de contrôler la qualité et de valider leur travail, et d'intégrer de façon transparente les nouvelles données dans OpenStreetMap sans endommager les données existantes. Le gestionnaire de tâches HOT a servi de lien entre les deux parties; est un outil permettant à la communauté de définir les besoins en matière de données et aux cartographes individuels d'y contribuer avec facilité et confiance.

![Screen Shot 2022-08-24 at 3.14.13 PM-ce4f17.png](/uploads/Screen%20Shot%202022-08-24%20at%203.14.13%20PM-ce4f17.png)

**Qu'en est-il des tâches de cartographie sur le terrain ?**

Il existe un certain nombre d'excellents outils de collecte de données sur le terrain! 

Le puissant [OpenDataKit](https://getodk.org/) et les nombreuses plateformes construites à partir de celui-ci, comme [Kobo Toolbox](https://www.kobotoolbox.org/), permettent à toute personne disposant d'un appareil Android de collecter des données à l'aide de formulaires flexibles et puissants conçus dans un tableur. 

![Screen Shot 2022-08-24 at 3.15.46 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.15.46%20PM.png)

*La feuille de calcul de gauche crée le questionnaire et l'activité "Sélectionner sur la carte" sur le téléphone.*

[Vespucci](https://vespucci.io/) apporte une grande partie de la puissance de JOSM à un éditeur mobile. [EveryDoor](https://every-door.app/) offre aux utilisateurs d'Android et d'iPhone une plateforme simple pour modifier les données OSM, et StreetComplete fait de même pour les utilisateurs d'Android. [OSMAND](https://osmand.net/) et [Organic Maps](https://organicmaps.app/) permettent de naviguer et de visualiser des cartes hors ligne avec des données OSM, ainsi que d'ajouter ou de modifier des fonctionnalités pour contribuer à OSM.

![Screen Shot 2022-08-24 at 3.27.54 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.27.54%20PM.png)

*Captures d'écran de EveryDoor, Vespucci, OSMAnd et Organic Maps*

Comme pour la cartographie à distance, nous disposons d'un excellent référentiel de données (OSM) et d'excellents outils d'édition et/ou de collecte de données, mais il n'existe pas de plateforme de coordination pour faciliter la cartographie de terrain à grande échelle et de haute qualité pour OpenStreetMap. 

Nous proposons un gestionnaire de tâches de cartographie de terrain pour répondre à ce besoin.

**Les composants d'un gestionnaire de tâches de cartographie de terrain sont pour la plupart déjà construits!**

Si nous devions partir de zéro, ce serait une proposition décourageante. Toutefois, grâce à l'incroyable travail de [Nafundi](https://nafundi.com/), principaux développeurs d'OpenDataKit (ODK), et à certains travaux connexes réalisés par HOT et la communauté de la cartographie ouverte, les pièces sont déjà en place.

**Que faut-il pour un gestionnaire de tâches de cartographie de terrain?**
Que faut-il pour mettre en œuvre un gestionnaire de tâches de cartographie de terrain ? Nous avons besoin d'un moyen de:

* Définir un domaine d'intérêt et le diviser en tâches plus petites
* Répartir les tâches entre les individus de manière à éviter les doubles emplois et les lacunes.
* Suivre l'avancement des tâches de cartographie sur le terrain
* Convertir les résultats de la cartographie de terrain (soumissions) vers un format approprié pour la validation. 
* Valider le travail et fournir un retour d'information aux mappeurs si nécessaire (y compris leur demander de revoir ou de corriger les erreurs).
* Intégrer les nouvelles données dans l'OSM ou dans d'autres plateformes.
      * L'idéal serait d'attribuer spécifiquement au cartographe de 
        terrain les données qu'il a créées, une demande de longue 
        date de la communauté OSM qui privilégie la responsabilité 
        individuelle des contributions par rapport aux importations 
        de données agrégées.

**Qu'avons-nous déjà?**

À partir de la mi-2022, nous disposerons d'outils capables de répondre à toutes ces exigences. Une fonctionnalité semblable à celle du Gestionnaire de Tâches peut déjà être réalisée avec (beaucoup) de travail manuel. Avec un peu d'automatisation simple, nous pouvons déjà rendre cela beaucoup plus facile, et finalement créer un flux de travail de gestionnaire de tâches de cartographie de terrain hautement accessible et fonctionnel. 

**Nouvelle fonctionnalité ODK "sélectionner à partir de la carte" et attribution de formulaires individuels**

À partir du milieu de l'année 2022, ODK intègre une nouvelle fonctionnalité, [Select from map](https://forum.getodk.org/t/odk-collect-v2022-2-beta-select-from-map-geojson-datasets/36913), qui permet aux cartographes de terrain de sélectionner un objet sur une carte, de visualiser les attributs existants et de remplir un formulaire pour ajouter de nouvelles informations et de nouveaux attributs à cet objet. Par exemple, un cartographe peut s'approcher d'un bâtiment, le sélectionner sur une carte dans ODK sur son téléphone portable, et ajouter les heures d'ouverture, le nombre d'étages, le matériau de construction ou tout autre attribut utile dans un format de questionnaire bien structuré*.

     *Il reproduit en grande partie la fonctionnalité du très regretté [OpenMapKit](http://www.openmapkit.org/), un fork très utile d'ODK créé par la Croix-Rouge américaine avec le soutien de HOT et d'autres agences, qui permettait aux utilisateurs de lancer des formulaires à partir d'une vue cartographique et de sélectionner des bâtiments/éléments auxquels ajouter des attributs. Malheureusement, OMK n'est plus maintenu et ne peut plus être utilisé de manière fiable.*


![Screen Shot 2022-08-24 at 3.34.04 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.34.04%20PM.png)


En outre, la nouvelle application serveur web [ODK Central](https://docs.getodk.org/central-intro/) contient des outils très granulaires permettant d'attribuer des formulaires à des utilisateurs individuels. Il est possible, en effet, de créer des questionnaires individuels pour un nombre arbitraire de petites zones (comme des quartiers), chacune avec son propre ensemble de caractéristiques (comme des bâtiments). Ces formulaires peuvent ensuite être attribués à des "utilisateurs de l'application" spécifiques, l'accès à des formulaires spécifiques (et donc à des quartiers/zones) étant défini par un code QR. 

![Screen Shot 2022-08-24 at 3.35.11 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.35.11%20PM.png)

*ODK Central prend en charge l'attribution de formulaires individuels - et des fonctionnalités correspondantes telles que les bâtiments - à des utilisateurs individuels.*


Comment ce système d'"app user" facilite-t-il la tâche d'un Gestionnaire de Tâches ? Nous sommes ravis que vous ayez posé la question ! En créant un code QR  pour chaque quartier (ou "tâche"), et en les attribuant un par un aux individus, nous pouvons :
* Attribuer des domaines spécifiques à des personnes spécifiques (soit en les attribuant directement, soit en proposant une sélection de domaines et en laissant les personnes choisir).
* Gardez la trace des zones qui ont été allouées et complétées (et, avec un peu plus de travail, validées). Gardez la trace de qui a cartographié chaque zone.
* Attribuez de nouvelles zones aux personnes qui ont terminé les leurs.
* Garder la trace des domaines qui doivent encore être cartographiés (ou complétés/corrigés après validation).

Pour l'instant, cela représente beaucoup de travail manuel. Cependant, ODK Central dispose d'une [API puissante](https://odkcentral.docs.apiary.io/#) et bien documentée, et la création de tâches/zones individuelles, l'attribution à des utilisateurs spécifiques, le suivi des résultats entrants et le gel des formulaires déjà attribués, peuvent être automatisés!

Alors que nous pouvons déjà répartir les tâches manuellement, la prochaine étape évidente est une carte web permettant aux cartographes de terrain de sélectionner facilement une zone. L'équipe d'[OpenMapDevelopment Tanzania (OMDTZ)](https://www.omdtz.or.tz/about/) a été la première à créer des [cartes web interactives qui s'intègrent à ODK Central](https://millmaps.org/), démontrant ainsi une voie prometteuse.

**Conversion des soumissions ODK en OSM XML pour la validation et le téléchargement.**

L'équipe technique de HOT a déjà créé un ensemble de scripts qui convertissent les soumissions des formulaires ODK en OSM XML, le format de données natif d'OpenStreetMap. Cela permet aux soumissions provenant de la cartographie de terrain d'entrer facilement dans le pipeline de données traditionnel de validation dans le JOSM, suivi d'un téléchargement vers OSM attribué à l'OSM ID du cartographe de terrain. 

L'existence de ces scripts facilite une fonctionnalité plus proche de celle du Gestionnaire de Tâches car la conversion des soumissions en ensembles de données prêts à être validés est simple et facilement automatisée. Les scripts sont particulièrement faciles à adapter lorsqu'ils visent des formulaires ODK standardisés de bonne qualité, ce qui constitue un avantage clé de l'ensemble du système.

**Que devons-nous construire?**

En principe, nous pouvons déjà mettre en œuvre un flux de travail de type Gestionnaire de Tâches, mais cela nécessite un travail manuel délicat. Notre plan est de le faire, et d'automatiser progressivement les points douloureux ! Le chemin le plus probable ressemble probablement à ceci :

1. Créez une carte web adaptée aux mobiles (pas une application mobile, juste une application web) qui :

      a. Affiche toutes les tâches individuelles d'un projet, avec 
         un code couleur par statut d'affectation/achèvement.
      b. Permet aux cartographes de cliquer sur une tâche à 
         proximité de leur emplacement physique et de se la voir 
         attribuer (soit à l'aide d'un code QR, soit par un 
         lancement direct d'ODK Collect avec la configuration 
         appropriée).
      c. Permet aux mappeurs, aux validateurs et aux gestionnaires 
         de voir l'état d'avancement et de sélectionner les tâches à 
         poursuivre en matière de mappage ou de validation.

2. Créer une carte web pour les écrans d'ordinateur qui facilite la création de projets et de tâches individuelles

      a. Utilise idéalement les réseaux de routes et de voies 
         navigables pour répartir judicieusement les tâches de 
         cartographie sur le terrain plutôt que des carrés 
         arbitraires.
      b. Automatise le processus de téléchargement des données OSM 
         (probablement des bâtiments en première priorité) pour la 
         zone couverte par chaque tâche et les convertit en éléments 
         sélectionnables dans un formulaire ODK pour chaque zone de 
         tâche.

   *Similaire à l'interface utilisateur de HOT Tasking Manager et 
   éventuellement basée sur celle-ci, bien qu'optimisée pour le 
   mobile;les personnes qui utilisent Tasking Manager utilisent par 
   définition un écran d'ordinateur , tandis que les cartographes de 
   terrain utilisent par définition un appareil mobile.*

3. Affiner et étendre le(s) formulaire(s) disponible(s) pour couvrir les besoins les plus critiques des communautés en matière de données cartographiques sur le terrain.

   *La plupart des données de cartographie de terrain sont 
   actuellement téléchargées sur OSM sous forme d'importations en 
   masse attribuées à l'organisation, au projet ou au validateur. 
   C'est une source de frustration pour la communauté OSM, qui 
   apprécie grandement la responsabilité individuelle des 
   modifications apportées à la carte.*


4. Rationaliser le processus de validation et d'importation des données

5. Et ainsi de suite...

**Prochaines étapes**

En collaboration avec l'équipe Tech and Communities et les groupes de travail Community et Training, l'équipe Field Programs de HOT organisera un partage de compétences à l'adresse le 9 septembre 2022, où nous ferons la démonstration de l'utilisation d'un flux de travail rudimentaire du Field Mapping Tasking Manager. Tous sont les bienvenus ! 

Les sessions en français et en anglais se tiendront dans plusieurs fuseaux horaires, et des sessions supplémentaires pourront être ajoutées s'il y a un intérêt pour d'autres fuseaux horaires et d'autres langues ( nous pouvons probablement gérer une session en espagnol si les participants sont prêts à entendre la langue de Cervantès impitoyablement massacrée). 

Si, à la suite de la session de partage de compétences, la communauté manifeste un intérêt substantiel pour l'utilisation de ce flux de travail, nous continuerons à le développer en collaboration avec ces utilisateurs. Donc, si vous pensez que c'est quelque chose que vous voulez ou dont vous avez besoin, assurez-vous de vous inscrire pour le partage de compétences à tinyurl.com/field-mapping-tools1.






