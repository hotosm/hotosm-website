<?php

/**
 * @file
 *
 * File for the long description of the filter format.
 */
function _textile_filter_long_tips() {
    return t('Textile Help

<h2>Block modifier syntax:</h2>

<p>
  CSS attributes can be applied to blocks (paragraphs, headers,
  etc.). CSS classes are specifed with <q><code>(<em>class</em>)</code></q>;
  CSS IDs are specified with <q><code>(#<em>id</em>)</code></q>; both can be
  specified with <q><code>(<em>class</em>#<em>id</em>)</code></q>. An arbtirary
  CSS style can be applied by using
  <q><code>{<em>style</em>}</code></q>. Finally, language attributes are
  applied using <q><code>[<em>language</em>]</code></q>.
</p>
<p>
  Additionally, alignment and indentation shorthands are provided. To
  left-align, right-align, center, and justify text, use
  <q><code>&lt;</code></q>, <q><code>&gt;</code></q>, <q><code>=</code></q>, and
  <q><code>&lt;&gt;</code></q>, respectively. <q><code>(</code></q> left-indents
  a block 1em for each occurrence, and <q><code>)</code></q> right-indents
  similarly.
</p>
<p>
  Tables have additional options. <q><code>^</code></q>, <q><code>-</code></q>,
  and <q><code>~</code></q> specify top, middle, and bottom vertical
  alignment. The <q><code>_</code></q> attribute on a cell indicates that
  it is a table header.
</p>
<p>
  The examples below illustrate these attributes.
</p>

<table>
<tr>
  <th>textile input</th>
  <th>output</th>
</tr>

<tr class="dark">
  <td colspan="2">
    <h3>Headings</h3>
    <code>h<em>x</em>.</code> (where <em>x</em> is 1 - 6)
  </td>
</tr>
<tr class="light">
  <a name="10"></a>
  <td>h1. Heading</td>
  <td><h1>Heading</h1></td>
</tr>
<tr class="light">
  <td>h2(class). Heading with class</td>
  <td><h2 class="class">Heading with class</h2></td>
</tr>

<tr class="dark">
  <td colspan="2"><h3>Paragraphs</h3></td>
</tr>
<tr class="light">
  <td>p=. Centered text</td>
  <td><p style="text-align:center;">Centered text</p></td>
</tr>
<tr class="light">
  <td>p())(#id). Indented text with ID</td>
  <td>
    <p style="padding-left:1em;padding-right:2em;" id="id">Indented
    text with ID</p>
  </td>
</tr>

<tr class="dark">
  <td colspan="2"><h3>Block quotes</h3></td>
</tr>
<tr class="light">
  <td>bq(class#id). Quote with class and ID</td>
  <td>
    <blockquote class="class" id="id">Quote with class and
    ID</blockquote>
  </td>
</tr>
<tr class="light">
  <td>bq[en]. English quote</td>
  <td>
    <blockquote lang="en">English quote</blockquote>
  </td>
</tr>

<tr class="dark">
  <td colspan="2"><h3>Ordered lists</h3></td>
</tr>
<tr class="light">
  <td>
    {color: blue}# Attributes specified<br />
    # before the first item<br />
    # affect the whole list
  </td>
  <td>
    <ol style="color:blue;">
      <li>Attributes specified</li>
      <li>before the first item</li>
      <li>affect the whole list</li>
    </ol>
  </td>
</tr>

<tr class="dark">
  <td colspan="2"><h3>Unordered lists</h3></td>
</tr>
<tr class="light">
  <td>
    * Lists can have<br />
    ## subitems or<br />
    ## sublists<br />
    * too
  </td>
  <td>
    <ul>
      <li>Lists can have
        <ol>
          <li>subitems or</li>
          <li>sublists</li>
        </ol>
      </li>
      <li>too</li>
    </ul>
  </td>
</tr>

<tr class="dark">
  <td colspan="2">
    <h3>Footnotes</h3>
    <code>fn<em>x</em>.</code> (where <em>x</em> is 1 - 100)
  </td>
</tr>
<tr class="light">
  <td>fn17. Footnote</td>
  <td><p id="fn17"><sup>17</sup> Footnote</p></td>
</tr>

<tr class="dark">
  <td colspan="2"><h3>Tables</h3></td>
</tr>
<tr class="light">
  <td>
    |_. A|_. B|_. C|<br />
    (dark). |very|simple|table|<br />
    |&lt;. left|=. center|&gt;. right|<br />
    |^{height:3em}. top|-. middle|~. bottom|
  </td>
  <td>
    <table>
    <tr>
      <th>A</th>
      <th>B</th>
      <th>C</th>
    </tr>
    <tr class="dark">
      <td>very</td>
      <td>simple</td>
      <td>table</td>
    </tr>
    <tr>
      <td style="text-align:left;">left</td>
      <td style="text-align:center;">center</td>
      <td style="text-align:right;">right</td>
    </tr>
    <tr>
      <td style="vertical-align:top;height:3em;">top</td>
      <td style="vertical-align:middle;">middle</td>
      <td style="vertical-align:bottom;">bottom</td>
    </tr>
    </table>
  </td>
</tr>
</table>

<h2>Phrase modifier syntax:</h2>
<p>
  The class, ID, style, and language attributes described above also
  apply to the span phrase modifier as shown below.
</p>

<table>
<tr>
  <th>textile input</th>
  <th>output</th>
</tr>
<tr class="dark">
  <td>_emphasis_</td>
  <td><em>emphasis</em></td>
</tr>
<tr class="light">
  <td>__italic__</td>
  <td><em>italic</em></td>
</tr>
<tr class="dark">
  <td>*strong*</td>
  <td><strong>strong</strong></td>
</tr>
<tr class="light">
  <td>**bold**</td>
  <td><b>bold</bold></td>
</tr>
<tr class="dark">
  <td>??citation??</td>
  <td><cite>citation</cite></td>
</tr>
<tr class="light">
  <td>-delete text-</td>
  <td><del>deleted text</del></td>
</tr>
<tr class="dark">
  <td>+inserted text+</td>
  <td><ins>inserted text</ins></td>
</tr>
<tr class="light">
  <td>^superscript^</td>
  <td><sup>superscript</sup></td>
</tr>
<tr class="dark">
  <td>~subscript~</td>
  <td><sub>subscript</sub></td>
</tr>
<tr class="light">
  <td>@code@</td>
  <td><code>code</code></td>
</tr>
<tr class="dark">
  <td>%(class)span%</td>
  <td><span class="class">span</span></td>
</tr>
<tr class="dark">
  <td>%{color:red;}span%</td>
  <td><span style="color:red;">span</span></td>
</tr>
<tr class="light">
  <td>==no textile==</td>
  <td>no textile</td>
</tr>
<tr class="dark">
  <td>"link text":@url</td>
  <td><a href="@url">link text</a></td>
</tr>
<tr class="light">
  <td>"link text(title)":@url</td>
  <td><a href="@url" title="title">link text</a></td>
</tr>
<tr class="dark">
  <td>&#33@image-url&#33</td>
  <td><img src="@image-url" /></td>
</tr>
<tr class="light">
  <td>&#33@image-url(alt text)&#33</td>
  <td><img src="@image-url" alt="alt text" /></td>
</tr>
<tr class="dark">
  <td>&#33@image-url&#33:@url</td>
  <td><a href="@url"><img src="@image-url" /></a></td>
</tr>
<tr class="light">
  <td>ABC(Always Be Closing)</td>
  <td><acronym title="Always Be Closing">ABC</acronym></td>
</tr>
<tr class="dark">
  <td>Footnote reference[10]</td>
  <td>Footnote reference<sup><a href="#10">10</a></sup></td>
</tr>
</table>', array('@image-url' => url('misc/druplicon.png'), '@url' => 'http://drupal.org'));
}
