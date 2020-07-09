// add stats to the home page
$(document).ready(function () {
  fetch('https://osmstats-api.hotosm.org/wildcard?key=hotosm-project-*')
  .then(function (response) {
    return response.json()
  })
  .then(function (jsonData) {
    $('#Community-Mappers').text(formatedData(jsonData['users']));
    $('#Total-Map-Edits').text(formatedData(jsonData['edits']));
    $('#Buildings-Mapped').text(formatedData(jsonData['building_count_add']));
    $('#Roads-Mapped').text(formatedData(Math.round(parseInt(jsonData['road_km_add']))));  
    $('.loader').hide()
  }
  )
})
