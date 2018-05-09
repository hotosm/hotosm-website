// add stats to the home page
$(document).ready(function(){
  $('#mappers').show();
  $('#edits').show();
  $('#buildings').show();
  $('#roads').show();
  $.get("https://tasks.hotosm.org/api/v1/stats/home-page", function(data){
    $('#Community-Mappers').text(formatedData(data['totalMappers']));
    $('#mappers').hide();
  });

  $.get("https://osm-stats-production-api.azurewebsites.net/stats/missingmaps", function(data){
    $('#Total-Map-Edits').text(formatedData(data['edits']));
    $('#Buildings-Mapped').text(formatedData(data['buildings']));
    $('#Roads-Mapped').text(formatedData(Math.round(parseInt(data['roads']))));
    $('#edits').hide();
    $('#buildings').hide();
    $('#roads').hide();
  });
});
