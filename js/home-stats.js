$(document).ready(function () {
    $('.loader').show();
    $.get('https://tasks.hotosm.org/api/v1/stats/home-page', function (data) {
      console.log(data)
      $('#Community-Mappers').text(formatedData(data['totalMappers']));
      $('#Online-Mappers').text(formatedData(data['mappersOnline']));
      $('#Tasks-Mapped').text(formatedData(data['tasksMapped']));
      $('.loader').hide();
    });
  });