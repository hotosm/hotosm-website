---
title: A fresh look for hotosm.org
date: 2018-06-12 21:16:00 Z
Feature Image: https://cdn.hotosm.org/website/hotosm-dot-org-3-compressor.png
Person: Nate Smith
Working Group:
- Technical
---

Today we flipped the switch on a new look for [hotosm.org](https://www.hotosm.org/). The new design has updated information on projects, new ways of accessing information about the community, and most of all maps!

### Projects, stats, and maps

The new hotosm.org has a number of new views that communicate what HOT does, who the HOT community is, and how to get directed to the right place.

![hotosm-dot-org-4-compressor.png](https://cdn.hotosm.org/website/hotosm-dot-org-4-compressor.png)

Within the Our Work section, you’ll find information about where and who makes up the HOT community. We’ve integrated a map view that allows navigation to countries and projects.

![hotosm-dot-org-2-compressor.png](https://cdn.hotosm.org/website/hotosm-dot-org-2-compressor.png)

In addition to project information, we’ve integrated the Missing Maps API to give access to country level OSM editing. This shows the mapping activity across OSM that is happening within every country.

![hotosm-dot-org-1-compressor.png](https://cdn.hotosm.org/website/hotosm-dot-org-1-compressor.png)

### Implementing a process to design and build

Over a year ago, Felix Delattre and I discussed ideas and options for how we can reduce maintenance and overhead of keeping our Drupal site up and secure. After our discussion, we agreed at looking into other options and we began a process of not only looking at the technology behind the website but also conduct a design update. Since last summer, the [website working group](https://github.com/hotosm/design-strategy/wiki/Design-Strategy-Working-Group) has been engaging in a process that has taken us from [research and strategy phase](https://www.hotosm.org/updates/2017-08-09_making_hot%E2%80%99s_design_experience_sizzle), to designing and developing a prototype with designer [Brendan Gatens](http://brendangatens.com/). The Working Group has now finished not only content migration, but collaborated with the Communications Working Group to engage HOT and OSM community projects to have their information highlighted and accessible on the website.

On the technical side, the entire site is built using [Jekyll](https://jekyllrb.com/), a simple open source static site generator. We’ve integrated a content editor called [Siteleaf](https://www.siteleaf.com/), which gives us the ability to add another option of editing beyond Github.

### What’s Next

The new hotosm.org is an updated way of how our community provides accessible information and data. Rebuilding the website gives us a foundation to incorporate more feedback and ideas going forward.

Over the next month one of our Outreachy interns, Ramya Ragupathy, is working on updated stats and integrating additional data into more map views across project and country pages. If you're a developer and interested in joining in on the work, [get in touch with me](mailto:nate@hotosm.org)

Have an idea about a new page, or want to get your project highlighted? [Post an issue](https://github.com/hotosm/hotosm-website/issues) on Github and we’ll help you make a contribution. If you’re a voting or community member that wants to have access to draft a blog post, [check out the instructions](https://github.com/hotosm/hotosm-website/wiki/How-to-update-your-profile-or-draft-a-blog-post) for the ways you can contribute.

*Thanks to the Website and Communications Working Group, along with Brendan Gatens, Ramya Ragupathy, Wille Marcel, and Dakota Benjamin's development support!*