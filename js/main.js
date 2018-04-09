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
  if (currentScroll >= fixmeTop) {
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
<<<<<<< HEAD

$(function() {
  $("#submit").hide();
  $("#country-select select").change(function() {
    window.location = $("#page-changer select option:selected").val();
  })
});

$(".search-link").on("click",function () {
  $("#search-overlay")
    .height($(document).height())
    .show();
  $('body').addClass('search-on');
});

$(".search-close").on("click", function() {
  $("#search-overlay").hide();
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
  searchResultTemplate: '<li><a class="results-link" href="{url}"><h3 class="search-result-title">{title}</h3><p class="search-result-summary">{summary}</p><h6>{person}</h6></a></li><div class="hr-h"></div>'
});
=======
>>>>>>> fbc1c3ce0eef64e61a1f05bda489012321f0f465
