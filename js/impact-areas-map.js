
  var countries = {};
  var impactAreas;
  var projectCountries, memberCountries = [];
  var impactTitle;
  
  fetch('/countries.json')
    .then(function(response) {
      return response.json();
    })
    .then(function(jsonData) {
      countries = jsonData;
      console.log(countries)
      countriesList = Object.keys(countries);
      projectCountries = countriesList.filter(function(item) {
        return countries[item].hot_program || countries[item].community_program;
      });
      memberCountries = countriesList.filter(function(item) {
        return countries[item].member && !projectCountries.includes(item);
      });
    }
  );
  
  fetch('/impact-filter.json')
    .then(function(response) {
      console.log(JSON.stringify(response))
      return response.json();
    })
    .then(function(jsonData) {
      impactAreas = jsonData;
      impactTitle = $(document).find("title").text().split('|')[1].trim()
      console.log(impactTitle)
      countriesList = Object.keys(impactAreas);
      impactCountries = countriesList.filter(function(item){
        return impactAreas[item][impactTitle];
      })
      console.log('ImpactAreas: ', impactAreas)
      console.log('ImpactCountries: ', impactCountries)
     

    }
  );
  
  mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
  var map = new mapboxgl.Map({
    container: 'map',
    logoPosition: 'bottom-right',
    scrollZoom: false,
    dragRotate: false,
    zoom: 1.25,
    center: [0, 17],
    style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
  });
  
  map.on('load', function () {
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
      "filter": ['in','name_low'].concat(impactCountries),
      "paint": {
        "fill-pattern": "lines-red-4",
        "fill-outline-color": "#EFB4B4"
      }
    }, 'place-city-sm');
  
    map.on('click', function(e) {
      var features = map.queryRenderedFeatures(
        [e.point.x, e.point.y],
        {layers: ['project_countries']}
      );
      if (features.length) {
        var country_name = features[0].properties.name_low.split(' ').join('-');
        $(location).attr('href', '/where-we-work/' + country_name);
      }
    });
  
    var lastCountry;
    map.on('mousemove', function(e) {
      var areaHover = map.queryRenderedFeatures(
        e.point,
        {layers: ['project_countries']}
      );
      if (areaHover.length) {
        map.getCanvas().style.cursor = 'pointer';
        if (lastCountry !== areaHover[0].properties.NAME_LONG) {
          $("#hover-country").empty();
          $("#hover-country").append(
            '<p><strong>' + areaHover[0].properties.NAME_LONG + '</strong></p>' +
            '<p>(click on the country to see the details)</p>'
          );
          lastCountry = areaHover[0].properties.NAME_LONG;
        }
        console.log(areaHover[0].properties.name_low);
      } else {
        console.log('limpando');
        map.getCanvas().style.cursor = '';
        lastCountry = '';
        $("#hover-country").empty();
      }
    });
  });
  


