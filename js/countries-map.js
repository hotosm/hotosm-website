var countries;
var countryData = {
  "type": "FeatureCollection",
  "features": []
};
var projectYears;

fetch('/aggregatedStats.json')
  .then(function (response) {
    return response.json();
  })
  .then(function (jsonData) {
    if (projectCount !== '0') {
      var countryTitle = $(document).find("title").text().split('|')[1].trim();
      if (jsonData[countryTitle]) countryData.features = (jsonData[countryTitle]);
      var campaignCount = countryData.features.length;
      if (campaignCount) {
        var hotStatsElements = ["hot-stats", "hot-stats-tab"]
        hotStatsElements.forEach(hotStatsEle => {
          var ele = document.getElementById(hotStatsEle);
          ele.classList.remove("hide");
          ele.classList.add("active");
        })
        document.getElementById("osm-stats-tab").classList.remove("active");
        updateCountryPageIntro(campaignCount);
        projectYears = getProjectsYearRange();
        createTimeSlider();
        setSliderTimeRange();
      } else {
        var campaignCount = 0;
        document.getElementById("osm-stats").style.display = "flex";
        document.getElementById("osm-stats-tab").classList.add("active");
        updateCountryPageIntro(campaignCount);
      }
    } else {
      document.getElementById("osm-stats").style.display = "flex";
      document.getElementById("osm-stats-tab").classList.add("active");
    }
  });

mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
var map = new mapboxgl.Map({
  container: 'map-view',
  logoPosition: 'bottom-left',
  // scrollZoom: false,
  // dragRotate: false,
  maxzoom: 16,
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
});
var mapHeight = $('#map-content').height();
$('#country-contact-info__details').height(mapHeight);
map.resize();

map.on('load', function () {
  map.addSource('countriesbetter', {
    "type": "vector",
    "url": "mapbox://hot.9fvp7us2"
  });
  map.addSource('countriesProjects', {
    "type": "geojson",
    "data": countryData
  });
  map.addLayer({
    "id": "active_countries",
    "type": "fill",
    "source": "countriesbetter",
    "source-layer": "countriesbetter",
    "minzoom": 0,
    "maxzoom": 8,
    "filter": ['any', ['in', 'name_low'].concat(countryName.toLowerCase()), ['in', 'ISO_A2'].concat(countryCode)],
    "paint": {
      "fill-pattern": "lines-red-4",
      "fill-outline-color": "#EFB4B4"
    }
  }, 'place-city-sm');

  map.addLayer({
    "id": "country-projects-edits-circle",
    "type": "circle",
    "source": "countriesProjects",
    "minzoom": 0,
    "maxzoom": 18,
    "paint": {
      'circle-radius': {
        property: 'edits',
        stops: [
          [0, 10],
          [10000, 15],
          [50000, 20],
          [100000, 25],
          [125000, 30],
          [150000, 35],
          [200000, 40]
        ]
      },
      "circle-opacity": 0.7,
      "circle-color": "#FFC151",
    }
  }, 'place-city-sm');

  map.addLayer({
    "id": "country-projects-black-circle",
    "type": "circle",
    "source": "countriesProjects",
    "minzoom": 0,
    "maxzoom": 18,
    "paint": {
      'circle-radius': 6.5,
      "circle-opacity": 1,
      "circle-color": "#000000",
    }
  }, 'place-city-sm');
  map.addLayer({
    "id": "country-projects-symbol",
    "type": "symbol",
    "source": "countriesProjects",
    "minzoom": 0,
    "maxzoom": 18,
    "layout": {
      "text-field": "+",
      "text-font": ["Open Sans Bold"],
      "text-offset": [-0.001, -0.03]
    },
    "paint": {
      "text-color": "#FFFFFF"
    }
  }, 'place-city-sm');

  setSliderFilters();

  fetch('/js/bbox.json')
    .then(function (response) {
      return response.json();
    })
    .then(function (jsonData) {
      countries = jsonData;
      map.fitBounds(countries[countryCode][1], {
        // padding: 40
      }, setTimeout(() => {
        var boxZoom = map.getZoom();
        map.setMinZoom(boxZoom);
      }, 2000));
    }
    );
  map.on('mousemove', function (e) {
    var projectHover = map.queryRenderedFeatures(
      e.point,
      { layers: ['country-projects-edits-circle', 'country-projects-black-circle', 'country-projects-symbol'] }
    );
    if (projectHover.length) {
      map.getCanvas().style.cursor = 'pointer';
      $("#map__popover").empty();
      $("#map__popover").removeClass('hide');
      $("#map__popover").append(
        `<p class="popover__key">${projectHover[0].properties.status}</p>
            <p class="popover__title">${projectHover[0].properties.title}</p>
            <ul class="popover__data">
                <li>
                    <span>${projectHover[0].properties.created}</span>
                    <span>started</span>
                </li>
                <li>
                    <span class="project-status">${projectHover[0].properties.status}</span>
                    <span>status</span>
                </li>
                <li>
                    <span>${projectHover[0].properties.edits} </span>
                    <span>edits</span>
                </li>
            </ul>
            <a class="popover__link" target="_blank" href="https://tasks.hotosm.org/project/${projectHover[0].properties.id}"> 
                <p>See Tasking Manager for details</p>
            </a>`
      );

      var projectStatus = document.querySelector('.project-status');
      var popoverTitle = document.querySelector('.popover__key');
      if (projectHover[0].properties.status === 'PUBLISHED') {
        projectStatus.textContent = "Active";
        popoverTitle.innerHTML = "Active";
      }
      if (projectHover[0].properties.status === 'ARCHIVED') {
        projectStatus.textContent = "Completed";
        popoverTitle.textContent = "Completed";
      }
      if (projectHover[0].properties.title === 'Untitled project') {
        projectStatus.textContent = "Unknown";
        popoverTitle.textContent = "Unkown";
      }

      var coordinates = projectHover[0].geometry.coordinates.slice();
      while (Math.abs(e.lngLat.lng - coordinates[0]) > 180) {
        coordinates[0] += e.lngLat.lng > coordinates[0] ? 360 : -360;
      }
    } else {
      map.getCanvas().style.cursor = '';
    }
  });
});

function updateCountryPageIntro(campaignCount) {
  var intro = document.querySelector('.country-map-section__description');
  if (campaignCount !== 0) {
    if (campaignCount > 1) {
      campaignCount += ' mapping campaigns';
    } else campaignCount += ' mapping campaign';
  } else campaignCount = '';

  if (projectCount !== '0') {
    if (projectCount > 1) {
      if (campaignCount !== '') {
        projectCount = ', including ' + projectCount + ' HOT Projects.';
      } else projectCount += ' HOT Projects ';
    } else {
      if (campaignCount !== '') {
        projectCount = ', including ' + projectCount + ' HOT Project.';
      } else projectCount += ' HOT Project.';
    }
  } else projectCount = '';

  if (projectCount !== '') {
    intro.innerHTML = countryName + ' has ' +
      campaignCount + projectCount;
  } else {
    intro.innerHTML = countryName + ' has ' +
      campaignCount + projectCount;
  }
}

function getProjectsYearRange() {
  const arrayOfYears = countryData.features.map(countryProject => countryProject.properties.created)
    .map(item => Number(item));
  return arrayOfYears.filter((year, index) => index === arrayOfYears.indexOf(year)).sort((a, b) => a - b);
}