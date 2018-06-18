// country level stats from stats-collector
var edits = 0; 
var mappers = 0; 
var buildings = 0;
var roads = 0;
var country = $(document).find("title").text().split('|')[1].trim();   

$(document).ready(function () {
  $('.loader').show()
  fetch('/aggregatedStats.json')
  .then(function (response) {
    return response.json()
  })
  .then(function (jsonData) {
    console.log(jsonData)
    jsonData[country].forEach(project => {
      edits += project.properties['edits']
      mappers += project.properties['mappers']
      buildings += project.properties['buildings']
      roads += project.properties['roads']
    })
    console.log('edits: ', edits)
    console.log('mappers: ', mappers)
    console.log('buildings: ', buildings)
    console.log('roads: ', roads)
    $('#Total-Map-Edits').text(formatedData(edits))
    $('#Buildings-Mapped').text(formatedData(buildings))
    $('#Roads-Mapped').text(formatedData(Math.round(parseInt(roads))))
    $('#Community-Mappers').text(formatedData(mappers))
    $('.loader').hide()
  }
  )
})
