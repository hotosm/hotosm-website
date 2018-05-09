// country level stats from Missing Maps
$(document).ready(function () {
  $('.loader').show();
  $.get('https://osm-stats-production-api.azurewebsites.net/countries/' + missingMapsCode, function (data) {
    $('#Total-Map-Edits').text(formatedData(data['all_edits']));
    $('#Buildings-Mapped').text(formatedData(data['building_count_add'] + data['building_count_mod']));
    $('#Roads-Mapped').text(formatedData(Math.round(parseInt(data['road_km_add']) + parseInt(data['road_km_mod']))));
    $('#Community-Mappers').text(formatedData(data['contributors']));
    $('.loader').hide();
  });
});