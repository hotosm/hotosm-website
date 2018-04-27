// add stats to the home page
$(document).ready(function(){
  $.get("https://tasks.hotosm.org/api/v1/stats/home-page", function(data){
    $('#Community-Mappers').text(formatedData(data['totalMappers']));
  });

  $.get("https://osm-stats-production-api.azurewebsites.net/stats/missingmaps", function(data){
    $('#Total-Map-Edits').text(formatedData(data['edits']));
    $('#Buildings-Mapped').text(formatedData(data['buildings']));
    $('#Roads-Mapped').text(formatedData(Math.round(parseInt(data['roads']))));
  });
});
