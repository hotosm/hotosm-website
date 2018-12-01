
var navAnchor = document.getElementById('nav-anchor'),
    nav = document.getElementById('nav-container');

navAnchor.addEventListener('click', function(e) {
    nav.className = nav.className? '' : 'show-nav';
    e.preventDefault();
});

$(document).on('click', 'a[href^="#"]', function (event) {
  event.preventDefault();
  $('html, body').animate({
    scrollTop: $($.attr(this, 'href')).offset().top - 72
  }, 500);
});

$('#control-right').on('click', function (event) {
  $('.home-highlights-wrapper').addClass('right');
});

$('#control-left').on('click', function (event) {
  $('.home-highlights-wrapper').removeClass('right');
});

var fixmeTop = $('.nav-main').offset().top;
$(window).scroll(function() {
  var currentScroll = $(window).scrollTop();
  if (currentScroll >= fixmeTop + 64) {
    $('#nav-container').addClass( 'fixed-nav' );
    $('.nav-logo').addClass( 'fixed-nav' );
    $('.nav-logo-text').addClass( 'fixed-nav' );
    $('.nav-main').addClass( 'fixed-nav' );
  } else {
    $('#nav-container').removeClass( 'fixed-nav' );
    $('.nav-logo').removeClass( 'fixed-nav' );
    $('.nav-logo-text').removeClass( 'fixed-nav' );
    $('.nav-main').removeClass( 'fixed-nav' );
  }
});

$(".search-link").on("click",function () {
  $("#search-overlay").addClass('search-show');
  $( "#search-input" ).focus();
  $('body').addClass('search-on');
});

$(".search-close").on("click", function() {
  $("#search-overlay").removeClass('search-show');
  $('body').removeClass('search-on');
});

//esc key
$('body').on('keyup', function(e) {
  if ($('body').hasClass('search-on') && e.keyCode == 27) {
          $(".search-overlay").hide();
          $('body').removeClass('search-on');
        }
});

var sjs = SimpleJekyllSearch({
  searchInput: document.getElementById('search-input'),
  resultsContainer: document.getElementById('results-container'),
  json: '/search.json',
  searchResultTemplate: '<li><a class="results-link" href="{url}"><h5>{type}</h5><h3 class="search-result-title">{title}</h3><p class="search-result-summary">{summary}</p><h6>{subtitle}</h6></a></li><div class="hr-h"></div>'
});

// util functions for frontpage stats
function formatedData(x){
  return x.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
}


const triggers = Array.from(document.querySelectorAll('[data-toggle="collapse"]'));

window.addEventListener('click', (ev) => {
  const elm = ev.target;
  if (triggers.includes(elm)) {
    const selector = elm.getAttribute('data-target');
    collapse(selector, 'toggle');
  }
}, false);


const fnmap = {
  'toggle': 'toggle',
  'show': 'add',
  'hide': 'remove'
};
const collapse = (selector, cmd) => {
  const targets = Array.from(document.querySelectorAll(selector));
  targets.forEach(target => {
    target.classList[fnmap[cmd]]('show');
  });
}


document.addEventListener("DOMContentLoaded", function(event) {
  
  function setOptOutText(element) {
    _paq.push([function() {
      element.checked = !this.isUserOptedOut();
      document.querySelector('label[for=optout] strong').innerText = this.isUserOptedOut()
        ? 'You are currently opted out. Click here to opt in.'
        : 'You are currently opted in. Click here to opt out.';
    }]);
  }

  var optOut = document.getElementById("optout");
  optOut.addEventListener("click", function() {
    if (this.checked) {
      _paq.push(['forgetUserOptOut']);
    } else {
      _paq.push(['optUserOut']);
    }
    setOptOutText(optOut);
  });
  setOptOutText(optOut);
  // if (!localStorage.getItem("optout-closed")) {
  //   document.getElementById("optout-form").style.display = "grid";
  //   console.log("Opened")
  // }
  $("#optout-form").addClass("optout-show");
});

// $('#optout-close').on("click", function() {
//   document.getElementById("optout-form").style.display = "none";
//   console.log("Closing")
//   localStorage.setItem("optout-closed", 1);
// });

$(".optout-close").click(function() {
  $("#optout-form").removeClass("optout-show");
  console.log("Closing");
});
