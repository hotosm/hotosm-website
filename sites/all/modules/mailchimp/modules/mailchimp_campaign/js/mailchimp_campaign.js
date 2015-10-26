/**
 * @file
 * Mailchimp Campaign javascript.
 */

(function ($) {

  Drupal.behaviors.mailchimp_campaign = {
    attach:function (context, settings) {
      google.load("visualization", "1", {packages:["corechart"], "callback":drawCharts});

      function drawCharts() {
        var dataTable = new google.visualization.DataTable();
        dataTable.addColumn('datetime', Drupal.t('Date'));
        dataTable.addColumn('number', Drupal.t('Emails sent'));
        dataTable.addColumn('number', Drupal.t('Unique opens'));
        dataTable.addColumn('number', Drupal.t('Clicks'));

        for (var key in settings.mailchimp_campaign.stats) {
          dataTable.addRow([
            new Date(settings.mailchimp_campaign.stats[key]['timestamp']),
            settings.mailchimp_campaign.stats[key]['emails_sent'],
            settings.mailchimp_campaign.stats[key]['unique_opens'],
            settings.mailchimp_campaign.stats[key]['recipients_click']
          ]);
        }

        var options = {
          pointSize:5,
          hAxis:{format:'MM/dd/y hh:mm aaa'}
        };

        var chart = new google.visualization.LineChart(document.getElementById('mailchimp-campaign-chart'));
        chart.draw(dataTable, options);
      }
    }
  }

})(jQuery);
