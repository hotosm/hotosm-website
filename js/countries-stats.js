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
        stats.edits = data['all_edits'];
        stats.buildings = data['building_count_add'] + data['building_count_mod'];
        stats.roads = Math.round(parseInt(data['road_km_add']) + parseInt(data['road_km_mod']));
        stats.mappers = data['contributors'];
        updateStats(stats)
      });
    }
  }
  )
})

function switchTab(evt, cityName) {
  // Declare all variables
  var i, tabcontent, tablinks;

  // Get all elements with class="tabcontent" and hide them
  tabcontent = document.getElementsByClassName("tabcontent");
  for (i = 0; i < tabcontent.length; i++) {
      console.log(tabcontent[i])
      tabcontent[i].style.display = "none";
  }

  // Get all elements with class="tablinks" and remove the class "active"
  tablinks = document.getElementsByClassName("tablinks");
  for (i = 0; i < tablinks.length; i++) {
      console.log(tablinks[i])
      tablinks[i].className = tablinks[i].className.replace(" active", "");
  }

  // Show the current tab, and add an "active" class to the button that opened the tab
  document.getElementById(cityName).style.display = "flex";
  evt.currentTarget.className += " active";
}

function updateStats (stats) {
  $('#Total-Map-Edits').text(formatedData(stats.edits));
  $('#Buildings-Mapped').text(formatedData(stats.buildings));
  $('#Roads-Mapped').text(formatedData(stats.roads));
  $('#Community-Mappers').text(formatedData(stats.mappers));
  $('.loader').hide();
}
