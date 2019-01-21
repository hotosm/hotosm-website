// country level stats from stats-collector
var hotStats = {'edits': 0, 'mappers': 0, 'buildings': 0, 'roads': 0};
var osmStats = {'edits': 0, 'mappers': 0, 'buildings': 0, 'roads': 0};
var country = $(document).find('title').text().split('|')[1].trim();   
if (country.startsWith('United')) country = 'United States of America'

$(document).ready(function () {
  var options = {
    headers: {
      'Accept': 'application/json',
      'Accept-Language': 'en'
    }
  }
  
  options.url = 'https://s3.amazonaws.com/hotosm-stats-collector/aggregatedStats.json'
  $.ajax({
    url: options.url,
    type: 'GET',
    dataType: 'json',
    success: function (jsonData) {
      if (jsonData[country]) {
        jsonData[country].forEach(project => {
          hotStats.edits += project.properties['edits']
          hotStats.mappers += project.properties['mappers']
          hotStats.buildings += project.properties['buildings']
          hotStats.roads += Math.round(project.properties['roads'])
        })
        updateStats(hotStats, 'hot')
      } else {
        $.get('https://osm-stats-production-api.azurewebsites.net/countries/' + missingMapsCode, function (data) {
          hotStats.edits = data['all_edits'];
          hotStats.buildings = data['building_count_add'] + data['building_count_mod'];
          hotStats.roads = Math.round(parseInt(data['road_km_add']) + parseInt(data['road_km_mod']));
          hotStats.mappers = data['contributors'];
          updateStats(hotStats, 'hot')
      });
      }
      $.get('https://osm-stats-production-api.azurewebsites.net/countries/' + missingMapsCode, function (data) {
        osmStats.edits = data['all_edits'];
        osmStats.buildings = data['building_count_add'] + data['building_count_mod'];
        osmStats.roads = Math.round(parseInt(data['road_km_add']) + parseInt(data['road_km_mod']));
        osmStats.mappers = data['contributors'];
        updateStats(osmStats, 'osm')
      });
    },
    error: function (error) {
    }
  })
    
  
})

function updateStats (stats, type) {
  if (type === 'hot') {
    $('#Total-Map-Edits').text(formatedData(hotStats.edits));
    $('#Buildings-Mapped').text(formatedData(hotStats.buildings));
    $('#Roads-Mapped').text(formatedData(hotStats.roads));
    $('#Community-Mappers').text(formatedData(hotStats.mappers));
    $('.loader').hide();
  } else {
    $('#OSM-Total-Map-Edits').text(formatedData(osmStats.edits));
    $('#OSM-Buildings-Mapped').text(formatedData(osmStats.buildings));
    $('#OSM-Roads-Mapped').text(formatedData(osmStats.roads));
    $('#OSM-Community-Mappers').text(formatedData(osmStats.mappers));
    $('.osm-loader').hide();
  }
}

function switchTab(evt, tabName) {
  var i, tabcontent, tablinks;
  tabcontent = document.getElementsByClassName('tabcontent');
  for (i = 0; i < tabcontent.length; i++) {
    tabcontent[i].style.display = 'none';
  }
  tablinks = document.getElementsByClassName('tablinks');
  for (i = 0; i < tablinks.length; i++) {
    tablinks[i].className = tablinks[i].className.replace(' active', '');
  }
  document.getElementById(tabName).style.display = 'flex';
  evt.currentTarget.className += ' active';
}
