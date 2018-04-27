var countries;

mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
var map = new mapboxgl.Map({
  container: 'country-map-wrap',
  logoPosition: 'bottom-left',
  scrollZoom: false,
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
});

map.on('load', function() {
  map.addSource('countriesbetter', {
    "type": "vector",
    "url": "mapbox://hot.9fvp7us2"
  });

  map.addLayer({
    "id": "active_countries",
    "type": "fill",
    "source": "countriesbetter",
    "source-layer": "countriesbetter",
    "minzoom": 0,
    "maxzoom": 8,
    "filter": ['any', ['in', 'name_low'].concat(countryName), ['in', 'ISO_A2'].concat(countryCode)],
    "paint": {
      "fill-pattern": "lines-red-4",
      "fill-outline-color": "#fff"
    }
  }, 'place-city-sm');
  fetch('/js/bbox.json')
    .then(function(response) {
      return response.json();
    })
    .then(function(jsonData) {
      countries = jsonData;
      map.fitBounds(countries[countryCode][1], {
        padding: 40
      });
    }
  );
});
