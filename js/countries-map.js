var countries;

mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
var map = new mapboxgl.Map({
  container: 'country-map-area',
  logoPosition: 'bottom-left',
  scrollZoom: false,
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
});

map.on('load', function() {
  fetch('/js/bbox.json')
    .then(function(response) {
      return response.json();
    })
    .then(function(jsonData) {
      countries = jsonData;
      map.fitBounds(countries[countryCode][1], {
        padding: 60
      });
    }
  );
});
