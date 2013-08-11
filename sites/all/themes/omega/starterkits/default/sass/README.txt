Introduction to Sass (http://sass-lang.com/)
============================================
Sass makes CSS fun again. Sass is an extension of CSS3, adding nested rules,
variables, mixins, selector inheritance, and more. It’s translated to well-
formatted, standard CSS using the command line tool or a web-framework plugin.

Sass has two syntaxes. The new main syntax (as of Sass 3) is known as “SCSS”
(for “Sassy CSS”), and is a superset of CSS3’s syntax. This means that every
valid CSS3 stylesheet is valid SCSS as well. SCSS files use the extension .scss.

The second, older syntax is known as the indented syntax (or just “Sass”).
Inspired by Haml’s terseness, it’s intended for people who prefer conciseness
over similarity to CSS. Instead of brackets and semicolons, it uses the
indentation of lines to specify blocks. Although no longer the primary syntax,
the indented syntax will continue to be supported. Files in the indented syntax
use the extension .sass.

@see http://sass-lang.com/docs.html
  Please refer to the Sass documentation for further information about the
  syntax.

Introduction to Compass (http://compass-style.org/)
===================================================
Compass is an open-source CSS Authoring Framework.

@see http://compass-style.org/reference
  Please refer to the Compass documentation for further information on how to
  leverage the powerful Compass framework.

Compass extensions
==================
There are many extensions available for Compass. You can install and use as many
of them together or just a single one depending on your use-case. Good examples
for useful Compass extensions are "susy" (a responsive grid framework
[http://susy.oddbird.net/]) or "compass-rgbapng" (a rgba() .png file generator)
but there are many more.

Setting up and using Sass and Compass
=====================================
Compass runs on any computer that has ruby installed.

@see http://www.ruby-lang.org/en/downloads
  For a tutorial on how to install ruby.

Once you got ruby installed you can easily install the required gems from the
command line:

$ gem update --system
$ gem install compass

Any additional library can be installed in the same way:
$ gem install compass-rgbapng
$ gem install susy

Once you have set up your environment you can navigate to the folder that holds
your config.rb file.

The config.rb file is the configuration file that helps Sass and Compass to
understand your environment. For example, it defines which folder your .scss
or .sass files are stored in or where the generated .css files should be output
to.

Executing the following command will constantly watch for any change in your
.scss files and re-compile them into .css:

$ compass watch

You can also clear and recompile your .css manually:

$ compass clean
$ compass compile

Barebones Sass Structure
========================
The barebones CSS structure provided in this starterkit uses many of the ideas
discussed in Jonathan Snook's SMACSS (http://smacss.com/) and is intended to
provide a starting point for building modular, scalable CSS using Sass and
Drupal.

Multiple Sass partials are used to help organise the styles, these are combined
by including them in style.scss which is compiled into style.css in the css/
directory.

All styles are included in order of specificity, this means that as you go down
the document each section builds upon and inherits sensibly from the previous
ones. This results in less undoing of styles, less specificity problems and
all-round better architected and lighter stylesheets.

Multiple Sass partials are used to help organise the styles, these are combined
by including them in style.scss which is compiled into style.css in the css/
directory. By separating our Sass into a file and folder structure makes finding
the correct code much easier than scrolling through a large file.

All styles are included in order of specificity, this means that as you go
down the document each section builds upon and inherits sensibly from the
previous ones. This results in less undoing of styles, less specificity
problems and all-round better architected and lighter stylesheets.

The file structure contained in this folder looks something like this:
    *   styles.scss
        This file shouldn't directly contain any CSS code, instead
        it only serves to combine the CSS contained in other Sass partials
        through @import directives.

    *   _utils.scss
        Global Sass variables and mixins should be defined here along with
        importing any Sass extensions required. These can then be accessed by
        importing _utils.scss where required.

    *   _base.scss
        These rules are the "Branding" of a theme also describe how common HTML
        and Drupal elements should look. Once this file is completed the
        theme's styleguide should be completely styled.

    *   _layout.scss
        The layout of the major regions (usually, but not necessarily Drupal
        regions) that components will be added to.

    *   _components.scss
        Imports more partials that contain full components and their
        sub-components ('modules' in SMACSS) that can be placed within the
        layout provided by _layout.scss.
