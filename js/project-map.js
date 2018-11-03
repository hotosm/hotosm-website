var allProjects = {}
var tmProjects = {
    "type": "FeatureCollection",
    "features": []
}
var totalArea = 0, totalEdits = 0, totalMappers = 0
var totalRoads = 0, totalBuildings = 0, totalChangesets = 0

var countryList = countries.split(',')
countryList.forEach((country, countryIndex) => {
  countryList[countryIndex] = country.trim().toLowerCase()
})

$(document).ready(function (){
  
})

mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
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
});

fetch('/campaigns.json')
  .then(function(response) {
    return response.json();
  })
  .then(function (jsonData) {
    allProjects = jsonData
    console.log(allProjects)
    console.log(campaignTags)
    campaignTags = campaignTags.split(',')
    console.log(campaignTags)
    

    campaignTags.forEach(campaignTag => {
        campaignTag = campaignTag.trim()
        allProjects[campaignTag].forEach(campaignProject => {
            tmProjects.features.push(campaignProject)
            totalArea += campaignProject.properties.area
            totalEdits += campaignProject.properties.edits
            totalMappers += campaignProject.properties.mappers
            totalChangesets += campaignProject.properties.changesets
            totalRoads += campaignProject.properties.roads
            totalBuildings += campaignProject.properties.buildings
        })
        console.log('Total Projects: ', tmProjects.features.length)
        console.log('Total Area: ', totalArea)
        console.log('Total Buildings: ', totalBuildings)
        console.log('Total Roads: ', totalRoads)
        console.log('Total Mappers: ', totalMappers)
        console.log('Total Edits: ', totalEdits)
        console.log('Total Changesets: ', totalChangesets)
        console.log('Total Countries: ', countryList.length)
        document.getElementById('Project-Area').innerHTML = formatedData(Math.round(totalArea))
        // document.getElementById('Buildings-Mapped').innerHTML = formatedData(Math.round(totalBuildings))
        // document.getElementById('Roads-Mapped').innerHTML = formatedData(Math.round(totalRoads))
        document.getElementById('Total-Map-Edits').innerHTML = formatedData(Math.round(totalEdits))
        document.getElementById('Community-Mappers').innerHTML = formatedData(Math.round(totalMappers))
        document.getElementById('Countries-Covered').innerHTML = countryList.length
    })
});

map.on('load', function () {
  $('.mapboxgl-ctrl').addClass('hide');
  $('#loading-map').detach();
  map.addSource('countriesbetter', {
    "type": "vector",
    "url": "mapbox://hot.6w45pyli"
  });
  map.addSource('tmProjects', {
    "type": "geojson",
    "data": tmProjects
  });
 

  map.addLayer({
    "id": "tm-projects-edits-circle",
    "type": "circle",
    "source": "tmProjects",
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
    "id": "tm-projects-black-circle",
    "type": "circle",
    "source": "tmProjects",
    "minzoom": 0,
    "maxzoom": 18,
    "paint": {
      'circle-radius': 6.5,
      "circle-opacity": 1,
      "circle-color": "#000000",
    }
  }, 'place-city-sm');  
  map.addLayer({
    "id": "tm-projects-symbol",
    "type": "symbol",
    "source": "tmProjects",
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

});

function content(action) {
  if (action === 'more') {
    document.getElementById("panel").style.height="100%"
    document.getElementById("less").style.display="block"
    document.getElementById("more").style.display="none"
  } else {
    document.getElementById("panel").style.height="100px"
    document.getElementById("more").style.display="block"
    document.getElementById("less").style.display="none"
  }
}