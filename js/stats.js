// add stats to the home page
$(document).ready(function () {
  fetch('https://s3.amazonaws.com/hotosm-stats-collector/aggregatedStats.json')
  .then(function (response) {
    return response.json()
  })
  .then(function (jsonData) {
    $('#Community-Mappers').text(formatedData(jsonData['totalMappers']));
    $('#Total-Map-Edits').text(formatedData(jsonData['totalEdits']));
    $('#Buildings-Mapped').text(formatedData(jsonData['totalBuildings']));
    $('#Roads-Mapped').text(formatedData(Math.round(parseInt(jsonData['totalRoads']))));  
    $('.loader').hide()
  }
  )
})
