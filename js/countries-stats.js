// country level stats from stats-collector
var stats = {'edits': 0, 'mappers': 0, 'buildings': 0, 'roads': 0};
var country = $(document).find("title").text().split('|')[1].trim();   
if (country.startsWith('United')) country = 'United States of America'

$(document).ready(function () {
  fetch('/aggregatedStats.json')
  .then(function (response) {
    return response.json()
  })
  .then(function (jsonData) {
    console.log(jsonData)
    if (jsonData[country]) {
      jsonData[country].forEach(project => {
        stats.edits += project.properties['edits']
        stats.mappers += project.properties['mappers']
        stats.buildings += project.properties['buildings']
        stats.roads += Math.round(project.properties['roads'])
      })
      updateStats(stats)
    } else {
      $.get('https://osm-stats-production-api.azurewebsites.net/countries/' + missingMapsCode, function (data) {
        stats.edits = formatedData(data['all_edits']);
        stats.buildings = formatedData(data['building_count_add'] + data['building_count_mod']);
        stats.roads = formatedData(Math.round(parseInt(data['road_km_add']) + parseInt(data['road_km_mod'])));
        stats.mappers = formatedData(data['contributors']);
        updateStats(stats)
      });
    }
  }
  )
})

function updateStats (stats) {
  $('#Total-Map-Edits').text(stats.edits);
  $('#Buildings-Mapped').text(stats.buildings);
  $('#Roads-Mapped').text(stats.roads);
  $('#Community-Mappers').text(stats.mappers);
  $('.loader').hide();
}
