var osmStats = {'edits': 0, 'mappers': 0, 'buildings': 0, 'roads': 0}
  $.get('https://osm-stats-production-api.azurewebsites.net/group-summaries/' + activationCode , function (data) {
    var activeData = data[activationCode];
      osmStats.edits = activeData['edits'];
      osmStats.buildings = activeData['building_count_add'] + activeData['building_count_mod'];
      osmStats.roads = Math.round(parseInt(activeData['road_km_add']) + parseInt(activeData['road_km_mod']));
      osmStats.mappers = activeData['users'];
      updateStats(osmStats)

  });

function updateStats (stats) {
  $('#OSM-Total-Map-Edits-DST').text(formatedData(osmStats.edits));
  $('#OSM-Buildings-Mapped-DST').text(formatedData(osmStats.buildings));
  $('#OSM-Roads-Mapped-DST').text(formatedData(osmStats.roads));
  $('#OSM-Community-Mappers-DST').text(formatedData(osmStats.mappers));
  $('.osm-loader').hide();

}


