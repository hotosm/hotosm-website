var allProjects = {}
var projectList = []
const proxyUrl = "https://cors-anywhere.herokuapp.com/"
const driveUrl = "https://drive.google.com/uc?export=download&id="
var totalArea = 0, totalEdits = 0, totalMappers = 0
var totalRoads = 0, totalBuildings = 0, totalChangesets = 0
var bboxCoordinatesArray = [];
var currentPolygonIndex;
var numOfPolygons;

var options = {
  headers: {
    'Accept': 'application/json',
    'Accept-Language': 'en'
  }
}
var tmProjectCentroids = {
  'type': 'FeatureCollection',
  'features': []
}

var tmProjectPolygons = {
  'type': 'FeatureCollection',
  'features': []
}

campaignTags = campaignTags.split(',')
var countryList = countries.split(',')
countryList.forEach((country, countryIndex) => {
  countryList[countryIndex] = country.trim().toLowerCase()
})

mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA'

var map = new mapboxgl.Map({
  container: 'map',
  logoPosition: 'bottom-left',
  scrollZoom: false,
  dragRotate: false,
  maxZoom: 18,
  minZoom: 1.25,
  zoom: 1.25,
  center: [0, 8],
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
})

var popup = new mapboxgl.Popup({
  closeButton: false,
  closeOnClick: false
}).setHTML('')

const loadMapLayers = () => {
  if (tmProjectCentroids.features.length > 0) {
    map.addSource('tmProjectPolygons', {
      'type': 'geojson',
      'data': tmProjectPolygons
    })
    map.addSource('tmProjectCentroids', {
      'type': 'geojson',
      'data': tmProjectCentroids
    })
    map.addLayer({
      'id': 'tm-projects-polygons',
      'type': 'fill',
      'source': 'tmProjectPolygons',
      'minzoom': 4.5,
      'maxzoom': 19,
      'paint': {
        'fill-opacity': 0.2,
        'fill-color': '#000000'
      }
    }, 'place-city-sm')

    map.addLayer({
      'id': 'tm-projects-black-circle',
      'type': 'circle',
      'source': 'tmProjectCentroids',
      'minzoom': 10,
      'maxzoom': 19,
      'paint': {
        'circle-radius': 5,
        'circle-opacity': 0.7,
        'circle-color': '#000000'
      }
    }, 'place-city-sm')

    map.addLayer({
      'id': 'tm-projects-symbol',
      'type': 'symbol',
      'source': 'tmProjectCentroids',
      'minzoom': 10,
      'maxzoom': 19,
      'layout': {
        'text-field': '+',
        'text-font': ['Open Sans Bold'],
        'text-offset': [-0.001, -0.03],
        'text-size': 10
      },
      'paint': {
        'text-color': '#FFFFFF'
      }
    }, 'place-city-sm')

    document.getElementById('Project-Area').innerHTML = formatedData(Math.round(totalArea))
    document.getElementById('Total-Map-Edits').innerHTML = formatedData(Math.round(totalEdits))
    document.getElementById('Community-Mappers').innerHTML = formatedData(Math.round(totalMappers))
    document.getElementById('Countries-Covered').innerHTML = countryList.length

    map.on('mousemove', function (e) {
      var features = map.queryRenderedFeatures(e.point, {
        layers: ['tm-projects-black-circle', 'tm-projects-symbol']
      });

      map.getCanvas().style.cursor = (features.length) ? 'pointer' : '';

      if (!features.length) {
        popup.remove();
        return;
      }
    })

    map.on('click', function (e) {
      var features = map.queryRenderedFeatures(e.point, {
        layers: ['tm-projects-black-circle', 'tm-projects-symbol']
      });

      if (!features.length) {
        return;
      }

      var feature = features[0];

      updatePopupOnClick(feature);
    });
  }

  var projectExtentJSON
  const downloadUrl = proxyUrl + driveUrl + fileId
  $.get(downloadUrl, function (data) {
    projectExtentJSON = JSON.parse(data)

    projectExtentJSON.features.forEach(function (feature) {
      bboxCoordinatesArray.push(turf.bbox(feature));
    });

    var numOfPolygons = projectExtentJSON.features.length;

    if (numOfPolygons.length === 1) {
      setMapView();
    }

    currentPolygonIndex = 0;

    addFlyBtn();
    setMapView();

    document.getElementById('flybtn').addEventListener('click', function () {
      if (currentPolygonIndex >= (numOfPolygons - 1)) {
        currentPolygonIndex = 0;
      } else {
        currentPolygonIndex++;
      }

      setMapView();

      var popUps = document.getElementsByClassName('mapboxgl-popup');
      if (popUps[0]) popUps[0].remove();
    });

    map.addSource('projectExtent', {
      'type': 'geojson',
      'data': projectExtentJSON
    })
    map.addLayer({
      'id': 'project-extent',
      'source': 'projectExtent',
      'type': 'line',
      'layout': {},
      'paint': {
        'line-dasharray': [2, 1, 2, 1, 2],
        'line-gap-width': 1,
        'line-color': '#000000'
      }
    }, 'place-city-sm')
    $('#loading-map').detach()
  })
}

map.addControl(new mapboxgl.NavigationControl());

function addFlyBtn() {
  var flyButton = document.createElement('button');
  flyButton.id = 'flybtn';
  flyButton.classList.add('btn', 'btn-primary', 'btn-block');
  flyButton.textContent = "Zoom to next area";
  document.querySelector('.flybtn-holder').appendChild(flyButton);
};

function setMapView() {
  map.fitBounds(bboxCoordinatesArray[currentPolygonIndex], {
    padding: 50,
    maxZoom: 14.15,
    duration: 2000
  })
};

function updatePopupOnClick(currentFeature) {
  var popup = new mapboxgl.Popup()
    .setLngLat(currentFeature.geometry.coordinates)
    .setHTML('<p class="project__title">' +
      '<a class="project__title__link" target="_blank" href="https://tasks.hotosm.org/project/' +
      currentFeature.properties.id +
      '">#' + currentFeature.properties.id + '</a>' +
      ' - ' +
      currentFeature.properties.name + '</p>' +
      '<p class="project__details">Mappers: ' + formatedData(currentFeature.properties.mappers) + '</p>'
      + '<p class="project__details">Edits: ' + formatedData(currentFeature.properties.edits) + '</p>')
    .addTo(map);
}

function flyToNextArea() {
  var flyButton = document.createElement('button');
  flyButton.id = 'flybtn';
  flyButton.classList.add('btn', 'btn-primary', 'btn-block');
  flyButton.textContent = "Zoom to next area";
  document.querySelector('.flybtn-holder').appendChild(flyButton);

  var index = 0;
  document.getElementById('flybtn').addEventListener('click', function () {
    if (index >= bboxArray.length) {
      index = 0;
    }

    var popUps = document.getElementsByClassName('mapboxgl-popup');
    if (popUps[0]) popUps[0].remove();

    map.fitBounds(bboxArray[index], {
      padding: 50,
      maxZoom: 14.15,
      duration: 2000
    })
    index++;
  });
}

if (campaignTags[0] !== '') {
  fetch('/allProjects-minified-v2.json')
    .then(function (response) {
      return response.json()
    })
    .then(function (jsonData) {
      allProjects = jsonData
      fetch('/campaign-match.json')
        .then(function (response) {
          return response.json()
        })
        .then(function (jsonData) {
          campaignTags.forEach(campaignTag => {
            campaignTag = campaignTag.trim()
            if (jsonData[campaignTag]) {
              projectList = projectList.concat(jsonData[campaignTag])
            }
          })
          var totalProjects = projectList.length
          projectList.forEach((project, projectCount) => {
            var feature = {
              'type': 'Feature',
              'properties': {},
              'geometry': {}
            }
            feature.properties['id'] = project
            feature.properties['name'] = allProjects[project][0]
            feature.properties['status'] = allProjects[project][1]
            feature.properties['campaignTag'] = allProjects[project][2]
            feature.properties['created'] = allProjects[project][3]
            feature.properties['lastUpdated'] = allProjects[project][4]
            feature.properties['lastActive'] = allProjects[project][6]
            feature.properties['changesets'] = allProjects[project][7]
            feature.properties['mappers'] = allProjects[project][8]
            feature.properties['roads'] = allProjects[project][9]
            feature.properties['buildings'] = allProjects[project][10]
            feature.properties['edits'] = allProjects[project][11]

            totalEdits += allProjects[project][11]
            totalMappers += allProjects[project][8]
            totalChangesets += allProjects[project][7]
            totalRoads += allProjects[project][9]
            totalBuildings += allProjects[project][10]
            feature.geometry['type'] = 'Point'
            feature.geometry['coordinates'] = allProjects[project][5]
            tmProjectCentroids.features.push(feature)
            options.url = 'https://s3.amazonaws.com/hotosm-stats-collector/' + project + '-aoi.json'
            $.ajax({
              url: options.url,
              type: 'GET',
              dataType: 'json',
              success: function (result) {
                var polygonFeature = {
                  'type': 'Feature',
                  'properties': {},
                  'geometry': {}
                }
                var aoi = result
                aoi = JSON.parse(JSON.stringify(aoi))
                polygonFeature.properties['area'] = aoi.properties.area
                totalArea += aoi.properties.area
                polygonFeature.geometry = aoi.geometry
                tmProjectPolygons.features.push(polygonFeature)
                if (projectCount === (totalProjects - 1)) {
                  loadMapLayers()
                }
              },
              error: function (error) {
              }
            })
          })
        })
    })
} else {
  loadMapLayers()
}
