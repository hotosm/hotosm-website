var countries = {};

fetch('/countries.json')
  .then(function(response) {
    return response.json();
  })
  .then(function(jsonData) {
    countries = jsonData;
  }
);


mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
var map = new mapboxgl.Map({
  container: 'map',
  logoPosition: 'bottom-right',
  // scrollZoom: false,
  zoom: 1.25,
  center: [0, 25],
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
});

map.on('load', function () {
  countriesList = Object.keys(countries);
  var activeCountries = countriesList.filter(function(item) {
    return countries[item].hot_program || countries[item].member;
  });
  var communityCountries = countriesList.filter(function(item) {
    return countries[item].community_program && !activeCountries.includes(item);
  });

  map.addSource('countriesbetter', {
    "type": "vector",
    "url": "mapbox://hot.9fvp7us2"
  });

  map.addLayer({
    "id": "active_countries",
    "type": "fill",
    "source": 'countriesbetter',
    "source-layer": 'countriesbetter',
    "minzoom": 0,
    "maxzoom": 8,
    'filter': ['in', 'name_low'].concat(activeCountries),
    "paint": {
      "fill-color": "#D73F3F"
    }
  });
  map.addLayer({
    "id": "community_countries",
    "type": "fill",
    "source": 'countriesbetter',
    "source-layer": 'countriesbetter',
    "minzoom": 0,
    "maxzoom": 8,
    'filter': ['in', 'name_low'].concat(communityCountries),
    "paint": {
      "fill-color": "#FAA71E"
    }
  });
});

var fullMap = false;

function expandMap() {
  if (fullMap) {
    map.scrollZoom.disable();
    $('.project-index-header').removeClass('boxed-down');
    $('#close-map-txt').addClass('hide');
    $('#expand-map-txt').removeClass('hide');
  } else {
    map.scrollZoom.enable();
    $('.project-index-header').addClass('boxed-down');
    $('.home-highlights-wrapper').addClass('right');
    $('.home-highlights-wrapper').addClass('right');
    $('#close-map-txt').removeClass('hide');
    $('#expand-map-txt').addClass('hide');
  }
  fullMap = !fullMap;
}
