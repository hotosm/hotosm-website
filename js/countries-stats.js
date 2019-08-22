// country level stats from stats-collector
var hotStats = { 'edits': 0, 'mappers': 0, 'buildings': 0, 'roads': 0 };
var osmStats = { 'edits': 0, 'mappers': 0, 'buildings': 0, 'roads': 0 };
var country = $(document).find('title').text().split('|')[1].trim();
if (country.startsWith('United')) country = 'United States of America'

$(document).ready(function () {
  fetch('/aggregatedStats.json')
    .then(function (response) {
      return response.json()
    })
    .then(function (jsonData) {
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
    }
    )
})

function updateStats(stats, type) {
  if (type === 'hot') {
    $('#Total-Map-Edits > span').after(formatedData(hotStats.edits));
    $('#Buildings-Mapped > span').after(formatedData(hotStats.buildings));
    $('#Roads-Mapped > span').after(formatedData(hotStats.roads));
    $('#Community-Mappers > span').after(formatedData(hotStats.mappers));
    $('.loader').hide();
  } else {
    $('#OSM-Total-Map-Edits > span').after(formatedData(osmStats.edits));
    $('#OSM-Buildings-Mapped > span').after(formatedData(osmStats.buildings));
    $('#OSM-Roads-Mapped > span').after(formatedData(osmStats.roads));
    $('#OSM-Community-Mappers > span').after(formatedData(osmStats.mappers));
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
