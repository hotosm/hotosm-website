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
  scrollZoom: false,
  zoom: 1.25,
  center: [0, 17],
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
});

map.on('load', function () {
  $('.mapboxgl-ctrl').addClass('hide');

  countriesList = Object.keys(countries);
  var projectCountries = countriesList.filter(function(item) {
    return countries[item].hot_program || countries[item].community_program;
  });
  var memberCountries = countriesList.filter(function(item) {
    return countries[item].member && !projectCountries.includes(item);
  });

  map.addSource('countriesbetter', {
    "type": "vector",
    "url": "mapbox://hot.9fvp7us2"
  });

  map.addLayer({
    "id": "project_countries",
    "type": "fill",
    "source": "countriesbetter",
    "source-layer": "countriesbetter",
    "minzoom": 0,
    "maxzoom": 8,
    "filter": ['in', 'name_low'].concat(projectCountries),
    "paint": {
      "fill-pattern": "lines-red-4",
      "fill-outline-color": "#EFB4B4"
    }
  }, 'place-city-sm');
  map.addLayer({
    "id": "member_countries",
    "type": "fill",
    "source": "countriesbetter",
    "source-layer": "countriesbetter",
    "minzoom": 0,
    "maxzoom": 8,
    "filter": ['in', 'name_low'].concat(memberCountries),
    "paint": {
      // "fill-pattern": "lines-orange-4",
      // "fill-outline-color": "#FBD088"
      "fill-pattern": "lines-blue-4",
      "fill-outline-color": "#C2C6CE"
    }
  }, 'place-city-sm');

  map.on('click', function(e) {
    var features = map.queryRenderedFeatures(
      [e.point.x, e.point.y],
      {layers: ['project_countries', 'member_countries']}
    );
    if (features.length) {
      var country_name = features[0].properties.name_low.split(' ').join('-');
      $(location).attr('href', '/where-we-work/' + country_name);
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
    $('.mapboxgl-ctrl').addClass('hide');
  } else {
    map.scrollZoom.enable();
    $('.project-index-header').addClass('boxed-down');
    $('.home-highlights-wrapper').addClass('right');
    $('.home-highlights-wrapper').addClass('right');
    $('#close-map-txt').removeClass('hide');
    $('#expand-map-txt').addClass('hide');
    $('.mapboxgl-ctrl').removeClass('hide');
  }
  fullMap = !fullMap;
}
