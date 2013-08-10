#

The Textile module allows you to enter content using Textile, a
simple, plain text syntax that is filtered into valid XHTML. The
filter tips found on the filter/tips page of your Drupal site provides
syntax descriptions and examples. If you are using the title module,
you will need to ensure that Textile comes before the title module on
the filter ordering page.

Textile can be enabled on a per-input-format basis.  There is an
option on the configuration page of each input format for indicating
whether or not Textile processing should only occur on text surrounded
by [textile] and (optional) [/textile] tags.  If an input format is
designed or required to use Textile, this option can be disabled, and
all input will be filtered.
