
-- SUMMARY --

Inline module allows you to display files uploaded with the current node
inline, i.e. with a link to the original file, using special tags. The tags
will be replaced with links to the corresponding files. If a tag refers to an
image, it will be replaced with the image.

Inline module does not attempt to resize a images. It assumes that the user 
will optimize the size and resolution of images prior to uploading it. A
configuration setting of this module allows to specify the maximum display
width and height for inline images. If the original image is not bigger than
the maximum width and height, it will be displayed as-is, otherwise its
dimensions will be recalculated, maintaining the same aspect ratio.

For a full description visit the project page:
  http://drupal.org/project/inline
Bug reports, feature suggestions and latest developments:
  http://drupal.org/project/issues/inline


-- REQUIREMENTS --

* Upload module (Drupal core)


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONFIGURATION --

* Enable "Inline filter" in the input formats you intend to use. To do this, go
  to Administer >> Input formats and click on one of the "Configure" links. For
  instance, you can click on the "Configure" link for "Filtered HTML" and then
  you will see a list of filters including "inline file filter". Turn that on
  and click on "Save".

* Go to Administer >> Site configuration >> Inline and edit the maximum width
  and height for inline images.  If an image exceeds those dimensions, it will
  be displayed as text link to download (like any other attachment than images).

  Please note that this configuration setting no longer applies if the optional
  ImageCache module is installed.

* Add to the CSS stylesheet you're using in your theme (usually style.css) the
  following lines which you can tune to your needs. This style will be used by
  the module to display images.

  .inline {
    float: left;
    display: inline;
    margin: 0 1em 1em 0;
    padding: 4px 4px;
  }


-- USAGE --

* For more details on using the module, see the help text by clicking:
  /filter/tips/1#filter-inline after you install it.

  [inline:filename=title]

  You can specify the file you want to display with the filename.

  If the file is not found, a 'NOT FOUND' message will be output.

  You can also specify a title for the file, by using an optional '=Title'
  parameter. In this case, it will be used as a title for the file link or as
  an ALT tag for an image. If no title is specified, the file name is used as
  title.


-- EXAMPLES --

* Suppose you uploaded three files (in this order):
  - imag1.png (referred as file #1)
  - file1.pdf (referred as file #2)
  - imag2.png (referred as file #3)

* [inline:file1.pdf]
  will be replaced with <a href="file1.pdf">file1.pdf</a>

* [inline:imag1.png=test]
  will be replaced with <img src="imag1.png" alt="test" />


-- CONTACT --

Current maintainers:
* Daniel F. Kudwien (sun) - dev@unleashedmind.com
* Richard Archer (Richard Archer) - http://www.juggernaut.com.au

Credits:
* Drupal 7 port - javier.alejandro.castro@gmail.com

Previous maintainers:
* Matteo Ferrari (matteo) - webmaster@cantincoro.org

This project has been sponsored by:
* UNLEASHED MIND
  Specialized in consulting and planning of Drupal powered sites, UNLEASHED
  MIND offers installation, development, theming, customization, and hosting
  to get you started. Visit http://www.unleashedmind.com for more information.

