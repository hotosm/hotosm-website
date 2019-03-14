var allProjects = {}
var projectList = []
const proxyUrl = "https://cors-anywhere.herokuapp.com/"
const driveUrl = "https://drive.google.com/uc?export=download&id="
var totalArea = 0, totalEdits = 0, totalMappers = 0
var totalRoads = 0, totalBuildings = 0, totalChangesets = 0
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
      'minzoom': 0,
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
      'minzoom': 0,
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
      var features = map.queryRenderedFeatures(
        [e.point.x, e.point.y],
        {layers: ['tm-projects-black-circle', 'tm-projects-symbol']}
      )
      if (features.length) {
        map.getCanvas().style.cursor = 'pointer'
        $('#hover-details').empty()
        $('#hover-details').removeClass('hide')
        $('#hover-details').append(
          '<p class="hover-name">' +
          '<a target="_blank" href="https://tasks.hotosm.org/project/' +
          features[0].properties.id +
          '">#' + features[0].properties.id + '</a>' +
            ' - ' +
            features[0].properties.name + '</p>' +
            '<p id="proj-details">Click on the project to see more details</p>'

        )
      } else {
        map.getCanvas().style.cursor = ''
      }
    })
    map.on('click', function (e) {
      var features = map.queryRenderedFeatures(
        [e.point.x, e.point.y],
        {layers: ['tm-projects-black-circle', 'tm-projects-symbol']}
      )
      if (features.length) {
        $('#proj-details').empty()
        $('#proj-details').append(
          '<p style="font-weight:bold" id = "details-mappers">Mappers: ' + formatedData(features[0].properties.mappers) + '</p>' +
          '<p style="font-weight:bold" id= "details-edits">Edits: ' + formatedData(features[0].properties.edits) + '</p>'
        )
      }
    })
  }
  var projectExtentJSON
  const downloadUrl = proxyUrl + driveUrl + fileId
  $.get(downloadUrl, function (data) {
    projectExtentJSON = data
    var bbox = turf.bbox(projectExtentJSON.features[0])
    // set bounds according to features
    map.fitBounds(bbox, {
      padding: 50,
      maxZoom: 14.15,
      duration: 2000
    })
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

map.addControl(new mapboxgl.NavigationControl())
map.on('mouseleave', function (e) {
  map.getCanvas().style.cursor = ''
  $('#hover-details').empty()
})

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
