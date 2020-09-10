// add stats to the home page
$(document).ready(function(){
  $.get("https://tasking-manager-tm4-production-api.hotosm.org/api/v2/system/statistics/?abbreviated=true", function(data){
    $('#Community-Mappers').text(formatedData(data['totalMappers']));
  });
  $.get("https://osmstats-api.hotosm.org/wildcard?key=hotosm-project-*", function(data){
    $('#Total-Map-Edits').text(formatedData(data['edits']));
    $('#Buildings-Mapped').text(formatedData(data['building_count_add']));
    $('#Roads-Mapped').text(formatedData(Math.round(parseInt(data['road_km_add']))));
   $('.loader').hide();
  });
});