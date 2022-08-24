---
title: 'La cartographie de terrain est l''avenir : Un flux de travail de Gestionnaire
  de Tâches utilisant ODK'
date: 2022-08-24 12:07:00 Z
---

**La cartographie de terrain par les populations locales est la clé de l'avenir de la cartographie ouverte. Cependant, les outils disponibles pour la cartographie de terrain - bien que beaucoup soient de grande qualité - ne forment pas un écosystème cohérent permettant de libérer le potentiel de la cartographie de terrain communautaire. Il manque quelque chose ! Pourrait-il s'agir d'un Gestionnaire de Tâches pour la cartographie de terrain?**

**Résumé (TL:DR)**

Bien que nous disposions d'assez bonnes applications de cartographie de terrain, nous n'avons pas de grands outils pour coordonner la cartographie de terrain. Cependant, nous disposons de la plupart des éléments nécessaires pour créer une version du Gestionnaire de Tâches HOT orientée vers la cartographie de terrain, qui permet aux gens de sélectionner des zones spécifiques et d'accomplir des tâches de manière coordonnée.

 Il est déjà possible de mettre en œuvre une sorte de flux de travail du Gestionnaire de Tâches pour la cartographie de terrain à l'aide d'outils existants (principalement basés sur ODK, en particulier la nouvelle fonctionnalité de "sélection à partir de la carte"), mais c'est assez laborieux et délicat. Nous travaillons sur une certaine automatisation afin d'atténuer les difficultés, ce qui nous rapproche d'un gestionnaire de tâches à part entière.

En collaboration avec l'équipe Tech and Communities et les groupes de travail Community et Training, l'équipe HOT Field Programs organisera une session de partage de compétences le 9 septembre 2022, au cours de laquelle les gens pourront comprendre et acquérir une certaine expérience de l'idée. Nous utiliserons les commentaires de cette session pour évaluer l'intérêt et la participation afin de poursuivre le développement. Nous encourageons les personnes et les communautés intéressées par les outils de coordination de la cartographie de terrain à y assister!

L'attribution de tâches permet une meilleure cartographie à distance
L'un des éléments les plus marquants de l'écosystème de la cartographie ouverte au cours des dix dernières années a été le gestionnaire de tâches HOT. OpenStreetMap a créé une base de données ouvert et massivement extensible pour les données géographiques, et des outils comme ID Editor et Java OpenStreetMap Editor (JOSM) ont fourni des outils de premier ordre pour ajouter des données à la carte à distance. Cependant, entre les outils d'édition et le référentiel, il y avait un fossé : comment les gens pouvaient-ils facilement choisir des zones à cartographier de manière complète et de haute qualité ?

Il fallait quelque chose : un moyen d'attribuer de petites tâches gérables aux individus, de suivre leur progression, de contrôler la qualité et de valider leur travail, et d'intégrer de façon transparente les nouvelles données dans OpenStreetMap sans endommager les données existantes. Le gestionnaire de tâches HOT a servi de lien entre les deux parties ; est un outil permettant à la communauté de définir les besoins en matière de données et aux cartographes individuels d'y contribuer avec facilité et confiance.

![Screen Shot 2022-08-24 at 3.14.13 PM-ce4f17.png](/uploads/Screen%20Shot%202022-08-24%20at%203.14.13%20PM-ce4f17.png)

**Qu'en est-il des tâches de cartographie sur le terrain ?**

Il existe un certain nombre d'excellents outils de collecte de données sur le terrain ! 

Le puissant OpenDataKit et les nombreuses plateformes construites à partir de celui-ci, comme Kobo Toolbox, permettent à toute personne disposant d'un appareil Android de collecter des données à l'aide de formulaires flexibles et puissants conçus dans un tableur. 

![Screen Shot 2022-08-24 at 3.15.46 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.15.46%20PM.png)

*La feuille de calcul de gauche crée le questionnaire et l'activité "Sélectionner sur la carte" sur le téléphone.*

Vespucci apporte une grande partie de la puissance de JOSM à un éditeur mobile. EveryDoor offre aux utilisateurs d'Android et d'iPhone une plateforme simple pour modifier les données OSM, et StreetComplete fait de même pour les utilisateurs d'Android. OSMAND et Organic Maps permettent de naviguer et de visualiser des cartes hors ligne avec des données OSM, ainsi que d'ajouter ou de modifier des fonctionnalités pour contribuer à OSM.

![Screen Shot 2022-08-24 at 3.27.54 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.27.54%20PM.png)

*Captures d'écran de EveryDoor, Vespucci, OSMAnd et Organic Maps*

Comme pour la cartographie à distance, nous disposons d'un excellent référentiel de données (OSM) et d'excellents outils d'édition et/ou de collecte de données, mais il n'existe pas de plateforme de coordination pour faciliter la cartographie de terrain à grande échelle et de haute qualité pour OpenStreetMap. 

Nous proposons un gestionnaire de tâches de cartographie de terrain pour répondre à ce besoin.

**Les composants d'un gestionnaire de tâches de cartographie de terrain sont pour la plupart déjà construits!**

Si nous devions partir de zéro, ce serait une proposition décourageante. Toutefois, grâce à l'incroyable travail de Nafundi, principaux développeurs d'OpenDataKit (ODK), et à certains travaux connexes réalisés par HOT et la communauté de la cartographie ouverte, les pièces sont déjà en place.

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




