var allProjects = {}
var tmProjectCentroids = {
  'type': 'FeatureCollection',
  'features': []
}
var tmProjectPolygons = {
  'type': 'FeatureCollection',
  'features': []
}
console.log(campaignTags)
campaignTags = campaignTags.split(',')
console.log('Campaign Tags: ', campaignTags)

var totalArea = 0, totalEdits = 0, totalMappers = 0
var totalRoads = 0, totalBuildings = 0, totalChangesets = 0
var countryList = countries.split(',')
console.log('Country List: ', countryList)
countryList.forEach((country, countryIndex) => {
  countryList[countryIndex] = country.trim().toLowerCase()
})

mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA'
var map = new mapboxgl.Map({
  container: 'map',
  logoPosition: 'bottom-left',
  // scrollZoom: false,
  // dragRotate: false,
  maxZoom: 18,
  minZoom: 1.25,
  zoom: 1.25,
  center: [0, 8],
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
})

const loadMapLayers = (boxZoom) => {
  fetch('/campaigns-boundaries.json')
  .then(function (response) {
    return response.json()
  })
  .then(function (jsonData) {
    if (campaignTags[0] !== ""){
    campaignTags.forEach(campaignTag => {
      if (jsonData[campaignTag]) {
        jsonData[campaignTag].forEach(campaignProject => {
          tmProjectPolygons.features.push(campaignProject)
        })
      }
    })
    console.log('Total Project Boundaries: ', tmProjectPolygons.features.length)
    var polygonZoom = 3.25
    if (boxZoom) {
      polygonZoom = boxZoom + 2
    }
    map.addSource('tmProjectPolygons', {
      'type': 'geojson',
      'data': tmProjectPolygons
    })
  
    map.addLayer({
      'id': 'tm-projects-polygons',
      'type': 'fill',
      'source': 'tmProjectPolygons',
      'minzoom': polygonZoom,
      'maxzoom': 19,
      'paint': {
        'fill-opacity': 0.2,
        'fill-color': '#000000'
      }
    }, 'place-city-sm')
  } else {
    if (boxZoom){
      map.setMaxZoom(boxZoom)
    } else map.setMaxZoom(1.25)
  }
  })

fetch('/campaigns-centroids.json')
  .then(function (response) {
    return response.json()
  })
  .then(function (jsonData) {
    allProjects = jsonData
    if (campaignTags[0] !== ""){
    campaignTags.forEach(campaignTag => {
      campaignTag = campaignTag.trim()
      if (allProjects[campaignTag]) {
        allProjects[campaignTag].forEach(campaignProject => {
          tmProjectCentroids.features.push(campaignProject)
          totalArea += campaignProject.properties.area
          totalEdits += campaignProject.properties.edits
          totalMappers += campaignProject.properties.mappers
          totalChangesets += campaignProject.properties.changesets
          totalRoads += campaignProject.properties.roads
          totalBuildings += campaignProject.properties.buildings
        })
      }

      console.log('Total Project Centroids: ', tmProjectCentroids.features.length)
      console.log('Total Area: ', totalArea)
      console.log('Total Buildings: ', totalBuildings)
      console.log('Total Roads: ', totalRoads)
      console.log('Total Mappers: ', totalMappers)
      console.log('Total Edits: ', totalEdits)
      console.log('Total Changesets: ', totalChangesets)
      console.log('Total Countries: ', countryList.length)
      document.getElementById('Project-Area').innerHTML = formatedData(Math.round(totalArea))
      document.getElementById('Total-Map-Edits').innerHTML = formatedData(Math.round(totalEdits))
      document.getElementById('Community-Mappers').innerHTML = formatedData(Math.round(totalMappers))
      document.getElementById('Countries-Covered').innerHTML = countryList.length
      
    })
    map.addSource('tmProjectCentroids', {
      'type': 'geojson',
      'data': tmProjectCentroids
    })
    
  
    // map.addLayer({
    //   'id': 'tm-projects-edits-circle',
    //   'type': 'circle',
    //   'source': 'tmProjectCentroids',
    //   'minzoom': 0,
    //   'maxzoom': 19,
    //   'paint': {
    //     'circle-radius': {
    //       property: 'edits',
    //       stops: [
    //         [0, 10],
    //         [10000, 15],
    //         [50000, 20],
    //         [100000, 25],
    //         [125000, 30],
    //         [150000, 35],
    //         [200000, 40]
  
    //       ]
    //     },
    //     'circle-opacity': 0.7,
    //     'circle-color': '#FFC151'
    //   }
    // }, 'place-city-sm')
    var centroidZoom = 1.25
    if (boxZoom){
      centroidZoom = boxZoom
    }
    map.addLayer({
      'id': 'tm-projects-black-circle',
      'type': 'circle',
      'source': 'tmProjectCentroids',
      'minzoom': centroidZoom,
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
      'minzoom': centroidZoom,
      'maxzoom': 19,
      'layout': {
        'text-field': '+',
        'text-font': ['Open Sans Bold'],
        'text-offset': [-0.001, -0.03],
        'text-size':10
      },
      'paint': {
        'text-color': '#FFFFFF'
      }
    }, 'place-city-sm')
  }
  })
}


map.on('load', function () {
  $('.mapboxgl-ctrl').addClass('hide')
  $('#loading-map').detach()
  map.addSource('countriesbetter', {
    'type': 'vector',
    'url': 'mapbox://hot.6w45pyli'
  })
  
  if (countryList.length < 2) {
    fetch('/js/bbox.json')
      .then(function (response) {
        return response.json()
    })
      .then(function (jsonData) {
        var bboxCountries = jsonData
        var countryCode
        for (bbox in bboxCountries) {
        // console.log(bbox)
        // console.log(countries.split(','))
        // console.log(bboxCountries[bbox][0])
          if (countries.split(',')[0] === bboxCountries[bbox][0]) {
            countryCode = bbox
            console.log('countryCode: ', countryCode)
          }
        }
        map.fitBounds(bboxCountries[countryCode][1], {
        }, setTimeout(() => {
          var boxZoom = map.getZoom()
          map.setMinZoom(boxZoom)
          map.addLayer({
            "id": "active_countries",
            "type": "fill",
            "source": "countriesbetter",
            "source-layer": "countries-polygon-7jl2br",
            "minzoom": 0,
            "maxzoom": 8,
            "filter": ['any', ['in', 'name_low'].concat(countryList)],
            "paint": {
              "fill-pattern": "lines-red-4",
              "fill-outline-color": "#EFB4B4"
            }
          }, 'place-city-sm');
          loadMapLayers(boxZoom)
        }, 2000))
       
      }
      )
  }
  else {
    map.addLayer({
      "id": "active_countries",
      "type": "fill",
      "source": "countriesbetter",
      "source-layer": "countries-polygon-7jl2br",
      "minzoom": 0,
      "maxzoom": 8,
      "filter": ['any', ['in', 'name_low'].concat(countryList)],
      "paint": {
        "fill-pattern": "lines-red-4",
        "fill-outline-color": "#EFB4B4"
      }
    }, 'place-city-sm');
    loadMapLayers()
  }
})

function content (action) {
  if (action === 'more') {
    document.getElementById('panel').style.height = '100%'
    document.getElementById('less').style.display = 'block'
    document.getElementById('more').style.display = 'none'
  } else {
    document.getElementById('panel').style.height = '100px'
    document.getElementById('more').style.display = 'block'
    document.getElementById('less').style.display = 'none'
  }
}

