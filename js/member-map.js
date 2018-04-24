mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
var map = new mapboxgl.Map({
  container: 'person-map-area',
  logoPosition: 'bottom-right',
  zoom: 0.5,
  center: [0, 15],
  scrollZoom: false,
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
});

map.on('load', function() {
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
          padding: 60
        });
      }

    }
  );
});
