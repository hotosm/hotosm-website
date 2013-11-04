// Optimized scalefix by jdalton: https://gist.github.com/903131
// Prevents iOS from overscaling the page on orientation change.
// 1) won't restrict viewport if JS is disabled
// 2) uses capture phase
// 3) assumes last viewport meta is the one to edit (incase for some odd reason there is more than one)
// 4) feature inference (no sniffs, behavior should be ignored on other enviros)
// 5) removes event handler after fired
!function(doc) {
  var addEvent = 'addEventListener',
      type = 'gesturestart',
      qsa = 'querySelectorAll',
      scales = [1, 1],
      meta = qsa in doc ? doc[qsa]('meta[name=viewport]') : [];

  function fix() {
    meta.content = 'width=device-width,minimum-scale=' + scales[0] + ',maximum-scale=' + scales[1];
    doc.removeEventListener(type, fix, !0);
  }
  if ((meta = meta[meta.length - 1]) && addEvent in doc) {
    fix();
    scales = [.25, 1.6];
    doc[addEvent](type, fix, !0);
  }
}(document);
