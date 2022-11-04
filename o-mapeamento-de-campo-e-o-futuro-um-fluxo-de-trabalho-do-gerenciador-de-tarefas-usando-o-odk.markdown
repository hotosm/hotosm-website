---
title: 'O mapeamento de campo é o futuro: um fluxo de trabalho do gerenciador de tarefas
  usando o ODK'
date: 2022-08-24 04:45:00 Z
---

**O mapeamento de campo pela população local é fundamental para o futuro do mapeamento aberto. No entanto, as ferramentas hoje disponíveis – apesar de muitas serem de alta qualidade – não formam um ecossistema coerente para liberar o potencial do mapeamento de campo comunitário. Algo está faltando! Poderia ser um Gerenciador de Tarefas para Mapeamento de Campo?**

> **Resumo (TL:DR)**
>
> Embora tenhamos alguns aplicativos de mapeamento de campo muito bons, não temos ótimas ferramentas para coordenar o mapeamento de campo.No entanto, temos a maioria dos elementos necessários para criar uma versão orientada para mapeamento de campo do HOT Tasking Manager, que permite selecionar áreas específicas e concluir tarefas de forma coordenada e organizada.
>
> Já é possível implementar uma espécie de fluxo de trabalho do Gerenciador de Tarefas de mapeamento de campo usando ferramentas existentes (principalmente baseadas em ODK, em particular a nova funcionalidade "selecionar do mapa"), mas é bastante trabalhoso e complicado.Estamos trabalhando na automação para aliviar os pontos problemáticos, aproximando-nos de um Gerenciador de Tarefas completo.
>
> Em colaboração com a equipe de Tecnologia e Comunidades e os Grupos de Trabalho de Comunidade e Treinamento, a Equipe de Programas de Campo HOT realizará uma [sessão de compartilhamento de habilidades](https://www.eventbrite.com/e/field-mapping-is-the-future-a-tasking-manager-workflow-for-odk-tickets-400186387257) em 9 de setembro de 2022, durante a qual os participantes poderão obter uma compreensão e alguma experiência com a ideia ;Usaremos o feedback desta sessão para avaliar o interesse e o engajamento para um maior desenvolvimento.Incentivamos a participação de indivíduos e comunidades interessados ​​em ferramentas de coordenação de mapeamento de campo.

**A atribuição de tarefas permite um melhor mapeamento remoto**

Um dos elementos mais impactantes do ecossistema de mapeamento aberto nos últimos dez anos foi o **[HOT Tasking Manager](https://tasks.hotosm.org/)**. O próprio **[OpenStreetMap](https://www.openstreetmap.org/#map=19/75.56995/-116.60797)** criou um repositório aberto e massivamente escalável para dados geográficos, e ferramentas como o **[ID Editor](http://ideditor.com/)** e o **[Java OpenStreetMap Editor (JOSM)](https://josm.openstreetmap.de/)** forneceram ferramentas de primeira linha para adicionar dados ao mapa remotamente. No entanto, entre as ferramentas de edição e o repositório, havia uma lacuna: como as pessoas poderiam facilmente escolher áreas para mapear de forma completa e com alta qualidade?

Algo era necessário: uma maneira de alocar tarefas pequenas e gerenciáveis ??a indivíduos, acompanhar seu progresso, verificar a qualidade e validar seu trabalho e integrar perfeitamente os novos dados ao OpenStreetMap sem danificar os dados existentes. O HOT Tasking Manager serviu como o tapete que unia a sala; uma ferramenta para a comunidade definir necessidades de dados e para mapeadores individuais contribuírem com facilidade e confiança.

![Screen Shot 2022-08-24 at 3.14.13 PM-ce4f17.png](/uploads/Screen%20Shot%202022-08-24%20at%203.14.13%20PM-ce4f17.png)

E quanto à tarefa de mapeamento de campo?

Há uma série de ótimas ferramentas de coleta de dados de campo!

O poderoso **[ODK – OpenDataKit](https://getodk.org/)** e as muitas plataformas construídas a partir dele, como o **[Kobo Toolbox](https://www.kobotoolbox.org/)**, possibilitam que qualquer pessoa com um dispositivo Android colete dados usando formulários flexíveis e poderosos projetados em uma planilha.

![Screen Shot 2022-08-24 at 3.15.46 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.15.46%20PM.png)

*A planilha à esquerda cria o questionário e a atividade “Selecionar do mapa” no telefone.*

O **[Vespucci](https://vespucci.io/)** traz muito do poder do JOSM para um editor móvel. O **[EveryDoor](https://every-door.app/)** oferece aos usuários do Android e do iPhone uma plataforma simples para editar dados do OSM, e o StreetComplete faz o mesmo para os usuários do Android. O **[OSMAND](https://osmand.net/)** e \*\*[Organic Maps](https://organicmaps.app/)\*\*permitem navegação e visualização de mapas offline com dados OSM, bem como alguma capacidade básica para adicionar ou editar recursos para contribuir com o OSM.

![Screen Shot 2022-08-24 at 3.27.54 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.27.54%20PM.png)

*Capturas de tela de EveryDoor, Vespucci, OSMAnd e Organic Maps*

Assim como no mapeamento remoto, temos um excelente repositório de dados (OSM) e ótimas ferramentas de edição e/ou coleta de dados, mas *não há uma plataforma de coordenação para facilitar o mapeamento de campo em larga escala e alta qualidade para o OpenStreetMap.*

Propomos um Gerenciador de Tarefas de Mapeamento de Campo para suprir essa necessidade.

**Os componentes de um Gerenciador de Tarefas de mapeamento de campo, em sua maioria, já estão construídos!**

Se estivéssemos começando do zero, esta seria uma proposta assustadora. No entanto, graças ao incrível trabalho de [Nafundi](https://nafundi.com/), os principais desenvolvedores do OpenDataKit (ODK), e alguns trabalhos relacionados acontecendo no HOT e na comunidade de mapeamento aberto mais ampla, as peças já estão em vigor.

**O que é necessário para um Gerenciador de Tarefas de mapeamento de campo?**

O que é necessário para implementar um Gerenciador de Tarefas de Mapeamento de Campo? Precisamos de uma maneira de:

* Definir uma ADI – Área de Interesse e dividi-la em tarefas menores. Alocar tarefas a indivíduos de forma que não haja duplicação nem lacunas

* Monitorar o progresso das tarefas de mapeamento de campo

* Converter os resultados do mapeamento de campo (submissões) em um formato apropriado para validação

* Validar o trabalho e fornecer feedback aos mapeadores, se necessário (incluindo pedir que revisem ou corrijam erros)

* Integrar os novos dados no OSM ou em outras plataformas \* Idealmente com atribuição específica ao mapeador de campo para os dados que eles criaram, uma solicitação de longa data da comunidade OSM que valoriza a responsabilidade individual pelas edições sobre as importações de dados agregados

**O que já temos?**

A partir de meados de 2022, temos ferramentas que podem cumprir todos os requisitos acima. Uma funcionalidade semelhante ao Gerenciador de Tarefas já pode ser alcançada com (muito) trabalho manual. Com um pouco de automação simples, já podemos tornar isso muito mais suave e, eventualmente, criar um fluxo de trabalho do Gerenciador de Tarefas de Mapeamento de Campo altamente acessível e funcional.

**Nova funcionalidade “selecionar do mapa” do ODK e alocação de formulário individual**

A partir de meados de 2022, o ODK incorpora uma nova funcionalidade denominada “**[selecionar no mapa](https://forum.getodk.org/t/odk-collect-v2022-2-beta-select-from-map-geojson-datasets/36913)**“, que permite aos mapeadores de campo selecionar um objeto de um mapa, visualizar os atributos existentes e preencher um formulário adicionando novas informações e atributos a esse objeto. Por exemplo, um mapeador pode abordar um prédio, selecionar esse prédio em uma visualização de mapa no ODK em seu celular e adicionar o horário de funcionamento, o número de andares, o material de construção ou qualquer número de atributos úteis em um formato de questionário bem estruturado\*.

*Isso replica principalmente a funcionalidade do muito lamentado **[OpenMapKit](http://www.openmapkit.org/)**, um fork do ODK muito útil criado pela Cruz Vermelha Americana com suporte da HOT e outras agências, que permitia aos usuários lançar formulários a partir de uma visualização de mapa e selecionar edifícios/recursos para adicionar atributos para. Infelizmente, o OMK não é mais mantido e não pode ser usado de forma confiável.*

![Screen Shot 2022-08-24 at 3.34.04 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.34.04%20PM.png)

Além disso, o novo aplicativo de servidor Web **[ODK Central](https://docs.getodk.org/central-intro/)** contém ferramentas muito granulares para alocar formulários a usuários individuais. É possível, de fato, criar questionários individuais para um número arbitrário de pequenas áreas (como bairros), cada uma com seu próprio conjunto de características (como prédios). Esses formulários podem ser alocados a “usuários de aplicativos” específicos, com acesso a formulários específicos (e, portanto, bairros/áreas) definidos por um código QR.

![Screen Shot 2022-08-24 at 3.35.11 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.35.11%20PM.png)

*O ODK Central oferece suporte à alocação de formulários individuais – e recursos correspondentes, como prédios – para usuários individuais*

Como esse sistema de “usuário de aplicativo” facilita um Gerenciador de Tarefas? Ficamos muito felizes que você perguntou! Ao criar um código QR para cada bairro (ou “tarefa”) e alocá-los um a um para os indivíduos, podemos:

* Atribuir áreas específicas a pessoas específicas (seja alocando-as diretamente ou fornecendo uma seleção de áreas e deixando as pessoas escolherem)

* Acompanhar quais áreas foram alocadas e concluídas (e, com um pouco mais de trabalho, validadas) Acompanhe quem mapeou qual área

* Alocar novas áreas para pessoas que terminaram as suas

* Acompanhar quais áreas ainda precisam de mapeamento (ou conclusão/correção após validação)

No momento, isso é muito trabalho manual. No entanto, o ODK Central possui uma [API poderosa e bem documentada](https://odkcentral.docs.apiary.io/#), e a criação de tarefas/áreas individuais, alocação para usuários específicos, rastreamento de resultados recebidos e congelamento de formulários que já estão alocados, podem ser automatizados!

Embora já possamos alocar tarefas manualmente, o próximo passo óbvio é um mapa da web, permitindo que os mapeadores de campo selecionem uma área facilmente. A equipe do **[OpenMapDevelopment Tanzania (OMDTZ)](https://www.omdtz.or.tz/about/)** foi pioneira em [mapas da web interativos que se integram ao ODK Central](https://millmaps.org/), demonstrando um caminho promissor a seguir.

**Conversão de envios ODK para XML OSM para validação e upload**

A HOT Tech Team já criou um conjunto de scripts que convertem o envio de formulários ODK em OSM XML, o formato de dados nativo do OpenStreetMap. Isso permite que os envios do mapeamento de campo entrem facilmente no pipeline de dados tradicional de validação no JOSM, seguido pelo upload para o OSM atribuído ao ID do OSM do mapeador de campo.

A existência desses scripts facilita mais a funcionalidade do Tasking Manager, pois a conversão de envios em conjuntos de dados prontos para validação é direta e facilmente automatizada. Os scripts são particularmente fáceis de adaptar quando visam formulários ODK padronizados de boa qualidade, um benefício importante de todo esse sistema.

**O que precisamos construir?**

Em princípio, já podemos implementar um fluxo de trabalho do Field Mapping Tasking Manager, mas requer muito trabalho manual complicado. Nosso plano é fazer isso e automatizar de forma incremental os pontos problemáticos! O caminho mais provável provavelmente se parece com:

* Criar um mapa da web compatível com dispositivos móveis (não um aplicativo para dispositivos móveis, apenas um aplicativo da web) que:

  * Exibir todas as tarefas individuais em um projeto, codificadas por cores por status de alocação/conclusão

  * Permitir que os mapeadores cliquem em uma tarefa perto de sua localização física e a atribuam a eles (com um código QR ou um lançamento direto do ODK Collect com a configuração relevante)

  * Permitir que mapeadores, validadores e gerentes vejam o progresso e selecionem tarefas para mapeamento ou validação adicional


* Criar um mapa web para telas de computador que facilite a criação de projetos e tarefas individuais

  * Idealmente, use redes rodoviárias e hidroviárias para dividir tarefas de forma sensata para mapeamento de campo, em vez de quadrados arbitrários

  * Automatize o processo de download de dados OSM (prováveis edifícios como primeira prioridade) para a área coberta por cada tarefa e converte-os em recursos selecionáveis em um formulário ODK para cada área de tarefa

*Semelhante e possivelmente baseado na interface do usuário do HOT Tasking Manager, embora otimizada para dispositivos móveis; as pessoas que usam o Gerenciador de Tarefas estão, por definição, usando uma tela de computador, enquanto os mapeadores de campo estão, por definição, usando um dispositivo móvel.*

* Refinar e expandir o(s) formulário(s) disponível(is) para cobrir as necessidades de dados de mapeamento de campo mais críticas das comunidades

*La mayoría de los datos de mapeo de campo se cargan actualmente en OSM como importaciones masivas atribuidas a la organización, el proyecto o el validador. Esto es una fuente de frustración para la comunidad de OSM, que valora mucho la responsabilidad individual de las ediciones individuales añadidas al mapa.*

* Simplifique o processo de validação e importação de dados

* E assim por diante…

### Próximos pasos

Em colaboração com a equipe de Tecnologia e Comunidades e os Grupos de Trabalho de Comunidade e Treinamento, a Equipe de Programas de Campo HOT realizou uma **[sessão de compartilhamento de habilidades](https://www.eventbrite.com/e/field-mapping-is-the-future-a-tasking-manager-workflow-for-odk-tickets-400186387257)** em 9 de setembro de 2022, durante a qual as pessoas puderam obter uma compreensão e alguma experiência com a ideia; o feedback desta sessão está sendo utilizado para avaliar o interesse e a participação para continuar o desenvolvimento. Incentivamos os indivíduos e comunidades interessados em ferramentas de coordenação de mapeamento de campo a acessar os conteúdos.

As sessões de francês e inglês foram realizadas em vários fusos horários, e sessões adicionais podem ser adicionadas se houver interesse de fusos horários e idiomas adicionais (provavelmente podemos gerenciar uma sessão em espanhol se os participantes estiverem preparados para ouvir o idioma de Cervantes sem piedade massacrado).

Se, após a sessão de compartilhamento de habilidades, houver um interesse substancial da comunidade em usar esse fluxo de trabalho, continuaremos a construí-lo em colaboração com esses usuários. Então, se você acha que isso é algo que você pode querer ou precisar, certifique-se de se inscrever para o [compartilhamento de habilidades](https://www.eventbrite.com/e/field-mapping-is-the-future-a-tasking-manager-workflow-for-open-data-kit-tickets-400186387257). 

*[Tradução](https://infosaofrancisco.canoadetolda.org.br/artigos/ciencia-e-tecnologia-cidadas/o-mapeamento-de-campo-e-o-futuro-um-fluxo-de-trabalho-do-gerenciador-de-tarefas-usando-o-odk/) gentilmente cedida por [InfoSãoFrancisco](https://infosaofrancisco.canoadetolda.org.br/).*

> **English**: Field Mapping is the Future: A Tasking Manager Workflow Using ODK
>
> [Read more](https://www.hotosm.org/updates/field-mapping-is-the-future-a-tasking-manager-workflow-using-odk/)
>
> **Français**: La cartographie de terrain est l’avenir : Un flux de travail de Gestionnaire de Tâches utilisant ODK
>
> [Read more](https://www.hotosm.org/la-cartographie-de-terrain-est-lavenir-un-flux-de-travail-de-gestionnaire-de-taches-utilisant-odk.html)
>
> **Español**: El mapeo de campo es el futuro: Un flujo de trabajo del Gestor de Tareas utilizando ODK
>
> [Read more](https://www.hotosm.org/el-mapeo-de-campo-es-el-futuro-un-flujo-de-trabajo-del-gestor-de-tareas-utilizando-odk.html)