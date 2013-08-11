/*
 copyright (c) 2008 Wouter van der Graaf, all rights reserved

 css3-mediaqueries.js - CSS Helper and CSS3 Media Queries Enabler

 author: Wouter van der Graaf <woutervandergraaf at gmail com>
 version: 0.9 (20091001)
 license: MIT
 website: http://woutervandergraaf.nl/css3-mediaqueries-js/

 W3C spec: http://www.w3.org/TR/css3-mediaqueries/

 Note: use of embedded <style> is not recommended when using media queries, because IE  has no way of returning the raw literal css text from a <style> element.
 */


// true prototypal inheritance (http://javascript.crockford.com/prototypal.html)
if (typeof Object.create !== 'function') {
  Object.create = function (o) {
    function F() {}
    F.prototype = o;
    return new F();
  };
}


// user agent sniffing shortcuts
var ua = {
  toString: function () {
    return navigator.userAgent;
  },
  test: function (s) {
    return this.toString().toLowerCase().indexOf(s.toLowerCase()) > -1;
  }
};
ua.version = (ua.toString().toLowerCase().match(/[\s\S]+(?:rv|it|ra|ie)[\/: ]([\d.]+)/) || [])[1];
ua.webkit = ua.test('webkit');
ua.gecko = ua.test('gecko') && !ua.webkit;
ua.opera = ua.test('opera');
ua.ie = ua.test('msie') && !ua.opera;
ua.ie6 = ua.ie && document.compatMode && typeof document.documentElement.style.maxHeight === 'undefined';
ua.ie7 = ua.ie && document.documentElement && typeof document.documentElement.style.maxHeight !== 'undefined' && typeof XDomainRequest === 'undefined';
ua.ie8 = ua.ie && typeof XDomainRequest !== 'undefined';



// initialize when DOM content is loaded
var domReady = function () {
  var fns = [];
  var init = function () {
    if (!arguments.callee.done) { // run init functions once
      arguments.callee.done = true;
      for (var i = 0; i < fns.length; i++) {
        fns[i]();
      }
    }
  };

  // listeners for different browsers
  if (document.addEventListener) {
    document.addEventListener('DOMContentLoaded', init, false);
  }
  if (ua.ie) {
    (function () {
      try {
        // throws errors until after ondocumentready
        document.documentElement.doScroll('left');
      }
      catch (e) {
        setTimeout(arguments.callee, 50);
        return;
      }
      // no errors, fire
      init();
    })();
    // trying to always fire before onload
    document.onreadystatechange = function () {
      if (document.readyState === 'complete') {
        document.onreadystatechange = null;
        init();
      }
    };
  }
  if (ua.webkit && document.readyState) {
    (function () {
      if (document.readyState !== 'loading') {
        init();
      }
      else {
        setTimeout(arguments.callee, 10);
      }
    })();
  }
  window.onload = init; // fallback

  return function (fn) { // add fn to init functions
    if (typeof fn === 'function') {
      // If DOM ready has already been fired, fire the function
      // right away.
      if(init.done) {
        fn();
      } else {
        // Add to the queue
        fns[fns.length] = fn;
      }
    }
    return fn;
  };
}();

// helper library for parsing css to objects
var cssHelper = function () {

  var regExp = {
    BLOCKS: /[^\s{][^{]*\{(?:[^{}]*\{[^{}]*\}[^{}]*|[^{}]*)*\}/g,
    BLOCKS_INSIDE: /[^\s{][^{]*\{[^{}]*\}/g,
    DECLARATIONS: /[a-zA-Z\-]+[^;]*:[^;]+;/g,
    RELATIVE_URLS: /url\(['"]?([^\/\)'"][^:\)'"]+)['"]?\)/g,
    // strip whitespace and comments, @import is evil
    REDUNDANT_COMPONENTS: /(?:\/\*([^*\\\\]|\*(?!\/))+\*\/|@import[^;]+;)/g,
    REDUNDANT_WHITESPACE: /\s*(,|:|;|\{|\})\s*/g,
    MORE_WHITESPACE: /\s{2,}/g,
    FINAL_SEMICOLONS: /;\}/g,
    NOT_WHITESPACE: /\S+/g
  };

  var parsed, parsing = false;

  var waiting = [];
  var wait = function (fn) {
    if (typeof fn === 'function') {
      waiting[waiting.length] = fn;
    }
  };
  var ready = function () {
    for (var i = 0; i < waiting.length; i++) {
      waiting[i](parsed);
    }
  };
  var events = {};
  var broadcast = function (n, v) {
    if (events[n]) {
      var listeners = events[n].listeners;
      if (listeners) {
        for (var i = 0; i < listeners.length; i++) {
          listeners[i](v);
        }
      }
    }
  };

  var requestText = function (url, fnSuccess, fnFailure) {
    if (ua.ie && !window.XMLHttpRequest) {
      window.XMLHttpRequest = function () {
        return new ActiveXObject('Microsoft.XMLHTTP');
      };
    }
    if (!XMLHttpRequest) {
      return '';
    }
    var r = new XMLHttpRequest();
    try {
      r.open('get', url, true);
      r.setRequestHeader('X_REQUESTED_WITH', 'XMLHttpRequest');
    }
    catch (e) {
      fnFailure();
      return;
    }
    var done = false;
    setTimeout(function () {
      done = true;
    }, 5000);
    document.documentElement.style.cursor = 'progress';
    r.onreadystatechange = function () {
      if (r.readyState === 4 && !done) {
        if (!r.status && location.protocol === 'file:' ||
          (r.status >= 200 && r.status < 300) ||
          r.status === 304 ||
          navigator.userAgent.indexOf('Safari') > -1 && typeof r.status === 'undefined') {
          fnSuccess(r.responseText);
        }
        else {
          fnFailure();
        }
        document.documentElement.style.cursor = '';
        r = null; // avoid memory leaks
      }
    };
    r.send('');
  };

  var sanitize = function (text) {
    text = text.replace(regExp.REDUNDANT_COMPONENTS, '');
    text = text.replace(regExp.REDUNDANT_WHITESPACE, '$1');
    text = text.replace(regExp.MORE_WHITESPACE, ' ');
    text = text.replace(regExp.FINAL_SEMICOLONS, '}'); // optional final semicolons
    return text;
  };

  var objects = {

    mediaQueryList: function (s) {
      var o = {};
      var idx = s.indexOf('{');
      var lt = s.substring(0, idx);
      s = s.substring(idx + 1, s.length - 1);
      var mqs = [], rs = [];

      // add media queries
      var qts = lt.toLowerCase().substring(7).split(',');
      for (var i = 0; i < qts.length; i++) { // parse each media query
        mqs[mqs.length] = objects.mediaQuery(qts[i], o);
      }

      // add rule sets
      var rts = s.match(regExp.BLOCKS_INSIDE);
      if (rts !== null) {
        for (i = 0; i < rts.length; i++) {
          rs[rs.length] = objects.rule(rts[i], o);
        }
      }

      o.getMediaQueries = function () {
        return mqs;
      };
      o.getRules = function () {
        return rs;
      };
      o.getListText = function () {
        return lt;
      };
      o.getCssText = function () {
        return s;
      };
      return o;
    },

    mediaQuery: function (s, mql) {
      s = s || '';
      var not = false, type;
      var exp = [];
      var valid = true;
      var tokens = s.match(regExp.NOT_WHITESPACE);
      for (var i = 0; i < tokens.length; i++) {
        var token = tokens[i];
        if (!type && (token === 'not' || token === 'only')) { // 'not' and 'only' keywords
          // keyword 'only' does nothing, as if it was not present
          if (token === 'not') {
            not = true;
          }
        }
        else if (!type) { // media type
          type = token;
        }
        else if (token.charAt(0) === '(') { // media feature expression
          var pair = token.substring(1, token.length - 1).split(':');
          exp[exp.length] = {
            mediaFeature: pair[0],
            value: pair[1] || null
          };
        }
      }

      return {
        getList: function () {
          return mql || null;
        },
        getValid: function () {
          return valid;
        },
        getNot: function () {
          return not;
        },
        getMediaType: function () {
          return type;
        },
        getExpressions: function () {
          return exp;
        }
      };
    },

    rule: function (s, mql) {
      var o = {};
      var idx = s.indexOf('{');
      var st = s.substring(0, idx);
      var ss = st.split(',');
      var ds = [];
      var dts = s.substring(idx + 1, s.length - 1).split(';');
      for (var i = 0; i < dts.length; i++) {
        ds[ds.length] = objects.declaration(dts[i], o);
      }

      o.getMediaQueryList = function () {
        return mql || null;
      };
      o.getSelectors = function () {
        return ss;
      };
      o.getSelectorText = function () {
        return st;
      };
      o.getDeclarations = function () {
        return ds;
      };
      o.getPropertyValue = function (n) {
        for (var i = 0; i < ds.length; i++) {
          if (ds[i].getProperty() === n) {
            return ds[i].getValue();
          }
        }
        return null;
      };
      return o;
    },

    declaration: function (s, r) {
      var idx = s.indexOf(':');
      var p = s.substring(0, idx);
      var v = s.substring(idx + 1);
      return {
        getRule: function () {
          return r || null;
        },
        getProperty: function () {
          return p;
        },
        getValue: function () {
          return v;
        }
      };
    }
  };

  var parseText = function (el) {
    if (typeof el.cssHelperText !== 'string') {
      return;
    }
    var o = {
      mediaQueryLists: [],
      rules: [],
      selectors: {},
      declarations: [],
      properties: {}
    };

    // parse blocks and collect media query lists and rules
    var mqls = o.mediaQueryLists;
    var ors = o.rules;
    var blocks = el.cssHelperText.match(regExp.BLOCKS);
    if (blocks !== null) {
      for (var i = 0; i < blocks.length; i++) {
        if (blocks[i].substring(0, 7) === '@media ') { // media query (list)
          mqls[mqls.length] = objects.mediaQueryList(blocks[i]);
          ors = o.rules = ors.concat(mqls[mqls.length - 1].getRules());
        }
        else { // regular rule set, page context (@page) or font description (@font-face)
          ors[ors.length] = objects.rule(blocks[i]);
        }
      }
    }

    // collect selectors
    var oss = o.selectors;
    var collectSelectors = function (r) {
      var ss = r.getSelectors();
      for (var i = 0; i < ss.length; i++) {
        var n = ss[i];
        if (!oss[n]) {
          oss[n] = [];
        }
        oss[n][oss[n].length] = r;
      }
    };
    for (i = 0; i < ors.length; i++) {
      collectSelectors(ors[i]);
    }

    // collect declarations
    var ods = o.declarations;
    for (i = 0; i < ors.length; i++) {
      ods = o.declarations = ods.concat(ors[i].getDeclarations());
    }

    // collect properties
    var ops = o.properties;
    for (i = 0; i < ods.length; i++) {
      var n = ods[i].getProperty();
      if (!ops[n]) {
        ops[n] = [];
      }
      ops[n][ops[n].length] = ods[i];
    }

    el.cssHelperParsed = o;
    parsed[parsed.length] = el;
    return o;
  };

  var parseEmbedded = function (el, s) {
    el.cssHelperText = sanitize(s || el.innerHTML); // bug in IE, where innerHTML gives us parsed css instead of raw literal
    return parseText(el);
  };

  var parse = function () {
    parsing = true;
    parsed = [];
    var linked = [];
    var finish = function () {
      for (var i = 0; i < linked.length; i++) {
        parseText(linked[i]);
      }
      var styles = document.getElementsByTagName('style');
      for (i = 0; i < styles.length; i++) {
        parseEmbedded(styles[i]);
      }
      parsing = false;
      ready();
    };
    var links = document.getElementsByTagName('link');
    for (var i = 0; i < links.length; i++) {
      var link = links[i];
      if (link.getAttribute('rel').indexOf('style') > -1 && link.href && link.href.length !== 0 && !link.disabled) {
        linked[linked.length] = link;
      }
    }
    if (linked.length > 0) {
      var c = 0;
      var checkForFinish = function () {
        c++;
        if (c === linked.length) { // parse in right order, so after last link is read
          finish();
        }
      };
      var processLink = function (link) {
        var href = link.href;
        requestText(href, function (text) {
          // fix url's
          text = sanitize(text).replace(regExp.RELATIVE_URLS, 'url(' + href.substring(0, href.lastIndexOf('/')) + '/$1)');
          link.cssHelperText = text;
          checkForFinish();
        }, checkForFinish);
      };
      for (i = 0; i < linked.length; i++) {
        processLink(linked[i]);
      }
    }
    else {
      finish();
    }
  };

  var types = {
    mediaQueryLists: 'array',
    rules: 'array',
    selectors: 'object',
    declarations: 'array',
    properties: 'object'
  };

  var collections = {
    mediaQueryLists: null,
    rules: null,
    selectors: null,
    declarations: null,
    properties: null
  };

  var addToCollection = function (name, v) {
    if (collections[name] !== null) {
      if (types[name] === 'array') {
        return (collections[name] = collections[name].concat(v));
      }
      else {
        var c = collections[name];
        for (var n in v) {
          if (v.hasOwnProperty(n)) {
            if (!c[n]) {
              c[n] = v[n];
            }
            else {
              c[n] = c[n].concat(v[n]);
            }
          }
        }
        return c;
      }
    }
  };

  var collect = function (name) {
    collections[name] = (types[name] === 'array') ? [] : {};
    for (var i = 0; i < parsed.length; i++) {
      addToCollection(name, parsed[i].cssHelperParsed[name]);
    }
    return collections[name];
  };

  // timer for broadcasting added elements
  domReady(function () {
    var els = document.body.getElementsByTagName('*');
    for (var i = 0; i < els.length; i++) {
      els[i].checkedByCssHelper = true;
    }

    if (document.implementation.hasFeature('MutationEvents', '2.0') || window.MutationEvent) {
      document.body.addEventListener('DOMNodeInserted', function (e) {
        var el = e.target;
        if (el.nodeType === 1) {
          broadcast('DOMElementInserted', el);
          el.checkedByCssHelper = true;
        }
      }, false);
    }
    else {
      setInterval(function () {
        var els = document.body.getElementsByTagName('*');
        for (var i = 0; i < els.length; i++) {
          if (!els[i].checkedByCssHelper) {
            broadcast('DOMElementInserted', els[i]);
            els[i].checkedByCssHelper = true;
          }
        }
      }, 1000);
    }
  });

  // viewport size
  var getViewportSize = function (d) {
    if (typeof window.innerWidth != 'undefined') {
      return window["inner" + d];
    }
    else if (typeof document.documentElement != 'undefined'
      && typeof document.documentElement.clientWidth != 'undefined'
      && document.documentElement.clientWidth != 0) {
      return document.documentElement["client" + d];
    }
  };

  // public static functions
  return {
    addStyle: function (s, process) {
      var el = document.createElement('style');
      el.setAttribute('type', 'text/css');
      document.getElementsByTagName('head')[0].appendChild(el);
      if (el.styleSheet) { // IE
        try {
          el.styleSheet.cssText = s;
        } catch (e) {} // IE will generate errors if it doesn't like the CSS; unless we try/catch here all processing will stop.
      }
      else {
        el.appendChild(document.createTextNode(s));
      }
      el.addedWithCssHelper = true;
      if (typeof process === 'undefined' || process === true) {
        cssHelper.parsed(function (parsed) {
          var o = parseEmbedded(el, s);
          for (var n in o) {
            if (o.hasOwnProperty(n)) {
              addToCollection(n, o[n]);
            }
          }
          broadcast('newStyleParsed', el);
        });
      }
      else {
        el.parsingDisallowed = true;
      }
      return el;
    },

    removeStyle: function (el) {
      return el.parentNode.removeChild(el);
    },

    parsed: function (fn) {
      if (parsing) {
        wait(fn);
      }
      else {
        if (typeof parsed !== 'undefined') {
          if (typeof fn === 'function') {
            fn(parsed);
          }
        }
        else {
          wait(fn);
          parse();
        }
      }
    },

    mediaQueryLists: function (fn) {
      cssHelper.parsed(function (parsed) {
        fn(collections.mediaQueryLists || collect('mediaQueryLists'));
      });
    },

    rules: function (fn) {
      cssHelper.parsed(function (parsed) {
        fn(collections.rules || collect('rules'));
      });
    },

    selectors: function (fn) {
      cssHelper.parsed(function (parsed) {
        fn(collections.selectors || collect('selectors'));
      });
    },

    declarations: function (fn) {
      cssHelper.parsed(function (parsed) {
        fn(collections.declarations || collect('declarations'));
      });
    },

    properties: function (fn) {
      cssHelper.parsed(function (parsed) {
        fn(collections.properties || collect('properties'));
      });
    },

    broadcast: broadcast,

    addListener: function (n, fn) { // in case n is 'styleadd': added function is called everytime style is added and parsed
      if (typeof fn === 'function') {
        if (!events[n]) {
          events[n] = {
            listeners: []
          };
        }
        events[n].listeners[events[n].listeners.length] = fn;
      }
    },

    removeListener: function (n, fn) {
      if (typeof fn === 'function' && events[n]) {
        var ls = events[n].listeners;
        for (var i = 0; i < ls.length; i++) {
          if (ls[i] === fn) {
            ls.splice(i, 1);
            i -= 1;
          }
        }
      }
    },

    getViewportWidth: function () {
      return getViewportSize("Width");
    },

    getViewportHeight: function () {
      return getViewportSize("Height");
    }
  };
}();



// function to test and apply parsed media queries against browser capabilities
domReady(function enableCssMediaQueries() {
  var meter;

  var regExp = {
    LENGTH_UNIT: /[0-9]+(em|ex|px|in|cm|mm|pt|pc)$/,
    RESOLUTION_UNIT: /[0-9]+(dpi|dpcm)$/,
    ASPECT_RATIO: /^[0-9]+\/[0-9]+$/,
    ABSOLUTE_VALUE: /^[0-9]*(\.[0-9]+)*$/
  };

  var styles = [];

  var nativeSupport = function () {
    // check support for media queries
    var id = 'css3-mediaqueries-test';
    var el = document.createElement('div');
    el.id = id;
    var style = cssHelper.addStyle('@media all and (width) { #' + id +
      ' { width: 1px !important; } }', false); // false means don't parse this temp style
    document.body.appendChild(el);
    var ret = el.offsetWidth === 1;
    style.parentNode.removeChild(style);
    el.parentNode.removeChild(el);
    nativeSupport = function () {
      return ret;
    };
    return ret;
  };

  var createMeter = function () { // create measuring element
    meter = document.createElement('div');
    meter.style.cssText = 'position:absolute;top:-9999em;left:-9999em;' +
      'margin:0;border:none;padding:0;width:1em;font-size:1em;'; // cssText is needed for IE, works for the others
    document.body.appendChild(meter);
    // meter must have browser default font size of 16px
    if (meter.offsetWidth !== 16) {
      meter.style.fontSize = 16 / meter.offsetWidth + 'em';
    }
    meter.style.width = '';
  };

  var measure = function (value) {
    meter.style.width = value;
    var amount = meter.offsetWidth;
    meter.style.width = '';
    return amount;
  };

  var testMediaFeature = function (feature, value) {
    // non-testable features: monochrome|min-monochrome|max-monochrome|scan|grid
    var l = feature.length;
    var min = (feature.substring(0, 4) === 'min-');
    var max = (!min && feature.substring(0, 4) === 'max-');

    if (value !== null) { // determine value type and parse to usable amount
      var valueType;
      var amount;
      if (regExp.LENGTH_UNIT.exec(value)) {
        valueType = 'length';
        amount = measure(value);
      }
      else if (regExp.RESOLUTION_UNIT.exec(value)) {
        valueType = 'resolution';
        amount = parseInt(value, 10);
        var unit = value.substring((amount + '').length);
      }
      else if (regExp.ASPECT_RATIO.exec(value)) {
        valueType = 'aspect-ratio';
        amount = value.split('/');
      }
      else if (regExp.ABSOLUTE_VALUE) {
        valueType = 'absolute';
        amount = value;
      }
      else {
        valueType = 'unknown';
      }
    }

    var width, height;
    if ('device-width' === feature.substring(l - 12, l)) { // screen width
      width = screen.width;
      if (value !== null) {
        if (valueType === 'length') {
          return ((min && width >= amount) || (max && width < amount) || (!min && !max && width === amount));
        }
        else {
          return false;
        }
      }
      else { // test width without value
        return width > 0;
      }
    }
    else if ('device-height' === feature.substring(l - 13, l)) { // screen height
      height = screen.height;
      if (value !== null) {
        if (valueType === 'length') {
          return ((min && height >= amount) || (max && height < amount) || (!min && !max && height === amount));
        }
        else {
          return false;
        }
      }
      else { // test height without value
        return height > 0;
      }
    }
    else if ('width' === feature.substring(l - 5, l)) { // viewport width
      width = document.documentElement.clientWidth || document.body.clientWidth; // the latter for IE quirks mode
      if (value !== null) {
        if (valueType === 'length') {
          return ((min && width >= amount) || (max && width < amount) || (!min && !max && width === amount));
        }
        else {
          return false;
        }
      }
      else { // test width without value
        return width > 0;
      }
    }
    else if ('height' === feature.substring(l - 6, l)) { // viewport height
      height = document.documentElement.clientHeight || document.body.clientHeight; // the latter for IE quirks mode
      if (value !== null) {
        if (valueType === 'length') {
          return ((min && height >= amount) || (max && height < amount) || (!min && !max && height === amount));
        }
        else {
          return false;
        }
      }
      else { // test height without value
        return height > 0;
      }
    }
    else if ('orientation' === feature.substring(l - 11, l)) { // orientation

      width = document.documentElement.clientWidth || document.body.clientWidth; // the latter for IE quirks mode
      height = document.documentElement.clientHeight || document.body.clientHeight; // the latter for IE quirks mode

      if (valueType === 'absolute') {
        return (amount === 'portrait') ? (width <= height) : (width > height);
      }
      else {
        return false;
      }
    }
    else if ('aspect-ratio' === feature.substring(l - 12, l)) { // window aspect ratio
      width = document.documentElement.clientWidth || document.body.clientWidth; // the latter for IE quirks mode
      height = document.documentElement.clientHeight || document.body.clientHeight; // the latter for IE quirks mode

      var curRatio = width / height;
      var ratio = amount[1] / amount[0];

      if (valueType === 'aspect-ratio') {
        return ((min && curRatio >= ratio) || (max && curRatio < ratio) || (!min && !max && curRatio === ratio));
      }
      else {
        return false;
      }
    }
    else if ('device-aspect-ratio' === feature.substring(l - 19, l)) { // screen aspect ratio
      return valueType === 'aspect-ratio' && screen.width * amount[1] === screen.height * amount[0];
    }
    else if ('color-index' === feature.substring(l - 11, l)) { // number of colors
      var colors = Math.pow(2, screen.colorDepth);
      if (value !== null) {
        if (valueType === 'absolute') {
          return ((min && colors >= amount) || (max && colors < amount) || (!min && !max && colors === amount));
        }
        else {
          return false;
        }
      }
      else { // test height without value
        return colors > 0;
      }
    }
    else if ('color' === feature.substring(l - 5, l)) { // bits per color component
      var color = screen.colorDepth;
      if (value !== null) {
        if (valueType === 'absolute') {
          return ((min && color >= amount) || (max && color < amount) || (!min && !max && color === amount));
        }
        else {
          return false;
        }
      }
      else { // test height without value
        return color > 0;
      }
    }
    else if ('resolution' === feature.substring(l - 10, l)) {
      var res;
      if (unit === 'dpcm') {
        res = measure('1cm');
      }
      else {
        res = measure('1in');
      }
      if (value !== null) {
        if (valueType === 'resolution') {
          return ((min && res >= amount) || (max && res < amount) || (!min && !max && res === amount));
        }
        else {
          return false;
        }
      }
      else { // test height without value
        return res > 0;
      }
    }
    else {
      return false;
    }
  };

  var testMediaQuery = function (mq) {
    var test = mq.getValid();
    var expressions = mq.getExpressions();
    var l = expressions.length;
    if (l > 0) {
      for (var i = 0; i < l && test; i++) {
        test = testMediaFeature(expressions[i].mediaFeature, expressions[i].value);
      }
      var not = mq.getNot();
      return (test && !not || not && !test);
    }
  };

  var testMediaQueryList = function (mql) {
    var mqs = mql.getMediaQueries();
    var t = {};
    for (var i = 0; i < mqs.length; i++) {
      if (testMediaQuery(mqs[i])) {
        t[mqs[i].getMediaType()] = true;
      }
    }
    var s = [], c = 0;
    for (var n in t) {
      if (t.hasOwnProperty(n)) {
        if (c > 0) {
          s[c++] = ',';
        }
        s[c++] = n;
      }
    }
    if (s.length > 0) {
      styles[styles.length] = cssHelper.addStyle('@media ' + s.join('') + '{' + mql.getCssText() + '}', false);
    }
  };

  var testMediaQueryLists = function (mqls) {
    for (var i = 0; i < mqls.length; i++) {
      testMediaQueryList(mqls[i]);
    }
    if (ua.ie) {
      // force repaint in IE
      document.documentElement.style.display = 'block';
      setTimeout(function () {
        document.documentElement.style.display = '';
      }, 0);
      // delay broadcast somewhat for IE
      setTimeout(function () {
        cssHelper.broadcast('cssMediaQueriesTested');
      }, 100);
    }
    else {
      cssHelper.broadcast('cssMediaQueriesTested');
    }
  };

  var test = function () {
    for (var i = 0; i < styles.length; i++) {
      cssHelper.removeStyle(styles[i]);
    }
    styles = [];
    cssHelper.mediaQueryLists(testMediaQueryLists);
  };

  var scrollbarWidth = 0;
  var checkForResize = function () {
    var cvpw = cssHelper.getViewportWidth();
    var cvph = cssHelper.getViewportHeight();

    // determine scrollbar width in IE, see resizeHandler
    if (ua.ie) {
      var el = document.createElement('div');
      el.style.width = '100px';
      el.style.height = '100px';
      el.style.position = 'absolute';
      el.style.top = '-9999em';
      el.style.overflow = 'scroll';
      document.body.appendChild(el);
      scrollbarWidth = el.offsetWidth - el.clientWidth;
      document.body.removeChild(el);
    }

    var timer;
    var resizeHandler = function () {
      var vpw = cssHelper.getViewportWidth();
      var vph = cssHelper.getViewportHeight();
      // check whether vp size has really changed, because IE also triggers resize event when body size changes
      // 20px allowance to accomodate short appearance of scrollbars in IE in some cases
      if (Math.abs(vpw - cvpw) > scrollbarWidth || Math.abs(vph - cvph) > scrollbarWidth) {
        cvpw = vpw;
        cvph = vph;
        clearTimeout(timer);
        timer = setTimeout(function () {
          if (!nativeSupport()) {
            test();
          }
          else {
            cssHelper.broadcast('cssMediaQueriesTested');
          }
        }, 500);
      }
    };

    window.onresize = function () {
      var x = window.onresize || function () {}; // save original
      return function () {
        x();
        resizeHandler();
      };
    }();
  };

  // prevent jumping of layout by hiding everything before painting <body>
  var docEl = document.documentElement;
  docEl.style.marginLeft = '-32767px';

  // make sure it comes back after a while
  setTimeout(function () {
    docEl.style.marginTop = '';
  }, 20000);

  return function () {
    if (!nativeSupport()) { // if browser doesn't support media queries
      cssHelper.addListener('newStyleParsed', function (el) {
        testMediaQueryLists(el.cssHelperParsed.mediaQueryLists);
      });
      // return visibility after media queries are tested
      cssHelper.addListener('cssMediaQueriesTested', function () {
        // force repaint in IE by changing width
        if (ua.ie) {
          docEl.style.width = '1px';
        }if(typeof Object.create!=="function"){
Object.create=function(o){
function F(){
};
F.prototype=o;
return new F();
};
}
var ua={toString:function(){
return navigator.userAgent;
},test:function(s){
return this.toString().toLowerCase().indexOf(s.toLowerCase())>-1;
}};
ua.version=(ua.toString().toLowerCase().match(/[\s\S]+(?:rv|it|ra|ie)[\/: ]([\d.]+)/)||[])[1];
ua.webkit=ua.test("webkit");
ua.gecko=ua.test("gecko")&&!ua.webkit;
ua.opera=ua.test("opera");
ua.ie=ua.test("msie")&&!ua.opera;
ua.ie6=ua.ie&&document.compatMode&&typeof document.documentElement.style.maxHeight==="undefined";
ua.ie7=ua.ie&&document.documentElement&&typeof document.documentElement.style.maxHeight!=="undefined"&&typeof XDomainRequest==="undefined";
ua.ie8=ua.ie&&typeof XDomainRequest!=="undefined";
var domReady=function(){
var _1=[];
var _2=function(){
if(!arguments.callee.done){
arguments.callee.done=true;
for(var i=0;i<_1.length;i++){
_1[i]();
}
}
};
if(document.addEventListener){
document.addEventListener("DOMContentLoaded",_2,false);
}
if(ua.ie){
(function(){
try{
document.documentElement.doScroll("left");
}
catch(e){
setTimeout(arguments.callee,50);
return;
}
_2();
})();
document.onreadystatechange=function(){
if(document.readyState==="complete"){
document.onreadystatechange=null;
_2();
}
};
}
if(ua.webkit&&document.readyState){
(function(){
if(document.readyState!=="loading"){
_2();
}else{
setTimeout(arguments.callee,10);
}
})();
}
window.onload=_2;
return function(fn){
if(typeof fn==="function"){
_1[_1.length]=fn;
}
return fn;
};
}();
var cssHelper=function(){
var _3={BLOCKS:/[^\s{][^{]*\{(?:[^{}]*\{[^{}]*\}[^{}]*|[^{}]*)*\}/g,BLOCKS_INSIDE:/[^\s{][^{]*\{[^{}]*\}/g,DECLARATIONS:/[a-zA-Z\-]+[^;]*:[^;]+;/g,RELATIVE_URLS:/url\(['"]?([^\/\)'"][^:\)'"]+)['"]?\)/g,REDUNDANT_COMPONENTS:/(?:\/\*([^*\\\\]|\*(?!\/))+\*\/|@import[^;]+;)/g,REDUNDANT_WHITESPACE:/\s*(,|:|;|\{|\})\s*/g,MORE_WHITESPACE:/\s{2,}/g,FINAL_SEMICOLONS:/;\}/g,NOT_WHITESPACE:/\S+/g};
var _4,_5=false;
var _6=[];
var _7=function(fn){
if(typeof fn==="function"){
_6[_6.length]=fn;
}
};
var _8=function(){
for(var i=0;i<_6.length;i++){
_6[i](_4);
}
};
var _9={};
var _a=function(n,v){
if(_9[n]){
var _b=_9[n].listeners;
if(_b){
for(var i=0;i<_b.length;i++){
_b[i](v);
}
}
}
};
var _c=function(_d,_e,_f){
if(ua.ie&&!window.XMLHttpRequest){
window.XMLHttpRequest=function(){
return new ActiveXObject("Microsoft.XMLHTTP");
};
}
if(!XMLHttpRequest){
return "";
}
var r=new XMLHttpRequest();
try{
r.open("get",_d,true);
r.setRequestHeader("X_REQUESTED_WITH","XMLHttpRequest");
}
catch(e){
_f();
return;
}
var _10=false;
setTimeout(function(){
_10=true;
},5000);
document.documentElement.style.cursor="progress";
r.onreadystatechange=function(){
if(r.readyState===4&&!_10){
if(!r.status&&location.protocol==="file:"||(r.status>=200&&r.status<300)||r.status===304||navigator.userAgent.indexOf("Safari")>-1&&typeof r.status==="undefined"){
_e(r.responseText);
}else{
_f();
}
document.documentElement.style.cursor="";
r=null;
}
};
r.send("");
};
var _11=function(_12){
_12=_12.replace(_3.REDUNDANT_COMPONENTS,"");
_12=_12.replace(_3.REDUNDANT_WHITESPACE,"$1");
_12=_12.replace(_3.MORE_WHITESPACE," ");
_12=_12.replace(_3.FINAL_SEMICOLONS,"}");
return _12;
};
var _13={mediaQueryList:function(s){
var o={};
var idx=s.indexOf("{");
var lt=s.substring(0,idx);
s=s.substring(idx+1,s.length-1);
var mqs=[],rs=[];
var qts=lt.toLowerCase().substring(7).split(",");
for(var i=0;i<qts.length;i++){
mqs[mqs.length]=_13.mediaQuery(qts[i],o);
}
var rts=s.match(_3.BLOCKS_INSIDE);
if(rts!==null){
for(i=0;i<rts.length;i++){
rs[rs.length]=_13.rule(rts[i],o);
}
}
o.getMediaQueries=function(){
return mqs;
};
o.getRules=function(){
return rs;
};
o.getListText=function(){
return lt;
};
o.getCssText=function(){
return s;
};
return o;
},mediaQuery:function(s,mql){
s=s||"";
var not=false,_14;
var exp=[];
var _15=true;
var _16=s.match(_3.NOT_WHITESPACE);
for(var i=0;i<_16.length;i++){
var _17=_16[i];
if(!_14&&(_17==="not"||_17==="only")){
if(_17==="not"){
not=true;
}
}else{
if(!_14){
_14=_17;
}else{
if(_17.charAt(0)==="("){
var _18=_17.substring(1,_17.length-1).split(":");
exp[exp.length]={mediaFeature:_18[0],value:_18[1]||null};
}
}
}
}
return {getList:function(){
return mql||null;
},getValid:function(){
return _15;
},getNot:function(){
return not;
},getMediaType:function(){
return _14;
},getExpressions:function(){
return exp;
}};
},rule:function(s,mql){
var o={};
var idx=s.indexOf("{");
var st=s.substring(0,idx);
var ss=st.split(",");
var ds=[];
var dts=s.substring(idx+1,s.length-1).split(";");
for(var i=0;i<dts.length;i++){
ds[ds.length]=_13.declaration(dts[i],o);
}
o.getMediaQueryList=function(){
return mql||null;
};
o.getSelectors=function(){
return ss;
};
o.getSelectorText=function(){
return st;
};
o.getDeclarations=function(){
return ds;
};
o.getPropertyValue=function(n){
for(var i=0;i<ds.length;i++){
if(ds[i].getProperty()===n){
return ds[i].getValue();
}
}
return null;
};
return o;
},declaration:function(s,r){
var idx=s.indexOf(":");
var p=s.substring(0,idx);
var v=s.substring(idx+1);
return {getRule:function(){
return r||null;
},getProperty:function(){
return p;
},getValue:function(){
return v;
}};
}};
var _19=function(el){
if(typeof el.cssHelperText!=="string"){
return;
}
var o={mediaQueryLists:[],rules:[],selectors:{},declarations:[],properties:{}};
var _1a=o.mediaQueryLists;
var ors=o.rules;
var _1b=el.cssHelperText.match(_3.BLOCKS);
if(_1b!==null){
for(var i=0;i<_1b.length;i++){
if(_1b[i].substring(0,7)==="@media "){
_1a[_1a.length]=_13.mediaQueryList(_1b[i]);
ors=o.rules=ors.concat(_1a[_1a.length-1].getRules());
}else{
ors[ors.length]=_13.rule(_1b[i]);
}
}
}
var oss=o.selectors;
var _1c=function(r){
var ss=r.getSelectors();
for(var i=0;i<ss.length;i++){
var n=ss[i];
if(!oss[n]){
oss[n]=[];
}
oss[n][oss[n].length]=r;
}
};
for(i=0;i<ors.length;i++){
_1c(ors[i]);
}
var ods=o.declarations;
for(i=0;i<ors.length;i++){
ods=o.declarations=ods.concat(ors[i].getDeclarations());
}
var ops=o.properties;
for(i=0;i<ods.length;i++){
var n=ods[i].getProperty();
if(!ops[n]){
ops[n]=[];
}
ops[n][ops[n].length]=ods[i];
}
el.cssHelperParsed=o;
_4[_4.length]=el;
return o;
};
var _1d=function(el,s){
el.cssHelperText=_11(s||el.innerHTML);
return _19(el);
};
var _1e=function(){
_5=true;
_4=[];
var _1f=[];
var _20=function(){
for(var i=0;i<_1f.length;i++){
_19(_1f[i]);
}
var _21=document.getElementsByTagName("style");
for(i=0;i<_21.length;i++){
_1d(_21[i]);
}
_5=false;
_8();
};
var _22=document.getElementsByTagName("link");
for(var i=0;i<_22.length;i++){
var _23=_22[i];
if(_23.getAttribute("rel").indexOf("style")>-1&&_23.href&&_23.href.length!==0&&!_23.disabled){
_1f[_1f.length]=_23;
}
}
if(_1f.length>0){
var c=0;
var _24=function(){
c++;
if(c===_1f.length){
_20();
}
};
var _25=function(_26){
var _27=_26.href;
_c(_27,function(_28){
_28=_11(_28).replace(_3.RELATIVE_URLS,"url("+_27.substring(0,_27.lastIndexOf("/"))+"/$1)");
_26.cssHelperText=_28;
_24();
},_24);
};
for(i=0;i<_1f.length;i++){
_25(_1f[i]);
}
}else{
_20();
}
};
var _29={mediaQueryLists:"array",rules:"array",selectors:"object",declarations:"array",properties:"object"};
var _2a={mediaQueryLists:null,rules:null,selectors:null,declarations:null,properties:null};
var _2b=function(_2c,v){
if(_2a[_2c]!==null){
if(_29[_2c]==="array"){
return (_2a[_2c]=_2a[_2c].concat(v));
}else{
var c=_2a[_2c];
for(var n in v){
if(v.hasOwnProperty(n)){
if(!c[n]){
c[n]=v[n];
}else{
c[n]=c[n].concat(v[n]);
}
}
}
return c;
}
}
};
var _2d=function(_2e){
_2a[_2e]=(_29[_2e]==="array")?[]:{};
for(var i=0;i<_4.length;i++){
_2b(_2e,_4[i].cssHelperParsed[_2e]);
}
return _2a[_2e];
};
domReady(function(){
var els=document.body.getElementsByTagName("*");
for(var i=0;i<els.length;i++){
els[i].checkedByCssHelper=true;
}
if(document.implementation.hasFeature("MutationEvents","2.0")||window.MutationEvent){
document.body.addEventListener("DOMNodeInserted",function(e){
var el=e.target;
if(el.nodeType===1){
_a("DOMElementInserted",el);
el.checkedByCssHelper=true;
}
},false);
}else{
setInterval(function(){
var els=document.body.getElementsByTagName("*");
for(var i=0;i<els.length;i++){
if(!els[i].checkedByCssHelper){
_a("DOMElementInserted",els[i]);
els[i].checkedByCssHelper=true;
}
}
},1000);
}
});
var _2f=function(d){
if(typeof window.innerWidth!="undefined"){
return window["inner"+d];
}else{
if(typeof document.documentElement!="undefined"&&typeof document.documentElement.clientWidth!="undefined"&&document.documentElement.clientWidth!=0){
return document.documentElement["client"+d];
}
}
};
return {addStyle:function(s,_30){
var el=document.createElement("style");
el.setAttribute("type","text/css");
document.getElementsByTagName("head")[0].appendChild(el);
if(el.styleSheet){
el.styleSheet.cssText=s;
}else{
el.appendChild(document.createTextNode(s));
}
el.addedWithCssHelper=true;
if(typeof _30==="undefined"||_30===true){
cssHelper.parsed(function(_31){
var o=_1d(el,s);
for(var n in o){
if(o.hasOwnProperty(n)){
_2b(n,o[n]);
}
}
_a("newStyleParsed",el);
});
}else{
el.parsingDisallowed=true;
}
return el;
},removeStyle:function(el){
return el.parentNode.removeChild(el);
},parsed:function(fn){
if(_5){
_7(fn);
}else{
if(typeof _4!=="undefined"){
if(typeof fn==="function"){
fn(_4);
}
}else{
_7(fn);
_1e();
}
}
},mediaQueryLists:function(fn){
cssHelper.parsed(function(_32){
fn(_2a.mediaQueryLists||_2d("mediaQueryLists"));
});
},rules:function(fn){
cssHelper.parsed(function(_33){
fn(_2a.rules||_2d("rules"));
});
},selectors:function(fn){
cssHelper.parsed(function(_34){
fn(_2a.selectors||_2d("selectors"));
});
},declarations:function(fn){
cssHelper.parsed(function(_35){
fn(_2a.declarations||_2d("declarations"));
});
},properties:function(fn){
cssHelper.parsed(function(_36){
fn(_2a.properties||_2d("properties"));
});
},broadcast:_a,addListener:function(n,fn){
if(typeof fn==="function"){
if(!_9[n]){
_9[n]={listeners:[]};
}
_9[n].listeners[_9[n].listeners.length]=fn;
}
},removeListener:function(n,fn){
if(typeof fn==="function"&&_9[n]){
var ls=_9[n].listeners;
for(var i=0;i<ls.length;i++){
if(ls[i]===fn){
ls.splice(i,1);
i-=1;
}
}
}
},getViewportWidth:function(){
return _2f("Width");
},getViewportHeight:function(){
return _2f("Height");
}};
}();
domReady(function enableCssMediaQueries(){
var _37;
var _38={LENGTH_UNIT:/[0-9]+(em|ex|px|in|cm|mm|pt|pc)$/,RESOLUTION_UNIT:/[0-9]+(dpi|dpcm)$/,ASPECT_RATIO:/^[0-9]+\/[0-9]+$/,ABSOLUTE_VALUE:/^[0-9]*(\.[0-9]+)*$/};
var _39=[];
var _3a=function(){
var id="css3-mediaqueries-test";
var el=document.createElement("div");
el.id=id;
var _3b=cssHelper.addStyle("@media all and (width) { #"+id+" { width: 1px !important; } }",false);
document.body.appendChild(el);
var ret=el.offsetWidth===1;
_3b.parentNode.removeChild(_3b);
el.parentNode.removeChild(el);
_3a=function(){
return ret;
};
return ret;
};
var _3c=function(){
_37=document.createElement("div");
_37.style.cssText="position:absolute;top:-9999em;left:-9999em;"+"margin:0;border:none;padding:0;width:1em;font-size:1em;";
document.body.appendChild(_37);
if(_37.offsetWidth!==16){
_37.style.fontSize=16/_37.offsetWidth+"em";
}
_37.style.width="";
};
var _3d=function(_3e){
_37.style.width=_3e;
var _3f=_37.offsetWidth;
_37.style.width="";
return _3f;
};
var _40=function(_41,_42){
var l=_41.length;
var min=(_41.substring(0,4)==="min-");
var max=(!min&&_41.substring(0,4)==="max-");
if(_42!==null){
var _43;
var _44;
if(_38.LENGTH_UNIT.exec(_42)){
_43="length";
_44=_3d(_42);
}else{
if(_38.RESOLUTION_UNIT.exec(_42)){
_43="resolution";
_44=parseInt(_42,10);
var _45=_42.substring((_44+"").length);
}else{
if(_38.ASPECT_RATIO.exec(_42)){
_43="aspect-ratio";
_44=_42.split("/");
}else{
if(_38.ABSOLUTE_VALUE){
_43="absolute";
_44=_42;
}else{
_43="unknown";
}
}
}
}
}
var _46,_47;
if("device-width"===_41.substring(l-12,l)){
_46=screen.width;
if(_42!==null){
if(_43==="length"){
return ((min&&_46>=_44)||(max&&_46<_44)||(!min&&!max&&_46===_44));
}else{
return false;
}
}else{
return _46>0;
}
}else{
if("device-height"===_41.substring(l-13,l)){
_47=screen.height;
if(_42!==null){
if(_43==="length"){
return ((min&&_47>=_44)||(max&&_47<_44)||(!min&&!max&&_47===_44));
}else{
return false;
}
}else{
return _47>0;
}
}else{
if("width"===_41.substring(l-5,l)){
_46=document.documentElement.clientWidth||document.body.clientWidth;
if(_42!==null){
if(_43==="length"){
return ((min&&_46>=_44)||(max&&_46<_44)||(!min&&!max&&_46===_44));
}else{
return false;
}
}else{
return _46>0;
}
}else{
if("height"===_41.substring(l-6,l)){
_47=document.documentElement.clientHeight||document.body.clientHeight;
if(_42!==null){
if(_43==="length"){
return ((min&&_47>=_44)||(max&&_47<_44)||(!min&&!max&&_47===_44));
}else{
return false;
}
}else{
return _47>0;
}
}else{
if("device-aspect-ratio"===_41.substring(l-19,l)){
return _43==="aspect-ratio"&&screen.width*_44[1]===screen.height*_44[0];
}else{
if("color-index"===_41.substring(l-11,l)){
var _48=Math.pow(2,screen.colorDepth);
if(_42!==null){
if(_43==="absolute"){
return ((min&&_48>=_44)||(max&&_48<_44)||(!min&&!max&&_48===_44));
}else{
return false;
}
}else{
return _48>0;
}
}else{
if("color"===_41.substring(l-5,l)){
var _49=screen.colorDepth;
if(_42!==null){
if(_43==="absolute"){
return ((min&&_49>=_44)||(max&&_49<_44)||(!min&&!max&&_49===_44));
}else{
return false;
}
}else{
return _49>0;
}
}else{
if("resolution"===_41.substring(l-10,l)){
var res;
if(_45==="dpcm"){
res=_3d("1cm");
}else{
res=_3d("1in");
}
if(_42!==null){
if(_43==="resolution"){
return ((min&&res>=_44)||(max&&res<_44)||(!min&&!max&&res===_44));
}else{
return false;
}
}else{
return res>0;
}
}else{
return false;
}
}
}
}
}
}
}
}
};
var _4a=function(mq){
var _4b=mq.getValid();
var _4c=mq.getExpressions();
var l=_4c.length;
if(l>0){
for(var i=0;i<l&&_4b;i++){
_4b=_40(_4c[i].mediaFeature,_4c[i].value);
}
var not=mq.getNot();
return (_4b&&!not||not&&!_4b);
}
};
var _4d=function(mql){
var mqs=mql.getMediaQueries();
var t={};
for(var i=0;i<mqs.length;i++){
if(_4a(mqs[i])){
t[mqs[i].getMediaType()]=true;
}
}
var s=[],c=0;
for(var n in t){
if(t.hasOwnProperty(n)){
if(c>0){
s[c++]=",";
}
s[c++]=n;
}
}
if(s.length>0){
_39[_39.length]=cssHelper.addStyle("@media "+s.join("")+"{"+mql.getCssText()+"}",false);
}
};
var _4e=function(_4f){
for(var i=0;i<_4f.length;i++){
_4d(_4f[i]);
}
if(ua.ie){
document.documentElement.style.display="block";
setTimeout(function(){
document.documentElement.style.display="";
},0);
setTimeout(function(){
cssHelper.broadcast("cssMediaQueriesTested");
},100);
}else{
cssHelper.broadcast("cssMediaQueriesTested");
}
};
var _50=function(){
for(var i=0;i<_39.length;i++){
cssHelper.removeStyle(_39[i]);
}
_39=[];
cssHelper.mediaQueryLists(_4e);
};
var _51=0;
var _52=function(){
var _53=cssHelper.getViewportWidth();
var _54=cssHelper.getViewportHeight();
if(ua.ie){
var el=document.createElement("div");
el.style.position="absolute";
el.style.top="-9999em";
el.style.overflow="scroll";
document.body.appendChild(el);
_51=el.offsetWidth-el.clientWidth;
document.body.removeChild(el);
}
var _55;
var _56=function(){
var vpw=cssHelper.getViewportWidth();
var vph=cssHelper.getViewportHeight();
if(Math.abs(vpw-_53)>_51||Math.abs(vph-_54)>_51){
_53=vpw;
_54=vph;
clearTimeout(_55);
_55=setTimeout(function(){
if(!_3a()){
_50();
}else{
cssHelper.broadcast("cssMediaQueriesTested");
}
},500);
}
};
window.onresize=function(){
var x=window.onresize||function(){
};
return function(){
x();
_56();
};
}();
};
var _57=document.documentElement;
_57.style.marginLeft="-32767px";
setTimeout(function(){
_57.style.marginTop="";
},20000);
return function(){
if(!_3a()){
cssHelper.addListener("newStyleParsed",function(el){
_4e(el.cssHelperParsed.mediaQueryLists);
});
cssHelper.addListener("cssMediaQueriesTested",function(){
if(ua.ie){
_57.style.width="1px";
}
setTimeout(function(){
_57.style.width="";
_57.style.marginLeft="";
},0);
cssHelper.removeListener("cssMediaQueriesTested",arguments.callee);
});
_3c();
_50();
}else{
_57.style.marginLeft="";
}
_52();
};
}());
try{
document.execCommand("BackgroundImageCache",false,true);
}
catch(e){
}

        setTimeout(function () {
          docEl.style.width = ''; // undo width
          docEl.style.marginLeft = ''; // undo hide
        }, 0);
        // remove this listener to prevent following execution
        cssHelper.removeListener('cssMediaQueriesTested', arguments.callee);
      });
      createMeter();
      test();
    }
    else {
      docEl.style.marginLeft = ''; // undo visibility hidden
    }
    checkForResize();
  };
}());


// bonus: hotfix for IE6 SP1 (bug KB823727)
try {
  document.execCommand("BackgroundImageCache", false, true);
} catch (e) {}