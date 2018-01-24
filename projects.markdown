---
title: Projects
date: 2018-01-24 11:36:00 Z
permalink: "/projects/"
layout: page
---

{% for item in site.projects %}
  <h2>{{ item.title }}</h2>
  <p>{{ item.content }}</p>
  <p><a href="{{ item.url }}">{{ item.title }}</a></p>
{% endfor %}