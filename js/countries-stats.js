// country level stats from Missing Maps
console.log(missingMapsCode);
$(document).ready(function(){
  $.get("https://osm-stats-production-api.azurewebsites.net/countries/" + missingMapsCode, function(data){
    console.log(data)
    $('#Total-Map-Edits').text(formatedData(data['all_edits']));
    $('#Buildings-Mapped').text(formatedData(data['building_count_add']) + formatedData(data['building_count_mod']));
    $('#Roads-Mapped').text(formatedData(Math.round(parseInt(data['road_km_add']) + parseInt(data['road_km_mod']))));
    $('#Community-Mappers').text(formatedData(data['contributors']));
  });
});