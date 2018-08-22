var countries;
var countryData = {
  "type": "FeatureCollection",
  "features": []
};
var years = []
var count = {}
var container = document.getElementById('year-checkbox')

mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
var map = new mapboxgl.Map({
  container: 'country-map-wrap',
  logoPosition: 'bottom-left',
  // scrollZoom: false,
  // dragRotate: false,
  maxzoom: 16,
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
});

fetch('/aggregatedStats.json')
.then(function(response) {
  return response.json();
})
.then(function (jsonData) {
  var countryTitle = $(document).find("title").text().split('|')[1].trim();
  countryData.features = (jsonData[countryTitle]);
  countryData.features.forEach(countryProject => {
    if (years.indexOf(countryProject.properties['created']) < 0) {
      years.push(countryProject.properties['created'])
    }
    if (count[countryProject.properties['status']]){
      count[countryProject.properties['status']]++
    } else {
      count[countryProject.properties['status']] = 1
    }
    if (count[countryProject.properties['created']]){
      count[countryProject.properties['created']]++
    } else {
      count[countryProject.properties['created']] = 1
    }
  })
  console.log(countryData);
  console.log(years);
  console.log(count);
  years.sort();
  var filterHeader = document.getElementById('filter-header')
  filterHeader.innerHTML = 'Filter ' + countryData.features.length + ' tasking manager projects by:'
  var publishedLabel = document.getElementById('published-label')
  publishedLabel.innerHTML = 'Active (' + count['PUBLISHED'] + ')'
  var archivedLabel = document.getElementById('archived-label')
  archivedLabel.innerHTML = 'Archived (' + count['ARCHIVED'] + ')'
  
  years.forEach(year => {
    var checkbox = document.createElement('input');
    checkbox.type = 'checkbox';
    checkbox.classList.add('style-checkbox');
    checkbox.name = 'checkbox';
    checkbox.value = 'created';
    checkbox.id = year;
    
    // checkbox.addEventListener('click', function() {
    //   showValues(year);
    // }, false)
    
    checkbox.checked = true;
    var label = document.createElement('label')
    label.id = year + '-label';
    label.htmlFor = year;
    label.appendChild(document.createTextNode(year + ' (' + count[year] + ')'));

    container.appendChild(checkbox);
    container.appendChild(label);
  })
}
);

map.on('load', function() {
  map.addSource('countriesbetter', {
    "type": "vector",
    "url": "mapbox://hot.9fvp7us2"
  });
  map.addSource('countriesProjects', {
    "type": "geojson",
    "data": countryData
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
      "fill-outline-color": "#EFB4B4"
    }
  }, 'place-city-sm');

  map.addLayer({
    "id": "country-projects-edits-circle",
    "type": "circle",
    "source": "countriesProjects",
    "minzoom": 0,
    "maxzoom": 18,
   "paint": {
    'circle-radius': {
      property: 'edits',
      stops: [
      [0, 10],
      [10000, 15],
      [50000, 20],
      [100000, 25],
      [125000, 30],
      [150000, 35],
      [200000, 40]

      ]
     },
    "circle-opacity": 0.7,
    "circle-color": "#FFC151",
    }
  }, 'place-city-sm');

  map.addLayer({
    "id": "country-projects-black-circle",
    "type": "circle",
    "source": "countriesProjects",
    "minzoom": 0,
    "maxzoom": 18,
   "paint": {
    'circle-radius': 6.5,
    "circle-opacity": 1,
    "circle-color": "#000000",
    }
  }, 'place-city-sm');  
map.addLayer({
    "id": "country-projects-symbol",
    "type": "symbol",
    "source": "countriesProjects",
    "minzoom": 0,
    "maxzoom": 18,
    "layout" : {
      "text-field": "+",
      "text-font" : ["Open Sans Bold"],
      "text-offset": [-0.001, -0.03]
    },
   "paint": {
     "text-color": "#FFFFFF"
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
      }, setTimeout(() => {
        var boxZoom = map.getZoom();
        map.setMinZoom(boxZoom);
        console.log(boxZoom);
      }, 2000));     
    }
  );
  map.on('mousemove', function(e) {
    var projectHover = map.queryRenderedFeatures(
      e.point,
      {layers: ['country-projects-edits-circle', 'country-projects-black-circle', 'country-projects-symbol']}
    );
    if (projectHover.length) {
      map.getCanvas().style.cursor = 'pointer';
      $("#hover-details").empty();
      $("#hover-details").removeClass('hide');
      $("#hover-details").append(
        '<p class="hover-name">' + 
        '<a target="_blank" href="https://tasks.hotosm.org/project/' +
        projectHover[0].properties.id + 
        '">#' + projectHover[0].properties.id +'</a>' +
          " - " +
        projectHover[0].properties.title + '</p>' +
        '<p class= "hover-edits">' + formatedData(projectHover[0].properties.edits) + ' Edits </p>' 
      );
      console.log()
      var coordinates = projectHover[0].geometry.coordinates.slice();
      var description = "<html><h6><a target='_blank' href='https://tasks.hotosm.org/project/" + projectHover[0].properties.id
                        + "'</a>#" + projectHover[0].properties.id + " - "
                        + projectHover[0].properties.title + "</h6></html>";
      while (Math.abs(e.lngLat.lng - coordinates[0]) > 180) {
        coordinates[0] += e.lngLat.lng > coordinates[0] ? 360 : -360;
      }
    } else {
      map.getCanvas().style.cursor = '';
    }
  });

  $(document).ready(function() {
    $("input[type='checkbox']").on('change', function() {
      count = {}
      var yearFilter = ['any']
      var statusFilter = ['any']
      var updateList = []
      var layers = ['country-projects-edits-circle', 'country-projects-black-circle', 'country-projects-symbol']
      var chkBoxes = document.getElementsByName('checkbox')
      chkBoxes.forEach(chkBox => {
        if (chkBox.checked) {
          var chkBoxFilter = ['==', chkBox.value, chkBox.id.toUpperCase()]
          if (chkBox.value === 'created') {
            yearFilter.push(chkBoxFilter)
            count[chkBoxFilter[2]] = 0;
            updateList.push(chkBoxFilter[2])
          } else {
            statusFilter.push(chkBoxFilter)
            count[chkBoxFilter[2]] = 0;
          }
        }
        
      })
      console.log(count)
      countryData.features.forEach(proj => {
        if (count.hasOwnProperty(proj.properties.created) &&
            count.hasOwnProperty(proj.properties.status)) {
          count[proj.properties.created]++
          count[proj.properties.status]++
        }
      })
      var filter = ['all', yearFilter, statusFilter]
      layers.forEach(layer => {
        map.setFilter(layer, filter)
      })
      
      var publishedLabel = document.getElementById('published-label')
      if (count['PUBLISHED']) {
        publishedLabel.innerHTML = 'Active (' + count['PUBLISHED'] + ')'
      } else {
        publishedLabel.innerHTML = 'Active (0)'
      }
      var archivedLabel = document.getElementById('archived-label')
      if (count['ARCHIVED']) {
        archivedLabel.innerHTML = 'Archived (' + count['ARCHIVED'] + ')'
      } else {
        archivedLabel.innerHTML = 'Archived (0)'
      }
      years.forEach(year => {
        var yearLabel = document.getElementById(year + '-label')
        if (count[year]) {
          yearLabel.innerHTML = year + ' (' + count[year] + ')'
        } else {
          yearLabel.innerHTML = year + ' (0)'
        }
      })
      
    });
  });
});