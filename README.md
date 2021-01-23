# HOTOSM Website

This repo is the codebase for the main Humanitarian OpenStreetMap Team website. See `gh-pages` branch for Jekyll code. If looking for the previous Drupal codebase, see the current `master` branch.

 - See the [issues queue](https://github.com/hotosm/hotosm-website/issues) for all discussions and tasks.
 - Chat available on [HOTOSM Slack](https://slack.hotosm.org/) within the #hotosm-website channel.

## Getting Started with Development

This site uses [Jekyll](https://jekyllrb.com/). To get started on GNU/Linux, Unix, or macOS, you must meet the following requirements:

  * Ruby 2.2.5 or above
  * RubyGems
  * GCC and Make

First, install [bundler](https://bundler.io/).

```
gem install bundler
```

Next, use bundler to install the build dependencies:

```
bundle install
```

Then, start Jekyll with bundler (this resolves any dependency issues you may have):

```
bundle exec jekyll serve --incremental
```

Finally, navigate to http://127.0.0.1:4000/ and you should see the new website!

## Key pages & script/data dependencies

![Website](https://user-images.githubusercontent.com/12103383/55768572-96f22280-5aa7-11e9-998d-9667f5d3a7dc.png)

## Website issues
Please use the issue tracker at https://github.com/hotosm/hotosm-website/issues to report bugs, develop ideas, ask questions or give feedback. Thank you!

## Security Notes

- Github Pages does not support HSTS even when added in meta tags
- Content-Security-Policy must be tweaked appropriately when new integrations are
  added
- Security header controls are absent in GH-Pages; So it's added as HTTP meta
  tags in `_includes/head.html`
