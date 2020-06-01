mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
var map = new mapboxgl.Map({
  container: 'person-map-area',
  logoPosition: 'bottom-left',
  zoom: 4,
  center: [0, 15],
  scrollZoom: false,
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4',
  attributionControl: false
})
  .addControl(new mapboxgl.AttributionControl({ compact: false }));
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
    "maxzoom": 18,
    "filter": ['in', 'name_low', country.toLowerCase()],
    "paint": {
      "fill-pattern": "lines-red-4",
      "fill-outline-color": "#EFB4B4"
    }
  }, 'place-city-sm');
  fetch('/js/bbox.json')
    .then(function(response) {
      return response.json();
    })
    .then(function(jsonData) {
      var countries = Object.values(jsonData);
      var bbox = countries.filter(function (item) {
        return item[0] === country;
      }).map(function(item) {
        return item[1];
      });
      if (bbox.length > 0) {
        map.fitBounds(bbox[0], {
          padding: 10
        });
      }
    }
  );
});
